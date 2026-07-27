"""

    This file implements the C preprocessor.

    I used the following documentation as a rough guide:
    * https://gcc.gnu.org/onlinedocs/cpp/index.html
    * https://en.cppreference.com/c/preprocessor

    ...and various files in the Linux kernel and CPython source for testing.

    =========================================================================
    ERRATA:
    Some of the behaviour in this implementation is incorrect.
    We're okay with this, since our intended use case is exploration of
    well-written codebases, e.g. CPython, SQLite, and the Linux kernel, which
    hopefully only contain "sane" uses of the preprocessor.

    For instance, according to the C standard, SOME_MACRO([1, 2]) should
    be interpreted as passing 2 parameters to SOME_MACRO: the token sequences
    "[1" and "2]".
    However, our processor implementation uses our "token trees", instead of
    token sequences, and so it naturally treats SOME_MACRO([1, 2]) as passing
    a single parameter to SOME_MACRO: the TokenTreeNode sequence "[1, 2]".

    We also don't support "preprocessor numbers".
    See: https://gcc.gnu.org/onlinedocs/cpp/Tokenization.html

        A preprocessing number has a rather bizarre definition. The category
        includes all the normal integer and floating point constants one
        expects of C, but also a number of other things one might not
        initially recognize as a number.
        Formally, preprocessing numbers begin with an optional period, a
        required decimal digit, and then continue with any sequence of
        letters, digits, underscores, periods, and exponents.
        ...etc...

"""

import sys
from typing import NamedTuple, Iterable, Iterator, Optional

from lgci.recursion import debug_recursion
from lgci.iter import FancyIterator
from lgci.lex import (
    ParseError,
    Token,
    TokenTreeNode,
    TokenTreeBuilder,
    build_toktree_from_file,
)


class PreprocessorDefinition(NamedTuple):
    """Represents a C #define directive"""
    name: str
    token: Token
    body: list[TokenTreeNode]
    params: list[str] = None

    @property
    def is_macro(self) -> bool:
        return self.params is not None

    def pprint(self):
        msg = f'#define {self.name}'
        if self.params is not None:
            msg += f"({', '.join(self.params)})"
        print(msg)
        for node in self.body:
            node.pprint(1)


class Preprocessor:
    r"""An implementation of the C processor.
    Takes token trees as input, and returns token trees as output.

        >>> pp = Preprocessor()

        Preprocessor definitions don't have any output of their own:
        >>> for node in pp.process(r'''
        ...     #define K 1024
        ...     #define SIZE 3 * K
        ...     #define DUMMY hello
        ...     #undef DUMMY
        ...     #define MALLOC(VAR, SIZE) \
        ...         VAR = malloc(SIZE);
        ... '''): node.pprint()

        The definitions are stored for use in subsequent processing:
        >>> for name, definition in pp.definitions.items():
        ...     definition.pprint()
        #define K
          DEC_INT val='1024'
        #define SIZE
          DEC_INT val='3'
          PUNCTUATION val='*'
          IDENTIFIER val='K'
        #define MALLOC(VAR, SIZE)
          IDENTIFIER val='VAR'
          PUNCTUATION val='='
          IDENTIFIER val='malloc'
          PUNCTUATION val='('
            IDENTIFIER val='SIZE'
          PUNCTUATION val=';'

        The definitions are expanded in the usual way:
        >>> for node in pp.process(r'''
        ...     size_t size = SIZE;
        ... '''): node.pprint()
        IDENTIFIER val='size_t'
        IDENTIFIER val='size'
        PUNCTUATION val='='
        DEC_INT val='3'
        PUNCTUATION val='*'
        DEC_INT val='1024'
        PUNCTUATION val=';'

        >>> for node in pp.process(r'''
        ...     char *msg;
        ...     MALLOC(msg, SIZE)
        ... '''): node.pprint()
        IDENTIFIER val='char'
        PUNCTUATION val='*'
        IDENTIFIER val='msg'
        PUNCTUATION val=';'
        IDENTIFIER val='msg'
        PUNCTUATION val='='
        IDENTIFIER val='malloc'
        PUNCTUATION val='('
          DEC_INT val='3'
          PUNCTUATION val='*'
          DEC_INT val='1024'
        PUNCTUATION val=';'

    Possible errors:

        >>> list(Preprocessor().process('#define X(Y Z)'))
        Traceback (most recent call last):
         ...
        lgci.lex.ParseError: <fakefile>:1:10: Param 1 consists of 2 tokens

        >>> list(Preprocessor().process('#define X(1, 2)'))
        Traceback (most recent call last):
         ...
        lgci.lex.ParseError: <fakefile>:1:11: Param 1 is not an identifier: DEC_INT val='1'

        >>> list(Preprocessor().process('#undef X Y'))
        Traceback (most recent call last):
         ...
        lgci.lex.ParseError: <fakefile>:1:1: Extra tokens after 'X'

    """

    def __init__(self, *, verbose: bool = True):
        self.verbose = verbose
        self.definitions: dict[str, PreprocessorDefinition] = {}
        self.macro_param_values: dict[str, list[TokenTreeNode]] = {}
        self.currently_expanding_macros: set[str] = set()

    def warn(self, token: Token, msg: str):
        if self.verbose:
            print(f"{token.location()}: {msg}", file=sys.stderr)

    @debug_recursion()
    def process(self, nodes: Iterable[TokenTreeNode]) -> Iterator[TokenTreeNode]:
        """Process top-level tree nodes"""
        if isinstance(nodes, str):
            # Support caller passing us a string, handy for doctests
            nodes = TokenTreeBuilder().build(nodes)
        yield from self.expand(nodes)

    @debug_recursion()
    def _handle_directive(self, node: TokenTreeNode, directive: str, nodes: Iterator[TokenTreeNode]):
        # NOTE: directive == node.token.directive()
        if directive == 'define':
            # Handle definitions
            name = node.token.value
            if name in self.definitions:
                definition = self.definitions[name]
                self.warn(node.token,
                    f"Redefining {name!r} (previous definition at {definition.token.location()})")
            if node.token.toktype == 'DEFMACRO':
                # Macro definition
                # NOTE: the way lexing of macro definitions works, we're
                # guaranteed to have at least one child, and for that first
                # child's type to be '('.
                params = []
                for i, param_nodes in enumerate(node.children[0].parse_parenlist()):
                    if len(param_nodes) != 1:
                        raise ParseError(node.children[0].token,
                            f"Param {i + 1} consists of {len(param_nodes)} tokens")
                    param_node = param_nodes[0]
                    if param_node.token.toktype != 'IDENTIFIER':
                        raise ParseError(param_node.token,
                            f"Param {i + 1} is not an identifier: {param_node.token.prettystring()}")
                    if param_node.token.value == '...':
                        # TODO: handle variadic macros T_T
                        raise ParseError(param_node.token, "Variadic macros not supported")
                    params.append(param_node.token.value)
                body = node.children[1:]
            else:
                # Non-macro definition
                params = None
                body = node.children
            self.definitions[name] = PreprocessorDefinition(
                name=name,
                token=node.token,
                body=body,
                params=params,
            )
        elif directive == 'undef':
            # Handle #undef NAME
            if node.children:
                raise ParseError(node.token, f"Extra tokens after {node.token.value!r}")
            self.definitions.pop(node.token.value, None)
        else:
            # Some other directive...
            self.warn(node.token,
                f"Ignoring unsupported directive: {node.token.prettystring()}")

    @debug_recursion()
    def _expand_definition(
            self,
            node: TokenTreeNode,
            name: str,
            nodes: FancyIterator[TokenTreeNode],
            ) -> Iterator[TokenTreeNode]:
        # NOTE: name == node.token.identifier()
        # NOTE: caller guarantees `name in self.definitions`
        definition = self.definitions[name]
        if definition.is_macro:
            # Grab the next node, and attempt to parse it as a
            # parenthesized list
            params_node = next(nodes, None)
            if params_node is None or params_node.token.punctuation() != '(':
                # If we're referring to a macro, but not calling it, then we
                # just emit its name as a token.
                if params_node is not None:
                    # We didn't actually find a node of params, so push
                    # whatever we found back onto the iterator...
                    nodes.push(params_node)
                yield node
                return
            param_values = params_node.parse_parenlist()
            if len(param_values) != len(definition.params):
                # TODO: handle variadic macros T_T
                raise ParseError(node.token,
                    f"Expected to receive {len(definition.params)} macro parameters, "
                    f"got {len(param_values)}")

            # Map parameter names to values, i.e. token sequences
            # NOTE: we do *NOT* expand the values here, but rather when a
            # param is referenced!..
            param_values_dict = dict(zip(definition.params, param_values))

            # Now, we store the parameter values in a dict on self, so that
            # they can be referred to while the macro body is being expanded
            old_param_values = self.macro_param_values
            self.macro_param_values = old_param_values.copy()
            self.macro_param_values.update(param_values_dict)
            try:
                # Expand the macro's body!
                yield from self.expand(definition.body)
            finally:
                # ...and roll back the parameter values, now that the
                # macro body has been expanded
                self.macro_param_values = old_param_values
        else:
            # Just expand the definition's body
            yield from self.expand(definition.body)

    @debug_recursion()
    def expand(self, nodes: Iterable[TokenTreeNode]) -> Iterator[TokenTreeNode]:
        """Recursively "expands" the given nodes, i.e. applies preprocessor
        definitions to them"""
        # We want our nodes to be a "fancy" iterator, so that we can e.g.
        # peek at them without actually consuming them!
        nodes = FancyIterator(nodes)
        for node in nodes:
            # NOTE: there's not much point to factoring self._expand_node
            # out of the loop here, except that it allows the node to show
            # up in the output of debug_recursion, which is super useful!
            yield from self._expand_node(node, nodes)

    @debug_recursion()
    def _expand_node(self, node: TokenTreeNode, nodes: FancyIterator[TokenTreeNode]) -> Iterator[TokenTreeNode]:
        directive = node.token.directive()
        if directive is not None:
            self._handle_directive(node, directive, nodes)
            return
        ident = node.token.identifier()
        if ident == '__FILE__':
            filename = node.token.filename
            yield TokenTreeNode(Token('STRING', filename, value=filename))
        elif ident == '__LINE__':
            filename = node.token.filename
            yield TokenTreeNode(Token('DEC_INT', filename, value=str(node.token.row)))
        elif ident in self.macro_param_values:
            # We found a reference to a bound macro parameter
            # NOTE: parameters' values are expanded here, when they are
            # referenced, *not* when the macro is called!..
            yield from self.expand(self.macro_param_values[ident])
        elif ident in self.definitions:
            # We found a reference to a definition, so let's expand it
            if ident in self.currently_expanding_macros:
                # Macros do not recurse!..
                yield node
            else:
                self.currently_expanding_macros.add(ident)
                try:
                    yield from self._expand_definition(node, ident, nodes)
                finally:
                    self.currently_expanding_macros.remove(ident)
        else:
            # This node is not a reference to a definition, but if it
            # has children, we need to recursively expand them
            if node.children is not None:
                node = node._replace(children=list(self.expand(node.children)))
            yield node


def main():
    filename = sys.argv[1]
    pp = Preprocessor()
    nodes = build_toktree_from_file(filename)
    for node in pp.process(nodes):
        node.pprint()


if __name__ == '__main__':
    main()
