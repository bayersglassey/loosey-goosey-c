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
    value: str = None
    exponent: str = None
    suffix: str = None

    def identifier(self) -> Optional[str]:
        return self.value if self.toktype == 'IDENTIFIER' else None

    def punctuation(self) -> Optional[str]:
        return self.value if self.toktype == 'PUNCTUATION' else None

    def keyword(self) -> Optional[str]:
        return self.value if self.toktype == 'KEYWORD' else None

    def directive(self) -> Optional[str]:
        if self.toktype == 'DIRECTIVE':
            return self.value
        elif self.toktype == 'INCLUDE':
            return 'include'
        elif self.toktype in ('DEFINE', 'DEFMACRO'):
            return 'define'
        elif self.toktype == 'UNDEF':
            return 'undef'
        else:
            return None

    def location(self) -> str:
        return f'{self.filename}:{self.row}:{self.col}'

    def prettystring(self) -> str:
        parts = [self.toktype]
        if self.value:
            parts.append(f'val={self.value!r}')
        if self.exponent:
            parts.append(f'exp={self.exponent!r}')
        if self.suffix:
            parts.append(f'suf={self.suffix!r}')
        return ' '.join(parts)

    def pprint(self, *, file=None):
        print(f"{self.location()}: {self.prettystring()}", file=file)


class TokenTreeNode(NamedTuple):
    token: Token
    children: list['Tokentree'] = None

    def pprint(self, depth=0, with_locations=False, file=None):
        msg = '  ' * depth
        if with_locations:
            msg += self.token.location() + ': '
        msg += self.token.prettystring()
        print(msg)
        for child in (self.children or ()):
            child.pprint(depth + 1, with_locations, file)

    def parse_parenlist(self) -> list[list['TokenTreeNode']]:
        """Parses a parenthesized list

            >>> [node] = TokenTreeBuilder().build("()")
            >>> node.parse_parenlist()
            []

            >>> [node] = TokenTreeBuilder().build("(x y, (1, 2), , hello,)")
            >>> for i, elem in enumerate(node.parse_parenlist()):
            ...     print(f"=== Element {i}:")
            ...     for child in elem:
            ...         child.pprint()
            === Element 0:
            IDENTIFIER val='x'
            IDENTIFIER val='y'
            === Element 1:
            PUNCTUATION val='('
              DEC_INT val='1'
              PUNCTUATION val=','
              DEC_INT val='2'
            === Element 2:
            === Element 3:
            IDENTIFIER val='hello'

            >>> [node] = TokenTreeBuilder().build("hello")
            >>> node.parse_parenlist()
            Traceback (most recent call last):
             ...
            lgci.lex.ParseError: <fakefile>:1:1: Can't parse parenthesized list from: IDENTIFIER val='hello'

        """
        if self.token.punctuation() != '(':
            raise ParseError(self.token, f"Can't parse parenthesized list from: {self.token.prettystring()}")
        return self.parse_list(self.children, ',')

    def parse_codeblock(self) -> list[list['TokenTreeNode']]:
        """Parses a semicolon-separated list surrounded by curly braces

            >>> [node] = TokenTreeBuilder().build("{}")
            >>> node.parse_codeblock()
            []

            >>> [node] = TokenTreeBuilder().build("{x y; {1; 2}; ; hello;}")
            >>> for i, elem in enumerate(node.parse_codeblock()):
            ...     print(f"=== Element {i}:")
            ...     for child in elem:
            ...         child.pprint()
            === Element 0:
            IDENTIFIER val='x'
            IDENTIFIER val='y'
            === Element 1:
            PUNCTUATION val='{'
              DEC_INT val='1'
              PUNCTUATION val=';'
              DEC_INT val='2'
            === Element 2:
            === Element 3:
            IDENTIFIER val='hello'

            >>> [node] = TokenTreeBuilder().build("hello")
            >>> node.parse_codeblock()
            Traceback (most recent call last):
             ...
            lgci.lex.ParseError: <fakefile>:1:1: Can't parse code block from: IDENTIFIER val='hello'

        """
        if self.token.punctuation() != '{':
            raise ParseError(self.token, f"Can't parse code block from: {self.token.prettystring()}")
        return self.parse_list(self.children, ';')

    @staticmethod
    def parse_list(nodes: Iterable['TokenTreeNode'], separator: str) -> list[list['TokenTreeNode']]:
        elems: list[list[TokenTreeNode]] = []
        elem: list[TokenTreeNode] = []
        for node in nodes:
            if node.token.punctuation() == separator:
                elems.append(elem)
                elem = []
            else:
                elem.append(node)
        if elem:
            elems.append(elem)
        return elems


class ParseError(Exception):

    def __init__(self, token: Token, msg):
        Exception.__init__(self, f"{token.location()}: {msg}")
        self.token = token


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

    'DEFINE'      : r'#[ \t]*define[ \t]*(?P<VALUE>[a-zA-Z_][0-9a-zA-Z_]*)',
    'UNDEF'       : r'#[ \t]*undef[ \t]*(?P<VALUE>[a-zA-Z_][0-9a-zA-Z_]*)',
    'DIRECTIVE'   : r'#[ \t]*(?P<VALUE>[a-zA-Z_][0-9a-zA-Z_]*)',
    'COMMENT'     : r'//(?P<VALUE>.*)',
    'BLOCKCOMMENT': r'/\*(?P<VALUE>.*?)(?:\*/|$)',
    'HEX_INT'     : r'0[xX](?P<VALUE>[a-fA-F0-9]+)' + INT_SUFFIX,
    'OCT_INT'     : r'0(?P<VALUE>[0-9]+)' + INT_SUFFIX,
    'DEC_INT'     : r'(?P<VALUE>[0-9]+)' + INT_SUFFIX,

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


class Lexer:
    r"""Consumes lines of C code, yielding a stream of tokens.

        >>> for token in Lexer().tokenize(r'''
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
        >>> for token in Lexer().tokenize(r'''
        ...     line 1 \
        ...     line 2
        ... '''): token.pprint()
        <fakefile>:1:1: EOL
        <fakefile>:2:5: IDENTIFIER val='line'
        <fakefile>:2:10: DEC_INT val='1'
        <fakefile>:3:5: IDENTIFIER val='line'
        <fakefile>:3:10: DEC_INT val='2'
        <fakefile>:3:11: EOL

        Multiline comments are handled:
        >>> for token in Lexer().tokenize(r'''
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
        >>> for token in Lexer().tokenize(r'''
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
        <fakefile>:4:5: DEFINE val='SIZE'
        <fakefile>:4:18: DEC_INT val='64'
        <fakefile>:4:20: EOL

    Possible errors:

        >>> list(Lexer().tokenize('"hello" "world'))
        Traceback (most recent call last):
         ...
        lgci.lex.ParseError: <fakefile>:1:9: Unexpected character: '"'

        >>> list(Lexer().tokenize('hello #define y'))
        Traceback (most recent call last):
         ...
        lgci.lex.ParseError: <fakefile>:1:7: Directive not first token of line: DEFINE val='y'

    """

    def __init__(self, filename: str = '<fakefile>', *, initial_row: int = 1):
        self.filename = filename
        self.row = initial_row
        self.block_comment_token = None

    def tokenize(self, lines: Iterable[str]) -> Iterator[Token]:
        """Yield a stream of tokens from the given lines of C code.
        The lines of code should be finite, and their end will be treated as
        an end-of-file."""

        # Support people passing us entire strings by accident, why not...
        if isinstance(lines, str):
            lines = lines.splitlines()

        for line in lines:
            yield from self.tokenize_line(line)

        yield from self.finish()

    def finish(self):
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

        # If we're in the middle of a block comment, figure out if it ends
        # on this line, etc
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
                self.block_comment_token = self.block_comment_token._replace(
                    value=self.block_comment_token.value + '\n' + line[:end_index])
                yield self.block_comment_token
                line = line[end_index + 2:]
                block_comment_chopped = end_index + 2
                self.block_comment_token = None

        # Parse tokens from this line
        directives_ok = True
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

            token = Token(
                filename=self.filename,
                row=self.row,
                col=1 + block_comment_chopped + match.start(),
                toktype=toktype,
                value=value,
                exponent=groups.get(f'{toktype}_EXPONENT'),
                suffix=groups.get(f'{toktype}_SUFFIX'),
            )

            if toktype == 'BADCHAR':
                raise ParseError(token, f"Unexpected character: {value!r}")

            if token.directive() and not directives_ok:
                raise ParseError(token, f"Directive not first token of line: {token.prettystring()}")

            if toktype != 'COMMENT':
                directives_ok = False

            if is_block_comment and not match.group().endswith('*/'):
                # We've found a block comment which doesn't end on this line!..
                self.block_comment_token = token
            else:
                yield token

        # Maybe emit an EOL token?..
        if not pasted and self.block_comment_token is None:
            yield Token(
                filename=self.filename,
                row=self.row,
                col=1 + block_comment_chopped + len(line),
                toktype='EOL',
            )

        self.row += 1


OPENERS = ('(', '[', '{')
CLOSERS = (')', ']', '}')


class TokenTreeBuilder:
    r"""Builds a super-simple parse tree from a stream of tokens.
    Only captures tree structures which can be detected purely from token
    types, e.g. (...), [...], {...}, and #define...EOL.

        >>> for node in TokenTreeBuilder().build(r'''
        ...     #include <stdio.h>
        ...     int main(int argc, char *argv) {
        ...         printf("Hello %s\n", argv[1]);
        ...     }
        ... '''): node.pprint()
        INCLUDE val='<stdio.h>'
        IDENTIFIER val='int'
        IDENTIFIER val='main'
        PUNCTUATION val='('
          IDENTIFIER val='int'
          IDENTIFIER val='argc'
          PUNCTUATION val=','
          IDENTIFIER val='char'
          PUNCTUATION val='*'
          IDENTIFIER val='argv'
        PUNCTUATION val='{'
          IDENTIFIER val='printf'
          PUNCTUATION val='('
            STRING val='Hello %s\\n'
            PUNCTUATION val=','
            IDENTIFIER val='argv'
            PUNCTUATION val='['
              DEC_INT val='1'
          PUNCTUATION val=';'

        >>> for node in TokenTreeBuilder().build(r'''
        ...     #define PRINT printf("Ping!\n");
        ...     #define PRINT_VALUE(X) printf("Got: %i\n", X);
        ...     int main() {
        ...         PRINT
        ...         PRINT_VALUE(99)
        ...     }
        ... '''): node.pprint()
        DEFINE val='PRINT'
          IDENTIFIER val='printf'
          PUNCTUATION val='('
            STRING val='Ping!\\n'
          PUNCTUATION val=';'
        DEFMACRO val='PRINT_VALUE'
          PUNCTUATION val='('
            IDENTIFIER val='X'
          IDENTIFIER val='printf'
          PUNCTUATION val='('
            STRING val='Got: %i\\n'
            PUNCTUATION val=','
            IDENTIFIER val='X'
          PUNCTUATION val=';'
        IDENTIFIER val='int'
        IDENTIFIER val='main'
        PUNCTUATION val='('
        PUNCTUATION val='{'
          IDENTIFIER val='PRINT'
          IDENTIFIER val='PRINT_VALUE'
          PUNCTUATION val='('
            DEC_INT val='99'

        Basically the whole reason we support "line pasting" (i.e. using
        backslash to escape newlines) is because people use it to define
        multi-line macros over multiple lines:
        >>> for node in TokenTreeBuilder().build(r'''
        ...     #define SWAP(TYPE, X, Y) { \
        ...         TYPE temp = X; \
        ...         X = Y; \
        ...         Y = temp; \
        ...     }
        ... '''): node.pprint()
        DEFMACRO val='SWAP'
          PUNCTUATION val='('
            IDENTIFIER val='TYPE'
            PUNCTUATION val=','
            IDENTIFIER val='X'
            PUNCTUATION val=','
            IDENTIFIER val='Y'
          PUNCTUATION val='{'
            IDENTIFIER val='TYPE'
            IDENTIFIER val='temp'
            PUNCTUATION val='='
            IDENTIFIER val='X'
            PUNCTUATION val=';'
            IDENTIFIER val='X'
            PUNCTUATION val='='
            IDENTIFIER val='Y'
            PUNCTUATION val=';'
            IDENTIFIER val='Y'
            PUNCTUATION val='='
            IDENTIFIER val='temp'
            PUNCTUATION val=';'

    You can also use a builder to stream tokens in, and stream tree nodes out:

        >>> builder = TokenTreeBuilder()

        We process some input, and harvest only the top-level tree nodes:
        >>> builder.process(Lexer().tokenize('1 + (2 + (3'))
        >>> for node in builder.harvest(): node.pprint()
        DEC_INT val='1'
        PUNCTUATION val='+'

        We process some more input, but no top-level tree nodes are available
        for harvesting.
        Tree nodes are being generated internally, but can't be harvested as
        they are not top-level:
        >>> builder.process(Lexer().tokenize('+ 4) +'))
        >>> for node in builder.harvest(): node.pprint()

        We process some more input, and are able to harvest top-level tree
        nodes.
        The non-top-level nodes which were generated earlier show up
        underneath the top-level nodes we harvest:
        >>> builder.process(Lexer().tokenize('5) * 100'))
        >>> for node in builder.harvest(): node.pprint()
        PUNCTUATION val='('
          DEC_INT val='2'
          PUNCTUATION val='+'
          PUNCTUATION val='('
            DEC_INT val='3'
            PUNCTUATION val='+'
            DEC_INT val='4'
          PUNCTUATION val='+'
          DEC_INT val='5'
        PUNCTUATION val='*'
        DEC_INT val='100'

    Possible errors:

        >>> TokenTreeBuilder().build('}')
        Traceback (most recent call last):
         ...
        lgci.lex.ParseError: <fakefile>:1:1: Unexpected PUNCTUATION val='}' at top level

        >>> TokenTreeBuilder().build('{ )')
        Traceback (most recent call last):
         ...
        lgci.lex.ParseError: <fakefile>:1:3: Expected '}' to match PUNCTUATION val='{' at <fakefile>:1:1), but got ')'

        >>> TokenTreeBuilder().build('{ ( )')
        Traceback (most recent call last):
         ...
        lgci.lex.ParseError: <fakefile>:1:1: PUNCTUATION val='{' missing closing '}'

    """

    def __init__(self):
        self.stack = []
        self.current_nodes = []
        self.directive_token = None

    def build(self, tokens: Iterable[Token]) -> list[TokenTreeNode]:
        """Fully process a finite stream of tokens, returning a list of
        tree nodes.
        The tokens are assumed to represent the "top level" of some C code,
        and their end will be treated as an end-of-file."""
        if isinstance(tokens, str):
            # Support caller passing us a string, why not, handy for doctests
            tokens = Lexer().tokenize(tokens)
        self.process(tokens)
        self.finish()
        return self.current_nodes

    def harvest(self) -> list[TokenTreeNode]:
        """Return all top-level tree nodes produced so far, and forget
        them; that is, each call to harvest() pops tree nodes from an
        internal buffer."""
        if self.stack:
            # We're not at top level right now, so we have to extract the
            # top-level nodes from the stack
            opener_token, expected_closer, nodes = self.stack[0]
            self.stack[0] = (opener_token, expected_closer, [])
            return nodes
        else:
            nodes = self.current_nodes
            self.current_nodes = []
            return nodes

    def close_node(self, token: Token, closer: str):
        """Attempt to \"close\" the current tree node, e.g. process the '}'
        of a {...} structure"""
        if not self.stack:
            raise ParseError(token, f"Unexpected {token.prettystring()} at top level")
        nodes = self.current_nodes
        opener_token, expected_closer, self.current_nodes = self.stack.pop()
        if closer != expected_closer:
            raise ParseError(token,
                f"Expected {expected_closer!r} "
                f"to match {opener_token.prettystring()} at {opener_token.location()}), "
                f"but got {closer!r}")
        self.current_nodes.append(TokenTreeNode(opener_token, nodes))

    def finish(self):
        """To be called at the end of a finite stream of tokens, e.g. at the
        end of a file"""
        if self.stack:
            # Something was left unclosed!..
            opener_token, expected_closer, nodes = self.stack[-1]
            raise ParseError(opener_token,
                f"{opener_token.prettystring()} missing closing {expected_closer!r}")

    def process(self, tokens: Iterable[Token]):
        """Process a finite stream of tokens"""
        for token in tokens:
            punctuation = token.punctuation()
            if punctuation in OPENERS:
                closer = CLOSERS[OPENERS.index(punctuation)]
                self.stack.append((token, closer, self.current_nodes))
                self.current_nodes = []
            elif token.directive():
                # NOTE: the Lexer guarantees that two directives can't appear
                # on the same line, so this assertion is just a sanity check
                assert self.directive_token is None
                self.stack.append((token, 'EOL', self.current_nodes))
                self.current_nodes = []
                self.directive_token = token
            elif punctuation in CLOSERS:
                self.close_node(token, punctuation)
            elif token.toktype == 'EOL':
                if self.directive_token is not None:
                    self.close_node(token, 'EOL')
                    self.directive_token = None
                else:
                    # Don't create TokenTreeNode instances for EOL tokens
                    pass
            else:
                self.current_nodes.append(TokenTreeNode(token))


def build_toktree_from_file(filename: str) -> list[TokenTreeNode]:
    if filename == '-':
        filename = '<stdin>'
        file = sys.stdin
        should_close = False
    else:
        file = open(filename, 'r')
        should_close = True
    try:
        tokens = Lexer(filename).tokenize(file)
        return TokenTreeBuilder().build(tokens)
    finally:
        if should_close:
            file.close()


def main():
    filename = sys.argv[1]
    for node in build_toktree_from_file(filename):
        node.pprint()


if __name__ == '__main__':
    main()
