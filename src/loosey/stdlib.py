import os
import sys
import errno as errno_module
from typing import Any, Optional

from loosey.runtime import (
    Value,
    Struct,
    Pointer,
    MemoryBlock,
    value_as_bool,
    value_as_string,
    value_as_char,
    Exit,
)


FileLikeObject = Any # file-like object

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

class CStdlib:
    """Python functions implementing (a subset of) the C stdlib for MiniC"""

    def __init__(self):

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

    @property
    def registry(self) -> dict[str, Any]:
        return {
            name: getattr(self, attr)
            for attr, name in _CSTDLIB_REGISTRY.items()}

    @_cstdlib_register()
    def __loosey_assert__(self, cond: Value):
        # NOTE: in assert.h, we `#define assert __loosey_assert__`
        if not value_as_bool(cond):
            raise AssertionError(f"Failed condition: {cond!r}")

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

            >>> stdlib = CStdlib()
            >>> stdlib.printf('Hello %s\n', 'world')
            Hello world
            0
            >>> stdlib.printf('%i + %i = %i\n', 1, 2, 3)
            1 + 2 = 3
            0
            >>> stdlib.printf('[%c]\n', 65)
            [A]
            0

            >>> buf = Pointer(MemoryBlock())
            >>> buf[0] = 'H'
            >>> buf[1] = 'i'
            >>> buf[2] = '!'
            >>> stdlib.printf('%s\n', buf)
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
        # "return the character read as an unsigned char cast to an int or
        # EOF on end of file or error"
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
        # "return the character written as an unsigned char cast to an int or
        # EOF on error"
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
            s[i] = value_as_char(c)
        return s # return s on success, NULL on error

    @_cstdlib_register()
    def fflush(self, file) -> int:
        file = self._get_file(file)
        file.flush()
        return 0 # return 0 on success, EOF on error

    @_cstdlib_register()
    def fopen(self, filename: str, mode: str = 'r') -> FileHandle:
        filename = value_as_string(filename)
        mode = value_as_string(mode)
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
    def memset(self, dst: Pointer, val: int = 0, size: Optional[int] = None) -> Pointer:
        """

            >>> stdlib = CStdlib()

            >>> dst = Pointer(MemoryBlock.from_sequence(
            ...     [10, 20, 30, 40, Struct({'x': 1})]))
            >>> dst.as_list()
            [10, 20, 30, 40, Struct({'x': 1})]
            >>> _ = stdlib.memset(dst + 1, 0, 2) # zero out 2 items
            >>> dst.as_list()
            [10, 0, 0, 40, Struct({'x': 1})]
            >>> _ = stdlib.memset(dst) # zero out all items
            >>> dst.as_list()
            [0, 0, 0, 0, Struct()]

        """
        if not isinstance(dst, Pointer):
            raise Exception(f"Can only use memset() on a pointer, got: {dst!r}")
        if val != 0:
            raise Exception(f"Second argument to memset is currently only allowed to be 0")
        for i, value in dst.items():
            if i < 0:
                continue
            if size is not None and i >= size:
                break
            if isinstance(value, Struct):
                # NOTE: this probably isn't quite good enough!..
                # We're trying to "zero out" all memory locations pointed to
                # by our original pointer, so we're replacing Struct instances
                # with fresh Struct instances.
                # However, if any of the struct's fields were array fields,
                # then really we need to put a fresh Pointer(MemoryBlock())
                # in that field!..
                # But that would require us to distinguish between Struct
                # fields which are arrays, and those which simply hold a
                # Pointer, and we don't currently make that distinction...
                # I guess at some point, we'll likely be forced to keep
                # better track of our C types. :P
                value = Struct()
            else:
                value = 0
            dst[i] = value
        return dst # return the original pointer

    @_cstdlib_register()
    def strlen(self, s) -> int:
        s = value_as_string(s)
        return len(s)

    @_cstdlib_register()
    def getenv(self, name: str) -> str:
        return os.environ.get(value_as_string(name), 0)
