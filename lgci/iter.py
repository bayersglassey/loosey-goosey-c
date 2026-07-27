from typing import Iterable, Iterator, Optional, Generic, TypeVar


T = TypeVar('T')


class FancyIterator(Generic[T]):
    """An iterator which allows for peeking at the next value, and "pushing"
    a next value, i.e. the opposite of "popping", i.e. next()

        >>> it = FancyIterator((1, 2, 3))
        >>> next(it)
        1
        >>> it.peek()
        2
        >>> it.push(99)
        Traceback (most recent call last):
         ...
        Exception: Can't push 99, already have 2
        >>> next(it)
        2
        >>> it.push(99)
        >>> next(it)
        99
        >>> next(it)
        3
        >>> next(it, None)

        Calling the constructor on an instance returns the same instance,
        preserving its state (e.g. whether something has been pushed onto
        it).
        This makes it safe to try and "coerce" things to FancyIterator,
        without having to worry that you'll throw away the state if the
        thing already is one.
        >>> FancyIterator(it) is it
        True

    """

    def __new__(cls, arg):
        if isinstance(arg, FancyIterator):
            return arg
        return object.__new__(cls)

    def __init__(self, things: Iterable[T]):
        self._it = iter(things)
        self._peek = None

    def __iter__(self) -> Iterator[T]:
        return self

    def __next__(self) -> T:
        if self._peek is not None:
            value = self._peek
            self._peek = None
            return value
        return next(self._it)

    def peek(self) -> Optional[T]:
        if self._peek is None:
            self._peek = next(self._it, None)
        return self._peek

    def push(self, value: T):
        if self._peek is not None:
            raise Exception(f"Can't push {value!r}, already have {self._peek!r}")
        self._peek = value
