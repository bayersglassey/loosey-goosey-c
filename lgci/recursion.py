import os
from inspect import isgeneratorfunction
from functools import wraps

from lgci.lex import Token, TokenTreeNode


NoneType = type(None)
_SIMPLE_TOSTR_TYPES = (int, str, NoneType)
def value_tostr(arg) -> str:
    if isinstance(arg, _SIMPLE_TOSTR_TYPES):
        return repr(arg)
    elif isinstance(arg, Token):
        return arg.prettystring()
    elif isinstance(arg, TokenTreeNode):
        return f'<{arg.token.prettystring()}>'
    else:
        return '...'


_depth = 0
ACTIVE = os.environ.get('LGCI_DEBUG_RECURSION', '').lower() in ('1', 'true')
MAX_DEPTH = int(os.environ.get('LGCI_DEBUG_RECURSION_MAX_DEPTH', 30))
def debug_recursion(*, method=True, max_depth=MAX_DEPTH, force=False):
    """

        >>> @debug_recursion(method=False, force=True)
        ... def fib(n):
        ...     if n <= 1:
        ...         return n
        ...     return fib(n - 2) + fib(n - 1)

        >>> fib(1)
        fib(1)
        -> return 1
        1

        >>> fib(2)
        fib(2)
          fib(0)
          -> return 0
          fib(1)
          -> return 1
        -> return 1
        1

        >>> fib(3)
        fib(3)
          fib(1)
          -> return 1
          fib(2)
            fib(0)
            -> return 0
            fib(1)
            -> return 1
          -> return 1
        -> return 2
        2

        >>> @debug_recursion(method=False, force=True)
        ... def walk(tree):
        ...     for child in tree:
        ...         if isinstance(child, tuple):
        ...             yield from walk(child)
        ...         else:
        ...             yield child

        >>> list(walk((1, 2)))
        walk(...)
        -> yield 1
        -> yield 2
        -> return
        [1, 2]

        >>> list(walk((1, (2, 3), 4)))
        walk(...)
        -> yield 1
          walk(...)
          -> yield 2
        ---> yield 2
          -> yield 3
        ---> yield 3
          -> return
        -> yield 4
        -> return
        [1, 2, 3, 4]

        >>> list(walk((1, ((2, 3), 4), 5)))
        walk(...)
        -> yield 1
          walk(...)
            walk(...)
            -> yield 2
          ---> yield 2
        -----> yield 2
            -> yield 3
          ---> yield 3
        -----> yield 3
            -> return
          -> yield 4
        ---> yield 4
          -> return
        -> yield 5
        -> return
        [1, 2, 3, 4, 5]

    """
    def decorator(func):
        if not force and not ACTIVE:
            # Do nothing!
            return func
        func_name = func.__name__
        def dump_args(args, kwargs, depth):
            parts = []
            if method:
                args = args[1:]
            for arg in args:
                parts.append(value_tostr(arg))
            for key, arg in kwargs.items():
                parts.append(f"{key}={value_tostr(arg)}")
            print('  ' * depth + f"{func_name}({', '.join(parts)})")
        if isgeneratorfunction(func):
            @wraps(func)
            def wrapped_func(*args, **kwargs):
                global _depth
                depth = _depth
                if depth >= max_depth:
                    raise Exception(f"Max depth of {max_depth} exceeded!")
                dump_args(args, kwargs, depth)
                _depth += 1
                try:
                    for value in func(*args, **kwargs):
                        print('  ' * depth + '--' * (_depth - depth - 1) + f"-> yield {value_tostr(value)}")
                        yield value
                    print('  ' * depth + '-> return')
                finally:
                    _depth -= 1
        else:
            @wraps(func)
            def wrapped_func(*args, **kwargs):
                global _depth
                depth = _depth
                if depth >= max_depth:
                    raise Exception(f"Max depth of {max_depth} exceeded!")
                dump_args(args, kwargs, depth)
                _depth += 1
                try:
                    value = func(*args, **kwargs)
                    print('  ' * depth + f"-> return {value_tostr(value)}")
                    return value
                finally:
                    _depth -= 1
        return wrapped_func
    return decorator
