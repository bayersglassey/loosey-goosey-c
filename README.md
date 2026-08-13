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
fragments of C code without having to `#include` all the proper stuff, and
then you can instantiate the types and call the functions and so on, and
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

It's very dynamic: it ignores the C type system almost entirely, using Python
objects as values, including a custom Pointer class.
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
* Doctests throughout the Python code (and other places, like this README)
* C tests in [minictests](/minictests), run with [minictests.sh](/minictests.sh)
* Preprocessor tests in [pptests](/pptests), run with [pptests.sh](/pptests.sh)
* All tests are kicked off by: [runtests.sh](/runtests.sh)

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
>>> mini.eval('void f(int *ptr) { *ptr += 1; }')(ptr)
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

# Pretty-printing a nested structure, even a circular one:
>>> mini.eval("""
...     typedef struct list { int data; struct list *next; } List;
...     struct list *mklist(int data, List *next) {
...         List *list = malloc(sizeof *list);
...         list->data = data;
...         list->next = next;
...         return list;
...     }
...     List *list = mklist(1, mklist(2, mklist(3, 0)));
...     list->next->next->next = list; // make it circular!..
...     pprint(list);
... """)
  0x0: Pointer (offset=0) into memory:
  0x1:   0: Struct:
  0x2:     'data': 1
  0x3:     'next': Pointer (offset=0) into memory:
  0x4:       0: Struct:
  0x5:         'data': 2
  0x6:         'next': Pointer (offset=0) into memory:
  0x7:           0: Struct:
  0x8:             'data': 3
  0x9:             'next': Pointer (offset=0) into memory at 0x0

# Pretty-printing a structure with multiple pointers to offsets of the
# same underlying block of memory:
>>> mini.eval(r"""
...     typedef struct { const char *data; int len; } Word;
...     const char WORD_DATA[] = "cathousebear";
...     Word words[] = {
...         {WORD_DATA + 0, 3},
...         {WORD_DATA + 3, 5},
...         {WORD_DATA + 8, 4},
...     };
...     printf("The words are:\n");
...     int i;
...     for (i = 0; i < 3; i++) {
...         Word word = words[i];
...         printf("  %.*s\n", word.len, word.data);
...     }
...     printf("...and here's what's going on in memory:\n");
...     pprint(words);
... """)
The words are:
  cat
  house
  bear
...and here's what's going on in memory:
  0x0: Pointer (offset=0) into memory:
  0x1:   0: Struct:
  0x2:     'data': Pointer (offset=0) into memory:
  0x3:       As a C string: b'cathousebear'
  0x4:       0: 99
  0x5:       1: 97
  0x6:       2: 116
  0x7:       3: 104
  0x8:       4: 111
  0x9:       5: 117
  0xa:       6: 115
  0xb:       7: 101
  0xc:       8: 98
  0xd:       9: 101
  0xe:       10: 97
  0xf:       11: 114
 0x10:     'len': 3
 0x11:   1: Struct:
 0x12:     'data': Pointer (offset=3) into memory at 0x2
 0x13:     'len': 5
 0x14:   2: Struct:
 0x15:     'data': Pointer (offset=8) into memory at 0x2
 0x16:     'len': 4

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

### Overview

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


### Example: reverse_slice() from CPython

Here is an example .c file, which I extracted from a larger file in the
CPython source code, and added a doctest to:
* [reverse_slice.c](/examples/cpython/reverse_slice.c)

I can run the doctests in that file the same way I would for any other
file.
If there are no test failures, then there is no output.
If there are test failures, e.g. if I edit the .c file and introduce a bug,
they show up something like this:
```
$ python -m doctest examples/cpython/reverse_slice.c
**********************************************************************
File "examples/cpython/reverse_slice.c", line 30, in reverse_slice.c
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
the MiniC Python class, and uses it to evalute the C file.
(The file's path must be hardcoded in the doctest; it would be nice if there
were a global variable called e.g. `__file__` with the path of the file
currently being executed by doctest, AFAIK but there is not.)

Like this:
```python
from loosey.mini import MiniC
mini = MiniC()
mini.eval_file('examples/cpython/reverse_slice.c')

# ...now add tests, using mini to run C code and inspect its output.
# All macros, typedefs, global variables, functions etc from reverse_slice.c
# are available.
```

In this case, I had to copy-paste the function out of the C file I found it in
(CPython's Objects/listobject.c), because MiniC wasn't able to parse that file
as-is.
Going forward, I'd like to increasingly be able to just point MiniC at existing
files, and extract functions from them directly...


### Example: bytecode-based regex compiler

Here is a more exciting example:
* [regexp-bytecode.c](/examples/regexp-bytecode.c)

...it's a complete "bytecode machine implementation of Ken Thompson's
on-the-fly regular expression compiler", which I got from Russ Cox's website,
while reading his excellent articles such as "Regular Expression Matching Can
Be Simple And Fast":
* https://swtch.com/~rsc/regexp/regexp1.html

Pretty much all I did to the file was to change tabs to spaces, fix compile()
to avoid undefined behaviour involving `++`, and add doctests!


### Example: SQLite's hash table

Now we're cooking!!
* [hash.c](/examples/sqlite/hash.c)

Note how easily (by calling our built-in `pprint()`) we can see the internal
structure of SQLite's Hash struct after inserting a couple of keys:
```
      0x0: Struct:
      0x1:   'first': Pointer (offset=0) into memory:
      0x2:     0: Struct:
      0x3:       'pKey': Pointer (offset=0) into memory:
      0x4:         As a C string: b'key2'
      0x5:         0: 107
      0x6:         1: 101
      0x7:         2: 121
      0x8:         3: 50
      0x9:         4: 0
      0xa:       'h': 3723489572637945191932448255262090573131
      0xb:       'data': Pointer (offset=0) into memory:
      0xc:         As a C string: b'world'
      0xd:         0: 119
      0xe:         1: 111
      0xf:         2: 114
     0x10:         3: 108
     0x11:         4: 100
     0x12:         5: 0
     0x13:       'next': Pointer (offset=0) into memory:
     0x14:         0: Struct:
     0x15:           'pKey': Pointer (offset=0) into memory:
     0x16:             As a C string: b'key1'
     0x17:             0: 107
     0x18:             1: 101
     0x19:             2: 121
     0x1a:             3: 49
     0x1b:             4: 0
     0x1c:           'h': 3723489572637945191932448255259436137370
     0x1d:           'data': Pointer (offset=0) into memory:
     0x1e:             As a C string: b'bonjour'
     0x1f:             0: 98
     0x20:             1: 111
     0x21:             2: 110
     0x22:             3: 106
     0x23:             4: 111
     0x24:             5: 117
     0x25:             6: 114
     0x26:             7: 0
     0x27:           'next': 0
     0x28:           'prev': Pointer (offset=0) into memory at 0x1
     0x29:       'prev': 0
     0x2a:   'count': 2
     0x2b:   'htsize': 0
     0x2c:   'ht': 0
```

...it's a doubly-linked list, so there are some circular references going
on, but they're handled just fine.
Note how the "prev" field of the second entry is a pointer "into memory at
0x1", that is, into the "first" field of the hash table!..
