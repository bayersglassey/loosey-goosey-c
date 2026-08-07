import inspect
from typing import Any, Optional, NamedTuple, Iterator
from functools import cached_property
from contextlib import contextmanager
from argparse import ArgumentParser

from loosey import get_data_filepath
from loosey.grammar import ParseMatch
from loosey.pplex import Token, ParseError
from loosey.pp import GrammarEvaluatorWithPreprocessor


GRAMMAR_FILENAME = get_data_filepath('ansi-c-grammar.txt')

POSITIONAL_PARAM_KINDS = (
    inspect.Parameter.POSITIONAL_ONLY,
    inspect.Parameter.POSITIONAL_OR_KEYWORD,
)

NO_DEFAULT = object()

Value = Any


def value_as_bool(value: Value) -> bool:
    if value is None:
        return False
    elif isinstance(value, (int, float)):
        return bool(value)
    else:
        # E.g. Python strings should be interpreted as `const char *`,
        # so always truthy, even the empty string!..
        return True


class TypeDef(NamedTuple):
    name: str

    # E.g. 'typedef int'
    declspec: ParseMatch

    # E.g. 'x', '*x', etc
    declarator: ParseMatch

    def __repr__(self) -> str:
        return f'{self.__class__.__name__}({self.name!r})'


class Function:
    def __init__(
            self,
            *,
            name: str,
            params: list[str],
            variadic: bool,
            body: ParseMatch,
            mini: 'MiniC',
            ):
        self.name = name
        self.params = params
        self.variadic = variadic
        self.body = body
        self.mini = mini

    def __repr__(self) -> str:
        params_msg = ', '.join(self.params)
        if self.variadic:
            params_msg += ', ...'
        return f"{self.name}({params_msg})"

    def __call__(self, *args) -> Value:
        return self.mini.call_func(self, *args)

    @cached_property
    def labels(self) -> dict[str, ParseMatch]:
        labels = {}
        for child in self.body.findall('.* labeled_statement'):
            name = child.children[0].token.value
            labels[name] = child.children[1]
        return labels


class PythonFunction:
    """Looks and behaves like a Function, but just wraps a Python function,
    not C code"""

    def __init__(self, func, name=None):
        self.func = func
        self.name = func.__name__ if name is None else name

        sig_params = inspect.signature(func).parameters
        self.params = [name
            for name, param in sig_params.items()
            if param.kind in POSITIONAL_PARAM_KINDS]
        self.variadic = any(param.kind == inspect.Parameter.VAR_POSITIONAL
            for param in sig_params.values())

    def __call__(self, *args):
        return self.func(*args)

    def __repr__(self) -> str:
        params_msg = ', '.join(self.params)
        if self.variadic:
            params_msg += ', ...'
        return f"{self.name}({params_msg})"


class Return(Exception):
    def __init__(self, value: Value):
        self.value = value
class Continue(Exception): pass
class Break(Exception): pass
class Goto(Exception):
    def __init__(self, label_name: str):
        self.label_name = label_name


class SegmentationFault(IndexError): pass


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
        # Each field is a Pointer, currently always of unbounded size, to
        # support array fields
        self.__dict__['fields'] = {}

    def __repr__(self) -> str:
        return f"{self.__class__.__name__}({', '.join(self.fields)})"

    def __setattr__(self, attr: str, value: Value):
        ptr = self._struct_get_field_pointer(attr)
        ptr.contents = value

    def _struct_get_field_pointer(self, attr: str) -> 'Pointer':
        if attr in self.fields:
            return self.fields[attr]
        else:
            ptr = self.fields[attr] = Pointer(MemoryBlock(Struct()))
            return ptr

    def __getattr__(self, attr: str) -> Value:
        if attr == '_ipython_canary_method_should_not_exist_':
            # ipython checks for this, which is annoying...
            # We don't want to create a field for it, since that shows
            # up in our __repr__.
            # We raise Exception, not AttributeError, to convince iPython
            # to stop poking at us looking for more weird methods.
            raise Exception("No thanks, iPython")
        ptr = self._struct_get_field_pointer(attr)
        return ptr.contents


class MemoryBlock:
    """Behaves like a block of memory in C, i.e. an array of objects.
    By default, grows without bounds in negative and positive indexes,
    but can be given a fixed size if desired.
    Should generally be accessed through a Pointer."""

    def __init__(self, value: Value = NO_DEFAULT, *, size: Optional[int] = None):
        if value is NO_DEFAULT:
            value = Struct()
        self.entries: dict[int, Value] = {0: value}
        self._sorted = False

        self.size = size
        if size is not None:
            self.min_index = 0
            self.max_index = size - 1
        else:
            self.min_index = self.max_index = 0

        self.freed = False

    def _update_indexes(self, new_index: int):
        self._sorted = False
        if new_index < self.min_index:
            self.min_index = new_index
        if new_index > self.max_index:
            self.max_index = new_index

    def _sort_entries(self):
        if self._sorted:
            return
        self.entries = dict(sorted(self.entries.items()))
        self._sorted = True

    def __repr__(self) -> str:
        msg = f'{self.min_index}..{self.max_index}'
        if self.size is not None:
            msg += ', fixed=True'
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
        if self.size is not None:
            if index < 0:
                raise SegmentationFault(f"Index {index} < 0")
            elif index >= self.size:
                raise SegmentationFault(f"Index {index} >= {self.size}")
        should_update = index not in self.entries
        self.entries[index] = value
        if should_update:
            # We may have new min/max indexes, so update them
            self._update_indexes(index)

    def __getitem__(self, index: int) -> Value:
        if self.size is not None:
            if index < 0:
                raise SegmentationFault(f"Index {index} < 0")
            elif index >= self.size:
                raise SegmentationFault(f"Index {index} >= {self.size}")
        if index not in self.entries:
            # You can access any offset of the pointer, and by default, you
            # will find a fresh Struct there.
            # So you can allocate fresh memory for an object, and assign to
            # its fields right away.
            self.entries[index] = Struct()
            self._update_indexes(index)
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

        Memory blocks can also be given a fixed size when created.
        >>> ptr = Pointer(MemoryBlock(size=3))
        >>> ptr
        Pointer(0..2, fixed=True)
        >>> ptr[0] = 'start'
        >>> ptr[2] = 'end'
        >>> ptr[-1] = 'uh oh'
        Traceback (most recent call last):
         ...
        loosey.mini.SegmentationFault: Index -1 < 0
        >>> ptr[3] = 'not again'
        Traceback (most recent call last):
         ...
        loosey.mini.SegmentationFault: Index 3 >= 3

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
    def size(self) -> int:
        return self.mem.max_index + 1

    @property
    def freed(self) -> bool:
        return self.mem.freed

    def __repr__(self) -> str:
        msg = f'{self.min_index}..{self.max_index}'
        if self.mem.size is not None:
            msg += ', fixed=True'
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


# Maps rule names to operators
# NOTE: only lists rules which correspond to a single operator.
# As an example of a rule which is not listed here, additive_expression
# corresponds to operators '+' and '-', so we have to extract those
# from the ParseMatch.
BINARY_EXPRESSION_OPS = {
    'and_expression': '&',
    'exclusive_or_expression': '|',
    'inclusive_or_expression': '^',
    'logical_and_expression': '&&',
    'logical_or_expression': '||',
}


class MiniC(GrammarEvaluatorWithPreprocessor):
    r"""Miniature C interpreter, which can use many Python objects and
    functions directly, and whose objects and functions can be used
    directly from Python.

    Comes with its own C preprocessor, can parse all of ANSI C, and can
    run... some C code. It's a work in progress.

        >>> mini = MiniC()

        >>> mini.eval('1 + 2')
        3

        Watch out for parentheses when you're using macros, of course!..
        >>> mini.eval('#define DOUBLE(X) X + X')
        >>> mini.eval('10 * DOUBLE(2)')
        22

        >>> mini.eval('int add(int x, int y) { return x + y; }')
        add(x, y)

        >>> mini.eval('int x = 1, y = 2;')
        {'x': 1, 'y': 2}

        >>> mini.eval('int total = add(x, y);')
        {'total': 3}

        >>> mini.eval('int total = add(2, 3);')
        {'total': 5}

        We can use Python values directly!
        >>> mini.set_var('x', 99)
        >>> mini.set_var('ten', lambda x: x * 10)
        >>> mini.eval('int total = ten(x);')
        {'total': 990}

        The C preprocessor is available too!
        >>> mini.eval('#define DOUBLE(X) X + X')
        >>> mini.eval('int x = DOUBLE(3);')
        {'x': 6}

        Parsing of typedefs is handled correctly!
        See: https://en.wikipedia.org/wiki/Lexer_hack
        In the examples below, when Integer is not a typedef, `Integer *x`
        is interpreted as a multiplication; when it's a typedef, `Integer *x`
        is interpreted as a variable declaration:
        >>> f = mini.eval('void f() { Integer *x; }')
        >>> for child in f.body.children: child.pprint()
        multiplicative_expression
          ident: Integer
          *
          ident: x
        >>> f = mini.eval('void f() { typedef int Integer; Integer *x; }')
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
        >>> mini.parse('T *x;').pprint()
        multiplicative_expression
          ident: T
          *
          ident: x
        >>> mini.eval('typedef struct t T;')
        {'T': TypeDef('T')}
        >>> mini.parse('T *x;').pprint()
        declaration
          declspec: declaration_specifiers
            T
          decl: init_declarator
            declarator
              pointer: *
              declare: x

    Accessing attributes and methods of Python objects:

        >>> from types import SimpleNamespace

        >>> add_struct_fields = mini.eval('''
        ... int add_struct_fields(struct t *obj) {
        ...     return obj->x + obj->y;
        ... }''')
        >>> add_struct_fields(SimpleNamespace(x=1, y=2))
        3

        >>> add_dict_keys = mini.eval('''
        ... int add_dict_keys(struct t *obj) {
        ...     return obj->get("x") + obj->get("y");
        ... }''')
        >>> add_dict_keys({'x': 1, 'y': 2})
        3

    Allocating and interacting with memory & pointers:

        Creating a pointer in Python and passing it to C code:
        >>> ptr = mini.malloc()
        >>> ptr.contents.x = 3
        >>> ptr_test = mini.eval('void ptr_test(void *ptr) { ptr->x += 1; }')
        >>> ptr_test(ptr)
        >>> ptr.contents.x
        4

        Creating a pointer in C code and returning it to Python:
        >>> mkptr = mini.eval('''
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
    main_rule_name = 'repl_commands'
    squash_children = True
    pass_through_exceptions = (
        Return,
        Continue,
        Break,
        Goto,
    )
    handler_prefixes = ('reference',)

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        # NOTE: this is the "call stack" for variables during evaluation
        self.global_scope: dict[str, Pointer] = {}
        self.scopes: list[dict[str, Pointer]] = [self.global_scope]

        # Add some default stdlib functions
        def _add_func(func):
            func_obj = PythonFunction(func)
            self.global_scope[func_obj.name] = Pointer(MemoryBlock(func_obj, size=1))
        _add_func(self.malloc)
        _add_func(self.calloc)
        _add_func(self.realloc)
        _add_func(self.free)
        _add_func(self.printf)
        _add_func(self.fprintf)

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
        elif isinstance(self.get_var(name, None), TypeDef):
            return True
        else:
            return False

    @contextmanager
    def new_scope(self) -> dict[str, Pointer]:
        scope = {}
        self.scopes.append(scope)
        try:
            yield scope
        finally:
            assert self.scopes.pop() is scope

    def get_var(self, name: str, default=NO_DEFAULT) -> Value:
        """Get the value of the indicated variable (including functions,
        typedefs, etc)"""
        for scope in reversed(self.scopes):
            if name in scope:
                return scope[name].contents
        if default is NO_DEFAULT:
            raise self.var_lookup_error(name)
        else:
            return default

    def get_var_ref(self, name: str) -> Pointer:
        """Get a reference to the indicated variable"""
        for scope in reversed(self.scopes):
            if name in scope:
                return scope[name]
        raise self.var_lookup_error(name)

    def var_lookup_error(self, name: str) -> Exception:
        names_msg = ' '.join(f"{{{' '.join(scope)}}}" for scope in self.scopes)
        raise Exception(f"Object not found: {name!r} (names currently in scope: {names_msg})")

    def set_var(self, name: str, value: Value):
        scope = self.scopes[-1]
        if name in scope:
            scope[name].contents = value
        else:
            scope[name] = Pointer(MemoryBlock(value, size=1))

    def malloc(self, size: int = 1) -> Pointer:
        return Pointer(MemoryBlock(size=size))

    def calloc(self, nmemb: int = 1, size: int = 1) -> Pointer:
        return self.malloc(nmemb * size)

    def realloc(self, ptr: Optional[Pointer], size: int = 1) -> Pointer:
        if ptr is None:
            return self.malloc(size)
        elif ptr.size >= size:
            return ptr
        else:
            new_ptr = Pointer(MemoryBlock(size=size))
            self.memcpy(new_ptr, ptr, ptr.size)
            return new_ptr

    def free(self, ptr: Optional[Pointer]):
        if ptr is not None:
            ptr.free()

    def printf(self, fmt: str, *args):
        # TODO: parse the fmt, etc...
        print(f"=== PRINTF: {fmt!r} {args!r}")

    def fprintf(self, file, fmt: str, *args):
        self.printf(fmt, *args)


    ###########################################################################
    # GRAMMAR HANDLER METHODS

    def on_function_definition(self, match: ParseMatch) -> Value:
        declarator = match.find('declarator')
        name = declarator.find('declare:.').token.value
        params = [child.token.value for child in
            # NOTE: might be a parameter_type_list, i.e. (int x, int y), or
            # might be a list of declarator_identifier, i.e. just (x, y)
            declarator.children[1].findall('.* declare:.')]
        body = match.find('block:compound_statement')
        variadic = declarator.children[1].find('.* ellipsis') is not None
        function = Function(
            name=name,
            params=params,
            variadic=variadic,
            body=body,
            mini=self,
        )
        self.set_var(name, function)
        return function

    def on_cast__cast_expression(self, match: ParseMatch) -> Value:
        # TODO: handle conversions between char* and other things...
        # I think the way to do it will be to have sizeof X always be 1,
        # and then have a MagicCharPointer class...
        # The idea being that the representation of any value by char* will
        # be an instance of MagicCharPointer, which behaves like a pointer
        # to a single-char array {0xFF}, but also has a reference to an
        # arbitrary object, which is extracted when we cast to anything
        # other than char *.
        return self.on(match.children[1])

    def on_declaration_list(self, match: ParseMatch) -> dict[str, Value]:
        intialized_values = {}
        for child in match.children:
            intialized_values.update(self.on(child))
        return intialized_values

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

            if is_typedef:
                # Handle typedefs
                value = TypeDef(
                    name=name,
                    declspec=declspec,
                    declarator=declarator,
                )
                self.set_var(name, value)
                intialized_values[name] = value
            else:
                # Handle variable initializations
                value_match = child.find('assign:initializer .')
                if value_match:
                    value = self.on(value_match)
                else:
                    # Uninitialized variables are assigned a magic Struct object
                    # which allows you to access arbitrary "fields"...
                    value = Struct()
                self.set_var(name, value)
                intialized_values[name] = value

        return intialized_values

    def on_declspec__declaration_specifiers(self, match: ParseMatch):
        # E.g. for struct definitions, like `struct t { int x; };`
        pass

    def get_reference(self, match: ParseMatch) -> Pointer:
        with self.use_handler_prefix('reference'):
            return self.on(match)

    def dereference(self, value: Value) -> Value:
        # If value is a pointer, dereference it!..
        # Otherwise, we return value as-is, which is especially handy if we
        # want to pass arbitrary Python objects to C code.
        if isinstance(value, Pointer):
            return value.contents
        else:
            return value

    def on_unary_expression(self, match: ParseMatch) -> Value:
        op = match.children[0].token.value
        if op == '&':
            return self.get_reference(match.children[1])
        value = self.on(match.children[1])
        if op == '+':
            return value
        elif op == '-':
            return -value
        elif op == '~':
            return ~value
        elif op == '!':
            return not value
        elif op == '*':
            return self.dereference(value)
        else:
            # Should never happen!
            raise ParseError(match.token, f"Dunno prefix operator: {op!r}")

    def on_reference__unary_expression(self, match: ParseMatch) -> Pointer:
        op = match.children[0].token.value
        if op == '*':
            with self.use_handler_prefix(None):
                return self.on(match.children[1])
        else:
            raise ParseError(match.token, f"Can't produce an lvalue: {op!r}")

    def _postfix_operator(self, value: Value, match: ParseMatch) -> Value:
        assert match.rule_name == 'postfix_operator'
        if match.pattern_name == 'index':
            index = self.on(match.children[1])
            return value[index]
        elif match.pattern_name == 'call':
            param_values = [self.on(child) for child in match.children]
            value = self.dereference(value) # handle function pointers
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
            # Aren't those kind of crazy, though?!.. they require, like...
            # postponing the increment/decrement until the end of the
            # statement, or something?..
            raise ParseError(match.token, f"Dunno postfix operator: {match.prettystring()}")

    def _postfix_reference_operator(self, value: Value, match: ParseMatch) -> Pointer:
        assert match.rule_name == 'postfix_operator'
        if match.pattern_name == 'index':
            # e.g. &(x[3]), i.e. &(*(x + 3)), i.e. x + 3
            index = self.on(match.children[1])
            return value + index
        elif match.pattern_name in ('dot', 'arrow'):
            attr = match.children[0].token.value
            if match.pattern_name == 'arrow':
                # e.g. &(x->y), i.e. &((*x).y))
                value = self.dereference(value)
            if not isinstance(value, Struct):
                field_msg = ('->' if match.pattern_name == 'arrow' else '.') + attr
                raise Exception(f"Can only get address-of-field ({field_msg}) from Struct, not from {type(value)}")
            return value._struct_get_field_pointer(attr)
        else:
            raise ParseError(match.token, f"Can't produce an lvalue: {match.prettystring()}")

    def on_postfix_expression(self, match: ParseMatch) -> Value:
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            value = self._postfix_operator(value, child)
        return value

    def on_reference__postfix_expression(self, match: ParseMatch) -> Pointer:
        # When trying to get a reference from a series of postfix operations,
        # e.g. x.y->z[3], it's only the last operation, i.e. `[3]` in this
        # example, which needs to produce a reference.
        # The rest are producing rvalues as usual.
        # So, we deactivate the 'reference' handler prefix for the remainder
        # of this function, so we can calculate lvalues normally:
        with self.use_handler_prefix(None):
            # Find the rvalue from which to extract a reference...
            value = self.on(match.children[0])
            for child in match.children[1:-1]:
                value = self._postfix_operator(value, child)

            # ...and extract a reference from it!
            return self._postfix_reference_operator(value, match.children[-1])

    def call_func(self, func: Function, *param_values) -> Value:
        with self.new_scope() as scope:
            n_missing_params = len(func.params) - len(param_values)
            if n_missing_params:
                # Missing parameters default to magic Struct objects, for
                # maximum permissiveness
                original_param_values = param_values
                param_values = list(original_param_values) + [
                    Struct() for i in range(n_missing_params)]
            elif len(param_values) > len(func.params):
                self.warn(f"Calling {func} with {len(param_values)} parameters, extras will be ignored")
            for param_name, param_value in zip(func.params, param_values):
                scope[param_name] = Pointer(MemoryBlock(param_value, size=1))
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

    def _eval_children(self, match: ParseMatch):
        value = None
        for child in match.children:
            value = self.on(child)
        return value

    on_block__compound_statement = _eval_children
    on_statement_list = _eval_children
    on_translation_unit = _eval_children
    on_label__labeled_statement = _eval_children
    on_expression = _eval_children
    on_expression_statement = _eval_children
    on_trailing__repl_expression = _eval_children

    def on_return__jump_statement(self, match: ParseMatch) -> Value:
        if match.children:
            value = self.on(match.children[0])
        else:
            value = None
        raise Return(value)

    def on_ident__primary_expression(self, match: ParseMatch) -> Value:
        return self.get_var(match.token.value)

    def on_reference__ident__primary_expression(self, match: ParseMatch) -> Pointer:
        return self.get_var_ref(match.token.value)

    def on_goto__jump_statement(self, match: ParseMatch):
        raise Goto(label_name=match.children[0].token.value)

    def on_continue__jump_statement(self, match: ParseMatch):
        raise Continue()

    def on_break__jump_statement(self, match: ParseMatch):
        raise Break()

    def _on_binary_expression(self, match: ParseMatch) -> Value:
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            if match.rule_name in BINARY_EXPRESSION_OPS:
                op = BINARY_EXPRESSION_OPS[match.rule_name]
            else:
                op = child.token.value
                child = next(children)
            if op not in ('&&', '||'):
                # Short-circuiting logic!.. only evalute the argument if
                # we need to, see below...
                arg = self.on(child)
            if op == '+':
                value += arg
            elif op == '-':
                value -= arg
            elif op == '*':
                value *= arg
            elif op == '/':
                value /= arg
            elif op == '%':
                value %= arg
            elif op == '<<':
                value <<= arg
            elif op == '>>':
                value >>= arg
            elif op == '<':
                value = value < arg
            elif op == '>':
                value = value > arg
            elif op == '<=':
                value = value <= arg
            elif op == '>=':
                value = value >= arg
            elif op == '==':
                value = value == arg
            elif op == '!=':
                value = value != arg
            elif op == '&':
                value &= arg
            elif op == '^':
                value ^= arg
            elif op == '|':
                value |= arg
            elif op == '&&':
                # Short-circuiting logic!
                if not value:
                    return False
                return self.on(next(children))
            elif op == '||':
                # Short-circuiting logic!
                if value:
                    return True
                return self.on(next(children))
            else:
                # We should never get here...
                raise ParseError(token, f"Dunno binary op {op!r}")
        return value

    on_additive_expression = _on_binary_expression
    on_multiplicative_expression = _on_binary_expression
    on_shift_expression = _on_binary_expression
    on_relational_expression = _on_binary_expression
    on_equality_expression = _on_binary_expression
    on_and_expression = _on_binary_expression
    on_exclusive_or_expression = _on_binary_expression
    on_inclusive_or_expression = _on_binary_expression
    on_logical_and_expression = _on_binary_expression
    on_logical_or_expression = _on_binary_expression

    def on_sizeof_expr__unary_expression(self, match: ParseMatch) -> Value:
        # Currently, sizeof always returns 1, which allows us to freely
        # grow our objects (see the Struct class) without messing up the
        # pointer math?..
        # It's weird, and it'll have very strange results for code which
        # assumes (correctly, according to the standard) that e.g. int is
        # always greater than one byte...
        # It might be better if we decided to have sizeof always return 4,
        # so we could at least handle C libraries which know about 32-bit
        # math.
        # But then we run into the question of whether to support 64-bit
        # "long long" values, and then pretty soon we probably just need
        # a more complicated system than what we have at the moment!..
        return 1

    on_sizeof_type__unary_expression = on_sizeof_expr__unary_expression

    def on_assign__assignment_expression(self, match: ParseMatch) -> Value:
        lhs = self.get_reference(match.children[0])
        op = match.children[1].token.value
        rhs = self.on(match.children[2])
        if op == '=':
            value = rhs
        elif op == '*=':
            value = lhs.contents * rhs
        elif op == '/=':
            value = lhs.contents / rhs
        elif op == '%=':
            value = lhs.contents % rhs
        elif op == '+=':
            value = lhs.contents + rhs
        elif op == '-=':
            value = lhs.contents - rhs
        elif op == '<<=':
            value = lhs.contents << rhs
        elif op == '>>=':
            value = lhs.contents >> rhs
        elif op == '&=':
            value = lhs.contents & rhs
        elif op == '^=':
            value = lhs.contents ^ rhs
        elif op == '|=':
            value = lhs.contents | rhs
        else:
            # Should never happen...
            raise ParseError(match.token, f"Dunno binary op {op!r}")
        lhs.contents = value
        return value

    def on_if__selection_statement(self, match: ParseMatch):
        cond_value = self.on(match.children[0])
        if value_as_bool(cond_value):
            self.on(match.children[1])
        elif len(match.children) >= 3:
            else_branch = match.children[2]
            assert else_branch.rule_name == 'else_statement'
            self.on(else_branch.children[0])

    def on_repl_commands(self, match: ParseMatch) -> Value:
        last_child = match.children[-1]
        value = None
        for child in match.children:
            value = self.on(child)
        if last_child.rule_name in ('function_definition', 'repl_expression'):
            return value
        else:
            return None


def main():
    parser = ArgumentParser()
    parser.add_argument('-f', '--filename', default='-')
    parser.add_argument('-v', '--verbose', default=False, action='store_true')
    parser.add_argument('--partial', default=False, action='store_true')
    args = parser.parse_args()

    mini = MiniC()
    match = mini.parse_file(
        args.filename,
        verbose=args.verbose,
        partial=args.partial,
    )
    if match:
        match.pprint()


if __name__ == '__main__':
    main()
