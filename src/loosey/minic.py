from typing import Any, Optional, NamedTuple
from contextlib import contextmanager
from argparse import ArgumentParser

from loosey import get_data_filepath
from loosey.grammar import ParseMatch
from loosey.pplex import Token, ParseError
from loosey.pp import GrammarEvaluatorWithPreprocessor


GRAMMAR_FILENAME = get_data_filepath('ansi-c-grammar.txt')

Value = Any


class Type(NamedTuple):
    match: ParseMatch


class TagDefinitionField(NamedTuple):
    name: str


class TagDefinition(NamedTuple):
    kind: str # 'struct' or 'union'
    name: str
    fields: list[TagDefinitionField]

    def __repr__(self) -> str:
        return f'{self.__class__.__name__}({self.kind!r}, {self.name!r}, {len(self.fields)} fields)'


class Function:
    def __init__(self, name: str, params: list[str], body: ParseMatch, minic: 'MiniC'):
        self.name = name
        self.params = params
        self.body = body
        self.minic = minic

    def __repr__(self) -> str:
        return f"{self.name}({', '.join(self.params)})"

    def __call__(self, *args) -> Value:
        return self.minic.call_func(self, *args)


class Return(Exception):
    def __init__(self, value: Value):
        self.value = value
class Continue(Exception): pass
class Break(Exception): pass
class Goto(Exception):
    def __init__(self, label_name: str):
        self.label_name = label_name


class MiniC(GrammarEvaluatorWithPreprocessor):
    r"""Miniature C interpreter, which can use many Python objects and
    functions directly, and whose objects and functions can be used
    directly from Python.

    Comes with its own C preprocessor, can parse all of ANSI C, and can
    run... some C code. It's a work in progress.

        >>> minic = MiniC()

        >>> minic.eval('1 + 2')
        3

        >>> minic.eval('int add(int x, int y) { return x + y; }')
        add(x, y)

        >>> minic.eval('int x = 1, y = 2;')
        {'x': 1, 'y': 2}

        >>> minic.eval('int total = add(x, y);')
        {'total': 3}

        >>> minic.eval('int total = add(2, 3);')
        {'total': 5}

        >>> minic.globals
        {'add': add(x, y), 'x': 1, 'y': 2, 'total': 5}

        We can use Python values directly!
        >>> minic.globals['x'] = 99
        >>> minic.globals['ten'] = lambda x: x * 10
        >>> minic.eval('int total = ten(x);')
        {'total': 990}

        The C preprocessor is available too!
        >>> minic.eval('#define DOUBLE(X) X + X')
        >>> minic.eval('int x = DOUBLE(3);')
        {'x': 6}

        Parsing of typedefs are correctly handled...
        See: https://en.wikipedia.org/wiki/Lexer_hack
        >>> minic.parse('typedef int Integer; Integer *x;').pprint()
        translation_unit
          declaration
            declspec: declaration_specifiers
              typedef
              int
            declare: Integer
          declaration
            declspec: declaration_specifiers
              Integer
            declarator
              pointer: *
              declare: x

        >>> minic.parse('struct T { int x; int y; };').pprint()
        declspec: declaration_specifiers
          struct_or_union_specifier
            struct
            T
            struct_declaration_list
              struct_declaration
                int
                declare: x
              struct_declaration
                int
                declare: y

    Accessing attributes and methods of Python objects:

        >>> from types import SimpleNamespace

        >>> add_struct_fields = minic.eval('''
        ...     int add_struct_fields(struct t *obj) {
        ...         return obj->x + obj->y;
        ...     }
        ... ''')
        >>> add_struct_fields(SimpleNamespace(x=1, y=2))
        3

        >>> add_dict_keys = minic.eval('''
        ...     int add_dict_keys(struct t *obj) {
        ...         return obj->get("x") + obj->get("y");
        ...     }
        ... ''')
        >>> add_dict_keys({'x': 1, 'y': 2})
        3

    """

    grammar_filename = GRAMMAR_FILENAME
    main_rule_name = 'repl_command'
    squash_children = True

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.globals: dict[str, Value] = {}

        # NOTE: this is essentially the "call stack" used during evaluation
        self.scopes: list[dict[str, Value]] = [self.globals]

        self.global_tags: dict[str, TagDefinition] = {}
        self.tag_scopes: list[dict[str, TagDefinition]] = [{}]

        # The rules for parsing C typedefs are awful, because they're not
        # purely based on the structure of the grammar, they're also based
        # on whether the given identifier was declared as a typedef...
        # See: https://en.wikipedia.org/wiki/Lexer_hack
        # Anyway, the typedef_blocks and related callbacks here are used to
        # handle that.
        self.typedef_blocks: list[set[str]] = []
        self.pattern_callbacks = {
            ('compound_statement', 'block'):
                (self.enter_typedef_block, self.exit_typedef_block),
            ('translation_unit', None):
                (self.enter_typedef_block, self.exit_typedef_block),
            ('declaration', None):
                (None, self.exit_declaration),
        }
        self.toktype_predicates = {
            'TYPE_NAME': self.is_type_name_token,
        }

    def no_match(self, tokens: list[Token], rule_name: str) -> Optional[ParseMatch]:
        if not tokens:
            # If we got no tokens from parsing, that might mean e.g. that
            # user hit Enter at the REPL without typing anything, or that
            # they entered some valid C preprocessor stuff which didn't
            # generate any tokens, like a #define.
            # That's all good!
            return None
        return super().no_match(tokens, rule_name)

    def enter_typedef_block(self, token: Token):
        self.typedef_blocks.append(set())

    def exit_typedef_block(self, token: Token, match: Optional[ParseMatch]):
        self.typedef_blocks.pop()

    def exit_declaration(self, token: Token, match: Optional[ParseMatch]):
        if match is None:
            return
        if not self.typedef_blocks:
            return
        typedef_block = self.typedef_blocks[-1]
        for child in match.findall('.* declare:'):
            typedef_block.add(child.token.value)

    def is_type_name_token(self, token: Token) -> bool:
        # TODO: also check for typedefs which were previously evaluated,
        # not just which were declared during the current parse (which is
        # all that is tracked by self.typedef_blocks)
        return (
            token.toktype == 'IDENTIFIER'
            and self.typedef_blocks and any(
                token.value in block
                for block in reversed(self.typedef_blocks)))

    @contextmanager
    def new_scope(self) -> dict[str, Value]:
        scope = {}
        self.scopes.append(scope)
        try:
            yield scope
        finally:
            assert self.scopes.pop() is scope

    def get_var(self, name: str) -> Value:
        for scope in reversed(self.scopes):
            if name in scope:
                return scope[name]
        return None

    def set_var(self, name: str, value: Value):
        self.scopes[-1][name] = value

    def set_vars(self, values: dict[str, Value]):
        self.scopes[-1].update(values)

    def on_function_definition(self, match: ParseMatch) -> Value:
        declarator = match.find('declarator')
        name = declarator.find('declare:.').token.value
        params = [child.token.value for child in declarator.findall(
            'params:declarator_suffix .* declare:.')]
        body = match.find('block:compound_statement')
        function = Function(name, params, body, self)
        self.globals[name] = function
        return function

    def on_declaration(self, match: ParseMatch) -> dict[str, Value]:
        match = match.find('init_declarator_list') or match
        values = {}
        for child in match.findall('init_declarator'):
            name = child.find('declare:.').token.value
            value = self.on(child.children[-1])
            self.set_var(name, value)
            values[name] = value
        return values

    def dereference(self, value: Value) -> Value:
        # TODO: if value is a pointer, dereference it!..
        # Otherwise, we return value as-is, which is especially handy if we
        # want to pass arbitrary Python objects to C code.
        return value

    def on_postfix_expression(self, match: ParseMatch) -> Value:
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            if child.pattern_name == 'call':
                param_values = [self.on(subchild) for subchild in child.children]
                value = value(*param_values)
            elif child.pattern_name == 'dot':
                attr = child.children[0].token.value
                value = getattr(value, attr)
            elif child.pattern_name == 'arrow':
                value = self.dereference(value)
                attr = child.children[0].token.value
                value = getattr(value, attr)
            else:
                raise child.missing_handler()
        return value

    def call_func(self, func: Function, *param_values) -> Value:
        with self.new_scope() as scope:
            for param_name, param_value in zip(func.params, param_values):
                scope[param_name] = param_value
            try:
                self.on(func.body)
            except Return as ret:
                return ret.value

    def on_literal__primary_expression(self, match: ParseMatch) -> Value:
        token = match.token
        if token.toktype == 'NUMBER':
            return token.parse_number()
        elif token.toktype == 'STRING':
            return token.parse_string()
        elif token.toktype == 'CHAR':
            return ord(token.parse_char())
        else:
            raise match.missing_handler()

    def on_block__compound_statement(self, match: ParseMatch) -> Value:
        for child in match.children:
            value = self.on(child)
        return None

    def on_return__jump_statement(self, match: ParseMatch) -> Value:
        if match.children:
            value = self.on(match.children[0])
        else:
            value = None
        raise Return(value)

    def on_ident__primary_expression(self, match: ParseMatch) -> Value:
        return self.get_var(match.token.value)

    def on_additive_expression(self, match: ParseMatch) -> Value:
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            op = child.token.value
            arg = self.on(next(children))
            if op == '+':
                value += arg
            else:
                raise ParseError(token, f"Dunno binary op {op!r}")
        return value


def main():
    parser = ArgumentParser()
    parser.add_argument('-f', '--filename', default='-')
    parser.add_argument('-v', '--verbose', default=False, action='store_true')
    parser.add_argument('--partial', default=False, action='store_true')
    args = parser.parse_args()

    minic = MiniC()
    match = minic.parse_from_file(
        args.filename,
        verbose=args.verbose,
        partial=args.partial,
    )
    if match:
        match.pprint()


if __name__ == '__main__':
    main()
