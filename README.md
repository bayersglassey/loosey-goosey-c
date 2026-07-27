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
And you should be able to define missing functions and things quickly in
Python, so you can re-run the thing you were actually interested in, and have
it succeed this time.

In order for this to work, we're not gonna worry too much about e.g. whether
`f(x)` is a preprocessor macro or a function call.
And we're not gonna worry too much about whether every statement ends in a
semicolon, because maybe `MY_MACRO(X, Y)` is supposed to expand to a bunch of
statements with semicolons already at the end... but we don't care if we've
actually got the macro definition, we'll just call that a "function call",
and if the function's defined in Python, so be it!

So, we're going to support some invalid C code, and we're probably also
going to fail on some valid C code, because C allows for a lot of weird
stuff which is handy if you're writing for the Obfuscated C Contest, but
I don't think we need to worry about if we're just trying to e.g. play with
nicely formatted stuff we find in the Linux kernel.

Last thing in this rationale, I'm going to breathe to you a secret word...
doctests.
Imagine doctests for your C code.


## The Lexer

The lexer produces not just token sequences, but "token trees", where certain
tokens may have children:
```
// Matching parens/brackets/curlies:
(...)
[...]
{...}

// From a directive (e.g. #define) to the end of the line:
#define NAME ...

// Of course, in C the "end of the line" can be deferred with a backslash:
#define NAME ... \
    ... \
    ...
```

For example, here is a tree with a directive at the root (DEFMACRO), and
some parenthesized child nodes (`PUNCTUATION val='('`), with children of
their own:
```
$ echo "#define ADD(X, Y) (X + Y)" | python -m lgci.lex -
DEFMACRO val='ADD'
  PUNCTUATION val='('
    IDENTIFIER val='X'
    PUNCTUATION val=','
    IDENTIFIER val='Y'
  PUNCTUATION val='('
    IDENTIFIER val='X'
    PUNCTUATION val='+'
    IDENTIFIER val='Y'
```

It's also possible for directive nodes to live under other nodes.
Here is an example where some directives (DEFINE, UNDEF) live inside some
curly braces (`PUNCTUATION val='{'`):
```
$ echo '
  int main(argc, argv) {
  #define VALUE 3
      return VALUE
  #undef VALUE
  }
  ' | python -m lgci.lex -
IDENTIFIER val='int'
IDENTIFIER val='main'
PUNCTUATION val='('
  IDENTIFIER val='argc'
  PUNCTUATION val=','
  IDENTIFIER val='argv'
PUNCTUATION val='{'
  DEFINE val='VALUE'
    DEC_INT val='3'
  IDENTIFIER val='return'
  IDENTIFIER val='VALUE'
  UNDEF val='VALUE'
```

Why use "token trees"?.. because I had an intuition that it would make some
things easier later on!.. perhaps that will turn out to be incorrect, however.
In any case, it certainly causes certain aspects of the preprocessor's
behaviour to be incorrect; e.g. according to the C standard, in
`SOME_MACRO([1, 2])`, there are two parameters being passed: the token
sequences `[1` and `2]`.
However, our implementation of the preprocessor considers that to be a
single parameter being passed: the token tree `[1, 2]`.

In any case, it makes the lexer's (and preprocessor's) output easier to
eyeball.
Looking at a more complicated example, here's a function from CPython's list
implementation:
```
$ ack -B1 -A5 ^sortslice_reverse ~/repos/cpython/Objects/listobject.c
static void
sortslice_reverse(sortslice *s, Py_ssize_t n)
{
    reverse_slice(s->keys, &s->keys[n]);
    if (s->values != NULL)
        reverse_slice(s->values, &s->values[n]);
}

$ ack -B1 -A5 ^sortslice_reverse ~/repos/cpython/Objects/listobject.c | python -m lgci.lex -
IDENTIFIER val='static'
IDENTIFIER val='void'
IDENTIFIER val='sortslice_reverse'
PUNCTUATION val='('
  IDENTIFIER val='sortslice'
  PUNCTUATION val='*'
  IDENTIFIER val='s'
  PUNCTUATION val=','
  IDENTIFIER val='Py_ssize_t'
  IDENTIFIER val='n'
PUNCTUATION val='{'
  IDENTIFIER val='reverse_slice'
  PUNCTUATION val='('
    IDENTIFIER val='s'
    PUNCTUATION val='->'
    IDENTIFIER val='keys'
    PUNCTUATION val=','
    PUNCTUATION val='&'
    IDENTIFIER val='s'
    PUNCTUATION val='->'
    IDENTIFIER val='keys'
    PUNCTUATION val='['
      IDENTIFIER val='n'
  PUNCTUATION val=';'
  IDENTIFIER val='if'
  PUNCTUATION val='('
    IDENTIFIER val='s'
    PUNCTUATION val='->'
    IDENTIFIER val='values'
    PUNCTUATION val='!='
    IDENTIFIER val='NULL'
  IDENTIFIER val='reverse_slice'
  PUNCTUATION val='('
    IDENTIFIER val='s'
    PUNCTUATION val='->'
    IDENTIFIER val='values'
    PUNCTUATION val=','
    PUNCTUATION val='&'
    IDENTIFIER val='s'
    PUNCTUATION val='->'
    IDENTIFIER val='values'
    PUNCTUATION val='['
      IDENTIFIER val='n'
  PUNCTUATION val=';'
```
