/*

    I downloaded this from: https://www.bellard.org/otcc/
    I mostly just added doctests, but in some cases I factored out a function
    or macro so that I could use or test it directly, e.g. init() and
    MAGIC_TOKEN_STRING.

    - BAG, 2026

*/
/*
  Obfuscated Tiny C Compiler

  Copyright (C) 2001-2003 Fabrice Bellard

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product and its documentation 
     *is* required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
/*

    Note, the supported subset of C, according to https://www.bellard.org/otcc/, is:
    * Expressions:
      * binary operators, by decreasing priority order: '*' '/' '%', '+' '-', '>>' '<<',
        '<' '<=' '>' '>=', '==' '!=', '&', '^', '|', '=', '&&', '||'.
      * '&&' and '||' have the same semantics as C : left to right evaluation and early exit.
      * Parenthesis are supported.
      * Unary operators: '&', '*' (pointer indirection), '-' (negation), '+', '!', '~',
        post fixed '++' and '--'.
      * Pointer indirection ('*') only works with explicit cast to 'char *', 'int *'
        or 'int (*)()' (function pointer).
      * '++', '--', and unary '&' can only be used with variable lvalue (left value).
      * '=' can only be used with variable or '*' (pointer indirection) lvalue.
      * Function calls are supported with standard i386 calling convention.
        Function pointers are supported with explicit cast.
        Functions can be used before being declared.
    * Types: only signed integer ('int') variables and functions can be declared.
      Variables cannot be initialized in declarations.
      Only old K&R function declarations are parsed (implicit integer return value
      and no types on arguments).
    * Any function or variable from the libc can be used because OTCC uses the libc
      dynamic linker to resolve undefined symbols.
    * Instructions: blocks ('{' '}') are supported as in C. 'if' and 'else' can be
      used for tests.
      The 'while' and 'for' C constructs are supported for loops.
      'break' can be used to exit loops.
      'return' is used for the return value of a function.
    * Identifiers are parsed the same way as C. Local variables are handled, but
      there is no local name space (not a problem if different names are used for
      local and global variables).
    * Numbers can be entered in decimal, hexadecimal ('0x' or '0X' prefix), or
      octal ('0' prefix).
    * '#define' is supported without function like arguments.
      No macro recursion is tolerated. Other preprocessor directives are ignored.
    * C Strings and C character constants are supported. Only '\n', '\"', '\''
      and '\\' escapes are recognized.
    * C Comments can be used (but no C++ comments).
    * No error is displayed if an incorrect program is given.
    * Memory: the code, data, and symbol sizes are limited to 100KB (it can be
      changed in the source code).

    And now, doctests (by BAG)!

    >>> from io import BytesIO
    >>> from loosey.mini import MiniC

    These are the global C variables.
    We list them here so that later on we can set up e.g. watches for
    when their values change.
    >>> globvars = (
    ...     'tok', 'tokc', 'tokl', 'ch', 'vars', 'rsym', 'prog', 'ind',
    ...     'loc', 'glo', 'file', 'sym_stk', 'dstk', 'dptr', 'dch', 'last_id')

    Helper function to create a new MiniC interpreter, using the given input.
    We use a BytesIO which the C code reads from as if it were stdin.
    >>> def new_mini(input: bytes, **kwargs) -> MiniC:
    ...     kwargs.setdefault('handle_errors', True)
    ...     mini = MiniC(**kwargs)
    ...     mini.eval('#include <string.h>')
    ...     mini.eval('#include <ctype.h>')
    ...     mini.eval('#include <stdlib.h>')
    ...     mini.eval_file('examples/bellard/otccn.c')
    ...     file = BytesIO(input)
    ...     mini.set_var('file', file)
    ...     mini.eval('init();')
    ...     return mini

    The function for getting the next character from input is inp():
    >>> mini = new_mini(b'hi!')
    >>> for i in range(3):
    ...     mini.eval('inp(); putchar(ch);')
    hi!

    If `dptr` and `dch` are set up, inp() takes its input from a macro
    definition instead of the input file.
    Macros can't refer to each other: each macro just stores a string of
    characters to be used directly as input.
    The end of a macro definition is indicated by a sentinal character
    value, TAG_MACRO:
    >>> mini = new_mini(b'123')
    >>> mini.eval("int dptr[] = {'a', 'b', 'c', TAG_MACRO}; dch = '/';")
    >>> for i in range(7):
    ...     mini.eval('inp(); putchar(ch);')
    abc/123

    Let's see what happens when we try to get a token.
    We'll attempt to parse the expression '12 + 34'.
    >>> mini = new_mini(b'12 + 34')
    >>> mini.watch_vars(*globvars)
    >>> mini.debug_func_calls = 1
    >>> mini.add_debug_func_filter(lambda func:
    ...     func.match.token.filename.endswith('otccn.c'))

    Now, we call inp() to load the first character of input, and then next()
    to get the first token:
    >>> mini.eval('inp(); next();')
    Calling: inp
      Watched ch change to: 49
    Returning from: inp
    Calling: next
      Watched tokl change to: 0
      Watched tok change to: 49
      Calling: isid
      Returning from: isid
      Calling: pdef
        Watched dstk change to: Pointer(-49..99949, fixed=True)
        Watched dstk[0] change to: 32
      Returning from: pdef
      Watched last_id change to: Pointer(-49..99949, fixed=True)
      Calling: isid
      Returning from: isid
      Calling: pdef
        Watched dstk change to: Pointer(-50..99948, fixed=True)
      Returning from: pdef
      Calling: inp
        Watched ch change to: 50
      Returning from: inp
      Calling: isid
      Returning from: isid
      Calling: pdef
        Watched dstk change to: Pointer(-51..99947, fixed=True)
      Returning from: pdef
      Calling: inp
        Watched ch change to: 32
      Returning from: inp
      Calling: isid
      Returning from: isid
      Watched tokc change to: 12
      Watched tok change to: 2
    Returning from: next

    We have successfully parsed a token: the number 12!
    The token type is in `tok`, and the token value is in `tokc`.
    The token types are defined by some macros with a 'TOK_' prefix.
    >>> tok = mini.eval('tok')
    >>> tok
    2
    >>> toktypes = {mini.eval(k): k for k in mini.pp.macros
    ...     if k.startswith('TOK_')}
    >>> toktypes[tok]
    'TOK_NUM'
    >>> mini.eval('tokc')
    12

    Notice how our token, "12", now shows up on the end of dstk, which a
    comment in the original code says is the "define stack":
    >>> dstk = mini.eval('dstk')
    >>> dstk
    Pointer(-51..99947, fixed=True)
    >>> (dstk - 51).as_c_string()
    b' int if else while break return for define main  12'

    Remember, the input was '12 + 34'.
    Let's turn off a lot of the debugging stuff, and try to get the next
    two tokens, '+' and '34'.
    Here's how we parse the '+'. Ready?..
    >>> mini.eval('next();')
    Calling: next
      Calling: inp
        Watched ch change to: 43
      Returning from: inp
      Watched tokl change to: 0
      Watched tok change to: 43
      Calling: isid
      Returning from: isid
      Calling: inp
        Watched ch change to: 32
      Returning from: inp
      Calling: magic
        Watched tokc change to: 0
        Watched tokl change to: -63
        Watched tokc change to: 1
        Watched tokl change to: 11
        Watched tokc change to: 0
        Watched tokl change to: -61
        Watched tokc change to: 3
        Watched tokl change to: -1
        Watched tokc change to: 255
        Watched tokl change to: 11
        Watched tokc change to: 0
        Watched tokl change to: -16
        Watched tokc change to: 48
        Watched tokl change to: -38
        Watched tokc change to: 3098
        Watched tokl change to: -4
        Watched tokc change to: 198332
        Watched tokl change to: -49
        Watched tokc change to: 12693263
        Watched tokl change to: 1
        Watched tokc change to: 0
        Watched tokl change to: -61
        Watched tokc change to: 3
        Watched tokl change to: -7
        Watched tokc change to: 249
        Watched tokl change to: -3
        Watched tokc change to: 15997
        Watched tokl change to: -7
        Watched tokc change to: 1023865
        Watched tokl change to: -26
        Watched tokc change to: 65527398
        Watched tokl change to: -47
        Watched tokc change to: 4193753489
        Watched tokl change to: 1
        Watched tokc change to: 0
        Watched tokl change to: -61
        Watched tokc change to: 3
        Watched tokl change to: -7
        Watched tokc change to: 249
        Watched tokl change to: -3
        Watched tokc change to: 15997
        Watched tokl change to: -7
        Watched tokc change to: 1023865
        Watched tokl change to: -26
        Watched tokc change to: 65527398
        Watched tokl change to: -47
        Watched tokc change to: 4193753489
        Watched tokl change to: 1
        Watched tokc change to: 0
        Watched tokl change to: -52
        Watched tokc change to: 12
        Watched tokl change to: -32
        Watched tokc change to: 800
        Watched tokl change to: -63
        Watched tokc change to: 51201
        Watched tokl change to: 2
      Returning from: magic
    Returning from: next

    ...wow. Was that what you expected?
    Something crazy is going on in the magic() function.
    First of all, notice how early on, `ch` and then `tok` are set to 43.
    That's the '+' character:
    >>> ord('+')
    43

    We then see an incredible dance between `tokc` and `tokl`.
    If you look in the magic() function, you will see it making use of this
    strange string literal:
    >>> mini.eval('MAGIC_TOKEN_STRING')
    "++#m--%am*@R<^1c/@%[_[H3c%@%[_[H3c+@.B#d-@%:_^BKd<<Z/03...

    And magic() largely consists of this fancy while-loop:

        t = MAGIC_TOKEN_STRING;
        while (l = *(char *)t++) {
            a = *(char *)t++;
            tokc = 0;
            while ((tokl = *(char *)t++ - 'b') < 0)
                tokc = tokc * 64 + tokl + 64;
            if (l == tok & (a == ch | a == '@')) {
                // We exit the while-loop!..

    ...so it looks like information about the various operators is encoded
    in the magic string, somehow...
    TODO: investigate that!

*/
#ifndef TINY
#include <stdarg.h>
#endif
#include <stdio.h>

/* vars: value of variables 
   loc : local variable index
   glo : global variable index
   ind : output code ptr
   rsym: return symbol
   prog: output code
   dstk: define stack
   dptr, dch: macro state
*/
int tok, tokc, tokl, ch, vars, rsym, prog, ind, loc, glo, file, sym_stk, dstk, dptr, dch, last_id;

#define ALLOC_SIZE 99999

#define MAGIC_TOKEN_STRING "++#m--%am*@R<^1c/@%[_[H3c%@%[_[H3c+@.B#d-@%:_^BKd<<Z/03e>>`/03e<=0f>=/f<@.f>@1f==&g!=\'g&&k||#l&@.BCh^@.BSi|@.B+j~@/%Yd!@&d*@b"

/* depends on the init string (i.e. MAGIC_TOKEN_STRING?.. - BAG) */
#define TOK_STR_SIZE 48
#define TOK_IDENT    0x100
#define TOK_INT      0x100
#define TOK_IF       0x120
#define TOK_ELSE     0x138
#define TOK_WHILE    0x160
#define TOK_BREAK    0x190
#define TOK_RETURN   0x1c0
#define TOK_FOR      0x1f8
#define TOK_DEFINE   0x218
#define TOK_MAIN     0x250

#define TOK_DUMMY   1
#define TOK_NUM     2

#define LOCAL   0x200

#define SYM_FORWARD 0
#define SYM_DEFINE  1

/* tokens in string heap */
#define TAG_TOK    ' '
#define TAG_MACRO  2

pdef(t)
{
    *(char *)dstk++ = t;
}

inp()
{
    if (dptr) {
        ch = *(char *)dptr++;
        if (ch == TAG_MACRO) {
            dptr = 0;
            ch = dch;
        }
    } else
        ch = fgetc(file);
    /*    printf("ch=%c 0x%x\n", ch, ch); */
}

isid()
{
    return isalnum(ch) | ch == '_';
}

/* read a character constant */
getq()
{
    if (ch == '\\') {
        inp();
        if (ch == 'n')
            ch = '\n';
    }
}

magic()
{
    int t, l, a;

    t = MAGIC_TOKEN_STRING;
    while (l = *(char *)t++) {
        a = *(char *)t++;
        tokc = 0;
        while ((tokl = *(char *)t++ - 'b') < 0)
            tokc = tokc * 64 + tokl + 64;
        if (l == tok & (a == ch | a == '@')) {
#if 0
            printf("%c%c -> tokl=%d tokc=0x%x\n",
                   l, a, tokl, tokc);
#endif
            if (a == ch) {
                inp();
                tok = TOK_DUMMY; /* dummy token for double tokens */
            }
            break;
        }
    }
}

next()
{
    while (isspace(ch) | ch == '#') {
        if (ch == '#') {
            inp();
            next();
            if (tok == TOK_DEFINE) {
                next();
                pdef(TAG_TOK); /* fill last ident tag */
                *(int *)tok = SYM_DEFINE;
                *(int *)(tok + 4) = dstk; /* define stack */
            }
            /* well we always save the values ! */
            while (ch != '\n') {
                pdef(ch);
                inp();
            }
            pdef(ch);
            pdef(TAG_MACRO);
        }
        inp();
    }
    tokl = 0;
    tok = ch;
    /* encode identifiers & numbers */
    if (isid()) {
        pdef(TAG_TOK);
        last_id = dstk;
        while (isid()) {
            pdef(ch);
            inp();
        }
        if (isdigit(tok)) {
            tokc = strtol(last_id, 0, 0);
            tok = TOK_NUM;
        } else {
            *(char *)dstk = TAG_TOK; /* no need to mark end of string (we
                                        suppose data is initied to zero */
            tok = strstr(sym_stk, last_id - 1) - sym_stk;
            *(char *)dstk = 0;   /* mark real end of ident for dlsym() */
            tok = tok * 8 + TOK_IDENT;
            if (tok > TOK_DEFINE) {
                tok = vars + tok;
                /*        printf("tok=%s %x\n", last_id, tok); */
                /* define handling */
                if (*(int *)tok == SYM_DEFINE) {
                    dptr = *(int *)(tok + 4);
                    dch = ch;
                    inp();
                    next();
                }
            }
        }
    } else {
        inp();
        if (tok == '\'') {
            tok = TOK_NUM;
            getq();
            tokc = ch;
            inp();
            inp();
        } else if (tok == '/' & ch == '*') {
            inp();
            while (ch) {
                while (ch != '*')
                    inp();
                inp();
                if (ch == '/')
                    ch = 0;
            }
            inp();
            next();
        } else {
            magic();
        }
    }
#if 0
    {
        int p;

        printf("tok=0x%x ", tok);
        if (tok >= TOK_IDENT) {
            printf("'");
            if (tok > TOK_DEFINE) 
                p = sym_stk + 1 + (tok - vars - TOK_IDENT) / 8;
            else
                p = sym_stk + 1 + (tok - TOK_IDENT) / 8;
            while (*(char *)p != TAG_TOK && *(char *)p)
                printf("%c", *(char *)p++);
            printf("'\n");
        } else if (tok == TOK_NUM) {
            printf("%d\n", tokc);
        } else {
            printf("'%c'\n", tok);
        }
    }
#endif
}

#ifdef TINY
#define skip(c) next()
#else

void error(char *fmt,...)
{
    va_list ap;

    va_start(ap, fmt);
    fprintf(stderr, "%d: ", ftell((FILE *)file));
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
    va_end(ap);
}

void skip(c)
{
    if (tok != c) {
        error("'%c' expected", c);
    }
    next();
}

#endif

o(n)
{
    /* cannot use unsigned, so we must do a hack */
    while (n && n != -1) {
        *(char *)ind++ = n;
        n = n >> 8;
    }
}

/* output a symbol and patch all calls to it */
gsym(t)
{
    int n;
    while (t) {
        n = *(int *)t; /* next value */
        *(int *)t = ind - t - 4;
        t = n;
    }
}

/* psym is used to put an instruction with a data field which is a
   reference to a symbol. It is in fact the same as oad ! */
#define psym oad

/* instruction + address */
oad(n, t)
{
    o(n);
    *(int *)ind = t;
    t = ind;
    ind = ind + 4;
    return t;
}

/* load immediate value */
li(t)
{
    oad(0xb8, t); /* mov $xx, %eax */
}

gjmp(t)
{
    return psym(0xe9, t);
}

/* l = 0: je, l == 1: jne */
gtst(l, t)
{
    o(0x0fc085); /* test %eax, %eax, je/jne xxx */
    return psym(0x84 + l, t);
}

gcmp(t)
{
    o(0xc139); /* cmp %eax,%ecx */
    li(0);
    o(0x0f); /* setxx %al */
    o(t + 0x90);
    o(0xc0);
}

gmov(l, t)
{
    o(l + 0x83);
    oad((t < LOCAL) << 7 | 5, t);
}

/* l is one if '=' parsing wanted (quick hack) */
unary(l)
{
    int n, t, a, c;

    n = 1; /* type of expression 0 = forward, 1 = value, other =
              lvalue */
    if (tok == '\"') {
        li(glo);
        while (ch != '\"') {
            getq();
            *(char *)glo++ = ch;
            inp();
        }
        *(char *)glo = 0;
        glo = glo + 4 & -4; /* align heap */
        inp();
        next();
    } else {
        c = tokl;
        a = tokc;
        t = tok;
        next();
        if (t == TOK_NUM) {
            li(a);
        } else if (c == 2) {
            /* -, +, !, ~ */
            unary(0);
            oad(0xb9, 0); /* movl $0, %ecx */
            if (t == '!')
                gcmp(a);
            else
                o(a);
        } else if (t == '(') {
            expr();
            skip(')');
        } else if (t == '*') {
            /* parse cast */
            skip('(');
            t = tok; /* get type */
            next(); /* skip int/char/void */
            next(); /* skip '*' or '(' */
            if (tok == '*') {
                /* function type */
                skip('*');
                skip(')');
                skip('(');
                skip(')');
                t = 0;
            }
            skip(')');
            unary(0);
            if (tok == '=') {
                next();
                o(0x50); /* push %eax */
                expr();
                o(0x59); /* pop %ecx */
                o(0x0188 + (t == TOK_INT)); /* movl %eax/%al, (%ecx) */
            } else if (t) {
                if (t == TOK_INT)
                    o(0x8b); /* mov (%eax), %eax */
                else 
                    o(0xbe0f); /* movsbl (%eax), %eax */
                ind++; /* add zero in code */
            }
        } else if (t == '&') {
            gmov(10, *(int *)tok); /* leal EA, %eax */
            next();
        } else {
            n = *(int *)t;
            /* forward reference: try dlsym */
            if (!n)
                n = dlsym(0, last_id);
            if (tok == '=' & l) {
                /* assignment */
                next();
                expr();
                gmov(6, n); /* mov %eax, EA */
            } else if (tok != '(') {
                /* variable */
                gmov(8, n); /* mov EA, %eax */
                if (tokl == 11) {
                    gmov(0, n);
                    o(tokc);
                    next();
                }
            }
        }
    }

    /* function call */
    if (tok == '(') {
        if (n == 1)
            o(0x50); /* push %eax */

        /* push args and invert order */
        a = oad(0xec81, 0); /* sub $xxx, %esp */
        next();
        l = 0;
        while(tok != ')') {
            expr();
            oad(0x248489, l); /* movl %eax, xxx(%esp) */
            if (tok == ',')
                next();
            l = l + 4;
        }
        *(int *)a = l;
        next();
        if (!n) {
            /* forward reference */
            t = t + 4;
            *(int *)t = psym(0xe8, *(int *)t);
        } else if (n == 1) {
            oad(0x2494ff, l); /* call *xxx(%esp) */
            l = l + 4;
        } else {
            oad(0xe8, n - ind - 5); /* call xxx */
        }
        if (l)
            oad(0xc481, l); /* add $xxx, %esp */
    }
}

sum(l)
{
    int t, n, a;

    if (l-- == 1)
        unary(1);
    else {
        sum(l);
        a = 0;
        while (l == tokl) {
            n = tok;
            t = tokc;
            next();

            if (l > 8) {
                a = gtst(t, a); /* && and || output code generation */
                sum(l);
            } else {
                o(0x50); /* push %eax */
                sum(l);
                o(0x59); /* pop %ecx */
                
                if (l == 4 | l == 5) {
                    gcmp(t);
                } else {
                    o(t);
                    if (n == '%')
                        o(0x92); /* xchg %edx, %eax */
                }
            }
        }
        /* && and || output code generation */
        if (a && l > 8) {
            a = gtst(t, a);
            li(t ^ 1);
            gjmp(5); /* jmp $ + 5 */
            gsym(a);
            li(t);
        }
    }
}

expr()
{
    sum(11);
}


test_expr()
{
    expr();
    return gtst(0, 0);
}

block(l)
{
    int a, n, t;

    if (tok == TOK_IF) {
        next();
        skip('(');
        a = test_expr();
        skip(')');
        block(l);
        if (tok == TOK_ELSE) {
            next();
            n = gjmp(0); /* jmp */
            gsym(a);
            block(l);
            gsym(n); /* patch else jmp */
        } else {
            gsym(a); /* patch if test */
        }
    } else if (tok == TOK_WHILE | tok == TOK_FOR) {
        t = tok;
        next();
        skip('(');
        if (t == TOK_WHILE) {
            n = ind;
            a = test_expr();
        } else {
            if (tok != ';')
                expr();
            skip(';');
            n = ind;
            a = 0;
            if (tok != ';')
                a = test_expr();
            skip(';');
            if (tok != ')') {
                t = gjmp(0);
                expr();
                gjmp(n - ind - 5);
                gsym(t);
                n = t + 4;
            }
        }
        skip(')');
        block(&a);
        gjmp(n - ind - 5); /* jmp */
        gsym(a);
    } else if (tok == '{') {
        next();
        /* declarations */
        decl(1);
        while(tok != '}')
            block(l);
        next();
    } else {
        if (tok == TOK_RETURN) {
            next();
            if (tok != ';')
                expr();
            rsym = gjmp(rsym); /* jmp */
        } else if (tok == TOK_BREAK) {
            next();
            *(int *)l = gjmp(*(int *)l);
        } else if (tok != ';')
            expr();
        skip(';');
    }
}

/* 'l' is true if local declarations */
decl(l)
{
    int a;

    while (tok == TOK_INT | tok != -1 & !l) {
        if (tok == TOK_INT) {
            next();
            while (tok != ';') {
                if (l) {
                    loc = loc + 4;
                    *(int *)tok = -loc;
                } else {
                    *(int *)tok = glo;
                    glo = glo + 4;
                }
                next();
                if (tok == ',') 
                    next();
            }
            skip(';');
        } else {
            /* patch forward references (XXX: do not work for function
               pointers) */
            gsym(*(int *)(tok + 4));
            /* put function address */
            *(int *)tok = ind;
            next();
            skip('(');
            a = 8;
            while (tok != ')') {
                /* read param name and compute offset */
                *(int *)tok = a;
                a = a + 4;
                next();
                if (tok == ',')
                    next();
            }
            next(); /* skip ')' */
            rsym = loc = 0;
            o(0xe58955); /* push   %ebp, mov %esp, %ebp */
            a = oad(0xec81, 0); /* sub $xxx, %esp */
            block(0);
            gsym(rsym);
            o(0xc3c9); /* leave, ret */
            *(int *)a = loc; /* save local variables */
        }
    }
}

init()
{
    dstk = strcpy(sym_stk = calloc(1, ALLOC_SIZE), 
                  " int if else while break return for define main ") + TOK_STR_SIZE;
    glo = calloc(1, ALLOC_SIZE);
    ind = prog = calloc(1, ALLOC_SIZE);
    vars = calloc(1, ALLOC_SIZE);
}

main(n, t)
{
    file = stdin;
    if (n-- > 1) {
        t = t + 4;
        file = fopen(*(int *)t, "r");
    }
    init();
    inp();
    next();
    decl(0);
#ifdef TEST
    { 
        FILE *f;
        f = fopen(*(char **)(t + 4), "w");
        fwrite((void *)prog, 1, ind - prog, f);
        fclose(f);
        return 0;
    }
#else
    return (*(int (*)())*(int *)(vars + TOK_MAIN)) (n, t);
#endif
}
