

# NOTE: I copy-pasted this metaclass from:
# https://blag.nullteilerfrei.de/2020/06/28/wrapping-integers-in-python-with-metaclassing/
# ...thanks, mystery Internet person!
# - BAG, 2026
class uint_meta(type):
    def __new__(cls, name, bases, nmspc, mod=None, bits=None, hexrep=False, signed=False):
        assert int in bases[0].__mro__
        if None not in (mod, bits) and 1 << bits != mod:
            raise ValueError('incompatible mod and bits argument.')
        mod = mod or bits and 1 << bits
        if mod:
            for op in 'add', 'and', 'floordiv', 'lshift', 'mod', 'mul', 'or', 'rshift', 'sub', 'xor':
                opname = F'__{op}__'
                nmspc[F'__r{op}__'] = nmspc[opname] = lambda self, them, op=getattr(int, opname): (
                    self.__class__(op(self, them)))
            nmspc['__rtruediv__'] = nmspc['__truediv__'] = lambda self, them, p=int.__pow__: (
                self.__class__(self * p(them, -1, mod)))
            nmspc['__pow__'] = lambda self, them, op=int.__pow__: self.__class__(op(self, them, mod))
            nmspc['__inv__'] = lambda self, op=int.__invert__: self.__class__(op(self))
            nmspc['__neg__'] = lambda self, op=int.__neg__: self.__class__(op(self))
            nmspc.update(mod=mod, signed=signed)
            if hexrep is True:
                nib, up = divmod((mod.bit_length() - 1) - 1, 4)
                nib += bool(up)
                nmspc['__repr__'] = lambda self: F'{self:#0{nib}x}'
        return type.__new__(cls, name, bases, nmspc)

    def __call__(cls, value=0, *args, **kwargs):
        if isinstance(value, int):
            value = value % cls.mod
            if cls.signed and (value & (cls.mod >> 1)):
                value -= cls.mod
            return type.__call__(cls, value)
        return cls(int(value, *args, **kwargs))


class u8(int, metaclass=uint_meta, bits=8): ...
class u16(int, metaclass=uint_meta, bits=16): ...
class u32(int, metaclass=uint_meta, bits=32): ...
class u64(int, metaclass=uint_meta, bits=64): ...

class i8(int, metaclass=uint_meta, bits=8, signed=True): ...
class i16(int, metaclass=uint_meta, bits=16, signed=True): ...
class i32(int, metaclass=uint_meta, bits=32, signed=True): ...
class i64(int, metaclass=uint_meta, bits=64, signed=True): ...
