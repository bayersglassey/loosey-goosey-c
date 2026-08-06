import inspect
from typing import Any, Optional, NamedTuple, Iterator
from contextlib import contextmanager
from argparse import ArgumentParser

from loosey import get_data_filepath
from loosey.grammar import ParseMatch
from loosey.pplex import Token, ParseError
from loosey.pp import GrammarEvaluatorWithPreprocessor


GRAMMAR_FILENAME = get_data_filepath('ansi-c-grammar.txt')

Value = Any


class TypeDef(NamedTuple):
    name: str

    # E.g. 'typedef int'
    declspec: ParseMatch

    # E.g. 'x', '*x', etc
    declarator: ParseMatch

    def __repr__(self) -> str:
        return f'{self.__class__.__name__}({self.name!r})'


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


class PythonFunction:
    """Looks and behaves like a Function, but just wraps a Python function,
    not C code"""

    def __init__(self, func, name=None):
        self.func = func
        self.name = func.__name__ if name is None else name
        self.params = list(inspect.signature(func).parameters)

    def __call__(self, *args):
        return self.func(*args)

    def __repr__(self) -> str:
        return f"{self.name}({', '.join(self.params)})"


class Return(Exception):
    def __init__(self, value: Value):
        self.value = value
class Continue(Exception): pass
class Break(Exception): pass
class Goto(Exception):
    def __init__(self, label_name: str):
        self.label_name = label_name


class Struct:
    """Can be used as a struct or union by MiniC.
    Automatically creates new fields as they are referenced.

        >>> obj = Struct()
        >>> obj
        Struct()
        >>> obj.x = 2
        >>> obj.x
        2
        >>> obj.y
        Struct()
        >>> obj
        Struct(x, y)

    """

    def __init__(self):
        self.__dict__['fields'] = {}

    def __repr__(self) -> str:
        return f"{self.__class__.__name__}({', '.join(self.fields)})"

    def __setattr__(self, attr: str, value: Value):
        self.fields[attr] = value

    def __getattr__(self, attr: str) -> Value:
        if attr not in self.fields:
            self.fields[attr] = Struct()
        return self.fields[attr]


class MemoryBlock:
    """Behaves like a block of memory in C, i.e. an array of objects.
    Should generally be accessed through a Pointer."""

    def __init__(self):
        self.entries: dict[int, Value] = {}
        self._update_indexes()

        self.freed = False

    def _update_indexes(self):
        self.min_index = 0 if not self.entries else min(self.entries)
        self.max_index = 0 if not self.entries else max(self.entries)
        self._sorted = False

    def _sort_entries(self):
        if self._sorted:
            return
        entries = self.entries
        self.entries = {index: entries[index] for index in sorted(entries)}
        self._sorted = True

    def __repr__(self) -> str:
        msg = f'{self.min_index}..{self.max_index}'
        if self.freed:
            msg += ', freed=True'
        return f'{self.__class__.__name__}({msg})'

    def __iter__(self) -> Iterator[int]:
        self._sort_entries()
        return iter(self.entries)

    def items(self) -> Iterator[tuple[int, Value]]:
        self._sort_entries()
        return self.entries.items()

    def __contains__(self, index: int) -> bool:
        return index in self.entries

    def __setitem__(self, index: int, value: Value):
        self.entries[index] = value
        self._update_indexes()

    def __getitem__(self, index: int) -> Value:
        if index not in self.entries:
            # You can access any offset of the pointer, and by default, you
            # will find a fresh Struct there.
            # So you can allocate fresh memory for an object, and assign to
            # its fields right away.
            self.entries[index] = Struct()
            self._update_indexes()
        return self.entries[index]

    def free(self):
        if self.freed:
            raise Exception(f"Attempted to free already-freed memory: {self!r}")
        else:
            self.freed = True


class Pointer:
    """Behaves like a C pointer, i.e. an offset into a block of memory.

        >>> ptr = Pointer(MemoryBlock())
        >>> ptr
        Pointer(0..0)
        >>> ptr[0]
        Struct()
        >>> ptr[0] = 1
        >>> ptr[0]
        1
        >>> ptr[-1] = 'hello'
        >>> ptr[2] = 'world'
        >>> ptr
        Pointer(-1..2)
        >>> ptr + 2
        Pointer(-3..0)
        >>> (ptr + 2)[-3]
        'hello'
        >>> (ptr + 2)[0]
        'world'
        >>> list(ptr + 2)
        [-3, -2, 0]

        Some syntactic sugar: ptr.contents is the same as ptr[0].
        But frankly, [0] is probably more straightforward anyway.
        >>> ptr.contents = 'xx'
        >>> ptr.contents
        'xx'
        >>> ptr[0]
        'xx'

    """

    def __init__(self, mem: MemoryBlock, index: int = 0):
        self.__dict__['mem'] = mem
        self.__dict__['index'] = index

    @property
    def min_index(self) -> int:
        return self.mem.min_index - self.index

    @property
    def max_index(self) -> int:
        return self.mem.max_index - self.index

    @property
    def freed(self) -> bool:
        return self.mem.freed

    def __repr__(self) -> str:
        msg = f'{self.min_index}..{self.max_index}'
        if self.freed:
            msg += ', freed=True'
        return f'{self.__class__.__name__}({msg})'

    @property
    def contents(self) -> Value:
        return self[0]

    @contents.setter
    def contents(self, value: Value):
        self[0] = value

    def __iter__(self) -> Iterator[int]:
        for index in self.mem:
            yield index - self.index

    def items(self) -> Iterator[tuple[int, Value]]:
        for index, value in self.mem.items():
            yield (index - self.index, value)

    def __contains__(self, index: int) -> bool:
        return index + self.index in self.mem

    def __add__(self, index: int) -> 'Pointer':
        return Pointer(self.mem, self.index + index)

    def __sub__(self, index: int) -> 'Pointer':
        return Pointer(self.mem, self.index - index)

    def __iadd__(self, index: int) -> 'Pointer':
        self.__dict__['index'] += index
        return self

    def __isub__(self, index: int) -> 'Pointer':
        self.__dict__['index'] -= index
        return self

    def __setitem__(self, index: int, value: Value):
        self.mem[self.index + index] = value

    def __getitem__(self, index: int) -> Value:
        return self.mem[self.index + index]

    def __setattribute__(self, attr: str, value: Value):
        # It's very easy to accidentally set the attribute of a pointer,
        # instead of the Struct you expected it to be referring to...
        # So we explicitly reject random attribute assignments.
        raise AttributeError(f"Can't set attribute {attr!r} of a Pointer!")

    def free(self):
        self.mem.free()


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

        We can use Python values directly!
        >>> minic.globals['x'] = 99
        >>> minic.globals['ten'] = lambda x: x * 10
        >>> minic.eval('int total = ten(x);')
        {'total': 990}

        The C preprocessor is available too!
        >>> minic.eval('#define DOUBLE(X) X + X')
        >>> minic.eval('int x = DOUBLE(3);')
        {'x': 6}

        Parsing of typedefs is handled correctly!
        See: https://en.wikipedia.org/wiki/Lexer_hack
        In the examples below, when Integer is not a typedef, `Integer *x`
        is interpreted as a multiplication; when it's a typedef, `Integer *x`
        is interpreted as a variable declaration:
        >>> f = minic.eval('void f() { Integer *x; }')
        >>> for child in f.body.children: child.pprint()
        multiplicative_expression
          ident: Integer
          *
          ident: x
        >>> f = minic.eval('void f() { typedef int Integer; Integer *x; }')
        >>> for child in f.body.children: child.pprint()
        declaration_list
          declaration
            declspec: declaration_specifiers
              typedef
              int
            decl: init_declarator
              declare: Integer
          declaration
            declspec: declaration_specifiers
              Integer
            decl: init_declarator
              declarator
                pointer: *
                declare: x

        Similarly, if we evaluate a typedef, it exists in our globals, and
        is taken into account when parsing:
        >>> minic.parse('T *x;').pprint()
        multiplicative_expression
          ident: T
          *
          ident: x
        >>> minic.eval('typedef struct t T;')
        {'T': TypeDef('T')}
        >>> minic.parse('T *x;').pprint()
        declaration
          declspec: declaration_specifiers
            T
          decl: init_declarator
            declarator
              pointer: *
              declare: x

    Accessing attributes and methods of Python objects:

        >>> from types import SimpleNamespace

        >>> add_struct_fields = minic.eval('''
        ... int add_struct_fields(struct t *obj) {
        ...     return obj->x + obj->y;
        ... }''')
        >>> add_struct_fields(SimpleNamespace(x=1, y=2))
        3

        >>> add_dict_keys = minic.eval('''
        ... int add_dict_keys(struct t *obj) {
        ...     return obj->get("x") + obj->get("y");
        ... }''')
        >>> add_dict_keys({'x': 1, 'y': 2})
        3

    Allocating and interacting with memory & pointers:

        Creating a pointer in Python and passing it to C code:
        >>> ptr = minic.malloc()
        >>> ptr.contents.x = 3
        >>> ptr_test = minic.eval('void ptr_test(void *ptr) { ptr->x += 1; }')
        >>> ptr_test(ptr)
        >>> ptr.contents.x
        4

        Creating a pointer in C code and returning it to Python:
        >>> mkptr = minic.eval('''
        ... void *mkptr() {
        ...     void *ptr = malloc(1);
        ...     ptr->x = 3;
        ...     return ptr;
        ... }''')
        >>> ptr = mkptr()
        >>> ptr.contents.x
        3

    """

    grammar_filename = GRAMMAR_FILENAME
    main_rule_name = 'repl_command'
    squash_children = True

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.globals: dict[str, Value] = {
            'malloc': PythonFunction(self.malloc),
            'calloc': PythonFunction(self.calloc),
            'realloc': PythonFunction(self.realloc),
            'free': PythonFunction(self.free),
        }

        # NOTE: this is essentially the "call stack" used during evaluation
        self.scopes: list[dict[str, Value]] = [self.globals]

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
        if token.toktype != 'IDENTIFIER':
            return False
        name = token.value
        if self.typedef_blocks and any(
            name in block for block in reversed(self.typedef_blocks)
        ):
            return True
        elif isinstance(self.get_var(name), TypeDef):
            return True
        else:
            return False

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

    def malloc(self, size: int = 1) -> Pointer:
        # NOTE: size is currently unused... we don't care, our memory gives
        # you fresh Struct objects if you refer to fields or pointer indexes
        # which hadn't been initialized, it grows without bounds
        return Pointer(MemoryBlock())

    def calloc(self, nmemb: int = 1, size: int = 1) -> Pointer:
        return self.malloc(nmemb * size)

    def realloc(self, ptr: Optional[Pointer], size: int = 1) -> Pointer:
        return self.malloc(size) if ptr is None else ptr

    def free(self, ptr: Optional[Pointer]):
        if ptr is not None:
            ptr.free()


    ###########################################################################
    # GRAMMAR HANDLER METHODS

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
        intialized_values = {}

        # The declaration specifiers, e.g. 'int'
        declspec = match.find('declaration_specifiers')

        # Looking for specifiers like 'typedef', 'extern', 'const', etc
        specifiers: set[str] = {child.token.value
            for child in
                declspec.findall('storage_class_specifier')
                + declspec.findall('type_qualifier')}
        is_typedef = 'typedef' in specifiers

        for child in match.findall('init_declarator_list? init_declarator'):
            declarator = child.children[0]
            name = (declarator.find('.* declare:.') or declarator).token.value

            # Handle typedefs
            if is_typedef:
                value = TypeDef(
                    name=name,
                    declspec=declspec,
                    declarator=declarator,
                )
                self.set_var(name, value)
                intialized_values[name] = value

            # Handle variable initializations
            value_match = child.find('assign:initializer .')
            if value_match:
                value = self.on(value_match)
                self.set_var(name, value)
                intialized_values[name] = value

        return intialized_values

    def on_declspec__declaration_specifiers(self, match: ParseMatch):
        # E.g. for struct definitions, like `struct t { int x; };`
        pass

    def dereference(self, value: Value) -> Value:
        # If value is a pointer, dereference it!..
        # Otherwise, we return value as-is, which is especially handy if we
        # want to pass arbitrary Python objects to C code.
        if isinstance(value, Pointer):
            value = value[0]
        return value

    def _postfix_operator(self, value: Value, match: ParseMatch) -> Value:
        assert match.rule_name == 'postfix_operator'
        if match.pattern_name == 'index':
            index = self.on(match.children[1])
            return value[index]
        elif match.pattern_name == 'call':
            param_values = [self.on(child) for child in match.children]
            return value(*param_values)
        elif match.pattern_name == 'dot':
            attr = match.children[0].token.value
            return getattr(value, attr)
        elif match.pattern_name == 'arrow':
            value = self.dereference(value)
            attr = match.children[0].token.value
            return getattr(value, attr)
        else:
            # TODO: implement postfix increment/decrement!..
            # Although those will presumably require that value be a Pointer,
            # or a Reference if we add such a class.
            # That is, if value is e.g. the Python object 3, then we're not
            # going to be able to increment/decrement it in a way which is
            # visible outside this function...
            raise ParseError(match.token, f"Dunno postfix operator: {match.prettystring()}")

    def on_postfix_expression(self, match: ParseMatch) -> Value:
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            value = self._postfix_operator(value, child)
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
            # This should never happen
            raise ParseErrpr(token, f"Dunno literal: {match.prettystring()}")

    def on_block__compound_statement(self, match: ParseMatch):
        for child in match.children:
            self.on(child)

    def on_statement_list(self, match: ParseMatch):
        for child in match.children:
            self.on(child)

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
                # TODO: implement all the operators!..
                raise ParseError(token, f"Dunno binary op {op!r}")
        return value

    def on_assign__assignment_expression(self, match: ParseMatch) -> Value:
        lhs_match = match.children[0]
        op = match.children[1].token.value
        rhs = self.on(match.children[2])

        # HACK: we assume lhs_match has structure like `ptr->x`
        # TODO: figure out how to recursively calculate a reference, i.e.
        # an lvalue.
        # See also: self._postfix_operator, and its increment/decrement
        name = lhs_match.children[0].token.value
        attr = lhs_match.children[1].children[0].token.value
        lhs = self.get_var(name)
        lhs = self.dereference(lhs) # because we're assuming '->'
        if op == '=':
            value = rhs
        elif op == '+=':
            value = getattr(lhs, attr) + rhs
        else:
            # TODO: implement all the operators!..
            raise ParseError(token, f"Dunno binary op {op!r}")
        setattr(lhs, attr, value)


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
