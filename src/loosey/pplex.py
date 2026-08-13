"""

    This module's regexes are based on an ANSI C grammar in Lex format which I
    found on the Internet:
    https://www.lysator.liu.se/c/ANSI-C-grammar-l.html
    (Which I've copied into this repo, see: notes/ansi.c.grammar.l)

        In 1985, Jeff Lee published this Lex specification together with a Yacc
        grammar for the April 30, 1985 ANSI C draft.
        Tom Stockfisch reposted both to net.sources in 1987; that original, as
        mentioned in the answer to question 17.25 of the comp.lang.c FAQ, can be
        ftp'ed from ftp.uu.net, file usenet/net.sources/ansi.c.grammar.Z.
        I intend to keep this version as close to the current C Standard grammar
        as possible; please let me know if you discover discrepancies.

        Jutta Degener, 1995

    ...thanks, Jutta! :)

    I also used the GNU C preprocessor's excellent documentation:
    https://gcc.gnu.org/onlinedocs/cpp/Tokenization.html

    See also: docs/preprocessor.md

"""

import re
import sys
import json
from uuid import uuid4
from ast import literal_eval
from typing import NamedTuple, Iterable, Iterator, Optional


def to_string_literal(s: str) -> str:
    """Produce a C string literal (i.e. for use as Token.value) from a
    Python string.
    NOTE: should ideally be the inverse of Token.parse_string"""
    # HACK: json.dumps is prooooobably good enough
    return json.dumps(s)


def to_char_literal(s: str) -> str:
    """Produce a C char literal (i.e. for use as Token.value) from a
    Python string.
    NOTE: should ideally be the inverse of Token.parse_char"""
    # HACK: repr is prooooobably good enough
    return repr(s)


def generate_unique_id() -> str:
    return str(uuid4())


class SourceFile(NamedTuple):
    filename: str

    # Every time we parse a file, we generate a unique ID for it.
    # This lets us create cache keys for things derived from a parse,
    # like Token, ParseMatch, etc.
    # See also: generate_unique_id
    unique_id: str

    # If we were imported from another file
    parent: Optional['SourceFile'] = None


class SourceLine(NamedTuple):
    file: SourceFile
    row: int = 1

    @property
    def filename(self) -> str:
        return self.file.filename


TokenParents = tuple['Token', ...]


class Token(NamedTuple):
    toktype: str
    line: SourceLine
    col: int = 1
    value: str = ''

    # Used e.g. when pasting tokens together with '##', or doing macro
    # expansion, etc
    parents: TokenParents = ()

    @property
    def file(self) -> SourceFile:
        return self.line.file

    @property
    def parent_depth(self) -> int:
        depth = 0
        parents = self.parents
        while parents:
            parents = parents[0].parents
            depth += 1
        return depth

    @staticmethod
    def fake(toktype: str, value: str = '') -> 'Token':
        """Generate a token with fake location info, for use e.g. in
        doctests"""
        return Token(
            toktype=toktype,
            value=value,
            line=SourceLine(file=SourceFile('<fakefile>',
                unique_id=generate_unique_id())),
        )

    @staticmethod
    def from_parents(parents: TokenParents, toktype: str, value: str) -> 'Token':
        first_parent = parents[0]
        return Token(
            toktype=toktype,
            line=first_parent.line,
            col=first_parent.col,
            value=value,
            parents=parents,
        )

    def copy_with_parents(self, parents: TokenParents) -> 'Token':
        return self.from_parents(parents + (self,), self.toktype, self.value)

    @property
    def filename(self) -> str:
        return self.line.filename

    @property
    def row(self) -> int:
        return self.line.row

    @property
    def end(self) -> int:
        return self.col + len(self.value)

    def identifier(self) -> Optional[str]:
        if self.toktype == 'IDENTIFIER':
            return self.value
        return None

    def location(self) -> str:
        return f'{self.filename}:{self.row}:{self.col}'

    def prettystring(self) -> str:
        return f"{self.toktype}({self.value!r})"

    def pprint(
            self,
            *,
            indent='',
            with_location: bool = True,
            with_parents: bool = False,
            with_file_parents: bool = False,
            ):
        msg = self.prettystring()
        if with_location:
            msg = f'{self.location()}: {msg}'
        print(indent + msg)
        if with_parents and self.parents:
            print(f"{indent} ...from:")
            for parent in self.parents:
                parent.pprint(indent=indent + '  ', with_parents=True)
        if with_file_parents:
            file = self.line.file.parent
            while file:
                print(f"{indent} ...imported from: {file.filename}")
                file = file.parent

    def parse_string(self) -> str:
        """Produce a Python string from a C string literal
        NOTE: should ideally be the inverse of to_string_literal"""
        # HACK: json.loads is prooooobably good enough
        try:
            return json.loads(self.value)
        except ValueError:
            raise ParseError(self, f"Couldn't parse as string: {self.value!r}")

    def parse_char(self) -> str:
        """Produce a Python string from a C string literal
        NOTE: should ideally be the inverse of to_char_literal"""
        # HACK: literal_eval is prooooobably good enough
        try:
            return literal_eval(self.value)
        except SyntaxError:
            raise ParseError(self, f"Couldn't parse as char: {self.value!r}")

    def parse_number(self) -> int | float:
        """Produce a Python number from a C number literal"""
        text = self.value
        try:
            if '.' in text:
                return float(text)
            elif text.startswith('0x'):
                return int(text[2:], 16)
            elif len(text) > 1 and text.startswith('0'):
                return int(text[1:], 8)
            else:
                return int(text)
        except ValueError:
            raise ParseError(self, f"Couldn't parse as number: {text!r}")


class ParseError(Exception):

    def __init__(self, token: Optional[Token], msg):
        if token is not None and not isinstance(token, Token):
            # E.g. if we got a ParseMatch by accident
            token = token.token

        # NOTE: we almost never want to have token be None.
        # The one case I know we need to support is when we're trying to
        # tokenize a file which consists of a single backslash. O_o
        location = 'unknown' if token is None else token.location()
        msg = f"{location}: {msg}"

        # Experimental, probably too much info...
        INCLUDE_PARENTS = False
        if INCLUDE_PARENTS and token is not None:
            lines = [msg]
            def visit_token(token, depth=0):
                lines.append('  ' * depth + f'...from: {token.location()}')
                for parent in token.parents:
                    visit_token(parent, depth+1)
            for parent in token.parents:
                visit_token(parent)
            msg = '\n'.join(lines)

        Exception.__init__(self, msg)
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


# Regex patterns used to parse tokens from a single line of C code.
# We guarantee that any newlines or backslash+newline pairs have already
# been stripped from the lines we use these patterns with.
TOKEN_PATTERNS = {
    'WHITESPACE'  : r'[ \t]+',

    # The #include directive is the only place where a string lives inside
    # of "pointy brackets", so it's a special case for the tokenizer
    'INCLUDE'     : r'#[ \t]*include[ \t]*("(?:[^"]*)"|<(?:[^>]*)>)',

    # The preprocessor operators are '#' (stringize) and '##' (token paste
    # or concatenate).
    # NOTE: the '#' operator might be part of a directive (e.g. #define, #if)
    # or it might be the "stringize" operator, depending on whether we are
    # currently expanding a macro body or not.
    # See also:
    # * https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html
    # * https://gcc.gnu.org/onlinedocs/cpp/Concatenation.html
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
    'BADCHAR'     : r'.',
}

# A regex which matches #include directives
INCLUDE_REGEX = re.compile(TOKEN_PATTERNS['INCLUDE'])

# Using one giant regex with .finditer() instead of doing .match() ourselves
# with multiple small ones: this approach hopefully lets us execute less slow
# Python code and more fast C code, and I believe it lets us allocate fewer
# Python strings, since AFAIK there's no way to pass a start location to
# .match(), so if we were popping off a token at a time, we would have to
# create a fresh string representing the remainder of the line each time.
TOKEN_REGEX = re.compile('|'.join(
    f'(?P<{toktype}>{pattern})'
    for toktype, pattern in TOKEN_PATTERNS.items()))


class Lexer:
    r"""Turns lines of C code into lists of tokens.

        >>> for i, line in enumerate(Lexer().tokenize(r'''
        ...     int main() {
        ...         printf("Hello \"world\"!");
        ...     }
        ... ''')):
        ...     print(f"=== LINE {i + 1}:")
        ...     for token in line: token.pprint()
        === LINE 1:
        === LINE 2:
        <fakefile>:2:5: IDENTIFIER('int')
        <fakefile>:2:9: IDENTIFIER('main')
        <fakefile>:2:13: PUNCTUATION('(')
        <fakefile>:2:14: PUNCTUATION(')')
        <fakefile>:2:16: PUNCTUATION('{')
        === LINE 3:
        <fakefile>:3:9: IDENTIFIER('printf')
        <fakefile>:3:15: PUNCTUATION('(')
        <fakefile>:3:16: STRING('"Hello \\"world\\"!"')
        <fakefile>:3:34: PUNCTUATION(')')
        <fakefile>:3:35: PUNCTUATION(';')
        === LINE 4:
        <fakefile>:4:5: PUNCTUATION('}')

        Lines separated by pairs (backslash, newline) are "pasted" together
        into a single line:
        >>> for i, line in enumerate(Lexer().tokenize(r'''
        ...     line 1 \
        ...     line 2
        ... ''')):
        ...     print(f"=== LINE {i + 1}:")
        ...     for token in line: token.pprint()
        === LINE 1:
        === LINE 2:
        <fakefile>:2:5: IDENTIFIER('line')
        <fakefile>:2:10: NUMBER('1')
        <fakefile>:3:5: IDENTIFIER('line')
        <fakefile>:3:10: NUMBER('2')

        Multiline comments are handled:
        >>> for i, line in enumerate(Lexer().tokenize(r'''
        ...     x /* some comment */ y /* more
        ...     and more
        ...     comment */ z
        ... ''')):
        ...     print(f"=== LINE {i + 1}:")
        ...     for token in line: token.pprint()
        === LINE 1:
        === LINE 2:
        <fakefile>:2:5: IDENTIFIER('x')
        <fakefile>:2:7: COMMENT('/* some comment */')
        <fakefile>:2:26: IDENTIFIER('y')
        <fakefile>:2:28: COMMENT('/* more')
        <fakefile>:3:1: COMMENT('    and more')
        <fakefile>:4:1: COMMENT('    comment */')
        <fakefile>:4:16: IDENTIFIER('z')

        Preprocessor directives are handled:
        >>> for i, line in enumerate(Lexer().tokenize(r'''
        ...     #include <stdio.h>
        ...     #define PASTE(X, Y) X ## Y
        ...     #define SIZE 64
        ... ''')):
        ...     print(f"=== LINE {i + 1}:")
        ...     for token in line: token.pprint()
        === LINE 1:
        === LINE 2:
        <fakefile>:2:5: INCLUDE('#include <stdio.h>')
        === LINE 3:
        <fakefile>:3:5: PP_OPERATOR('#')
        <fakefile>:3:6: IDENTIFIER('define')
        <fakefile>:3:13: IDENTIFIER('PASTE')
        <fakefile>:3:18: PUNCTUATION('(')
        <fakefile>:3:19: IDENTIFIER('X')
        <fakefile>:3:20: PUNCTUATION(',')
        <fakefile>:3:22: IDENTIFIER('Y')
        <fakefile>:3:23: PUNCTUATION(')')
        <fakefile>:3:25: IDENTIFIER('X')
        <fakefile>:3:27: PP_OPERATOR('##')
        <fakefile>:3:30: IDENTIFIER('Y')
        === LINE 4:
        <fakefile>:4:5: PP_OPERATOR('#')
        <fakefile>:4:6: IDENTIFIER('define')
        <fakefile>:4:13: IDENTIFIER('SIZE')
        <fakefile>:4:18: NUMBER('64')

    Possible errors:

        >>> list(Lexer().tokenize('"hello" "world'))
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:9: Unexpected character: '"'

        >>> list(Lexer().tokenize('1 2 /* comment '))
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:5: Expected another line

        >>> list(Lexer().tokenize('1 2 hello\\')) #doctest: +NORMALIZE_WHITESPACE
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:5: Got IDENTIFIER('hello')
        immediately followed by backslash+newline. We don't support this!

        >>> list(Lexer().tokenize('1 2 // comment... \\')) #doctest: +NORMALIZE_WHITESPACE
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:5: Got COMMENT('// comment... ')
        immediately followed by backslash+newline. We don't support this!

    """

    def __init__(self, file: SourceFile | str = '<fakefile>'):
        if isinstance(file, str):
            file = SourceFile(filename=file, unique_id=generate_unique_id())
        self.file = file
        self.row = 1

        # Did previous line have an unterminated "/*"?..
        self.in_multiline_comment = False

        # Used when previous line ended with a backslash and/or unterminated
        # multiline comment
        self.tokens_from_prev_line: Optional[list[Token]] = None

    def reset_line(self):
        """Forgets everything about the previous line.
        For use e.g. if there is a syntax error during a multiline macro
        definition"""
        self.in_multiline_comment = False
        self.tokens_from_prev_line = None

    def tokenize(self, lines: Iterable[str] | str) -> Iterator[list[Token]]:
        """Turns lines of C code into lists of tokens.
        The lines of code should be finite, and their end will be treated as
        an end-of-file."""

        if isinstance(lines, str):
            # Support caller passing us a string, handy in doctests
            lines = lines.splitlines()

        for line in lines:
            tokenized_line = self.tokenize_line(line)
            if tokenized_line is None:
                # We didn't get a line yet, e.g. because a multiline comment
                # hasn't ended yet, and/or there was a backslash at the end
                # of the line
                pass
            else:
                yield tokenized_line
        self.finish()

    def finish(self):
        """To be called after a finite stream of lines has been processed,
        e.g. at the end of a file"""
        if self.tokens_from_prev_line is not None:
            if self.tokens_from_prev_line:
                last_token = self.tokens_from_prev_line[-1]
            else:
                # E.g. if we were trying to tokenize a file consisting of
                # just a backslash, with no tokens O_o
                last_token = None
            raise ParseError(last_token, "Expected another line")

    def tokenize_line(self, line: str) -> Optional[list[Token]]:
        """Turns a line of C code into a list of tokens... or into None, if
        the line ends in a backslash or unterminated block comment.
        (In the latter case, this line's tokens will be saved, and prepended
        to the list of tokens generated for the next line)"""
        try:
            # Strip newlines from the end so we can iterate directly over the
            # output of open()
            line = line.rstrip('\n')

            # Grab the tokens left over from previous line, if any.
            if self.tokens_from_prev_line is not None:
                tokens = self.tokens_from_prev_line
                self.tokens_from_prev_line = None
            else:
                tokens = []

            # Check for backslash at end of line
            line_ended_with_backslash = line.endswith('\\')
            if line_ended_with_backslash:
                line = line[:-1]

            # Reused by all Token instances generated for this line
            source_line = SourceLine(
                row=self.row,
                file=self.file,
            )

            # If we're in the middle of a multiline comment (started on a
            # previous line), figure out if it ends on this line, etc
            block_comment_chopped = 0
            if self.in_multiline_comment:
                end_index = line.find('*/')
                if end_index < 0:
                    # The comment continues for this entire line!
                    # We emit separate tokens for the parts of a multiline
                    # comment which come from different lines, for no
                    # particular reason.
                    tokens.append(Token(
                        toktype='COMMENT',
                        line=source_line,
                        value=line,
                    ))
                    self.row += 1
                    self.tokens_from_prev_line = tokens
                    return None
                else:
                    # The comment ends in this line, so chop it off and
                    # process the rest of the line
                    end_index += 2 # go past the '*/'
                    # We emit separate tokens for the parts of a multiline
                    # comment which come from different lines, for no
                    # particular reason.
                    tokens.append(Token(
                        toktype='COMMENT',
                        line=source_line,
                        value=line[:end_index],
                    ))
                    line = line[end_index:]
                    block_comment_chopped = end_index
                    self.in_multiline_comment = False

            # Parse tokens from this line
            for match in TOKEN_REGEX.finditer(line):
                groups = match.groupdict()
                toktype = next(toktype for toktype in TOKEN_PATTERNS
                    if groups[toktype] is not None)
                if toktype == 'WHITESPACE':
                    continue

                value = match.group()

                token = Token(
                    toktype=toktype,
                    line=source_line,
                    col=1 + block_comment_chopped + match.start(),
                    value=value,
                )

                if toktype == 'BADCHAR':
                    raise ParseError(token, f"Unexpected character: {value!r}")

                if value.startswith('/*') and not value.endswith('*/'):
                    # We've found a block comment which doesn't end on this
                    # line!..
                    self.in_multiline_comment = True

                tokens.append(token)

            last_token = None if not tokens else tokens[-1]
            if (
                line_ended_with_backslash and last_token and
                last_token.end == 1 + block_comment_chopped + len(line)
            ):
                # The C standards people are crazy to have allowed this...
                # It's like they forsaw the International Obfuscated C Code
                # Contest and welcomed its coming
                raise ParseError(last_token,
                    f"Got {last_token.prettystring()} immediately followed by backslash+newline. "
                    "We don't support this!")

            self.row += 1

            # Now we either return our list of tokens, or we save them for
            # the next line...
            if line_ended_with_backslash or self.in_multiline_comment:
                self.tokens_from_prev_line = tokens
                return None
            else:
                return tokens

        except Exception:
            # If we were continuing a previous line, forget about that now
            self.reset_line()
            raise


def tokenize_file(filename: str) -> Iterator[list[Token]]:
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
