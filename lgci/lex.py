"""

    This module's regexes are based on an ANSI C grammar in Lex format which I
    found on the Internet:
    https://www.lysator.liu.se/c/ANSI-C-grammar-l.html

        In 1985, Jeff Lee published this Lex specification together with a Yacc
        grammar for the April 30, 1985 ANSI C draft.
        Tom Stockfisch reposted both to net.sources in 1987; that original, as
        mentioned in the answer to question 17.25 of the comp.lang.c FAQ, can be
        ftp'ed from ftp.uu.net, file usenet/net.sources/ansi.c.grammar.Z.
        I intend to keep this version as close to the current C Standard grammar
        as possible; please let me know if you discover discrepancies.

        Jutta Degener, 1995

    ...thanks, Jutta! :)
    - BAG, 2026

"""

import re
from typing import NamedTuple

class Token(NamedTuple):
    filename: str
    row: int
    col: int
    toktype: str
    value: str = None
    exponent: str = None
    suffix: str = None

    def pprint(self):
        parts = [self.toktype]
        if self.value:
            parts.append(f'val={self.value!r}')
        if self.exponent:
            parts.append(f'exp={self.exponent!r}')
        if self.suffix:
            parts.append(f'suf={self.suffix!r}')
        print(f"{self.filename}:{self.row}:{self.col}: " + ' '.join(parts))

KEYWORDS = frozenset((
    'auto',
    'break',
    'case',
    'char',
    'const',
    'continue',
    'default',
    'do',
    'double',
    'else',
    'enum',
    'extern',
    'float',
    'for',
    'goto',
    'if',
    'int',
    'long',
    'register',
    'return',
    'short',
    'signed',
    'sizeof',
    'static',
    'struct',
    'switch',
    'typedef',
    'union',
    'unsigned',
    'void',
    'volatile',
    'while',
))

# NOTE: the order matters, e.g. '++' must come before '+'
PUNCTUATION = (
    '...',
    '>>=',
    '<<=',
    '+=',
    '-=',
    '*=',
    '/=',
    '%=',
    '&=',
    '^=',
    '|=',
    '>>',
    '<<',
    '++',
    '--',
    '->',
    '&&',
    '||',
    '<=',
    '>=',
    '==',
    '!=',
    ';',
    '{',
    '}',
    ',',
    ':',
    '=',
    '(',
    ')',
    '[',
    ']',
    '.',
    '&',
    '!',
    '~',
    '-',
    '+',
    '*',
    '/',
    '%',
    '<',
    '>',
    '^',
    '|',
    '?',
    '##',
    '#',
)

EXPONENT      = r'[Ee](?P<EXPONENT>[+-]?[0-9]+)'
FLOAT_SUFFIX  = r'(?P<SUFFIX>[fFlL])'
INT_SUFFIX    = r'(?P<SUFFIX>[uUlL]*)'

TOKEN_PATTERNS = {
    'WHITESPACE'  : r'[ \t]+',

    # The #include directive is the only place where a string lives inside
    # of "pointy brackets", so it's a special case for the tokenizer
    'INCLUDE'     : r'#[ \t]*include[ \t]*(?P<VALUE>".*"|<.*>)',

    # When defining a macro, there must be no space between the macro name
    # and the opening parenthesis, so it's a special case for the tokenizer
    'DEFMACRO'    : r'#[ \t]*define[ \t]*(?P<VALUE>[a-zA-Z_][0-9a-zA-Z_]*)(?=\()',

    'DIRECTIVE'   : r'#[ \t]*(?P<VALUE>[a-zA-Z_][0-9a-zA-Z_]*)',
    'COMMENT'     : r'//(?P<VALUE>.*)',
    'BLOCKCOMMENT': r'/\*(?P<VALUE>.*?)(?:\*/|$)',
    'HEX'         : r'0[xX](?P<VALUE>[a-fA-F0-9]+)' + INT_SUFFIX,
    'OCT'         : r'0(?P<VALUE>[0-9]+)' + INT_SUFFIX,
    'DEC'         : r'(?P<VALUE>[0-9]+)' + INT_SUFFIX,

    # NOTE: all of these patterns will result in a Token.toktype of 'FLOAT'
    'FLOAT1'      : r'(?P<VALUE>[0-9]+)' + EXPONENT + f'{FLOAT_SUFFIX}?',
    'FLOAT2'      : r'(?P<VALUE>[0-9]*\.[0-9]+)' + f'{EXPONENT}?' + f'{FLOAT_SUFFIX}?',
    'FLOAT3'      : r'(?P<VALUE>[0-9]+\.[0-9]*)' + f'{EXPONENT}?' + f'{FLOAT_SUFFIX}?',

    'CHAR'        : r"L?'(?P<VALUE>(?:\\.|[^\\'])+)'",
    'STRING'      : r'L?"(?P<VALUE>(?:\\.|[^\\"])*)"',

    # NOTE: identifier or keyword, see KEYWORDS
    'IDENTIFIER'  : r'[a-zA-Z_][0-9a-zA-Z_]*',

    'PUNCTUATION' : '|'.join(map(re.escape, PUNCTUATION)),
    'BADCHAR'     : '.',
}

TOKEN_REGEXES = {k: re.compile(v) for k, v in TOKEN_PATTERNS.items()}

# Using one giant regex with .finditer() instead of doing .match() ourselves
# with multiple small ones: this approach hopefully lets us execute less slow
# Python code and more fast C code, and I believe it lets us allocate fewer
# Python strings, since AFAIK there's no way to pass a start location to
# .match().
TOKEN_REGEX = re.compile('|'.join(
    f'(?P<{toktype}>' + pattern.replace('?P<', f'?P<{toktype}_') + ')'
    for toktype, pattern in TOKEN_PATTERNS.items()))

def tokenize(lines, filename: str = '<fakefile>', initial_row=1):
    r"""

        >>> for token in tokenize(r'''
        ...     int main() {
        ...         printf("Hello \"world\"!");
        ...     }
        ... '''): token.pprint()
        <fakefile>:1:1: EOL
        <fakefile>:2:5: IDENTIFIER val='int'
        <fakefile>:2:9: IDENTIFIER val='main'
        <fakefile>:2:13: PUNCTUATION val='('
        <fakefile>:2:14: PUNCTUATION val=')'
        <fakefile>:2:16: PUNCTUATION val='{'
        <fakefile>:2:17: EOL
        <fakefile>:3:9: IDENTIFIER val='printf'
        <fakefile>:3:15: PUNCTUATION val='('
        <fakefile>:3:16: STRING val='Hello \\"world\\"!'
        <fakefile>:3:34: PUNCTUATION val=')'
        <fakefile>:3:35: PUNCTUATION val=';'
        <fakefile>:3:36: EOL
        <fakefile>:4:5: PUNCTUATION val='}'
        <fakefile>:4:6: EOL

        Lines separated by pairs (backslash, newline) are "pasted" together
        into a single line, i.e. an EOL token isn't emitted between them:
        >>> for token in tokenize(r'''
        ...     line 1 \
        ...     line 2
        ... '''): token.pprint()
        <fakefile>:1:1: EOL
        <fakefile>:2:5: IDENTIFIER val='line'
        <fakefile>:2:10: DEC val='1'
        <fakefile>:3:5: IDENTIFIER val='line'
        <fakefile>:3:10: DEC val='2'
        <fakefile>:3:11: EOL

        Multiline comments are handled:
        >>> for token in tokenize(r'''
        ...     x /* some comment */ y /* more
        ...     and more\
        ...     comment */ z /* trailing off...
        ...     oh no...
        ... '''): token.pprint()
        <fakefile>:1:1: EOL
        <fakefile>:2:5: IDENTIFIER val='x'
        <fakefile>:2:7: COMMENT val=' some comment '
        <fakefile>:2:26: IDENTIFIER val='y'
        <fakefile>:2:28: COMMENT val=' more\n    and more\n    comment '
        <fakefile>:4:16: IDENTIFIER val='z'
        <fakefile>:4:18: COMMENT val=' trailing off...\n    oh no...'

        Preprocessor directives are handled:
        >>> for token in tokenize(r'''
        ...     #include <stdio.h>
        ...     #define PASTE(X, Y) X ## Y
        ...     #define SIZE 64
        ... '''): token.pprint()
        <fakefile>:1:1: EOL
        <fakefile>:2:5: INCLUDE val='<stdio.h>'
        <fakefile>:2:23: EOL
        <fakefile>:3:5: DEFMACRO val='PASTE'
        <fakefile>:3:18: PUNCTUATION val='('
        <fakefile>:3:19: IDENTIFIER val='X'
        <fakefile>:3:20: PUNCTUATION val=','
        <fakefile>:3:22: IDENTIFIER val='Y'
        <fakefile>:3:23: PUNCTUATION val=')'
        <fakefile>:3:25: IDENTIFIER val='X'
        <fakefile>:3:27: PUNCTUATION val='##'
        <fakefile>:3:30: IDENTIFIER val='Y'
        <fakefile>:3:31: EOL
        <fakefile>:4:5: DIRECTIVE val='define'
        <fakefile>:4:13: IDENTIFIER val='SIZE'
        <fakefile>:4:18: DEC val='64'
        <fakefile>:4:20: EOL

    """

    # Support people passing us entire strings by accident, why not...
    if isinstance(lines, str):
        lines = lines.splitlines()

    line_i = 0
    def iter_lines():
        nonlocal line_i
        for line in lines:
            # Strip newlines so we can iterate over the output of open()
            yield line.strip('\n')
            line_i += 1
    it = iter_lines()

    block_comment_token = None

    # Let's begin!
    while True:
        line = next(it, None)
        if line is None:
            break

        # Paste together lines joined with backslash + newline.
        # Actually, we don't really bother pasting the lines together, because
        # that behaviour is crazy!.. e.g. you can have a token which starts on
        # on one line, and ends on another.
        # Instead, if a line ends with a backslash, we just chop that off, and
        # remember not to emit an EOL token.
        pasted = line.endswith('\\')
        if pasted:
            line = line[:-1]

        # If we're in the middle of a block comment, figure out if it ends
        # on this line, etc
        block_comment_chopped = 0
        if block_comment_token is not None:
            end_index = line.find('*/')
            if end_index < 0:
                # The block comment continues for this entire line!
                block_comment_token = block_comment_token._replace(
                    value=block_comment_token.value + '\n' + line)
                continue
            else:
                # The block comment ends in this line, so chop it off,
                # then process all remaining tokens in the line
                block_comment_token = block_comment_token._replace(
                    value=block_comment_token.value + '\n' + line[:end_index])
                yield block_comment_token
                line = line[end_index + 2:]
                block_comment_chopped = end_index + 2
                block_comment_token = None

        # Parse tokens from this line
        for match in TOKEN_REGEX.finditer(line):
            groups = match.groupdict()
            toktype = next(toktype for toktype in TOKEN_PATTERNS
                if groups[toktype] is not None)

            if toktype in ('IDENTIFIER', 'PUNCTUATION', 'BADCHAR'):
                value = match.group()
            else:
                value = groups.get(f'{toktype}_VALUE')

            is_block_comment = False
            if toktype == 'WHITESPACE':
                continue
            elif toktype.startswith('FLOAT'):
                # We have separate FLOAT1, FLOAT2, FLOAT3 patterns, because
                # of their complexity, but they all represent the same token
                # type, so combine them here
                toktype = 'FLOAT'
            elif toktype == 'BLOCKCOMMENT':
                is_block_comment = True
                toktype = 'COMMENT'

            row = initial_row + line_i
            col = 1 + block_comment_chopped + match.start()

            token = Token(
                filename=filename,
                row=row,
                col=col,
                toktype=toktype,
                value=value,
                exponent=groups.get(f'{toktype}_EXPONENT'),
                suffix=groups.get(f'{toktype}_SUFFIX'),
            )

            if is_block_comment and not match.group().endswith('*/'):
                # We've found a block comment which doesn't end on this line!..
                block_comment_token = token
            else:
                yield token

        # Maybe emit an EOL token?..
        if not pasted and block_comment_token is None:
            yield Token(
                filename=filename,
                row=initial_row + line_i,
                col=1 + block_comment_chopped + len(line),
                toktype='EOL',
            )

    # If a block comment is unterminated, that's fine, just make sure we
    # remember to emit it!
    if block_comment_token is not None:
        yield block_comment_token
