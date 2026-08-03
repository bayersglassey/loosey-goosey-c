import re
from argparse import ArgumentParser
from typing import NamedTuple, Literal, Sequence, Optional, Union
from string import ascii_lowercase, ascii_uppercase

from loosey.pplex import Token, tokenize_file


RULE_TOKEN_REGEX = re.compile(r" +|\n|#[^\n]*|\)[?*]|[a-zA-Z_][a-zA-Z0-9_]*|'[^']+'|.")
NAME_CHARS = ascii_lowercase + '_'
TOKTYPE_CHARS = ascii_uppercase + '_'


GrammarPatternPartType = (
    Literal['rule']
    | Literal['toktype']
    | Literal['tokvalue']
    | Literal['maybe']
    | Literal['star']
)
GrammarPatternPart = tuple[GrammarPatternPartType, Union[str, 'GrammarPattern']]
GrammarPattern = list[GrammarPatternPart]


def pattern_to_string(pattern: GrammarPattern) -> str:
    s_parts = []
    def visit(pattern):
        for part_type, part_value in pattern:
            if part_type == 'tokvalue':
                s_parts.append(repr(part_value))
            elif part_type == 'maybe':
                s_parts.append('(')
                visit(part_value)
                s_parts.append(')?')
            elif part_type == 'star':
                s_parts.append('(')
                visit(part_value)
                s_parts.append(')*')
            else:
                s_parts.append(part_value)
    visit(pattern)
    return ' '.join(s_parts)


class GrammarRule(NamedTuple):
    name: str
    patterns: list[GrammarPattern]

    def pprint(self):
        print(self.name)
        for i, pattern in enumerate(self.patterns):
            print('    | ' + pattern_to_string(pattern))
        print('    ;')


class GrammarParseError(Exception):
    pass


def parse_rules_from_file(filename: str) -> dict[str, GrammarRule]:
    return parse_rules(open(filename, 'r').read(), filename)


def parse_rules(text: str, filename: str = '<fakefile>') -> dict[str, GrammarRule]:
    """

        >>> rules = parse_rules('''
        ...
        ...     value
        ...         | NUMBER
        ...         | array
        ...         ;
        ...
        ...     array
        ...         | '[' ( value ( ',' value )* )? ']'
        ...         ;
        ...
        ... ''')

        >>> for name, rule in rules.items(): rule.pprint()
        value
            | NUMBER
            | array
            ;
        array
            | '[' ( value ( ',' value )* )? ']'
            ;

    """
    rules = {}
    rule = None
    pattern = None
    pattern_stack = None
    row = 1
    col = 1

    def iter_tokens():
        nonlocal row, col
        for match in RULE_TOKEN_REGEX.finditer(text):
            token = match.group()
            if token[0] in '# \n':
                # Eat comments & whitespace
                pass
            else:
                yield token
            if token == '\n':
                col = 1
                row += 1
            else:
                col += len(token)

    def error(msg: str) -> GrammarParseError:
        return GrammarParseError(f"{filename}:{row}:{col}: {msg}")

    def unexpected(token) -> GrammarParseError:
        raise error(f"Unexpected: {token!r}")

    for token in iter_tokens():
        # Decide what kind of token is is based on first character
        c = token[0]

        # POSSIBLE STATES:
        if rule is None:
            # Not in a rule definition
            if c in ascii_lowercase:
                # Start a new rule definition
                if token in rules:
                    raise error(f"Duplicate definition for rule: {token!r}")
                rule = rules[token] = GrammarRule(name=token, patterns=[])
            else:
                raise unexpected(token)
        elif pattern is None:
            # In a rule definition, before first pattern
            if c == '|':
                # Start parsing patterns for the current rule
                pattern = []
                pattern_stack = []
            elif c == ';':
                raise error("Rule has no patterns: {rule.name}")
            else:
                raise unexpected(token)
        else:
            # In a pattern definition
            if c == ';':
                # Finish the current rule definition
                if pattern_stack:
                    raise error("Unterminated pattern")
                rule.patterns.append(pattern)
                rule = None
                pattern = None
                pattern_stack = None
            elif c == '|':
                # Start a new pattern for current rule
                if pattern_stack:
                    raise error("Unterminated pattern")
                rule.patterns.append(pattern)
                pattern = []
            elif c == "'":
                pattern.append(('tokvalue', token[1:-1]))
            elif c in NAME_CHARS:
                pattern.append(('rule', token))
            elif c in TOKTYPE_CHARS:
                pattern.append(('toktype', token))
            elif c == '(':
                pattern_stack.append(pattern)
                pattern = []
            elif c == ')':
                if token == ')?':
                    part_type = 'maybe'
                elif token == ')*':
                    part_type = 'star'
                else:
                    raise unexpected(token)
                if not pattern_stack:
                    raise unexpected(token)
                old_pattern = pattern_stack.pop()
                old_pattern.append((part_type, pattern))
                pattern = old_pattern
            else:
                raise unexpected(token)

    if rule is not None:
        raise error(f"Unterminated rule: {rule.name}")
    return rules


class ParseMatchKey(NamedTuple):
    """Cache key for GrammarParser.match_pattern"""
    rule_name: str
    pattern_i: int
    token_i: int


class ParseMatch(NamedTuple):
    """When one of a rule's patterns matches, we get a parse match"""
    rule_name: str
    pattern_i: int

    # The token matching the start of the pattern
    token: Token

    # The slice of matched tokens is parser.tokens[token_i: n_tokens]
    token_i: int
    n_tokens: int

    children: list['ParseMatch']

    def pprint(self, depth=0):
        if self.children:
            print('  ' * depth + self.rule_name)
            for child in self.children:
                child.pprint(depth+1)
        else:
            print('  ' * depth + self.token.value)


class GrammarParser:
    """

        >>> rules = parse_rules('''
        ...
        ...     value
        ...         | NUMBER
        ...         | array
        ...         ;
        ...
        ...     array
        ...         | '[' ( value ( ',' value )* )? ']'
        ...         ;
        ...
        ... ''')

        >>> from loosey.pplex import Lexer
        >>> def parse(text, rule_name='value', verbose=False):
        ...     tokens = [token for line in Lexer().tokenize(text)
        ...         for token in line]
        ...     parser = GrammarParser(rules, tokens, verbose=verbose)
        ...     match = parser.match_rule(rule_name)
        ...     if match is not None:
        ...         match.pprint()

        >>> parse('1')
        1

        Matching a prefix of the input:
        >>> parse('1 other stuff')
        1

        No match:
        >>> parse('x')

        >>> parse('[]')
        value
          [

        >>> parse('[1]')
        value
          array
            1

        >>> parse('[1,]')

        >>> parse('[1, 2]')
        value
          array
            1
            2

        >>> parse('[1, [2, 3], 4]')
        value
          array
            1
            value
              array
                2
                3
            4

    """

    def __init__(
            self,
            rules: dict[str, GrammarRule],
            tokens: Sequence[Token],
            *,
            verbose: bool = False,
            ):
        self.rules = rules
        self.tokens = tokens
        self.verbose = verbose

        self.main_rule_name = next(reversed(self.rules), None)
        self.match_depth = 0
        self.match_cache: dict[ParseMatchKey, Optional[ParseMatch]] = {}

    def match(self) -> Optional[ParseMatch]:
        if self.main_rule_name is None:
            raise Exception("No main rule")
        return self.match_rule(self.main_rule_name, full=True)

    def match_rule(self, rule_name: str, token_i: int = 0, *, full: bool = False) -> Optional[ParseMatch]:
        if self.verbose:
            print('. ' * self.match_depth + f"RULE: {rule_name}")
        rule = self.rules[rule_name]
        self.match_depth += 1
        try:
            for pattern_i in range(len(rule.patterns)):
                match = self.match_pattern(rule_name, pattern_i, token_i)
                if match is not None:
                    if full and match.token_i + match.n_tokens != len(self.tokens):
                        return None
                    return match
            return None
        finally:
            self.match_depth -= 1

    def match_pattern(self, rule_name: str, pattern_i: int, token_i: int) -> Optional[ParseMatch]:
        rule = self.rules[rule_name]
        pattern = rule.patterns[pattern_i]
        if self.verbose:
            print('. ' * self.match_depth + f"PATTERN {pattern_i}: {pattern_to_string(pattern)}")
        cache_key = (rule_name, pattern_i, token_i)
        if cache_key in self.match_cache:
            if self.verbose:
                print('. ' * self.match_depth + "FOUND IN CACHE!")
            return self.match_cache[cache_key]

        def cached(value):
            self.match_cache[cache_key] = value
            return value

        if token_i >= len(self.tokens):
            return cached(None)

        original_token_i = token_i
        children = []

        def match_subpattern(subpattern: GrammarPattern) -> bool:
            nonlocal token_i
            self.match_depth += 1
            try:
                for part_type, part_value in subpattern:
                    if part_type == 'rule':
                        match = self.match_rule(part_value, token_i)
                        if match is None:
                            if self.verbose:
                                print('. ' * self.match_depth + "NOT MATCH")
                            return False
                        assert match.token_i == token_i
                        token_i = token_i + match.n_tokens
                        children.append(match)
                    elif part_type == 'maybe':
                        # Zero or one matches of subpattern
                        if self.verbose:
                            print('. ' * self.match_depth + f"SUB-PATTERN ({part_type}): {pattern_to_string(part_value)}")
                        old_token_i = token_i
                        if not match_subpattern(part_value):
                            token_i = old_token_i
                    elif part_type == 'star':
                        # Zero or more matches of subpattern
                        if self.verbose:
                            print('. ' * self.match_depth + f"SUB-PATTERN ({part_type}): {pattern_to_string(part_value)}")
                        old_token_i = token_i
                        while match_subpattern(part_value):
                            old_token_i = token_i
                        token_i = old_token_i
                    else:
                        if token_i >= len(self.tokens):
                            if self.verbose:
                                print('. ' * self.match_depth + "END OF INPUT")
                            return False
                        token = self.tokens[token_i]
                        if self.verbose:
                            print('. ' * self.match_depth + f"TOKEN: {token.value!r}")
                        if part_type == 'toktype':
                            if token.toktype != part_value:
                                if self.verbose:
                                    print('. ' * self.match_depth + "NOT MATCH")
                                return False
                            token_i += 1
                        elif part_type == 'tokvalue':
                            if token.value != part_value:
                                if self.verbose:
                                    print('. ' * self.match_depth + "NOT MATCH")
                                return False
                            token_i += 1
                        else:
                            # We should never get here...
                            raise Exception(f"Unrecognized pattern part type: {part_type!r}")
                if self.verbose:
                    thing = 'RULE' if subpattern is pattern else 'SUB-PATTERN'
                    print('. ' * self.match_depth + f"{thing} MATCHED!")
                return True
            finally:
                self.match_depth -= 1

        if not match_subpattern(pattern):
            return cached(None)
        return cached(ParseMatch(
            rule_name=rule_name,
            pattern_i=pattern_i,
            token=self.tokens[original_token_i],
            token_i=original_token_i,
            n_tokens=token_i - original_token_i,
            children=children,
        ))


def main():
    parser = ArgumentParser()
    parser.add_argument('-g', '--grammar', default='src/loosey/data/grammar.txt')
    parser.add_argument('-p', '--print-grammar', default=False, action='store_true')
    parser.add_argument('-f', '--filename', default='-')
    parser.add_argument('-r', '--rule-name')
    parser.add_argument('--partial', default=False, action='store_true')
    parser.add_argument('-v', '--verbose', default=False, action='store_true')
    args = parser.parse_args()

    grammar_filename = args.grammar
    rules = parse_rules_from_file(grammar_filename)
    if args.print_grammar:
        for name, rule in rules.items():
            rule.pprint()
        return

    filename = args.filename
    tokens = [token for line in tokenize_file(filename) for token in line]
    parser = GrammarParser(rules, tokens, verbose=args.verbose)
    rule_name = args.rule_name or parser.main_rule_name
    match = parser.match_rule(rule_name, full=not args.partial)
    if match is None:
        print("No match!")
    else:
        match.pprint()


if __name__ == '__main__':
    main()
