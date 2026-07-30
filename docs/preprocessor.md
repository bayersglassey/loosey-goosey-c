# The C preprocessor

## Overview

The C language comes with a "preprocessor", which is basically a
separate language.
You really can't use C without it.

Our goal is to play with large C codebases, and to have a C
interpreter which can be used interactively.

We could just call out to a major C compiler's preprocessor, e.g. `gcc`
or `clang`, but that wouldn't work so well for interactive Python use.
So, we've implemented the preprocessor ourselves, in pure Python.

Unfortunately, the C preprocessor is a terrifying beast.
It's a macro system, which operates on tokens (but ones which are a
bit looser than those of C itself), including the ability to create
new tokens by gluing other ones together.
It has function-like macros, which are non-recursive, except that
you can kind of abuse them to almost be recursive.
You can have macros which dynamically glue tokens together to produce
macro calls which are then executed, and other monstrous things.

It's just really nasty.

How did it come to be?
When the original "K & R" version of C was first published, it barely
described the preprocessor.
Each compiler implemented their own half-baked version of it, and then
when the ANSI and C99 standards were written, it was too late: its
behaviour had grown beyond the ken of man, and the standards people
threw up their hands and left it kind of vague.

Here are some good resources for understanding its official behaviour:
* The GNU GCC docs: https://gcc.gnu.org/onlinedocs/cpp/index.html
* The C++ docs: https://en.cppreference.com/c/preprocessor
* Richard Stallman's docs: https://home.cs.colorado.edu/~main/cs1300/doc/gnu/cpp_toc.html
* "Dave Prosser's C Preprocessing Algorithm": https://www.spinellis.gr/blog/20060626/
    * Fascinating and terrifying. I have a math background, so I've
      enjoyed trying to understand this algorithm (see
      notes/cpp.algo.txt), but it's not yet clear to me how to
      implement it reasonably in an imperative language, nor can I
      confirm by looking at e.g. gcc's implementation whether its
      behaviour is really equivalent to this algorithm.

Our implementation doesn't support all of the official behaviour;
instead, we implement a "sane" algorithm which handles 99% of what
people generally actually use.
Since our goal is just to play with high-quality C codebases, like the
Linux kernel, CPython, etc, the hope is that our "sane preprocessor"
will suffice.

Specifically, we definitely don't support these official features:
* Trigraphs
* Using backslash-at-end-of-line to glue together a token which starts
  at the end of one line and ends at the start of the next line, or to
  continue a single-line comment (`// ...`) over multiple lines
* The complete macro call behaviour, with "painting tokens blue", or
  whatever is going on in "Dave Prosser's C Preprocessing Algorithm"
* Macro calls *dynamically* causing "token pasting" or "stringization"
* Any kind of recursion whatsoever
* ...probably some other things I'm forgetting


## Implementation details

Our preprocessor is split into a lexer and the preprocessor proper:
* The lexer consumes text, and produces tokens, one line's worth at a time
* The preprocessor consumes lines of tokens from the lexer, and produces
  ("yields") a stream of tokens

The code lives here:
* The Lexer class lives in [loosey/pplex.py](/src/loosey/pplex.py)
* The Preprocessor class lives in [loosey/pp.py](/src/loosey/pp.py)

The lexer mainly just splits the text into lines, then iterates over each
line, and uses regexes to split it into tokens, discarding whitespace.
It also has some fanciness to handle cases where the C preprocessor allows
multiple lines of input to be considered a single line of output:
* When a line of text ends in a backslash, the backslash and the newline
  which follows it are "deleted", conceptually concatenating the following
  line onto the current one
    * This is absolutely required, because macro definitions (`#define`)
      must live on a single "line", but of course people want multiline
      macro definitions, so they get them by concatenating the lines
      together with backslashes...
* Block comments (`/* ... */`) connect all lines of text they touch


### The algorithms

Some terminology:
* An "object-like" macro is one which doesn't have any parameters,
  e.g. `#define MACRO ...etc...`.
* A "function-like" macro is one which does have parameters, e.g.
  `#define MACRO(X, Y) ...etc...`.

Here is the preprocessor's algorithm:
* You pass it a line's worth of tokens (produced by the lexer)
    * Comments are stripped
    * If the line is a directive, it's handled
        * `#include` processes a file, **yield**ing its tokens
        * `#if`, `#elif`, `#endif`, etc: these push or pop from the
          if-stack, and turn "skip mode" on and off
        * `#define`, `#undef`: create and destroy macros
        * `#warning`, `#error`: one outputs a message, the other raises
          an error
        * Other directives, e.g. `#line`, `#pragma`, etc, are currently
          ignored
    * Otherwise, if "skip mode" is active (i.e. we're inside an #if
      block whose condition was false), ignore the line
    * Otherwise, **expand** the line (which is a token sequence, see
      below), **yield**ing tokens

What it means to "**expand** a token sequence":
* For each token in the line,
    * If we're currently parsing a macro call, hand off control to
      the **macro call parser** (see below)
        * If it consumes all tokens and asks for more input,
          do nothing; we're done processing the current line, and
          macro call parsing will continue when we're given another
          line to process
        * If it decided that this isn't a call,
            * If the macro is function-like, **yield** its name
            * Otherwise, **expand** the macro (see below)
        * If it decided that this was a call,
            * Get the param values from the macro call parser
            * Update bound param values
            * **Expand** the macro (see below)
            * Restore bound param values
    * Otherwise, do one of the following:
        * If token is `__FILE__` or `__LINE__`, **yield** a token
          consisting of the current filename or line number
        * If token is `#`, do "stringizing"
            * See: https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html
        * If *current* token is `##`, that's an error!
        * If *next* token is `##`, do "token pasting", a.k.a. "concatenation"
            * See: https://gcc.gnu.org/onlinedocs/cpp/Concatenation.html
        * If token is a bound macro parameter, **expand** the
          corresponding token sequence
        * If token is a macro name, and that macro is not in the
          macro expand stack,
            * If macro is function-like, start the **macro call parser**
              (see below), but don't hand off control to it yet
            * Otherwise, **expand** the macro
        * Otherwise, **yield** the token as-is

What it means to "**expand** a macro":
* Push the macro's name onto the macro expand stack
* **Expand** the macro's body (which is a token sequence, see above)
* Pop the macro's name from the macro expand stack

The "**macro call parser**" is like a function which "pauses" itself
whenever it runs out of input tokens, and can then be "unpaused" by
the preprocessor once there are more input tokens.
Its inputs are the macro which might be being called, and an input token
stream.
We need it in order to support macro calls which extend over multiple
lines, e.g.
```
SOME_MACRO(
    "hello",
    1, 2
)
```

...or even:
```
SOME_MACRO
(
    "hello",
    1, 2
)
```

The **macro call parser**'s logic (which can be paused anytime it tries
to get next token) is essentially:
* If next token is not `(`, **return**, saying "this wasn't a call"
* Otherwise, set "parenthesis depth" to 1
* Start a new "param value", i.e. the token sequence to be used as
  the value for the macro's first parameter
* Loop forever (until we **return**):
    * If next token is `(`, consume it & increment parenthesis depth
    * If next token is `)`, decrement parenthesis depth
        * If parenthesis depth is 0, **return**, saying "this was a call",
          and including the param values we parsed
    * If next token is `,` and parenthesis depth is 1, and the current
      macro parameter is not `__VA_ARGS__`,
        * The current param value is complete, so start a new one
          for the next macro parameter
    * Otherwise, append token to current param value
