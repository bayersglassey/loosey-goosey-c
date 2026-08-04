from typing import Any, Optional
from contextlib import contextmanager

from loosey import get_data_filename
from loosey.grammar import ParseMatch
from loosey.pplex import Token, ParseError
from loosey.pp import GrammarEvaluatorWithPreprocessor


GRAMMAR_FILENAME = get_data_filename('ansi-c-grammar.txt')

Value = Any


class Function:
    def __init__(self, name: str, params: list[str], body: ParseMatch, minic: 'MiniC'):
        self.name = name
        self.params = params
        self.body = body
        self.minic = minic

    def __repr__(self):
        return f"{self.name}({', '.join(self.params)})"

    def __call__(self, *args) -> Value:
        return self.minic.call_func(self, *args)


def _parse_number(token: Token) -> int | float:
    text = token.value
    try:
        if '.' in text:
            return float(text)
        elif text.startswith('0x'):
            return int(text[2:], 16)
        elif len(text) > 1 and text.startswith('0'):
            return int(text[1:], 8)
        else:
            return int(text)
    except ValueError:
        raise ParseError(token, f"Couldn't parse as number: {text!r}")


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

    """

    grammar_filename = GRAMMAR_FILENAME
    main_rule_name = 'repl_command'
    squash_children = True

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.globals = {}
        self.scopes = [self.globals]

        # The rules for parsing C typedefs are awful, because they're not
        # purely based on the structure of the grammar, they're also based
        # on whether the given identifier was declared as a typedef...
        # See: https://en.wikipedia.org/wiki/Lexer_hack
        # Anyway, the typedef_blocks and related callbacks here are used to
        # handle that.
        self.typedef_blocks: list[set[str]] = []
        self.pattern_callbacks = {
            ('compound_statement', 'block'):
                (self.enter_parse_block, self.exit_parse_block),
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

    def parse(self, *args, **kwargs):
        # Add an initial "typedef block" so typedefs are handled correctly
        # for the duration of the parse
        self.typedef_blocks.append(set())
        try:
            return super().parse(*args, **kwargs)
        finally:
            self.typedef_blocks.pop()

    def enter_parse_block(self, token: Token):
        self.typedef_blocks.append(set())

    def exit_parse_block(self, token: Token, match: Optional[ParseMatch]):
        self.typedef_blocks.pop()

    def exit_declaration(self, token: Token, match: Optional[ParseMatch]):
        if match is None:
            return
        parse_block = self.typedef_blocks[-1]
        declares = match.findall('.* declare:')
        for declare in declares:
            name = declare.token.value
            parse_block.add(name)

    def is_type_name_token(self, token: Token) -> bool:
        # TODO: also check for typedefs which were previously evaluated,
        # not just which were declared during the current parse (which is
        # all that is tracked by self.typedef_blocks)
        return (
            token.toktype == 'IDENTIFIER'
            and self.typedef_blocks and token.value in self.typedef_blocks[-1])

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
        name = match.find('declarator declare:.').token.value
        params = [child.token.value for child in declarator.findall(
            'params:direct_operator parameter_list parameter_declaration declare:.')]
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

    def on_postfix_expression(self, match: ParseMatch) -> Value:
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            if child.pattern_name == 'call':
                param_values = [self.on(subchild) for subchild in child.children]
                value = value(*param_values)
            else:
                raise ParseError(child.token, f"Dunno how to eval {child.spec}")
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
            return _parse_number(token)
        else:
            raise ParseError(token, f"Dunno how to eval {match.spec}")

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


def _parse_tests():
    r"""These doctests are basically tests of ansi-c-grammar.txt, making sure
    that it can produce reasonable parse trees

        >>> minic = MiniC()

        >>> minic.parse('int x = 2 * 3 + 4;').pprint()
        declaration
          declspec: declaration_specifiers
            int
          init_declarator
            declare: x
            =
            additive_expression
              multiplicative_expression
                literal: 2
                *
                literal: 3
              +
              literal: 4

        >>> minic.parse('int x, x = 1, *x = &x;').pprint()
        declaration
          declspec: declaration_specifiers
            int
          init_declarator_list
            declare: x
            init_declarator
              declare: x
              =
              literal: 1
            init_declarator
              declarator
                pointer: *
                declare: x
              =
              unary_expression
                &
                ident: x

        >>> minic.parse('int add(int x, int y) { return x + y; }').pprint()
        function_definition
          declspec: declaration_specifiers
            int
          declarator
            declare: add
            params: direct_operator
              parameter_list
                parameter_declaration
                  declspec: declaration_specifiers
                    int
                  declare: x
                parameter_declaration
                  declspec: declaration_specifiers
                    int
                  declare: y
          block: compound_statement
            return: jump_statement
              additive_expression
                ident: x
                +
                ident: y

        >>> minic.parse(r'''
        ...     void hello(int n, const char *name) {
        ...         int i;
        ...         for(i = 0; i < n; i++) printf("Hello, %s!\n", name);
        ...     }
        ... ''').pprint()
        function_definition
          declspec: declaration_specifiers
            void
          declarator
            declare: hello
            params: direct_operator
              parameter_list
                parameter_declaration
                  declspec: declaration_specifiers
                    int
                  declare: n
                parameter_declaration
                  declspec: declaration_specifiers
                    const
                    char
                  declarator
                    pointer: *
                    declare: name
          block: compound_statement
            declaration
              declspec: declaration_specifiers
                int
              declare: i
            for: iteration_statement
              assignment_expression
                ident: i
                =
                literal: 0
              relational_expression
                ident: i
                <
                ident: n
              postfix_expression
                ident: i
                inc: ++
              postfix_expression
                ident: printf
                call: postfix_operator
                  literal: "Hello, %s!\n"
                  ident: name

    """
