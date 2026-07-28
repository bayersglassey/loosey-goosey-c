"""

    This file implements the C preprocessor.

    I used the following documentation as a rough guide:
    * https://gcc.gnu.org/onlinedocs/cpp/index.html
    * https://en.cppreference.com/c/preprocessor

"""

import sys
from typing import NamedTuple

from loosey.iter import FancyIterator
from loosey.pplex import Token, Lexer, tokenize_file
from loosey.recursion import debug_recursion


class Macro(NamedTuple):
    """A macro, i.e. the thing produced by the #define directive"""
    token: Token
    body: list[Token]
    params: list[str] = None

    @property
    def name(self) -> str:
        return self.token.value

    @property
    def is_function(self) -> bool:
        """Function-like macros take parameters, i.e. `#define M()` as
        opposed to just `#define M`"""
        return self.params is not None


class Preprocessor:
    """An implementation of the C preprocessor.
    Transforms a stream of tokens."""

    def __init__(self, *, verbose: bool = True):
        self.verbose = verbose
        self.directives_ok = True

        # Defined macros
        self.macros: dict[str, Macro] = {}

        # The "call stack" for macro expansion
        self.expanding_macros: list[str] = []

    def warn(self, token: Token, msg: str):
        if self.verbose:
            print(f"{token.location()}: {msg}", file=sys.stderr)

    @debug_recursion()
    def process(self, tokens: Iterable[Token] | str) -> Iterator[Token]:
        """Process top-level tokens"""
        if isinstance(tokens, str):
            # Support caller passing us a string, handy for doctests
            tokens = Lexer().tokenize(tokens)

        # We want our tokens to be a "fancy" iterator, so that we can e.g.
        # peek at them without actually consuming them!
        tokens = FancyIterator(tokens)

        # We're at top-level, so we're at the start of the first line, so
        # enable directives
        self.directives_ok = True

        yield from self.expand(tokens)

    @debug_recursion()
    def _process(self, tokens: FancyIterator[Token]) -> Iterator[Token]:
        for token in tokens:
            # NOTE: there's not much point to factoring self._process_token
            # out of the loop here, except that it allows the token to show
            # up in the output of debug_recursion, which is super useful!
            yield from self._process_token(token, tokens)

    @debug_recursion()
    def _process_token(self, token: Token, tokens: FancyIterator[Token]) -> Iterator[Token]:
        if token.toktype == 'COMMENT':
            pass
        elif token.toktype == 'INCLUDE':
            # TODO: implement #include, probably with a whitelist
            self.warn(token, f"Ignoring include: {token.value}")
        elif token.toktype in ('DEFMACRO', 'DEFINE'):
            self._define_macro(token, tokens)
        elif token.value == '#':
        else:
            # Disable directives until the next line
            self.directives_ok = False
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


def main():
    filename = sys.argv[1]
    pp = Preprocessor()
    tokens = tokenize_file(filename)
    for token in pp.process(tokens):
        token.pprint()


if __name__ == '__main__':
    main()
