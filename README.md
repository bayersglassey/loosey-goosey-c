# The Loosey Goosey C Parser and Interpreter

## Rationale

I love programming with a REPL (Read-Eval-Print-Loop).

So for instance, I'm one of those people who's always at the CLI, instead of
in an IDE.

And I love Python, and iPython; my favourite style of Python programming is
where I'm typing stuff into the REPL, seeing what works, and when I find it,
I copy-paste it into a .py file as code and/or tests.

Now, I'm also a C programmer, and C is in many ways a *terrible* language to
work with.
It certainly doesn't lend itself well to programming in a REPL.
I can read through a large C codebase, like SQLite or PostgreSQL or CPython or
the Linux kernel, and come to some understanding of what it's doing, but I
can't easily *try it out*.
It's not like Python, where I'm at the REPL, and I can import a class,
instantiate it, and poke at it.

So, that's the goal here: what if you could "import" (or even just copy-paste)
C code, and play with it at a REPL?

The idea will be to map the runtime semantics of C onto some Python classes,
then have a C parser which is intentionally loosey-goosey, so it can parse
even fragments of C code without having to `#include` all the proper stuff,
and then you can instantiate the types and call the functions and so on, and
have things fail at runtime instead of compile-time, for instance if you
call some function which attempts to call another function which hasn't been
defined.
And you should be able to mock out missing functions and things quickly in
Python, so you can re-run the thing you were actually interested in, and have
it succeed this time.

Last thing in this rationale, I'm going to breathe to you a secret word...
[doctests](https://docs.python.org/3/library/doctest.html).
Imagine doctests for your C code.


## Existing C interpreters

Here are some projects I've played with or looked at, but didn't quite get
what I needed from:

* clang-repl: https://clang.llvm.org/docs/ClangRepl.html
* pycparser: https://github.com/eliben/pycparser


## Installation

```
pip install loosey-goosey-c
```

See also:
* https://pypi.org/project/loosey-goosey-c


## The C preprocessor

Implemented in pure Python!
It's actually fairly complete.

See its documentation here:
* [preprocessor.md](/docs/preprocessor.md)

Example usage:
```
$ echo -e '#define M(X) [X]\nM(M(1))' | python -m loosey.pp
[ [ 1 ] ]
```


## Mini C Interpreter

Work in progress.

Allows C code to be run dynamically, using Python values.
Functions and values can be freely exchanged between C and Python.

It's very dynamic: it ignores the C type system entirely, using Python objects
as values, including a custom Pointer class.
If you refer to uninitialized memory, you generally get an instance of Struct,
which is a custom Python class which secretly adds fields to itself whenever
you try to refer to them.

The parser uses a heavily tweaked version of the ANSI C yacc grammar
available online:
* [ansi-c-grammar.txt](/src/loosey/data/ansi-c-grammar.txt)

...which is parsed and interpreted with a custom grammar library, which is
probably a [packrat parser](https://en.wikipedia.org/wiki/Packrat_parser):
* [grammar.py](/src/loosey/grammar.py)

The interpreter's code lives here:
* [minic.py](/src/loosey/minic.py)

Example usage:
```python
>>> from loosey.minic import MiniC
>>> minic = MiniC()

>>> minic.eval('1 + 2')
3

>>> minic.eval('1 + 2 * 10 + 3')
24

# The C preprocessor is available, with all its foibles... remember to add
# lots of parentheses ;)
>>> minic.eval('#define DOUBLE(X) X + X')
>>> minic.eval('10 * DOUBLE(2)')
22

>>> add = minic.eval('int add(int x, int y) { int z = x + y; return z; }')
>>> add
add(x, y)

# Calling a mini-C function directly from Python:
>>> add(3, 4)
7

# Calling a mini-C function within mini-C:
>>> minic.eval('int x = 3, total = add(x, 5);')
{'x': 3, 'total': 8}

# Using a Python function from within mini-C:
>>> import math
>>> minic.globals['sqrt'] = math.sqrt
>>> minic.eval('sqrt(20 + 5)')
5.0

# Using Python objects, methods, etc from within mini-C:
# (NOTE: all C types are currently ignored, so the "struct t *" here could
# just as easily have been "int" or whatever)
>>> add_dict_keys = minic.eval("""
... int add_dict_keys(struct t *obj) {
...     return obj->get("x") + obj->get("y");
... }""")
>>> add_dict_keys({'x': 1, 'y': 2})
3

# Creating a pointer in Python and passing it to C code:
>>> ptr = minic.malloc()
>>> ptr.contents.x = 3
>>> ptr_test = minic.eval('void ptr_test(void *ptr) { ptr->x += 1; }')
>>> ptr_test(ptr)
>>> ptr.contents.x
4

# Creating a pointer in C code and returning it to Python:
>>> mkptr = minic.eval('''
... void *mkptr() {
...     void *ptr = malloc(1);
...     ptr->x = 3;
...     return ptr;
... }''')
>>> ptr = mkptr()
>>> ptr.contents.x
3
```
