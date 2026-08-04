import re
import os
from argparse import ArgumentParser
from typing import NamedTuple, Literal, Sequence, Optional, Union
from string import ascii_lowercase, ascii_uppercase
from functools import cached_property

from loosey.pplex import Token, Lexer, ParseError, tokenize_file


RULE_TOKEN_REGEX = re.compile(r" +|\n|#[^\n]*|\)[?*]|[a-z][a-z0-9_]*:?|[A-Z][A-Z0-9_]*|'[^']+'|.")
RULE_NAME_CHARS = ascii_lowercase + '_'
TOKTYPE_CHARS = ascii_uppercase + '_'


GrammarPatternPartType = (
    Literal['rule']
    | Literal['toktype']
    | Literal['tokvalue']
    | Literal['maybe']
    | Literal['star']
)

# Part consists of: (part_type, part_value)
GrammarPatternPart = tuple[GrammarPatternPartType, Union[str, 'GrammarPattern']]

class GrammarPattern(NamedTuple):
    name: Optional[str]
    parts: list[GrammarPatternPart]


def pattern_to_string(pattern: GrammarPattern) -> str:
    s_parts = []
    if pattern.name:
        s_parts.append(f'{pattern.name}:')
    def visit(pattern):
        for part_type, part_value in pattern.parts:
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
        ...         | negative: '-' value
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
            | negative: '-' value
            | array
            ;
        array
            | '[' ( value ( ',' value )* )? ']'
            ;

    """
    rules = {}
    rule = None
    pattern_name = None
    pattern_parts = None
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
            if c in RULE_NAME_CHARS and token[-1] != ':':
                # Start a new rule definition
                if token in rules:
                    raise error(f"Duplicate definition for rule: {token!r}")
                rule = rules[token] = GrammarRule(name=token, patterns=[])
            else:
                raise unexpected(token)
        elif pattern_parts is None:
            # In a rule definition, before first pattern
            if c == '|':
                # Start parsing patterns for the current rule
                pattern_parts = []
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
                rule.patterns.append(GrammarPattern(
                    name=pattern_name,
                    parts=pattern_parts,
                ))
                rule = None
                pattern_name = None
                pattern_parts = None
                pattern_stack = None
            elif c == '|':
                # Start a new pattern for current rule
                if pattern_stack:
                    raise error("Unterminated pattern")
                rule.patterns.append(GrammarPattern(
                    name=pattern_name,
                    parts=pattern_parts,
                ))
                pattern_name = None
                pattern_parts = []
            elif c == "'":
                pattern_parts.append(('tokvalue', token[1:-1]))
            elif c in RULE_NAME_CHARS:
                if token[-1] == ':':
                    if pattern_parts or pattern_stack or pattern_name:
                        raise unexpected(token)
                    pattern_name = token[:-1]
                else:
                    pattern_parts.append(('rule', token))
            elif c in TOKTYPE_CHARS:
                pattern_parts.append(('toktype', token))
            elif c == '(':
                pattern_stack.append(pattern_parts)
                pattern_parts = []
            elif c == ')':
                if token == ')?':
                    part_type = 'maybe'
                elif token == ')*':
                    part_type = 'star'
                else:
                    raise unexpected(token)
                if not pattern_stack:
                    raise unexpected(token)
                old_parts = pattern_stack.pop()
                # NOTE: sub-patterns currently can't have names, just because
                # it didn't seem that useful, so we're keeping the
                # pattern-parser simple
                sub_pattern = GrammarPattern(name=None, parts=pattern_parts)
                old_parts.append((part_type, sub_pattern))
                pattern_parts = old_parts
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
    pattern_name: Optional[str]

    # The token matching the start of the pattern
    token: Token

    # The slice of matched tokens is parser.tokens[token_i: n_tokens]
    token_i: int
    n_tokens: int

    children: list['ParseMatch']

    def prettystring(self):
        if self.children:
            children_s = ' '.join(child.prettystring() for child in self.children)
            return f'({self.rule_name} {children_s})'
        else:
            return self.token.value

    def pprint(self, depth=0):
        prefix = '  ' * depth
        if self.pattern_name:
            prefix = f'{prefix}{self.pattern_name}: '
        if self.children:
            print(prefix + self.rule_name)
            for child in self.children:
                child.pprint(depth+1)
        else:
            print(prefix + self.token.value)


# Internal type used by GrammarParser.match_pattern.
# Represents a tuple (children, token_i)
_MatchResult = tuple[list[ParseMatch], int]


class GrammarParser:
    """

        >>> rules = parse_rules('''
        ...
        ...     value
        ...         | NUMBER
        ...         | negative: '-' value
        ...         | array
        ...         ;
        ...
        ...     array
        ...         | '[' ( value ( ',' value )* )? ']'
        ...         ;
        ...
        ... ''')

        >>> def parse(text, rule_name='value', **kwargs):
        ...     parser = GrammarParser(rules, text, **kwargs)
        ...     match = parser.match_rule(rule_name)
        ...     if match is not None:
        ...         match.pprint()

        >>> parse('1')
        1

        >>> parse('-1')
        negative: value
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

        >>> parse('[1, [2, -3], -4, []]', squash_children=True)
        array
          1
          array
            2
            negative: value
              3
          negative: value
            4
          [

    """

    def __init__(
            self,
            rules: dict[str, GrammarRule] | str,
            tokens: Sequence[Token] | str,
            *,
            verbose: bool = False,
            main_rule_name: Optional[str] = None,
            max_match_depth: Optional[int] = None,
            squash_children: bool = False,
            ):
        if isinstance(rules, str):
            # Support caller passing us text, handy for doctests
            rules = parse_rules(rules)
        if isinstance(tokens, str):
            # Support caller passing us text, handy for doctests
            tokens = [token for line in Lexer().tokenize(tokens)
                for token in line]
        self.rules = rules
        self.tokens = tokens
        self.verbose = verbose
        self.max_match_depth = max_match_depth
        self.squash_children = squash_children

        if main_rule_name is None:
            main_rule_name = next(reversed(self.rules), None)
        self.main_rule_name = main_rule_name

        self.match_depth = 0
        self.match_cache: dict[ParseMatchKey, Optional[ParseMatch]] = {}

    def match(self) -> Optional[ParseMatch]:
        if self.main_rule_name is None:
            raise Exception("No main rule")
        return self.match_rule(self.main_rule_name, full=True)

    def increase_match_depth(self):
        self.match_depth += 1
        if self.max_match_depth is not None and self.match_depth >= self.max_match_depth:
            raise Exception(f"Exceeded max match depth: {self.max_match_depth}")

    def match_rule(self, rule_name: str, token_i: int = 0, *, full: bool = False) -> Optional[ParseMatch]:
        if self.verbose:
            print('. ' * self.match_depth + f"RULE: {rule_name}")
        rule = self.rules[rule_name]
        self.increase_match_depth()
        try:
            # Attempt to match against each of this rule's patterns
            for pattern_i in range(len(rule.patterns)):
                match = self.match_pattern(rule_name, pattern_i, token_i)
                if match is not None:
                    # Hooray, we matched one of this rule's patterns
                    if full and match.token_i + match.n_tokens != len(self.tokens):
                        # If user only wanted a full match, and we only have a
                        # partial match, then it's no match at all!
                        return None
                    # We have a match for the rule!
                    return match
            # No patterns matched, so the rule doesn't match!
            return None
        finally:
            self.match_depth -= 1

    def match_pattern(self, rule_name: str, pattern_i: int, token_i: int) -> Optional[ParseMatch]:
        rule = self.rules[rule_name]
        pattern = rule.patterns[pattern_i]
        if self.verbose:
            print('. ' * self.match_depth + f"PATTERN {pattern_i}: {pattern_to_string(pattern)}")

        # If we already have a cached result, just return that
        cache_key = (rule_name, pattern_i, token_i)
        if cache_key in self.match_cache:
            if self.verbose:
                print('. ' * self.match_depth + "FOUND IN CACHE!")
            return self.match_cache[cache_key]

        # Make sure that when we return a value, we add it to the cache
        def cached(value):
            self.match_cache[cache_key] = value
            return value

        # If we're past the end of our tokens, clearly there is no match!
        # (This means we don't support "empty" rules or patterns.)
        if token_i >= len(self.tokens):
            return cached(None)

        # Recursively match the pattern and its subpatterns
        def match_subpattern(subpattern: GrammarPattern, token_i: int) -> Optional[_MatchResult]:
            # NOTE: we return (children, token_i) or None
            original_token_i = token_i
            children = []
            self.increase_match_depth()
            try:
                for part_type, part_value in subpattern.parts:
                    if part_type == 'rule':
                        # This pattern consists of matching against another
                        # rule
                        match = self.match_rule(part_value, token_i)
                        if match is None:
                            if self.verbose:
                                print('. ' * self.match_depth + "NOT MATCH")
                            return None
                        assert match.token_i == token_i
                        token_i = token_i + match.n_tokens
                        children.append(match)
                    elif part_type == 'maybe':
                        # Zero or one matches of subpattern
                        if self.verbose:
                            print('. ' * self.match_depth + f"SUB-PATTERN ({part_type}): {pattern_to_string(part_value)}")
                        result = match_subpattern(part_value, token_i)
                        if result:
                            sub_children, token_i = result
                            children.extend(sub_children)
                    elif part_type == 'star':
                        # Zero or more matches of subpattern
                        if self.verbose:
                            print('. ' * self.match_depth + f"SUB-PATTERN ({part_type}): {pattern_to_string(part_value)}")
                        while True:
                            result = match_subpattern(part_value, token_i)
                            if result:
                                sub_children, token_i = result
                                children.extend(sub_children)
                            else:
                                break
                    else:
                        # Matching against a single token
                        if token_i >= len(self.tokens):
                            if self.verbose:
                                print('. ' * self.match_depth + "END OF INPUT")
                            return None
                        token = self.tokens[token_i]
                        if self.verbose:
                            print('. ' * self.match_depth + f"TOKEN: {token.value!r}")
                        if part_type == 'toktype':
                            # Match against token's toktype
                            if token.toktype != part_value:
                                if self.verbose:
                                    print('. ' * self.match_depth + "NOT MATCH")
                                return None
                            token_i += 1
                        elif part_type == 'tokvalue':
                            # Match against token's value
                            if token.value != part_value:
                                if self.verbose:
                                    print('. ' * self.match_depth + "NOT MATCH")
                                return None
                            token_i += 1
                        else:
                            # We should never get here...
                            raise Exception(f"Unrecognized pattern part type: {part_type!r}")
                if self.verbose:
                    thing = 'RULE' if subpattern is pattern else 'SUB-PATTERN'
                    print('. ' * self.match_depth + f"{thing} MATCHED!")
                return children, token_i
            finally:
                self.match_depth -= 1

        # Match the pattern...
        original_token_i = token_i
        result = match_subpattern(pattern, token_i)
        if result is None:
            return cached(None)
        children, token_i = result

        # Return a match object
        if (
            self.squash_children
            and len(children) == 1
            and not pattern.name # don't squash named patterns!
        ):
            return cached(children[0]._replace(
                token_i=original_token_i,
                n_tokens=token_i - original_token_i,
            ))
        else:
            return cached(ParseMatch(
                rule_name=rule_name,
                pattern_name=pattern.name,
                token=self.tokens[original_token_i],
                token_i=original_token_i,
                n_tokens=token_i - original_token_i,
                children=children,
            ))


class GrammarEvaluator:
    """Base class which can be extended to evaluate expressions of a
    particular grammar.

        >>> rules = parse_rules('''
        ...
        ...     value
        ...         | NUMBER
        ...         | negative: '-' value
        ...         | array
        ...         ;
        ...
        ...     array
        ...         | '[' ( value ( ',' value )* )? ']'
        ...         ;
        ...
        ... ''')

        >>> class ValueEvaluator(GrammarEvaluator):
        ...     grammar_rules = rules
        ...     main_rule_name = 'value'
        ...     squash_children = True
        ...     def on_negative__value(self, match):
        ...         return -self.on(match.children[0])
        ...     def on_value(self, match):
        ...         return int(match.token.value)
        ...     def on_array(self, match):
        ...         return [self.on(child) for child in match.children]

        >>> evaluator = ValueEvaluator()

        >>> evaluator.eval('1')
        1

        >>> evaluator.eval('-1')
        -1

        >>> evaluator.eval('[]')
        []

        >>> evaluator.eval('[1, 2, [-3, -4]]')
        [1, 2, [-3, -4]]

        >>> evaluator.eval('x y z')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: Couldn't parse as: value

    """

    grammar_filename: Optional[str] = None
    main_rule_name: Optional[str] = None
    squash_children: bool = False

    def __init__(self):
        self.validate()

    def get_handler_name(self, rule_name: str, pattern_name: Optional[str] = None) -> str:
        return (
            f'on_{pattern_name}__{rule_name}' if pattern_name
            else f'on_{rule_name}')

    def validate(self):
        bad_method_names = []
        possible_method_names = {
            self.get_handler_name(rule_name, pattern.name)
            for rule_name, rule in self.grammar_rules.items()
            for pattern in rule.patterns}
        for attr in dir(self):
            if attr.startswith('on_'):
                if attr not in possible_method_names:
                    bad_method_names.append(attr)
        if bad_method_names:
            raise Exception(f"Handler methods for missing rules/patterns: {', '.join(bad_method_names)}")

    @cached_property
    def grammar_rules(self) -> dict[str, GrammarRule]:
        # NOTE: subclasses may want to override this property
        if self.grammar_filename is not None:
            return parse_rules_from_file(self.grammar_filename)
        raise NotImplementedError("To be implemented by subclasses")

    def coerce_tokens(self, tokens: list[Token] | str) -> list[Token]:
        # NOTE: subclasses may want to override this property... for instance,
        # to stick a C preprocessor in front of it ;)
        if isinstance(tokens, str):
            # Support caller passing us a string, handy for doctests
            tokens = [token for line in Lexer().tokenize(tokens)
                for token in line]
        return tokens

    def parse(self, tokens: list[Token] | str, rule_name: Optional[str] = None) -> Optional[ParseMatch]:
        tokens = self.coerce_tokens(tokens)
        parser = GrammarParser(
            self.grammar_rules,
            tokens,
            main_rule_name=rule_name or self.main_rule_name,
            squash_children=self.squash_children,
        )
        return parser.match()

    def no_match(self, tokens: list[Token], rule_name: str):
        # NOTE: subclasses may want to override this method with custom
        # error message, etc
        first_token = tokens[0] if tokens else None
        raise ParseError(first_token, f"Couldn't parse as: {rule_name}")

    def eval(self, tokens: list[Token] | str, rule_name: Optional[str] = None):
        tokens = self.coerce_tokens(tokens)
        rule_name = rule_name or self.main_rule_name
        match = self.parse(tokens, rule_name)
        if match is None:
            self.no_match(tokens, rule_name)
        return self.on(match)

    def default(self, match: ParseMatch):
        # NOTE: subclasses probably want to override this method
        raise ParseError(match.token, "Don't know how to evaluate: {match.token.prettystring()}")

    def on(self, match: ParseMatch):
        handler_name = self.get_handler_name(match.rule_name, match.pattern_name)
        handler = getattr(self, handler_name, None)
        if handler is not None:
            return handler(match)
        else:
            return self.default(match)


def main():
    parser = ArgumentParser()
    parser.add_argument('-g', '--grammar')
    parser.add_argument('-p', '--print-grammar', default=False, action='store_true')
    parser.add_argument('-m', '--max-match-depth', type=int)
    parser.add_argument('-f', '--filename', default='-')
    parser.add_argument('-r', '--rule-name')
    parser.add_argument('--partial', default=False, action='store_true')
    parser.add_argument('-s', '--squash-children', default=False, action='store_true')
    parser.add_argument('-v', '--verbose', default=False, action='store_true')
    args = parser.parse_args()

    if not args.grammar:
        print(f"Missing grammar file (-g|--grammar), try one of:")
        for fname in get_grammar_filenames():
            print(f" * {fname}")
        sys.exit(1)

    grammar_filename = args.grammar
    rules = parse_rules_from_file(grammar_filename)
    if args.print_grammar:
        for name, rule in rules.items():
            rule.pprint()
        return

    filename = args.filename
    tokens = [token for line in tokenize_file(filename) for token in line]
    parser = GrammarParser(rules, tokens,
        verbose=args.verbose,
        max_match_depth=args.max_match_depth,
        squash_children=args.squash_children,
    )
    rule_name = args.rule_name or parser.main_rule_name
    match = parser.match_rule(rule_name, full=not args.partial)
    if match is None:
        print("No match!")
    else:
        match.pprint()


if __name__ == '__main__':
    main()
