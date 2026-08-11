import sys
import inspect
import errno as errno_module
from typing import Any, Optional, NamedTuple, Iterator, Sequence
from functools import cached_property
from contextlib import contextmanager
from argparse import ArgumentParser

from loosey import get_data_filepath
from loosey.grammar import ParseMatch
from loosey.pplex import Token, ParseError
from loosey.pp import (
    GrammarEvaluatorWithPreprocessor,
    get_local_dir_from_args,
)


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
    elif isinstance(value, Struct):
        # Struct behaves like 0 under arithmetic operations...
        return False
    else:
        # E.g. Python strings should be interpreted as `const char *`,
        # so always truthy, even the empty string!..
        return True


def value_as_int(value: Value) -> int:
    if isinstance(value, (str, bytes)):
        return ord(value)
    else:
        # NOTE: this will also turn Struct instances into 0
        return int(value)


def value_as_string(value: Value) -> str:
    """

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
        index = 0
        buf = bytearray()
        while True:
            i = value_as_int(value[index])
            if i == 0:
                # NUL byte
                break
            buf.append(i)
            index += 1
        return buf.decode() # I sure hope this is valid UTF-8!..
    else:
        return Exception(f"Expected string, got: {value!r}")


def copy_value(value: Value) -> Value:
    """Copy a C value"""
    if isinstance(value, Struct):
        # Copy the underlying memory for each field
        return value.copy()
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
    kind: Optional[str] # None or 'pointer' or 'array' or 'func'


class InitDeclarator(NamedTuple):
    declarator: Declarator
    initializer: Optional[ParseMatch]

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
    init_declarators: list[InitDeclarator]

    @property
    def is_typedef(self) -> bool:
        return 'typedef' in self.specifiers


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
    """Raised by CStdlib's exit()"""
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
        Struct(x=2, y=Struct())

        If the nesting is too deep, the repr will be truncated:
        >>> obj = Struct()
        >>> obj['a']['b']['c']['d']['e']['f'] = 3
        >>> obj
        Struct(a=Struct(b=Struct(c=Struct(d=Struct(e)))))

        For convenience, you can set struct fields when calling its
        constructor:
        >>> Struct(msg='hello', ptr=Pointer(Struct(x=1, y=2)))
        Struct(msg='hello', ptr=Pointer(Struct(x=1, y=2)))

    """

    def __init__(self, **kwargs):
        self.fields: dict[str, Pointer] = {
            attr: Pointer(value)
            for attr, value in kwargs.items()}

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
            parts = list(self.fields)
        else:
            parts = []
            for attr, ptr in self.fields.items():
                value = ptr.contents
                if isinstance(value, (Struct, Pointer)):
                    msg = value.mkrepr(depth - 1)
                else:
                    msg = repr(value)
                parts.append(f'{attr}={msg}')
        msg = ', '.join(parts)
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

    def free(self):
        if self.freed:
            raise Exception(f"Attempted to free already-freed memory: {self!r}")
        else:
            self.freed = True


class PythonMemoryBlock(BaseMemoryBlock):
    """Behaves like a block of memory in C, i.e. an array of objects.
    Is backed by any Python object which behaves like a Sequence[Value]."""

    min_index = 0

    def __init__(self, data: Sequence[Value]):
        super().__init__()
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

    def copy(self) -> 'PythonMemoryBlock':
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

    def __init__(self, mem: MemoryBlock | Value, index: int = 0):
        if not isinstance(mem, MemoryBlock):
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


# Maps attributes of CStdlib to C variable names
_CSTDLIB_REGISTRY: dict[str, str] = {}

def _cstdlib_register(_name=None):
    """Registers a method of CStdlib as a C function"""
    def decorator(func):
        name = _name
        if name is None:
            name = func.__name__
        elif not isinstance(name, str):
            raise Exception(f"Expected str, got: {name!r}")
        _CSTDLIB_REGISTRY[func.__name__] = name
        return func
    return decorator

class FileHandle:
    """Used by CStdlib to represent FILE* objects"""

    def __init__(self, filename: str, mode: str = '???'):
        self.filename = filename
        self.mode = mode

    def __repr__(self) -> str:
        return f'{self.__class__.__name__}({self.filename!r}, {self.mode!r})'

FileLikeObject = Any # file-like object

class CStdlib:
    """Python functions implementing (a subset of) the C stdlib for MiniC"""

    def __init__(self, mini: 'MiniC'):
        self.mini = mini

        for name in ('stdin', 'stdout', 'stderr'):
            _CSTDLIB_REGISTRY[name] = name
        self.stdin = FileHandle('<stdin>')
        self.stdout = FileHandle('<stdout>')
        self.stderr = FileHandle('<stderr>')

        self.errno = 0

        # NOTE: these match what we #define in stddef.h and stdio.h
        self.NULL = 0
        self.EOF = -1

        self.open_file_handles: dict[FileHandle, FileLikeObject] = {
            self.stdin: sys.stdin,
            self.stdout: sys.stdout,
            self.stderr: sys.stderr,
        }

    def _get_file(self, value: Value) -> FileLikeObject:
        if isinstance(value, FileHandle):
            # File handle, get the corresponding file-like object
            file = self.open_file_handles.get(value)
            if file is None:
                raise Exception(f"No open file for handle: {value!r}")
            return file
        elif hasattr(value, 'read') or hasattr(value, 'write'):
            # File-like object, use it directly
            return value
        else:
            raise Exception(f"Expected file-like object or file handle, got: {value!r}")

    @_cstdlib_register()
    def exit(self, code: int):
        raise Exit(code)

    @_cstdlib_register()
    def __loosey_errno__(self) -> int:
        # NOTE: in errno.h, we `#define errno __loosey_errno__()`
        return self.errno

    def set_errno(self, ex: Exception, errno=None):
        if errno is None:
            # TODO: set errno based on the actual exception we got...
            errno = errno_module.EPERM
        self.errno = errno
        self.errno_ex = ex

    @_cstdlib_register()
    def perror(self, msg=None):
        if msg:
            msg = f'{msg}: {self.errno_ex}'
        else:
            msg = str(self.errno_ex)
        print(msg, file=sys.stderr)

    @_cstdlib_register()
    def malloc(self, size: int = 1) -> Pointer:
        return Pointer(MemoryBlock(size=size))

    @_cstdlib_register()
    def calloc(self, nmemb: int = 1, size: int = 1) -> Pointer:
        return self.malloc(nmemb * size)

    @_cstdlib_register()
    def realloc(self, ptr: Optional[Pointer], size: int = 1) -> Pointer:
        if ptr is None:
            return self.malloc(size)
        elif ptr.size >= size:
            return ptr
        else:
            new_ptr = Pointer(MemoryBlock(size=size))
            self.memcpy(new_ptr, ptr, ptr.size)
            return new_ptr

    @_cstdlib_register()
    def free(self, ptr: Optional[Pointer]):
        if ptr is not None:
            ptr.free()

    @_cstdlib_register()
    def fprintf(self, file, fmt: str, *args) -> int:
        r"""

            >>> mini = MiniC()
            >>> mini.stdlib.printf('Hello %s\n', 'world')
            Hello world
            0
            >>> mini.stdlib.printf('%i + %i = %i\n', 1, 2, 3)
            1 + 2 = 3
            0
            >>> mini.stdlib.printf('[%c]\n', 65)
            [A]
            0

            >>> buf = Pointer(MemoryBlock())
            >>> buf[0] = 'H'
            >>> buf[1] = 'i'
            >>> buf[2] = '!'
            >>> mini.stdlib.printf('%s\n', buf)
            Hi!
            0

        """
        file = self._get_file(file)
        # TODO: use a proper C format-string parser...
        args = tuple(value_as_string(arg) if isinstance(arg, Pointer) else arg
            for arg in args)
        msg = str(fmt) % args
        print(msg, file=file, end='')
        return 0

    @_cstdlib_register()
    def printf(self, fmt: str, *args) -> int:
        return self.fprintf(self.stdout, fmt, *args)

    @_cstdlib_register()
    def fgetc(self, file) -> int:
        file = self._get_file(file)
        c = file.read(1)
        if not c:
            return self.EOF
        return ord(c)

    @_cstdlib_register()
    def getc(self, file) -> int:
        return self.fgetc(file)

    @_cstdlib_register()
    def getchar(self) -> int:
        return self.fgetc(self.stdin)

    @_cstdlib_register()
    def fputc(self, c, file) -> int:
        file = self._get_file(file)
        if isinstance(c, int):
            c = chr(c)
        file.write(c)
        return ord(c)

    @_cstdlib_register()
    def putc(self, c, file) -> int:
        return self.fputc(c, file)

    @_cstdlib_register()
    def putchar(self, c) -> int:
        return self.fputc(c, self.stdout)

    @_cstdlib_register()
    def fputs(self, s, file) -> int:
        file = self._get_file(file)
        file.write(s)
        return 1 # nonnegative number on success, EOF on error

    @_cstdlib_register()
    def puts(self, s) -> int:
        i = self.fputs(s, self.stdout)
        if i > 0:
            sys.stdout.write('\n')
        return i

    @_cstdlib_register()
    def fgets(self, s, size: int, file):
        file = self._get_file(file)
        data = file.read(size - 1)
        for i, c in enumerate(data):
            # TODO: figure out how we're going to do strings for real...
            s[i] = ord(c)
        return s # return s on success, NULL on error

    @_cstdlib_register()
    def fflush(self, file) -> int:
        file = self._get_file(file)
        file.flush()
        return 0 # return 0 on success, EOF on error

    @_cstdlib_register()
    def fopen(self, filename: str, mode: str = 'r') -> FileHandle:
        try:
            file = open(filename, mode)
        except OSError as ex:
            # TODO: set errno based on the actual exception we got...
            errno = errno_module.ENOENT
            self.set_errno(ex, errno)
            return self.NULL
        handle = FileHandle(filename, mode)
        self.open_file_handles[handle] = file
        return handle

    @_cstdlib_register()
    def fclose(self, file) -> FileHandle:
        file = self._get_file(file)
        try:
            file.close()
        except OSError as ex:
            self.set_errno(ex)
            return self.EOF
        if file in self.open_file_handles:
            del self.open_file_handles[file]
        return 0 # return 0 on success, EOF on error

    @_cstdlib_register()
    def fread(self, ptr: Pointer, size: int, nmemb: int, file) -> FileHandle:
        file = self._get_file(file)
        data = file.read(size * nmemb)
        # Copy data into ptr
        raise NotImplementedError("TODO: probably need to make sure all strings are actually bytes, etc...")
        self.memcpy(ptr, data)

    @_cstdlib_register()
    def fwrite(self, ptr: Pointer, size: int, nmemb: int, file) -> FileHandle:
        file = self._get_file(file)
        data = bytearray()
        # Extract size*nmemb bytes from ptr
        raise NotImplementedError("TODO: probably need to make sure all strings are actually bytes, etc...")
        file.write()

    @_cstdlib_register()
    def memcpy(self, dst, src, size: Optional[int] = None) -> FileHandle:
        if size is None:
            size = min(len(src), len(dst)) # ???
        raise NotImplementedError("TODO")

    @_cstdlib_register()
    def strlen(self, s) -> int:
        s = value_as_string(s)
        return len(s)


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
          decl: declaration
            declspec: declaration_specifiers
              typedef
              int
            decl: init_declarator
              decl: declarator
                declare: Integer
          decl: declaration
            declspec: declaration_specifiers
              Integer
            decl: init_declarator
              decl: declarator
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
        decl: declaration
          declspec: declaration_specifiers
            T
          decl: init_declarator
            decl: declarator
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

        # Creating a pointer in Python and passing it to C code:
        >>> ptr = Pointer(3)
        >>> mini.eval('void f(void *ptr) { *ptr += 1; }')(ptr)
        >>> ptr
        Pointer(4)

        # Dynamically allocating a data structure in C code and returning
        # it to Python:
        >>> mkobj = mini.eval('''
        ... void *mkobj() {
        ...     void *ptr = malloc(1);
        ...     ptr->x = 3;
        ...     ptr->y = 4;
        ...     return ptr;
        ... }''')
        >>> mkobj()
        Pointer(Struct(x=3, y=4))

    """

    grammar_filename = GRAMMAR_FILENAME
    main_rule_name = 'repl_commands'
    squash_children = True
    pass_through_exceptions = (
        Return,
        Continue,
        Break,
        Goto,
        Exit,
    )
    handler_prefixes = ('reference',)

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        # Define some default macros, which GCC seems to define on my system
        self.pp.execute('#define __restrict')
        self.pp.execute('#define __extension__')
        self.pp.execute('#define __attribute__(...)')
        self.pp.execute('#define _Float32 float')
        self.pp.execute('#define _Float64 float')
        self.pp.execute('#define _Float128 float')
        self.pp.execute('#define _Float32x float')
        self.pp.execute('#define _Float64x float')
        self.pp.execute('#define __asm__(...) ;')

        # NOTE: this is the "call stack" for variables during evaluation
        self.global_scope: dict[str, Pointer] = {}
        self.scopes: list[dict[str, Pointer]] = [self.global_scope]

        # Add some helper functions
        self.add_python_func(self.runtime_error, '__loosey_error__')
        self.add_python_func(self.trace, '__loosey_trace__')
        self.add_python_func(print)

        # Add some default stdlib functions
        self.stdlib = CStdlib(self)
        for attr, name in _CSTDLIB_REGISTRY.items():
            self.add_global(getattr(self.stdlib, attr), name)

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
            ('declaration', 'decl'):
                (None, self.exit_declaration),
        }
        for rule_name, pattern_name in self.pattern_callbacks:
            if rule_name not in self.grammar_rules:
                raise Exception(f"Unknown rule name: {rule_name}")
        self.toktype_predicates = {
            'TYPE_NAME': self.is_type_name_token,
        }

        self.parsed_declarators: dict[str, Declarator] = {}
        self.parsed_declarations: dict[str, Declaration] = {}

    def parse(self, *args, **kwargs):
        block = set()
        self.typedef_blocks.append(block)
        try:
            return super().parse(*args, **kwargs)
        finally:
            assert self.typedef_blocks.pop() is block

    def add_global(self, value, name):
        if inspect.isfunction(value):
            return self.add_python_func(value, name)
        else:
            self.global_scope[name] = Pointer(value)

    def add_python_func(self, func, name=None):
        if not isinstance(func, PythonFunction):
            func = PythonFunction(func, name)
        self.global_scope[func.name] = Pointer(func)

    def globals(self) -> dict[str, Value]:
        return {name: ptr.contents
            for name, ptr in self.global_scope.items()}

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
        declaration = self.parse_declaration(match)
        if not declaration.is_typedef:
            return
        typedef_block = self.typedef_blocks[-1]
        for init_declarator in declaration.init_declarators:
            typedef_block.add(init_declarator.name)

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

    def have_var(self, name: str) -> bool:
        for scope in reversed(self.scopes):
            if name in scope:
                return True
        return False

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
            scope[name] = Pointer(value)

    def parse_declarator(self, match: ParseMatch) -> Declarator:
        key = match.unique_id
        declarator = self.parsed_declarators.get(key)
        if declarator is None:
            declarator = self._parse_declarator(match)
            self.parsed_declarators[key] = declarator
        return declarator

    def _parse_declarator(self, match: ParseMatch) -> Declarator:
        """

            >>> mini = MiniC()

            >>> def test(text):
            ...     match = mini.parse(text, 'declarator')
            ...     decl = mini.parse_declarator(match)
            ...     return decl.name, decl.kind

            >>> test('x')
            ('x', None)

            >>> test('(x)')
            ('x', None)

            >>> test('*x')
            ('x', 'pointer')

            >>> test('*(x)')
            ('x', 'pointer')

            >>> test('(*x)')
            ('x', 'pointer')

            >>> test('x[]')
            ('x', 'array')

            >>> test('(x)[]')
            ('x', 'array')

            >>> test('(x[])')
            ('x', 'array')

            >>> test('x()')
            ('x', 'func')

            >>> test('(x)()')
            ('x', 'func')

            >>> test('(x())')
            ('x', 'func')

        The most obnoxious distinction in C's entire type system: function
        pointer vs function returning pointer:

            >>> test('(*x)()')
            ('x', 'pointer')

            >>> test('*x()')
            ('x', 'func')

            >>> test('*(x)()')
            ('x', 'func')

        Another tricky distinction: array of pointers vs pointer to array:

            >>> test('*x[]')
            ('x', 'array')

            >>> test('(*x)[]')
            ('x', 'pointer')

        """
        assert match.rule_name == 'declarator'

        # Find the stuff within the innermost set of parentheses...
        # 1. `*(*(**x[3])[])()` -> `**x[3]`
        # 2. `*(*(x)[])()` -> `*(x)[]`
        #    ...note how we don't count the parentheses around `(x)`, since
        #    they don't affect the type of x!.. e.g. `*((x))` is a pointer.
        child = innermost_match = match
        while True:
            if len(child.children) > 1:
                innermost_match = child
            next_child = child.find('declarator')
            if next_child is None:
                name = child.find('declare:.').token.value
                break
            child = next_child

        suffix = innermost_match.find('declarator_suffix')
        if suffix:
            if suffix.pattern_name == 'array':
                kind = 'array'
            elif suffix.pattern_name == 'params':
                kind = 'func'
            else:
                # Should never happen
                raise ParseError(match.token, f"Unknown suffix: {suffix}")
        elif innermost_match.find('pointer'):
            kind = 'pointer'
        else:
            kind = None

        return Declarator(
            match=match,
            name=name,
            kind=kind,
        )

    def parse_declaration(self, match: ParseMatch) -> Declaration:
        key = match.unique_id
        declaration = self.parsed_declarations.get(key)
        if declaration is None:
            declaration = self._parse_declaration(match)
            self.parsed_declarations[key] = declaration
        return declaration

    def _parse_declaration(self, match: ParseMatch) -> Declaration:
        assert match.rule_name == 'declaration'

        # The declaration specifiers, e.g. 'int'
        declspec = match.children[0]

        # Looking for specifiers like 'typedef', 'extern', 'const', etc
        specifiers: set[str] = {child.token.value
            for child in
                declspec.findall('storage_class_specifier')
                + declspec.findall('type_qualifier')}

        # Init declarators, e.g. `x`, `*x[3]`, `x = 2`, etc
        init_declarators: list[InitDeclarator] = []
        for child in match.children[1:]:
            assert child.rule_name == 'init_declarator'
            declarator = self.parse_declarator(child.children[0])
            initializer = child.children[1] if len(child.children) > 1 else None
            init_declarators.append(InitDeclarator(declarator, initializer))

        return Declaration(
            match=match,
            declspec=declspec,
            specifiers=specifiers,
            init_declarators=init_declarators,
        )

    def runtime_error(self, msg: str):
        # NOTE: this function is available to C code as __loosey_error__
        raise Exception(msg)

    def trace(self):
        # NOTE: this function is available to C code as __loosey_trace__
        import ipdb
        ipdb.set_trace()

    ###########################################################################
    # GRAMMAR HANDLER METHODS

    def on_function_definition(self, match: ParseMatch) -> Value:
        declarator = self.parse_declarator(match.find('declarator'))
        if declarator.kind != 'func':
            raise ParseError(match.token, "Trying to define a function using non-function variable")
        name = declarator.name
        params_match = declarator.match.find('params:.')
        params = [child.token.value for child in
            # NOTE: might be a parameter_type_list, i.e. (int x, int y), or
            # might be a list of param_identifier, i.e. just (x, y)
            params_match.findall('.* declare:.', sorted=True)]
        body = match.find('block:compound_statement')
        variadic = declarator.match.children[1].find('.* ellipsis') is not None
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

    def on_decl__declaration(self, match: ParseMatch) -> dict[str, Value]:
        intialized_values = {}

        declaration = self.parse_declaration(match)
        if declaration.is_typedef:
            # Handle typedefs
            for init_declarator in declaration.init_declarators:
                name = init_declarator.name
                value = TypeDef(
                    name=name,
                    declaration=declaration,
                    init_declarator=init_declarator,
                )
                self.set_var(name, value)
                intialized_values[name] = value
        else:
            # Handle variable initializations
            for init_declarator in declaration.init_declarators:
                name = init_declarator.name
                kind = init_declarator.kind
                initializer = init_declarator.initializer
                if initializer is not None:
                    if initializer.spec == 'initializer_list:initializer' and kind != 'array':
                        # TODO: implement struct initialization lists...
                        # HACK: for now, we just make sure `= {0}` works
                        value = self._create_uninitialized_value(
                            name, init_declarator.declarator)
                    else:
                        value = copy_value(self.on(initializer))
                    self.set_var(name, value)
                else:
                    scope = self.scopes[-1]
                    if name in scope:
                        # This variable is already initialized!.. so don't
                        # overwrite with a fresh Struct.
                        # In particular, we don't want to have function
                        # prototypes overwrite the actual functions!..
                        value = scope[name]
                    else:
                        # Uninitialized variables are assigned a reasonable
                        # default value
                        value = self._create_uninitialized_value(
                            name, init_declarator.declarator)
                        self.set_var(name, value)
                intialized_values[name] = value

        return intialized_values

    def _create_uninitialized_value(self, name: str, declarator: Declarator) -> Value:
        kind = declarator.kind
        if kind == 'array':
            # Array variables are initialized to pointers
            # backed by an auto-growing memory block
            return Pointer(MemoryBlock())
        elif kind == 'func':
            # Functions are initialized to a function which
            # tells you that it's uninitialized
            def func(*args):
                raise Exception(
                    f"Function {name!r} "
                    f"declared at {declarator.match.token.location()} "
                    "was never defined!")
            return PythonFunction(func, name)
        else:
            # Other kinds of variable are initialized to a
            # magic Struct object
            return Struct()

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

    def on_initializer_list__initializer(self, match: ParseMatch) -> Value:
        values = []
        for child in match.children:
            values.append(self.on(child))
        mem = MemoryBlock()
        for i, value in enumerate(values):
            mem[i] = value
        return Pointer(mem)

    def on_unary_expression(self, match: ParseMatch) -> Value:
        op = match.children[0].token.value
        if op == '&':
            return self.get_reference(match.children[1])
        value = self.on(match.children[1])
        if op == '+':
            return +value
        elif op == '-':
            return -value
        elif op == '~':
            return ~value
        elif op == '!':
            return not value_as_bool(value)
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
            index = self.on(match.children[0])
            return value[index]
        elif match.pattern_name == 'call':
            param_values = [copy_value(self.on(child))
                for child in match.children]
            value = self.dereference(value) # handle function pointers
            return value(*param_values)
        elif match.pattern_name in ('dot', 'arrow'):
            attr = match.children[0].token.value
            if match.pattern_name == 'arrow':
                value = self.dereference(value)
            if isinstance(value, Struct):
                return value[attr]
            else:
                return getattr(value, attr)
        else:
            # Should never happen!
            raise ParseError(match.token, f"Dunno postfix operator: {match.prettystring()}")

    def on_inc__postfix_increment_expression(self, match: ParseMatch) -> Value:
        ptr = self.get_reference(match.children[0])
        value = ptr.contents
        ptr.contents += 1
        return value # the un-incremented value

    def on_dec__postfix_increment_expression(self, match: ParseMatch) -> Value:
        ptr = self.get_reference(match.children[0])
        value = ptr.contents
        ptr.contents -= 1
        return value # the un-decremented value

    def _postfix_reference_operator(self, value: Value, match: ParseMatch) -> Pointer:
        assert match.rule_name == 'postfix_operator'
        assert self.handler_prefix is None # we are *NOT* in 'reference' prefixed mode
        if match.pattern_name == 'index':
            # e.g. &(x[3]), i.e. &(*(x + 3)), i.e. x + 3
            index = self.on(match.children[0])
            return value + index
        elif match.pattern_name in ('dot', 'arrow'):
            attr = match.children[0].token.value
            if match.pattern_name == 'arrow':
                # e.g. &(x->y), i.e. &((*x).y))
                value = self.dereference(value)
            if not isinstance(value, Struct):
                field_msg = ('->' if match.pattern_name == 'arrow' else '.') + attr
                raise Exception(f"Can only get address-of-field ({field_msg}) from Struct, not from {type(value)}")
            return value.get_or_create_field(attr)
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
                    Struct() for name in func.params[-n_missing_params:]]
            elif len(param_values) > len(func.params):
                self.warn(f"Calling {func} with {len(param_values)} parameters, extras will be ignored")
            for param_name, param_value in zip(func.params, param_values):
                scope[param_name] = Pointer(param_value)

            body = func.body.children
            while True:
                try:
                    for child in body:
                        self.on(child)
                except Return as ret:
                    return copy_value(ret.value)
                except Goto as goto:
                    label_match = func.labels.get(goto.label_name)
                    if label_match is None:
                        labels_msg = "from top-level labels: " + ' '.join(func.labels) if func.labels else "function has no top-level labels"
                        raise Exception(f"Top-level label {goto.label_name!r} not found in func: {func} ({labels_msg})")
                    label_index = func.label_statements.index(label_match)
                    # Go around the loop again, starting from the labeled
                    # child of the function body...
                    # NOTE: we don't support "deep" gotos at the moment, only
                    # gotos whose labels live at the top level of the function
                    # body.
                    body = func.label_statements[label_index:]
                except ControlFlow as ex:
                    raise ParseError(ex.match.token, "Uncaught control flow: {ex.__class__.__name__}")
                else:
                    break

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
    on_expression = _eval_children
    on_expression_statement = _eval_children
    on_trailing__repl_expression = _eval_children

    def on_label__labeled_statement(self, match: ParseMatch) -> Value:
        return self.on(match.children[1])

    def on_return__jump_statement(self, match: ParseMatch) -> Value:
        if match.children:
            value = self.on(match.children[0])
        else:
            value = None
        raise Return(match, value)

    def on_ident__primary_expression(self, match: ParseMatch) -> Value:
        return self.get_var(match.token.value)

    def on_reference__ident__primary_expression(self, match: ParseMatch) -> Pointer:
        return self.get_var_ref(match.token.value)

    def on_goto__jump_statement(self, match: ParseMatch):
        raise Goto(match, label_name=match.children[0].token.value)

    def on_continue__jump_statement(self, match: ParseMatch):
        raise Continue(match)

    def on_break__jump_statement(self, match: ParseMatch):
        raise Break(match)

    def on_inc__unary_expression(self, match: ParseMatch) -> Value:
        ptr = self.get_reference(match.children[0])
        value = ptr.contents + 1
        ptr.contents = value
        return value

    def on_dec__unary_expression(self, match: ParseMatch) -> Value:
        ptr = self.get_reference(match.children[0])
        value = ptr.contents - 1
        ptr.contents = value
        return value

    def on_conditional_expression(self, match: ParseMatch) -> Value:
        cond = value_as_bool(self.on(match.children[0]))
        if cond:
            return self.on(match.children[1])
        else:
            return self.on(match.children[2])

    def on_reference__conditional_expression(self, match: ParseMatch) -> Pointer:
        with self.use_handler_prefix(None):
            cond = value_as_bool(self.on(match.children[0]))
        if cond:
            return self.on(match.children[1])
        else:
            return self.on(match.children[2])

    def _on_binary_expression(self, match: ParseMatch) -> Value:
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            if match.rule_name in BINARY_EXPRESSION_OPS:
                op = BINARY_EXPRESSION_OPS[match.rule_name]
            else:
                op = child.token.value
                child = next(children)
            if op in ('&&', '||'):
                # Short-circuiting logic!.. only evalute the argument if
                # we need to, see below...
                pass
            else:
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
                value, arg = coerce_pointers_for_comparison(value, arg)
                value = value < arg
            elif op == '>':
                value, arg = coerce_pointers_for_comparison(value, arg)
                value = value > arg
            elif op == '<=':
                value, arg = coerce_pointers_for_comparison(value, arg)
                value = value <= arg
            elif op == '>=':
                value, arg = coerce_pointers_for_comparison(value, arg)
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
                # Short-circuiting logic: self.on(child) is only evaluated
                # if needed
                return value_as_bool(value) and value_as_bool(self.on(child))
            elif op == '||':
                # Short-circuiting logic: self.on(child) is only evaluated
                # if needed
                return value_as_bool(value) or value_as_bool(self.on(child))
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
            value = copy_value(rhs)
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

    def on_switch__selection_statement(self, match: ParseMatch):
        value_match = match.children[0]
        body = match.children[1:]

        # Collect the switch cases and default
        case_matches = []
        default_match = None
        for child in body:
            if child.pattern_name == 'case':
                case_matches.append(child)
            elif child.pattern_name == 'default':
                if default_match is not None:
                    raise ParseError(child.token, "Multiple defaults for a single switch!")
                default_match = child

        value = self.on(value_match)

        # Find a case_match, which is either one of the case_matches, or the
        # default_match, or None
        for case_match in case_matches:
            case_value = self.on(case_match.children[0])
            if case_value == value:
                break
        else:
            case_match = default_match

        if case_match is None:
            # We didn't match any of the cases, and we don't have a default
            return

        # Now evaluate all statements in the switch body from case_match
        # onwards:
        case_index = body.index(case_match)
        try:
            for child in body[case_index:]:
                if child.pattern_name in ('case', 'default'):
                    self.on(child.children[-1])
                else:
                    self.on(child)
        except Break:
            pass

    def on_while__iteration_statement(self, match: ParseMatch):
        cond_match, body_match = match.children
        while True:
            cond_value = self.on(cond_match)
            if not value_as_bool(cond_value):
                break
            try:
                self.on(body_match)
            except Continue:
                pass
            except Break:
                break

    def on_do__iteration_statement(self, match: ParseMatch):
        body_match, cond_match = match.children
        while True:
            try:
                self.on(body_match)
            except Continue:
                pass
            except Break:
                break
            cond_value = self.on(cond_match)
            if not value_as_bool(cond_value):
                break

    def on_empty_expression_statement(self, match: ParseMatch):
        return None

    def on_for__iteration_statement(self, match: ParseMatch):
        if len(match.children) == 4:
            init_match, cond_match, extra_match, body_match = match.children
        elif len(match.children) == 3:
            init_match, cond_match, body_match = match.children
            extra_match = None
        else:
            # Should never happen
            raise Exception(f"For-loop with unexpected number of children: {match}")

        if cond_match.rule_name == 'empty_expression_statement':
            cond_match = None

        self.on(init_match)
        while True:
            if cond_match is not None:
                cond_value = self.on(cond_match)
                if not value_as_bool(cond_value):
                    break
            try:
                self.on(body_match)
            except Continue:
                pass
            except Break:
                break
            if extra_match is not None:
                self.on(extra_match)

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
    parser.add_argument('--progname')
    parser.add_argument('--local-dir', help="Directory used for #include \"...\"")
    parser.add_argument('-I', '--include-sys', default=[], action='append')
    parser.add_argument('-v', '--verbose', default=False, action='store_true')
    parser.add_argument('-p', '--parse-only', default=False, action='store_true')
    parser.add_argument('-s', '--parse-silent', default=False, action='store_true')
    parser.add_argument('--partial', default=False, action='store_true')
    parser.add_argument('main_args', nargs='*') # NOTE: takes everything after '--'
    args = parser.parse_args()

    if args.main_args and '--' not in sys.argv:
        print(f"ERROR: got extra arguments: {args.main_args}")
        print("If this was intentional, put an explicit '--' before them.")
        print("Or if they were a filename, put a '-f' in front of them.")
        sys.exit(1)

    pp_kwargs = dict(
        local_dir=get_local_dir_from_args(args),
        sys_dirs=args.include_sys,
    )

    mini = MiniC(pp_kwargs=pp_kwargs)
    if args.parse_only or args.parse_silent:
        match = mini.parse_file(
            args.filename,
            verbose=args.verbose,
            partial=args.partial,
            raise_on_no_match=True,
        )
        if not args.parse_silent:
            # Handy if you want to see the parser's verbose output, but not
            # the pprint of a successful match
            match.pprint()
    else:
        mini.eval_file(args.filename)
        main_func = mini.globals().get('main')
        if main_func is None:
            raise Exception("No main() function found!")
        progname = args.progname or (args.filename if args.filename != '-' else 'main')
        argv = [progname] + args.main_args
        retcode = main_func(len(argv), argv)
        if retcode is None:
            retcode = 0
        elif not isinstance(retcode, int):
            raise Exception(f"Got non-integer exit code from main(): {retcode!r}")
        sys.exit(retcode)


if __name__ == '__main__':
    main()
