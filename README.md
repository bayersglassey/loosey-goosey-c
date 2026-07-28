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


## Installation

```
pip install loosey-goosey-c
```


## The C preprocessor

At the moment, we just have a functioning preprocessor lexer.
Here it is in action:
```
$ ack -B1 -A5 "^sortslice_copy\(" ~/repos/cpython/Objects/listobject.c 
Py_LOCAL_INLINE(void)
sortslice_copy(sortslice *s1, Py_ssize_t i, sortslice *s2, Py_ssize_t j)
{
    s1->keys[i] = s2->keys[j];
    if (s1->values != NULL)
        s1->values[i] = s2->values[j];
}

$ ack -B1 -A5 "^sortslice_copy\(" ~/repos/cpython/Objects/listobject.c | python -m loosey.pplex -
1:1: IDENTIFIER('Py_LOCAL_INLINE')
1:16: PUNCTUATION('(')
1:17: IDENTIFIER('void')
1:21: PUNCTUATION(')')
2:1: IDENTIFIER('sortslice_copy')
2:15: PUNCTUATION('(')
2:16: IDENTIFIER('sortslice')
2:26: PUNCTUATION('*')
2:27: IDENTIFIER('s1')
2:29: PUNCTUATION(',')
2:31: IDENTIFIER('Py_ssize_t')
2:42: IDENTIFIER('i')
2:43: PUNCTUATION(',')
2:45: IDENTIFIER('sortslice')
2:55: PUNCTUATION('*')
2:56: IDENTIFIER('s2')
2:58: PUNCTUATION(',')
2:60: IDENTIFIER('Py_ssize_t')
2:71: IDENTIFIER('j')
2:72: PUNCTUATION(')')
3:1: PUNCTUATION('{')
4:5: IDENTIFIER('s1')
4:7: PUNCTUATION('->')
4:9: IDENTIFIER('keys')
4:13: PUNCTUATION('[')
4:14: IDENTIFIER('i')
4:15: PUNCTUATION(']')
4:17: PUNCTUATION('=')
4:19: IDENTIFIER('s2')
4:21: PUNCTUATION('->')
4:23: IDENTIFIER('keys')
4:27: PUNCTUATION('[')
4:28: IDENTIFIER('j')
4:29: PUNCTUATION(']')
4:30: PUNCTUATION(';')
5:5: IDENTIFIER('if')
5:8: PUNCTUATION('(')
5:9: IDENTIFIER('s1')
5:11: PUNCTUATION('->')
5:13: IDENTIFIER('values')
5:20: PUNCTUATION('!=')
5:23: IDENTIFIER('NULL')
5:27: PUNCTUATION(')')
6:9: IDENTIFIER('s1')
6:11: PUNCTUATION('->')
6:13: IDENTIFIER('values')
6:19: PUNCTUATION('[')
6:20: IDENTIFIER('i')
6:21: PUNCTUATION(']')
6:23: PUNCTUATION('=')
6:25: IDENTIFIER('s2')
6:27: PUNCTUATION('->')
6:29: IDENTIFIER('values')
6:35: PUNCTUATION('[')
6:36: IDENTIFIER('j')
6:37: PUNCTUATION(']')
6:38: PUNCTUATION(';')
7:1: PUNCTUATION('}')
```

For fun, you can output the tokens on separate lines, but at their correct
horizontal positions...
```
$ ack -B1 -A5 "^sortslice_copy\(" ~/repos/cpython/Objects/listobject.c | python -m loosey.pplex --tree -
Py_LOCAL_INLINE
               (
                void
                    )
sortslice_copy
              (
               sortslice
                         *
                          s1
                            ,
                              Py_ssize_t
                                         i
                                          ,
                                            sortslice
                                                      *
                                                       s2
                                                         ,
                                                           Py_ssize_t
                                                                      j
                                                                       )
{
    s1
      ->
        keys
            [
             i
              ]
                =
                  s2
                    ->
                      keys
                          [
                           j
                            ]
                             ;
    if
       (
        s1
          ->
            values
                   !=
                      NULL
                          )
        s1
          ->
            values
                  [
                   i
                    ]
                      =
                        s2
                          ->
                            values
                                  [
                                   j
                                    ]
                                     ;
}
```
