import inspect
from typing import (
    Any,
    Optional,
    NamedTuple,
    Iterator,
    Iterable,
    Sequence,
    Callable,
)
from functools import cached_property

from loosey.grammar import ParseMatch


POSITIONAL_PARAM_KINDS = (
    inspect.Parameter.POSITIONAL_ONLY,
    inspect.Parameter.POSITIONAL_OR_KEYWORD,
)

NO_DEFAULT = object()

Value = Any

_SEQUENCE_TYPES = (str, bytes, list, tuple, bytearray)


def value_as_bool(value: Value) -> bool:
    """Interpret a C value as a boolean"""
    if value is None:
        return False
    elif isinstance(value, (int, float)):
        return bool(value)
    elif isinstance(value, Struct):
        # Struct behaves like 0 under arithmetic operations...
        return False
    else:
        # E.g. Python strings should be interpreted as `const char *`,
        # so always truthy, even the empty string!..
        return True


def value_as_int(value: Value) -> int:
    """Interpret a C value as an integer"""
    if isinstance(value, (str, bytes)):
        return ord(value)
    else:
        # NOTE: this will also turn Struct instances into 0
        return int(value)


def value_as_string(value: Value) -> str:
    """Interpret a C value as a string

        >>> value_as_string('hello')
        'hello'

        >>> value_as_string(b'hello')
        'hello'

        >>> ptr = Pointer(MemoryBlock())
        >>> ptr[0] = 'H'
        >>> ptr[1] = 'i'
        >>> ptr[2] = '!'
        >>> value_as_string(ptr)
        'Hi!'

    """
    # PROBABLY TODO: use bytes instead of str everywhere...
    if isinstance(value, str):
        return value
    elif isinstance(value, bytes):
        return value.decode()
    elif isinstance(value, Pointer):

        # We could do something fancy like this as an optimization, but we
        # need to be careful of the meaning of negative string indexes in
        # Python, etc...
        #if isinstance(value.mem, SequenceBackedMemoryBlock):
        #    return value.mem.data[value.index:]

        buf = bytearray()
        for index, elem in value.items():
            i = value_as_int(elem)
            if i == 0:
                # NUL byte
                break
            buf.append(i)
            index += 1
        return buf.decode() # I sure hope this is valid UTF-8!..
    else:
        return Exception(f"Expected string, got: {value!r}")


def value_as_pointer(value: Value) -> 'Pointer':
    """Interpret a C value as a pointer, e.g. so that we can try to do
    C array operations with it

        >>> value_as_pointer([10, 20, 30])
        Pointer(0..3, fixed=True)

        >>> value_as_pointer([10, 20, 30])[1]
        20

    """
    if isinstance(value, Pointer):
        return value
    elif isinstance(value, _SEQUENCE_TYPES):
        return Pointer(SequenceBackedMemoryBlock(value))
    else:
        raise Exception(f"Can't interpret as a pointer: {value!r}")


def copy_value(value: Value, *, initializer: bool = False) -> Value:
    """Copy a C value"""
    if isinstance(value, Struct):
        # Copy the underlying memory for each field
        return value.copy()
    elif isinstance(value, _SEQUENCE_TYPES):
        # TODO: this works well, but is it general enough?..
        # Do we want to do a check for isinstance(value, Sequence) etc?..
        # Is copy_value the correct place to wrap sequences in
        # SequenceBackedMemoryBlock?.. etc
        if initializer:
            # If we're an initializer, e.g. `char stuff[] = "Hello"`, then
            # we want to truly copy the data, not use it directly!
            # Because e.g. str is immutable.
            return Pointer(MemoryBlock.from_sequence(value))
        else:
            return Pointer(SequenceBackedMemoryBlock(value))
    else:
        # Everything else, including Pointers, is immutable!..
        # Also, we treat arbitrary Python objects as if they were pointers,
        # so they're "immutable" too from the perspective of our C code.
        return value


def coerce_pointers_for_comparison(lhs: Value, rhs: Value) -> tuple[Value, Value]:
    if isinstance(lhs, Pointer) and isinstance(rhs, Pointer):
        if lhs.mem is not rhs.mem:
            raise Exception("Can't compare pointers with different underlying memory blocks: {lhs!r} {op} {rhs!r}")
        return lhs.index, rhs.index
    else:
        return lhs, rhs


class Declarator(NamedTuple):
    """E.g. `x` or `*x[]` or `**(*x[3])[][4]`, etc."""
    match: ParseMatch
    name: str
    kind: Optional[str] # None or 'pointer' or 'array' or 'func' or 'bitfield'


class InitDeclarator(NamedTuple):
    """An init_declarator or a field_declarator"""
    declarator: Declarator
    initializer: Optional[ParseMatch] = None

    @property
    def name(self) -> str:
        return self.declarator.name

    @property
    def kind(self) -> str:
        return self.declarator.kind


class Declaration(NamedTuple):
    """E.g. `const int x, *y` or `typedef struct T T` or `int x = 1, y = 2`"""
    match: ParseMatch
    declspec: ParseMatch
    specifiers: set[str] # 'typedef', 'extern', 'const', etc

    # These might be init declarators, or field declarators...
    init_declarators: list[InitDeclarator]

    @property
    def is_typedef(self) -> bool:
        return 'typedef' in self.specifiers


class StructOrUnion(NamedTuple):
    kind: str # 'struct' or 'union'
    tag: Optional[str]
    field_declarations: list[Declaration]

    def pprint(self):
        msg = self.kind
        if self.tag is not None:
            msg = f'{msg} {self.tag}'
        print(f"{msg}:")
        for declaration in self.field_declarations:
            parts = []
            for init_declarator in declaration.init_declarators:
                part = init_declarator.name
                if init_declarator.kind:
                    part = f'{part}({init_declarator.kind})'
                parts.append(part)
            msg = ', '.join(parts)
            if declaration.specifiers:
                msg = f"{' '.join(declaration.specifiers)} {msg}"
            print(f"  {msg}")


class TypeDef(NamedTuple):
    name: str
    declaration: Declaration
    init_declarator: InitDeclarator

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
            call: Callable,
            ):
        self.name = name
        self.params = params
        self.variadic = variadic
        self.body = body
        self.call = call

    def __repr__(self) -> str:
        parts = list(self.params)
        if self.variadic:
            parts.append('...')
        msg = ', '.join(parts)
        return f"{self.name}({msg})"

    def __call__(self, *args) -> Value:
        return self.call(self, *args)

    @cached_property
    def label_statements(self) -> list[ParseMatch]:
        assert self.body.rule_name == 'compound_statement'
        # NOTE: we don't currently support "deep" labels, only labels at
        # the top level of the function body.
        statement_list = self.body.find('statement_list')
        if statement_list is not None:
            return statement_list.children
        else:
            return self.body.children

    @cached_property
    def labels(self) -> dict[str, ParseMatch]:
        return {
            child.children[0].token.value: child
            for child in self.label_statements
            if child.rule_name == 'labeled_statement'}


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


class ControlFlow(Exception):
    match: ParseMatch
class Return(ControlFlow):
    def __init__(self, match: ParseMatch, value: Value):
        self.match = match
        self.value = value
class Continue(ControlFlow):
    def __init__(self, match: ParseMatch):
        self.match = match
class Break(ControlFlow):
    def __init__(self, match: ParseMatch):
        self.match = match
class Goto(ControlFlow):
    def __init__(self, match: ParseMatch, label_name: str):
        self.match = match
        self.label_name = label_name

class Exit(Exception):
    """Raised by e.g. CStdlib's exit()"""
    def __init__(self, code: int):
        self.code = code


class SegmentationFault(IndexError): pass


_STRUCT_POINTER_REPR_DEPTH = 4


class Struct:
    """Can be used as a struct or union by MiniC.
    Automatically creates new fields as they are referenced.

        >>> obj = Struct()
        >>> obj
        Struct()
        >>> obj['x'] = 2
        >>> obj['x']
        2
        >>> obj['y']
        Struct()
        >>> obj
        Struct({'x': 2, 'y': Struct()})

        For convenience, you can set struct fields when calling its
        constructor:
        >>> Struct({'msg': 'hello', 'child': Struct()})
        Struct({'msg': 'hello', 'child': Struct()})

    """

    def __init__(self, values: Optional[dict[str, Value]] = None):
        self.fields: dict[str, Pointer] = {} if not values else {
            # NOTE: we use size=1 here, because unlike when referring to
            # a not-yet-extant field of a Struct, here we know we want it
            # to contain a single value, not an array of values.
            attr: Pointer(MemoryBlock(value, size=1))
            for attr, value in values.items()}

    def __iter__(self):
        return iter(self.fields)

    def items(self) -> Iterator[tuple[str, Value]]:
        for attr, ptr in self.fields.items():
            yield (attr, ptr.contents)

    def get_or_create_field(self, attr: str) -> 'Pointer':
        if attr in self.fields:
            return self.fields[attr]
        else:
            # NOTE: we don't use just Pointer(Struct()), because that would
            # create a MemoryBlock with size=1, whereas in order to support
            # array fields, we want an auto-growing MemoryBlock (i.e. one
            # with size=None).
            ptr = self.fields[attr] = Pointer(MemoryBlock(Struct()))
            return ptr

    def mkrepr(self, depth=_STRUCT_POINTER_REPR_DEPTH) -> str:
        if depth <= 0:
            msg = ', '.join(self.fields)
        elif self.fields:
            parts = []
            for attr, ptr in self.fields.items():
                value = ptr.contents
                if isinstance(value, (Struct, Pointer)):
                    msg = value.mkrepr(depth - 1)
                else:
                    msg = repr(value)
                parts.append(f'{attr!r}: {msg}')
            msg = '{' + ', '.join(parts) + '}'
        else:
            msg = ''
        return f"{self.__class__.__name__}({msg})"

    def __repr__(self) -> str:
        return self.mkrepr()

    def __eq__(self, other) -> bool:
        if other is self:
            return True
        elif isinstance(other, (int, float)):
            return other == 0
        elif isinstance(other, Struct):
            # NOTE: we can safely assume ptr.index and other.fields[name]
            # are always 0.
            return all(ptr.mem == other.fields[name].mem
                for name, ptr in self.fields.items()
                if name in other.fields)
        else:
            return False

    def copy(self) -> 'Struct':
        copy = Struct()
        for attr, ptr in self.fields.items():
            # Copy the underlying memory
            copy.fields[attr] = Pointer(ptr.mem.copy())
        return copy

    def __getitem__(self, attr: str) -> Value:
        ptr = self.get_or_create_field(attr)
        return ptr.contents

    def __setitem__(self, attr: str, value: Value):
        ptr = self.get_or_create_field(attr)
        ptr.contents = value


    ###########################################################################
    # Struct arithmetic:
    # Since we use a fresh Struct instance as the default value for
    # uninitialized memory, we need to handle cases where the type of that
    # memory was some kind of integer.
    # So, Struct behaves like the number 0 under arithmetic operations.
    # That is, the following C code should behave correctly:
    #
    #   int *mem = calloc(1, sizeof(int));
    #   mem[0]++; // if mem[0] was a Struct, it will now be the number 1
    #

    def __int__(self) -> Value:
        return 0
    __pos__ = __int__
    __neg__ = __int__
    def __invert__(self) -> Value:
        return ~0

    def __add__(self, other: Value) -> Value:
        return other
    __rlshift__ = __add__
    __rrshift__ = __add__
    __radd__ = __add__
    __rsub__ = __add__
    __rxor__ = __add__
    __xor__ = __add__
    __ror__ = __add__
    __or__ = __add__

    def __sub__(self, other: Value) -> Value:
        return -other

    def __mul__(self, other: Value) -> Value:
        return 0
    __rmul__ = __mul__
    __lshift__ = __mul__
    __rshift__ = __mul__
    __rand__ = __mul__
    __and__ = __mul__

    def __truediv__(self, other: Value) -> Value:
        if other == 0:
            raise ZeroDivisionError
        return 0 / other
    __mod__ = __truediv__

    def __rtruediv__(self, other: Value) -> Value:
        raise ZeroDivisionError
    __rmod__ = __rtruediv__

    def __lt__(self, other: Value) -> bool:
        return 0 < other
    def __le__(self, other: Value) -> bool:
        return 0 <= other
    def __gt__(self, other: Value) -> bool:
        return 0 > other
    def __ge__(self, other: Value) -> bool:
        return 0 >= other


class BaseMemoryBlock:
    """Behaves like a block of memory in C, i.e. an array of objects.
    NOTE: this is the base class, don't instantiate directly!"""

    size: Optional[int]
    min_index: int
    max_index: int

    def __init__(self):
        self.freed = False

    def __repr__(self) -> str:
        msg = f'{self.min_index}..{self.max_index}'
        if self.size is not None:
            msg += ', fixed=True'
        if self.freed:
            msg += ', freed=True'
        return f'{self.__class__.__name__}({msg})'

    def __eq__(self, other) -> bool:
        if other is self:
            return True
        elif not isinstance(other, BaseMemoryBlock):
            return False
        else:
            return all(value == other[index]
                for index, value in self.items()
                if index in other)

    # To be implemented by subclasses
    def __iter__(self) -> Iterator[int]: ...
    def items(self) -> Iterator[tuple[int, Value]]: ...
    def __contains__(self, index: int) -> bool: ...
    def __setitem__(self, index: int, value: Value): ...
    def __getitem__(self, index: int) -> Value: ...
    def copy(self) -> 'BaseMemoryBlock': ...

    def update(self, entries: Iterable[tuple[int, Value]]):
        # NOTE: subclasses may wish to override this method with a more
        # performant implementation
        for index, value in entries:
            self[index] = value

    def free(self):
        if self.freed:
            raise Exception(f"Attempted to free already-freed memory: {self!r}")
        else:
            self.freed = True


class SequenceBackedMemoryBlock(BaseMemoryBlock):
    """Behaves like a block of memory in C, i.e. an array of objects.
    Is backed by any Python object which behaves like a Sequence[Value].

        >>> mem = SequenceBackedMemoryBlock([10, 20, 30])
        >>> mem
        SequenceBackedMemoryBlock(0..3, fixed=True)
        >>> mem[1]
        20

        NOTE: strings automatically get a NUL byte appended to them
        >>> mem = SequenceBackedMemoryBlock('abc')
        >>> mem
        SequenceBackedMemoryBlock(0..4, fixed=True)
        >>> mem[1]
        98
        >>> mem[3] # NUL byte!
        0

    """

    min_index = 0

    def __init__(self, data: Sequence[Value]):
        super().__init__()
        if isinstance(data, str):
            # Make sure the elements of self.data are integers, i.e. C chars
            data = data.encode()
            if not data.endswith(b'\0'):
                data += b'\0'
            self.data = tuple(data)
        elif isinstance(data, bytes):
            # Make sure the elements of self.data are integers, i.e. C chars
            if not data.endswith(b'\0'):
                data += b'\0'
            self.data = tuple(data)
        else:
            self.data = data

    def size(self) -> Optional[int]:
        return len(self.data)

    @property
    def max_index(self) -> int:
        return len(self.data)

    def __iter__(self) -> Iterator[int]:
        return range(len(self.data))

    def items(self) -> Iterator[tuple[int, Value]]:
        return enumerate(self.data)

    def __contains__(self, index: int) -> bool:
        return 0 <= index < len(self.data)

    def __setitem__(self, index: int, value: Value):
        self.data[index] = value

    def __getitem__(self, index: int) -> Value:
        return self.data[index]

    def copy(self) -> 'SequenceBackedMemoryBlock':
        # NOTE: we could do something fancy, like use copy.copy, or
        # copy.deepcopy, but... would that always be correct?!
        # For now, it's only really safe to pass around *pointers* to Python
        # objects.
        raise Exception(
            f"Can't copy memory blocks backed by Python objects! "
            f"This one is backed by: {self.data!r}")


class MemoryBlock(BaseMemoryBlock):
    """Behaves like a block of memory in C, i.e. an array of objects.
    By default, grows without bounds in negative and positive indexes,
    but can be given a fixed size if desired.
    Should generally be accessed through a Pointer."""

    def __init__(self, value: Value = NO_DEFAULT, *, size: Optional[int] = None):
        super().__init__()

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

    @staticmethod
    def from_sequence(data: Sequence[Value]) -> 'MemoryBlock':
        # NOTE: we don't do size=len(data), because e.g. we want to use
        # this for initializers, like `char s[20] = "Hi"`, where the
        # initializer may contain less data than the array.
        self = MemoryBlock()
        self.update(enumerate(data))
        return self

    def copy(self) -> 'MemoryBlock':
        copy = MemoryBlock(size=self.size)
        for index, value in self.entries.items():
            # Copy all values
            copy.entries[index] = copy_value(value)
        return copy

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

    def __iter__(self) -> Iterator[int]:
        self._sort_entries()
        return iter(self.entries)

    def items(self) -> Iterator[tuple[int, Value]]:
        self._sort_entries()
        return self.entries.items()

    def __contains__(self, index: int) -> bool:
        return index in self.entries

    def _check_index(self, index: int):
        # NOTE: assumes self.size is not None
        if index < 0:
            raise SegmentationFault(f"Index {index} < 0")
        elif index >= self.size:
            raise SegmentationFault(f"Index {index} >= {self.size}")

    def update(self, entries: Iterable[tuple[int, Value]]):
        should_check_indexes = self.size is not None
        should_update = False
        for index, value in entries:
            if should_check_indexes:
                self._check_index(index)
            should_update = index not in self.entries
            self.entries[index] = value
        if should_update:
            # We may have new min/max indexes, so update them
            self._update_indexes(index)

    def __setitem__(self, index: int, value: Value):
        if self.size is not None:
            self._check_index(index)
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
        loosey.runtime.SegmentationFault: Index -1 < 0
        >>> ptr[3] = 'not again'
        Traceback (most recent call last):
         ...
        loosey.runtime.SegmentationFault: Index 3 >= 3

        You can initialize a Pointer with a value, instead of a MemoryBlock,
        in which case it creates a MemoryBlock of fixed size 1 to store the
        value.
        >>> ptr = Pointer('hello world')
        >>> ptr
        Pointer('hello world')
        >>> ptr.contents
        'hello world'
        >>> ptr + 1
        Pointer(-1..-1, fixed=True)
        >>> (ptr + 1)[-1]
        'hello world'

    """

    def __init__(self, mem: BaseMemoryBlock | Value, index: int = 0):
        if not isinstance(mem, BaseMemoryBlock):
            # If we're given a value, create a memory block containing just
            # that value.
            # This can be used for struct fields and variables which contain
            # a single value, and the fact that our constructor supports it
            # means that we can have a nice __repr__ which is actually
            # accurate.
            mem = MemoryBlock(mem, size=1)
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

    def mkrepr(self, depth=_STRUCT_POINTER_REPR_DEPTH) -> str:
        use_mkrepr = self.mem.size == 1 and self.index == 0 and depth > 0
        if use_mkrepr:
            value = self.contents
            if isinstance(value, (Struct, Pointer)):
                msg = value.mkrepr(depth - 1)
            else:
                msg = repr(value)
        else:
            msg = f'{self.min_index}..{self.max_index}'
        if self.mem.size is not None and not use_mkrepr:
            msg += ', fixed=True'
        if self.freed:
            msg += ', freed=True'
        return f'{self.__class__.__name__}({msg})'

    def __repr__(self) -> str:
        return self.mkrepr()

    def as_list(self) -> list[Value]:
        # Particularly useful for doctests!..
        return [self[i] for i in range(self.min_index, self.max_index + 1)]

    def as_string(self) -> str:
        # Particularly useful for doctests!..
        return value_as_string(self)

    @property
    def contents(self) -> Value:
        return self[0]

    @contents.setter
    def contents(self, value: Value):
        self[0] = value

    def __eq__(self, other) -> bool:
        if self is other:
            return True
        elif isinstance(other, Pointer):
            return self.mem is other.mem and self.index == other.index
        else:
            return False

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

    __radd__ = __add__

    def __setitem__(self, index: int, value: Value):
        self.mem[self.index + index] = value

    def __getitem__(self, index: int) -> Value:
        return self.mem[self.index + index]

    def free(self):
        self.mem.free()
