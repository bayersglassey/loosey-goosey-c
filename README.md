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
See also the "doctests for C" section below...


## Existing C interpreters

Here are some projects I've played with or looked at, but didn't quite get
what I needed from:

* clang-repl (formerly "cling"): https://clang.llvm.org/docs/ClangRepl.html
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
* [mini.py](/src/loosey/mini.py)

There are fairly extensive tests, see:
* Doctests throughout the Python code
* C tests in [minictests](/minictests), run with [minictests.sh](/minictests.sh)
* Preprocessor tests in [pptests](/pptests), run with [pptests.sh](/pptests.sh)

The "roadmap" is this big ol' checklist:
* [TODO](/TODO)

Example usage (from Python REPL):
```python

>>> from loosey.mini import MiniC, Pointer
>>> mini = MiniC()

>>> mini.eval('1 + 2')
3

>>> mini.eval('1 + 2 * 10 + 3')
24

# The C preprocessor is available, with all its foibles... remember to add
# lots of parentheses ;)
>>> mini.eval('#define DOUBLE(X) X + X')
>>> mini.eval('10 * DOUBLE(2)')
22

>>> add = mini.eval('int add(int x, int y) { int z = x + y; return z; }')
>>> add
add(x, y)

# Calling a mini-C function directly from Python:
>>> add(3, 4)
7

# Calling a mini-C function within mini-C:
>>> mini.eval('int x = 3, total = add(x, 5);')
{'x': 3, 'total': 8}

# Using a Python function from within mini-C:
>>> import math
>>> mini.add_python_func(math.sqrt)
>>> mini.eval('sqrt(20 + 5)')
5.0

# Using Python objects, methods, etc from within mini-C:
# (NOTE: all C types are currently ignored, so the "struct t *" here could
# just as easily have been "int" or whatever)
>>> add_dict_keys = mini.eval("""
... int add_dict_keys(struct t *obj) {
...     return obj->get("x") + obj->get("y");
... }""")
>>> add_dict_keys({'x': 1, 'y': 2})
3

# Creating a pointer in Python and passing it to C code:
>>> ptr = Pointer(3)
>>> mini.eval('void f(void *ptr) { *ptr += 1; }')(ptr)
>>> ptr
Pointer(4)

# Dynamically allocating a data structure in C code and returning
# it to Python:
>>> mkobj = mini.eval("""
... void *mkobj() {
...     void *ptr = malloc(1);
...     ptr->x = 3;
...     ptr->y = 4;
...     return ptr;
... }""")
>>> mkobj()
Pointer(Struct({'x': 3, 'y': 4}))

# Allocating an array of data structures in Python and passing them to C code:
>>> ptr = mini.stdlib.malloc(3)
>>> for i in range(3):
...     ptr[i]['x'] = i * 2
...     ptr[i]['y'] = i * 5
...     ptr[i]
Struct({'x': 0, 'y': 0})
Struct({'x': 2, 'y': 5})
Struct({'x': 4, 'y': 10})
>>> mini.eval(r"""f(struct t *objs) {
...     int i;
...     for (i = 0; i < 3; i += 1) printf("%i, %i\n", objs[i].x, objs[i].y);
... }""")(ptr)
0, 0
2, 5
4, 10

```

Example usage (from commandline):
```
$ cat hello.c
#include <stdio.h>
int main(int argc, char **argv) {
    const char *name = argv[1];
    printf("Hello, %s!\n", name);
    return 0;
}

$ python -m loosey.mini -f hello.c -- world
Hello, world!
```

As an example of a somewhat interesting C program which mini-C can actually run,
see e.g. [calc.c](/minictests/calc.c), which is a tiny stack-based calculator:
```
$ python -m loosey.mini -f minictests/calc.c
> 1 2 + 10
Stack: 3 10
> *
Stack: 30
> q
```

...and for even more interesting examples, see below...


## Doctests for C

Python has a built-in module called "doctest", which lets you run unit tests
found embedded in your code (especially in "docstrings", which are multiline
strings associated with individual modules, classes, and functions).
* https://docs.python.org/3/library/doctest.html

Doctests look something like this, with commands prefixed with `>>>`, and
followed by expected output on subsequent lines:
```python

>>> x = 2
>>> x + 4
6
>>> for i in range(3): print(i)
0
1
2

```

Interestingly, doctest can be used with any file, not just Python source
files; for instance, all the doctests in this README are run as part of this
repo's test suite (see [runtests.sh](/runtests.sh)).

So, once we have a C interpreter implemented in Python, we can include
doctests in our C code!..

Here is an example .c file, which I extracted from a larger file in the
CPython source code, and added a doctest to:
* [reverse_slice.c](/examples/reverse_slice.c)

I can run the doctests in that file the same way I would for any other
file.
If there are no test failures, then there is no output.
If there are test failures, e.g. if I edit the .c file and introduce a bug,
they show up something like this:
```
$ python -m doctest examples/reverse_slice.c
**********************************************************************
File "examples/reverse_slice.c", line 30, in reverse_slice.c
Failed example:
    mini.eval("""
        PyObject *objs[] = {1, 20, 30, 40, 5};
        reverse_slice(&objs[1], &objs[4]);
        print(objs.as_list());
    """)
Expected:
    [1, 40, 300, 20, 5]
Got:
    [1, 40, 30, 20, 5]
**********************************************************************
1 items had failures:
   1 of   5 in reverse_slice.c
***Test Failed*** 1 failures.
```

The approach is very simple: the doctest manually imports and instantiates
the MiniC class, and uses it to evalute the C file.
(The file's path must be hardcoded in the doctest; it would be nice if there
were a global variable called e.g. `__file__` with the path of the file
currently being executed by doctest, AFAIK but there is not.)

Like this:
```python
from loosey.mini import MiniC
mini = MiniC()
mini.eval_file('examples/reverse_slice.c')
```

In this case, I had to copy-paste the function out of the C file I found it in
(CPython's Objects/listobject.c), because MiniC wasn't able to parse that file
as-is.
Going forward, I'd like to increasingly be able to just point MiniC at existing
files, and extract functions from them directly...

Here is a more exciting example:
* [regexp-bytecode.c](/examples/regexp-bytecode.c)

...it's a complete "bytecode machine implementation of Ken Thompson's
on-the-fly regular expression compiler", which I got from Russ Cox's website,
while reading his excellent articles such as "Regular Expression Matching Can
Be Simple And Fast":
* https://swtch.com/~rsc/regexp/regexp1.html

Pretty much all I did to the file was to change tabs to spaces, fix compile()
to avoid undefined involving `++`, and add doctests!
