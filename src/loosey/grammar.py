import re
from typing import NamedTuple, Literal, Sequence, Optional
from string import ascii_lowercase, ascii_uppercase

from loosey.pplex import Token


RULE_TOKEN_REGEX = re.compile(r" +|\n|#[^\n]*|[a-zA-Z_][a-zA-Z0-9_]*|'[^']+'|.")
NAME_CHARS = ascii_lowercase + '_'
TOKTYPE_CHARS = ascii_uppercase + '_'


GrammarPatternPartType = Literal['rule'] | Literal['toktype'] | Literal['tokvalue']
GrammarPatternPart = tuple[GrammarPatternPartType, str]
GrammarPattern = list[GrammarPatternPart]


def pattern_to_string(pattern: GrammarPattern) -> str:
    return ' '.join(
        repr(v) if t == 'tokvalue' else v
        for t, v in pattern)


class GrammarRule(NamedTuple):
    name: str
    patterns: list[GrammarPattern]

    def pprint(self):
        print(self.name)
        for i, pattern in enumerate(self.patterns):
            sep = ':' if i == 0 else '|'
            print(f'    {sep} ' + pattern_to_string(pattern))
        print('    ;')


class GrammarParseError(Exception):
    pass


def parse_rules_from_file(filename: str) -> dict[str, GrammarRule]:
    return parse_rules(open(filename, 'r').read(), filename)


def parse_rules(text: str, filename: str = '<fakefile>') -> dict[str, GrammarRule]:
    """

        >>> rules = parse_rules('''
        ...     # Comment
        ...     rule1
        ...       : NUMBER
        ...       | '(' rule1 ')'
        ...       ;
        ...     rule1_list: rule1 | rule1 ',' rule1;
        ... ''')

        >>> for name, rule in rules.items(): rule.pprint()
        rule1
            : NUMBER
            | '(' rule1 ')'
            ;
        rule1_list
            : rule1
            | rule1 ',' rule1
            ;

    """
    rules = {}
    rule = None
    pattern = None
    row = 1
    col = 1
    tokens = (match.group() for match in RULE_TOKEN_REGEX.finditer(text))

    def error(msg: str) -> GrammarParseError:
        return GrammarParseError(f"{filename}:{row}:{col}: {msg}")
    def unexpected() -> GrammarParseError:
        raise error(f"Unexpected: {token!r}")

    prev_token = ''
    for token in tokens:
        if prev_token == '\n':
            col = 1
            row += 1
        else:
            col += len(prev_token)
        prev_token = token

        # Decide what kind of token is is based on first character
        c = token[0]
        if c in '# \n':
            # Eat comments & whitespace
            continue

        # POSSIBLE STATES:
        if rule is None:
            # Not in a rule definition
            if c in ascii_lowercase:
                # Start a new rule definition
                if token in rules:
                    raise error(f"Duplicate definition for rule: {token!r}")
                rule = rules[token] = GrammarRule(name=token, patterns=[])
            else:
                raise unexpected()
        elif pattern is None:
            # In a rule definition, before ':'
            if c == ':':
                # Start parsing patterns for the current rule
                pattern = []
            else:
                raise unexpected()
        else:
            # In a rule definition, after ':'
            if c == ';':
                # Finish the current rule definition
                rule.patterns.append(pattern)
                rule = None
                pattern = None
            elif c == '|':
                # Start a new pattern for current rule
                rule.patterns.append(pattern)
                pattern = []
            elif c == "'":
                pattern.append(('tokvalue', token[1:-1]))
            elif c in NAME_CHARS:
                pattern.append(('rule', token))
            elif c in TOKTYPE_CHARS:
                pattern.append(('toktype', token))
            else:
                raise unexpected()

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
        ...     value: NUMBER | array ;
        ...     array
        ...         : '[' ']'
        ...         | '[' value_list ']'
        ...         ;
        ...     value_list: value ',' value_list | value ;
        ... ''')

        >>> from loosey.pplex import Lexer
        >>> tokens = [token for line in Lexer().tokenize('''
        ...     [1, 2, [], [3, 4]]
        ... ''') for token in line]

        >>> parser = GrammarParser(rules, tokens, verbose=False)

        >>> match = parser.match_rule('value')
        >>> match.pprint()
        value
          array
            value_list
              1
              value_list
                2
                value_list
                  value
                    [
                  value_list
                    value
                      array
                        value_list
                          3
                          value_list
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

        self.match_depth = 0

        self.match_cache: dict[ParseMatchKey, Optional[ParseMatch]] = {}

    def match_rule(self, rule_name: str, token_i: int = 0) -> Optional[ParseMatch]:
        if self.verbose:
            print('  ' * self.match_depth + f"RULE: {rule_name}")
        rule = self.rules[rule_name]
        self.match_depth += 1
        try:
            for pattern_i in range(len(rule.patterns)):
                match = self.match_pattern(rule_name, pattern_i, token_i)
                if match is not None:
                    return match
            return None
        finally:
            self.match_depth -= 1

    def match_pattern(self, rule_name: str, pattern_i: int, token_i: int) -> Optional[ParseMatch]:
        rule = self.rules[rule_name]
        pattern = rule.patterns[pattern_i]
        if self.verbose:
            print('  ' * self.match_depth + f"PATTERN {pattern_i}: {pattern_to_string(pattern)}")
        cache_key = (rule_name, pattern_i, token_i)
        if cache_key in self.match_cache:
            if self.verbose:
                print('  ' * self.match_depth + "...FOUND IN CACHE!")
            return self.match_cache[cache_key]

        def cached(value):
            self.match_cache[cache_key] = value
            return value

        if token_i >= len(self.tokens):
            return cached(None)

        original_token_i = token_i
        children = []

        self.match_depth += 1
        try:
            for part_type, part_value in pattern:
                if part_type == 'rule':
                    match = self.match_rule(part_value, token_i)
                    if match is None:
                        return cached(None)
                    assert match.token_i == token_i
                    token_i = token_i + match.n_tokens
                    children.append(match)
                else:
                    if token_i >= len(self.tokens):
                        return cached(None)
                    token = self.tokens[token_i]
                    if self.verbose:
                        print('  ' * self.match_depth + f"TOKEN: {token.value!r}")
                    if part_type == 'toktype':
                        if token.toktype != part_value:
                            return cached(None)
                        token_i += 1
                    elif part_type == 'tokvalue':
                        if token.value != part_value:
                            return cached(None)
                        token_i += 1
                    else:
                        # We should never get here...
                        raise Exception(f"Unrecognized pattern part type: {part_type!r}")

            if self.verbose:
                print('  ' * (self.match_depth - 1) + "...MATCHED!")
            return cached(ParseMatch(
                rule_name=rule_name,
                pattern_i=pattern_i,
                token=self.tokens[original_token_i],
                token_i=original_token_i,
                n_tokens=token_i - original_token_i,
                children=children,
            ))
        finally:
            self.match_depth -= 1
