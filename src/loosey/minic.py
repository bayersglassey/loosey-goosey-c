from typing import NamedTuple, Any
from contextlib import contextmanager

from loosey import get_data_filename
from loosey.grammar import ParseMatch
from loosey.pplex import Token, ParseError
from loosey.pp import GrammarEvaluatorWithPreprocessor


class Function(NamedTuple):
    name: str
    params: list[str]
    body: ParseMatch


Value = Any


GRAMMAR_FILENAME = get_data_filename('ansi-c-grammar.txt')


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
    r"""Miniature C interpreter

        >>> minic = MiniC()

        >>> add = minic.eval('int add(int x, int y) { return x + y; }')
        >>> add.name, add.params
        ('add', ['x', 'y'])

        >>> minic.eval('int x = 1, y = 2;')
        {'x': 1, 'y': 2}

        >>> minic.eval('int total = add(x, y);')
        {'total': 3}

        >>> minic.eval('int total = add(2, 3);')
        {'total': 5}

        >>> list(minic.globals)
        ['add', 'x', 'y', 'total']

        We can use Python values directly!
        >>> minic.globals['x'] = 99
        >>> minic.globals['ten'] = lambda x: x * 10
        >>> minic.eval('int total = ten(x);')
        {'total': 990}

    """

    grammar_filename = GRAMMAR_FILENAME
    squash_children = True

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.globals = {}
        self.scopes = [self.globals]

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
        function = Function(name, params, body)
        self.globals[name] = function
        return function

    def on_declaration(self, match: ParseMatch) -> dict[str, Value]:
        match = match.find('init_declarator_list') or match
        values = {}
        for child in match.findall('init_declarator'):
            name = child.find('declare:.').token.value
            value = self.on(child.children[-1])
            values[name] = value
        self.set_vars(values)
        return values

    def on_postfix_expression(self, match: ParseMatch) -> Value:
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            if child.pattern_name == 'call':
                param_values = [self.on(subchild) for subchild in child.children]
                if callable(value):
                    value = value(*param_values)
                elif isinstance(value, Function):
                    value = self.call_func(value, *param_values)
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
