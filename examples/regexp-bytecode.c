/*
    NOTE: I downloaded this file (and then modified it, mostly
    just adding doctests) from:
    https://swtch.com/~rsc/regexp/regexp-bytecode.c.txt

    See also this fantastic related paper by Russ Cox:
    "Regular Expression Matching Can Be Simple And Fast"
    Russ Cox
    rsc@swtch.com
    January 2007
    https://swtch.com/~rsc/regexp/regexp1.html

    - BAG, 2026
*/
/*
 * Bytecode machine implementation of Thompson's
 * on-the-fly regular expression compiler.
 *
 * See also Thompson, Ken.  Regular Expression Search Algorithm,
 * Communications of the ACM 11(6) (June 1968), pp. 419-422.
 *
 * Copyright (c) 2004 Jan Burgy.
 * Can be distributed under the MIT license, see bottom of file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

enum    {
    STOP,
    JUMP,
    MATCH,
    BRANCH,
    LPAREN = CHAR_MAX + 1,
    RPAREN,     /* This should  */
    ALTERN,     /* reflect the  */
    CONCAT,     /* precedence   */
    KLEENE      /* rules!   */
};

const char *op_name[] = {"STOP  ", "JUMP  ", "MATCH ", "BRANCH"};
const char *postfix_name[] = {"LPAREN", "RPAREN", "ALTERN", "CONCAT", "KLEENE"};


/* prepare(): converts special characters to enum values, and handles escaping

    >>> from loosey.mini import MiniC; mini = MiniC()
    >>> mini.eval_file('examples/regexp-bytecode.c')
    main()

    >>> mini.eval('dump_prepared(prepare("a(b|c|\\n)*d"))')
     0: 'a'
     1: LPAREN
     2: 'b'
     3: ALTERN
     4: 'c'
     5: ALTERN
     6: '
    '
     7: RPAREN
     8: KLEENE
     9: CONCAT
    10: 'd'
    11: RPAREN

    ...note the trailing RPAREN, which corresponds to end-of-pattern, not
    to a ')' in the input.

    Also note that there is only one CONCAT, corresponding to the
    concatenation of "a(b|c|\\n)*" and "d"; there is none corresponding to
    the concatenation of "a" and "(b|c|\\n)*".
    This is because concatenation is implicit whenever a '(' is encountered.

*/
unsigned char *prepare (const char *src)
{
    unsigned char   escape[CHAR_MAX + 1] = "";
    unsigned char   *dest = malloc (2 * (strlen (src) + 1));
    int c, i, j = 0, concat = 0, nparen = 0;

    escape['a'] = '\a';
    escape['b'] = '\b';
    escape['f'] = '\f';
    escape['n'] = '\n';
    escape['r'] = '\r';
    escape['t'] = '\t';
    escape['v'] = '\v';
    for (i = 0; (c = "\"()*\\|"[i]); i++)
        escape[c] = c;

    for (i = 0; (c = src[i]); i++) {

        switch (c) {

            case '(':
                dest[j++] = LPAREN;
                concat = 0;
                nparen++;
                continue;
            case ')':
                dest[j++] = RPAREN;
                nparen--;
                break;
            case '*':
                dest[j++] = KLEENE;
                break;
            case '|':
                dest[j++] = ALTERN;
                concat = 0;
                continue;
            case '\\':
                c = escape[(int)src[i + 1]];
                c ? i++ : (c = '\\');
            default:
                if (concat)
                    dest[j++] = CONCAT;
                dest[j++] = c;

        }
        concat = 1;
        if (nparen < 0)
            printf ("unbalanced parentheses\n");

    }
    dest[j++] = RPAREN;
    dest[j++] = '\0';

    return  dest;
}

void dump_prepared(const unsigned char *src)
{
    int i, c;
    for (i = 0; (c = src[i]); i++) {
        if (c >= LPAREN) {
            printf ("%2d: %s\n", i, postfix_name[c - LPAREN]);
        } else {
            printf ("%2d: '%c'\n", i, c);
        }
    }
}


/* convert(): converts a regex into a reverse-Polish representation

    >>> from loosey.mini import MiniC; mini = MiniC()
    >>> mini.eval_file('examples/regexp-bytecode.c')
    main()

    >>> mini.eval('dump_prepared(convert("a(b|c)*d"))')
     0: 'a'
     1: 'b'
     2: 'c'
     3: ALTERN
     4: KLEENE
     5: 'd'
     6: CONCAT

    ...note the reverse-Polish (i.e. postfix operator) notation, e.g. "(b|c)"
    has become the sequence 'b', 'c', ALTERN.

    Also note the single CONCAT, despite the regex being composed of 3
    concatenated sub-regexes: "a", "(b|c)*", "d"
    This is because concatenation is implicit whenever a '(' is encountered.
    See also: prepare()

*/
unsigned char *convert (const char *src)
{   /* http://cs.lasierra.edu/~ehwang/cptg454/postfix.pdf */
    unsigned char   stack[BUFSIZ] = "";
    unsigned char   *dest = prepare (src);
    int c, i, j = 0, top = 0;

    stack[top++] = LPAREN;
    for (i = 0; (c = dest[i]); i++) {

        switch (c) {

            case LPAREN:
                stack[top++] = c;
                break;

            case RPAREN:
                while (c <= stack[top - 1])
                    dest[j++] = stack[--top];
                --top;  /* discard LPAREN */
                break;

            case ALTERN:
            case CONCAT:
            case KLEENE:
                while (c <= stack[top - 1])
                    dest[j++] = stack[--top];
                stack[top++] = c;
                break;

            default:
                dest[j++] = c;
                break;

        }

    }
    dest[j++] = '\0';

    return  dest;
}

struct  instr   {
    short   operand;
    short   address;
};

struct instr assemble (short operand, short address)
{
    struct  instr   this;

    this.operand = operand;
    this.address = address;
    return  this;
}

size_t memlen (const unsigned char *s)
{
    const unsigned char *p = s;

    while (*p)
        p++;
    return  p - s;
}

/*

    >>> from loosey.mini import MiniC; mini = MiniC()
    >>> mini.eval_file('examples/regexp-bytecode.c')
    main()

    The compile() function expects to be given the output of convert(),
    which produces a reverse-Polish (i.e. all operators are postfix) encoding
    of its input.
    The output of compile() is an array of compiled instructions:
    >>> code = mini.eval('compile(convert("a(b|c)*d"))')
    >>> for i, instr in code.items():
    ...     print(instr)
    Struct({'operand': 1, 'address': 1})
    Struct({'operand': 2, 'address': 97})
    Struct({'operand': 1, 'address': 10})
    Struct({'operand': 2, 'address': 98})
    Struct({'operand': 1, 'address': 10})
    Struct({'operand': 2, 'address': 99})
    Struct({'operand': 1, 'address': 10})
    Struct({'operand': 3, 'address': 124})
    Struct({'operand': 1, 'address': 5})
    Struct({'operand': 1, 'address': 3})
    Struct({'operand': 3, 'address': 42})
    Struct({'operand': 1, 'address': 7})
    Struct({'operand': 1, 'address': 13})
    Struct({'operand': 2, 'address': 100})
    Struct({'operand': 0, 'address': 14})

    The operands are enum values, and the "addresses" have a different
    meaning for each operand.
    There is a helper function, dump_code(), which produces a human-readable
    representation of the code:
    >>> mini.get_var('dump_code')(code)
     0: JUMP      1
     1: MATCH   'a'
     2: JUMP     10
     3: MATCH   'b'
     4: JUMP     10
     5: MATCH   'c'
     6: JUMP     10
     7: BRANCH  '|'
     8: JUMP      5
     9: JUMP      3
    10: BRANCH  '*'
    11: JUMP      7
    12: JUMP     13
    13: MATCH   'd'

    ...note, it looks to me as if the compilation algorithm could use some
    optimization: we've got an apparently unnecessary JUMP right off the bat,
    it looks like the JUMPs at addresses 9 and 12 can never be reached, etc!..

*/
struct instr *compile (const unsigned char *src)
{
    int i, c, pc = 0, top = 0;
    int stack[BUFSIZ];
    struct  instr   instr, *code = malloc (5 * memlen (src) * sizeof *code / 2);

    for (i = 0; (c = src[i]); i++) {

        switch (c) {

            default:
                stack[top++] = pc;
                instr = assemble (JUMP, pc + 1);
                code[pc++] = instr;
                code[pc++] = assemble (MATCH, c);
                break;

            case CONCAT:
                --top;
                break;

            case KLEENE:
                code[pc++] = assemble (BRANCH, '*');
                code[pc++] = code[stack[top - 1]];
                code[stack[top - 1]] = assemble (JUMP, pc - 2);
                break;

            case ALTERN:
                instr = assemble (JUMP, pc + 4);
                code[pc++] = instr;
                code[pc++] = assemble (BRANCH, '|');
                code[pc++] = code[stack[top - 1]];
                code[pc++] = code[stack[top - 2]];
                code[stack[top - 2]] = assemble (JUMP, pc - 3);
                code[stack[top - 1]] = assemble (JUMP, pc);
                --top;
                break;

        }

    }

    instr = assemble (STOP, pc);
    code[pc++] = instr;

    return  code;
}

struct instr *study (const char *re)
{
    unsigned char   *p = convert (re);
    struct  instr   *q = compile (p);

    if (p) free (p), p = NULL;
    return  q;
}

void dump_code (struct instr *code)
{
    int i, op;

    for (i = 0; (op = code[i].operand); i++)
        printf (op == JUMP ? "%2d: %s  %3d\n" : "%2d: %s  '%c'\n",
                i, op_name[op], code[i].address);
}

/*

    >>> from loosey.mini import MiniC; mini = MiniC()
    >>> mini.eval_file('examples/regexp-bytecode.c')
    main()

    >>> mini.eval(r"""
    ...     void test(const char *re, const char *input) {
    ...         struct instr *code = study(re);
    ...         printf("%s ~ %s == %i\n",
    ...             re, input, execute(code, input));
    ...     }
    ...     test("a(b|c)*d", "ad");
    ...     test("a(b|c)*d", "abccbd");
    ...     test("a(b|c)*d", "adz");
    ...     test("a(b|c)*d", "aFFFd");
    ... """)
    a(b|c)*d ~ ad == 1
    a(b|c)*d ~ abccbd == 1
    a(b|c)*d ~ adz == 0
    a(b|c)*d ~ aFFFd == 0

*/
int execute (struct instr *code, const char *src)
{
    short   i = 0, c = src[i++], pc = 0;
    short   clist[BUFSIZ], cnode = 0, shift = 0;
    short   nlist[BUFSIZ], nnode = 0;

    while (c) {

        switch (code[pc].operand) {

            case STOP:
                break;

            case JUMP:
                pc = code[pc].address;
                continue;

            case MATCH:
                if (c == code[pc].address)
                    nlist[nnode++] = code[pc + 1].address;
                break;

            case BRANCH:
                clist[cnode++] = code[pc + 1].address;
                pc = code[pc + 2].address;
                continue;

        }

        if (shift == cnode) {
            if (!nnode) return 0;
            shift = cnode = 0;
            while (nnode > 0)
                clist[cnode++] = nlist[--nnode];
            c = src[i++];
        }
        pc = clist[shift++];

    }

    /* is any of the current states final? */
    for (i = shift; i < cnode; i++)
        if (code[clist[i]].operand == STOP)
            return  1;

    return  code[pc].operand == STOP;
}

int main_alt (void) {
    // Alternate main() for debugging the output of gcc vs loosey...
    // - BAG, 2026
    const char *re = "a(b|c)*d";
    printf("RE: %s\n", re);
    printf("PREPARED:\n");
    dump_prepared(convert(re));
    printf("COMPILED:\n");
    dump_code(compile(convert(re)));
    return EXIT_SUCCESS;
}

int main (void)
{
    short   i;
    struct  {
        char    *re;
        char    *s;
    } test[] = {
        { "abcdefg",    "abcdefg"     },
        { "(a|b)*a",    "ababababab"  },
        { "(a|b)*a",    "aaaaaaaaba"  },
        { "(a|b)*a",    "aaaaaabac"   },
        { "a(b|c)*d",   "abccbcccd"   },
        { "a(b|c)*d",   "abccbcccde"  },
        { NULL,         NULL          }
    };

    for (i = 0; test[i].re; i++) {

        struct  instr   *this = study (test[i].re);

        printf ("%s %s /%s/\n",
                test[i].s,
                execute (this, test[i].s) ? "~" : "!~",
                test[i].re);

        if (this) free (this), this = NULL;
    }

    return  EXIT_SUCCESS;
}

/*
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall
 * be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
