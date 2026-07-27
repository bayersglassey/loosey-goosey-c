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
import sys
from typing import NamedTuple, Iterable, Iterator, Optional


class Token(NamedTuple):
    toktype: str
    filename: str
    row: int = 1
    col: int = 1
    value: str = ''

    def location(self) -> str:
        return f'{self.filename}:{self.row}:{self.col}'

    def prettystring(self) -> str:
        return f"{self.toktype}({self.value!r})"

    def pprint(self, *, file=None):
        print(f"{self.location()}: {self.prettystring()}", file=file)


class ParseError(Exception):

    def __init__(self, token: Token, msg):
        Exception.__init__(self, f"{token.location()}: {msg}")
        self.token = token


# NOTE: the order matters, e.g. '++' must come before '+'
# See:
# * notes/ansi.c.grammar.l
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
)


# Regex patterns used to parse tokens.
# See:
# * https://gcc.gnu.org/onlinedocs/cpp/Tokenization.html
# * notes/ansi.c.grammar.l
# NOTE: we only use these regex patterns on *lines* of code, so you won't
# see any mention of \n in here.
# NOTE: a pattern may include a named capture group called 'VALUE'.
# If such a group is present, then its captured value is used for Token.value,
# instead of Token.value being the entire token.
TOKEN_PATTERNS = {
    'WHITESPACE'  : r'[ \t]+',

    # The #include directive is the only place where a string lives inside
    # of "pointy brackets", so it's a special case for the tokenizer
    'INCLUDE'     : r'#[ \t]*include[ \t]*(?P<VALUE>"[^"]*"|<[^>]*>)',

    # When defining a function-like macro, there must be no space between
    # the macro name and the opening parenthesis, so it's a special case
    # for the tokenizer
    'FUNC_DEFINE' : r'#[ \t]*define[ \t]*(?P<VALUE>[a-zA-Z_][0-9a-zA-Z_]*)(?=\()',

    # The preprocessor operators are '#' or '##'.
    # NOTE: the '#' operator might be part of a directive (e.g. #define, #if)
    # or it might be the "stringize" operator, depending on whether we are
    # currently expanding a macro body or not.
    # See also:
    # * https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html
    'PP_OPERATOR' : r'##?',

    'COMMENT'     : r'//.*' + '|' + r'/\*.*?(?:\*/|$)',

    # See:
    # https://gcc.gnu.org/onlinedocs/cpp/Tokenization.html
    #
    #   A preprocessing number has a rather bizarre definition. The category
    #   includes all the normal integer and floating point constants one
    #   expects of C, but also a number of other things one might not
    #   initially recognize as a number.
    #   Formally, preprocessing numbers begin with an optional period, a
    #   required decimal digit, and then continue with any sequence of
    #   letters, digits, underscores, periods, and exponents.
    #   Exponents are the two-character sequences 'e+', 'e-', 'E+', 'E-',
    #   'p+', 'p-', 'P+', and 'P-'.
    #
    'NUMBER'      : r'\.?[0-9](?:[a-zA-Z0-9_.]|[eEpP][+-])*',

    'CHAR'        : r"[a-zA-Z]*'(?:\\.|[^'])*'",
    'STRING'      : r'[a-zA-Z]*"(?:\\.|[^"])*"',

    'IDENTIFIER'  : r'[a-zA-Z_][0-9a-zA-Z_]*',
    'PUNCTUATION' : '|'.join(map(re.escape, PUNCTUATION)),
    'BADCHAR'     : '.',
}

# Using one giant regex with .finditer() instead of doing .match() ourselves
# with multiple small ones: this approach hopefully lets us execute less slow
# Python code and more fast C code, and I believe it lets us allocate fewer
# Python strings, since AFAIK there's no way to pass a start location to
# .match().
TOKEN_REGEX = re.compile('|'.join(
    # Named capture groups must be uniquely named, so here we turn e.g.
    # 'VALUE' into f'{toktype}_VALUE'.
    f'(?P<{toktype}>' + pattern.replace('?P<', f'?P<{toktype}_') + ')'
    for toktype, pattern in TOKEN_PATTERNS.items()))


class Lexer:
    r"""Consumes lines of C code, yielding a stream of tokens.

        >>> for token in Lexer().tokenize(r'''
        ...     int main() {
        ...         printf("Hello \"world\"!");
        ...     }
        ... '''): token.pprint()
        <fakefile>:1:1: EOL('')
        <fakefile>:2:5: IDENTIFIER('int')
        <fakefile>:2:9: IDENTIFIER('main')
        <fakefile>:2:13: PUNCTUATION('(')
        <fakefile>:2:14: PUNCTUATION(')')
        <fakefile>:2:16: PUNCTUATION('{')
        <fakefile>:2:17: EOL('')
        <fakefile>:3:9: IDENTIFIER('printf')
        <fakefile>:3:15: PUNCTUATION('(')
        <fakefile>:3:16: STRING('"Hello \\"world\\"!"')
        <fakefile>:3:34: PUNCTUATION(')')
        <fakefile>:3:35: PUNCTUATION(';')
        <fakefile>:3:36: EOL('')
        <fakefile>:4:5: PUNCTUATION('}')
        <fakefile>:4:6: EOL('')

        Lines separated by pairs (backslash, newline) are "pasted" together
        into a single line, i.e. an EOL token isn't emitted between them:
        >>> for token in Lexer().tokenize(r'''
        ...     line 1 \
        ...     line 2
        ... '''): token.pprint()
        <fakefile>:1:1: EOL('')
        <fakefile>:2:5: IDENTIFIER('line')
        <fakefile>:2:10: NUMBER('1')
        <fakefile>:3:5: IDENTIFIER('line')
        <fakefile>:3:10: NUMBER('2')
        <fakefile>:3:11: EOL('')

        Multiline comments are handled:
        >>> for token in Lexer().tokenize(r'''
        ...     x /* some comment */ y /* more
        ...     and more\
        ...     comment */ z /* trailing off...
        ...     oh no...
        ... '''): token.pprint()
        <fakefile>:1:1: EOL('')
        <fakefile>:2:5: IDENTIFIER('x')
        <fakefile>:2:7: COMMENT('/* some comment */')
        <fakefile>:2:26: IDENTIFIER('y')
        <fakefile>:2:28: COMMENT('/* more\n    and more\n    comment */')
        <fakefile>:4:16: IDENTIFIER('z')
        <fakefile>:4:18: COMMENT('/* trailing off...\n    oh no...')

        Preprocessor directives are handled:
        >>> for token in Lexer().tokenize(r'''
        ...     #include <stdio.h>
        ...     #define PASTE(X, Y) X ## Y
        ...     #define SIZE 64
        ... '''): token.pprint()
        <fakefile>:1:1: EOL('')
        <fakefile>:2:5: INCLUDE('<stdio.h>')
        <fakefile>:2:23: EOL('')
        <fakefile>:3:5: FUNC_DEFINE('PASTE')
        <fakefile>:3:18: PUNCTUATION('(')
        <fakefile>:3:19: IDENTIFIER('X')
        <fakefile>:3:20: PUNCTUATION(',')
        <fakefile>:3:22: IDENTIFIER('Y')
        <fakefile>:3:23: PUNCTUATION(')')
        <fakefile>:3:25: IDENTIFIER('X')
        <fakefile>:3:27: PP_OPERATOR('##')
        <fakefile>:3:30: IDENTIFIER('Y')
        <fakefile>:3:31: EOL('')
        <fakefile>:4:5: PP_OPERATOR('#')
        <fakefile>:4:6: IDENTIFIER('define')
        <fakefile>:4:13: IDENTIFIER('SIZE')
        <fakefile>:4:18: NUMBER('64')
        <fakefile>:4:20: EOL('')

    Possible errors:

        >>> list(Lexer().tokenize('"hello" "world'))
        Traceback (most recent call last):
         ...
        lgci.pplex.ParseError: <fakefile>:1:9: Unexpected character: '"'

    """

    def __init__(self, filename: str = '<fakefile>'):
        self.filename = filename
        self.row = 1
        self.block_comment_token: Optional[Token] = None

    def tokenize(self, lines: str | Iterable[str]) -> Iterator[Token]:
        """Yield a stream of tokens from the given lines of C code.
        The lines of code should be finite, and their end will be treated as
        an end-of-file."""

        if isinstance(lines, str):
            # Support caller passing us a string, handy in doctests
            lines = lines.splitlines()

        for line in lines:
            yield from self.tokenize_line(line)

        yield from self.finish()

    def finish(self) -> Iterator[Token]:
        """To be called after a finite stream of lines has been processed,
        e.g. at the end of a file"""

        # If a block comment is unterminated, that's fine, just make sure we
        # remember to emit it!
        if self.block_comment_token is not None:
            yield self.block_comment_token
            self.block_comment_token = None

    def tokenize_line(self, line: str) -> Iterator[Token]:
        """Yield a stream of tokens from a single line of C code"""

        # Strip newlines from the end so we can iterate directly over the
        # output of open()
        line = line.rstrip('\n')

        # Paste together lines joined with backslash + newline.
        # Actually, we don't really bother pasting the lines together, because
        # that behaviour is crazy!.. e.g. you can have a token which starts on
        # on one line, and ends on another.
        # Instead, if a line ends with a backslash, we just chop that off, and
        # remember not to emit an EOL token.
        pasted = line.endswith('\\')
        if pasted:
            line = line[:-1]

        # If we're in the middle of a block comment (started on a previous
        # line), figure out if it ends on this line, etc
        block_comment_chopped = 0
        if self.block_comment_token is not None:
            end_index = line.find('*/')
            if end_index < 0:
                # The block comment continues for this entire line!
                self.block_comment_token = self.block_comment_token._replace(
                    value=self.block_comment_token.value + '\n' + line)
                self.row += 1
                return
            else:
                # The block comment ends in this line, so chop it off,
                # then process all remaining tokens in the line
                end_index += 2 # go past the '*/'
                self.block_comment_token = self.block_comment_token._replace(
                    value=self.block_comment_token.value + '\n' + line[:end_index])
                yield self.block_comment_token
                line = line[end_index:]
                block_comment_chopped = end_index
                self.block_comment_token = None

        # Parse tokens from this line
        for match in TOKEN_REGEX.finditer(line):
            groups = match.groupdict()
            toktype = next(toktype for toktype in TOKEN_PATTERNS
                if groups[toktype] is not None)
            if toktype == 'WHITESPACE':
                continue

            # For most tokens, this is just the entire token.
            # For some directives, e.g. #define, this is an identifier.
            # For #include, this is a filename.
            # For other directives, this is the directive name, e.g. for
            # #if, value will be 'pragma'.
            value = groups.get(f'{toktype}_VALUE') or match.group()

            token = Token(
                toktype=toktype,
                filename=self.filename,
                row=self.row,
                col=1 + block_comment_chopped + match.start(),
                value=value,
            )

            if toktype == 'BADCHAR':
                raise ParseError(token, f"Unexpected character: {value!r}")

            if value.startswith('/*') and not value.endswith('*/'):
                # We've found a block comment which doesn't end on this line!..
                self.block_comment_token = token
            else:
                yield token

        # Maybe emit an EOL token?..
        if not pasted and self.block_comment_token is None:
            yield Token(
                toktype='EOL',
                filename=self.filename,
                row=self.row,
                col=1 + block_comment_chopped + len(line),
            )

        self.row += 1


def tokenize_file(filename: str) -> Iterator[Token]:
    if filename == '-':
        filename = '<stdin>'
        file = sys.stdin
        should_close = False
    else:
        file = open(filename, 'r')
        should_close = True
    try:
        yield from Lexer(filename).tokenize(file)
    finally:
        if should_close:
            file.close()


def main():
    filename = sys.argv[1]
    try:
        for token in tokenize_file(filename):
            token.pprint()
    except BrokenPipeError:
        # So we can pipe ourselves into "less" and quit before lexing the
        # whole file, etc
        pass


if __name__ == '__main__':
    main()
