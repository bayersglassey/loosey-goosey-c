import re
import os
import sys
from tempfile import NamedTemporaryFile
from argparse import ArgumentParser
from typing import (
    Literal,
    Sequence,
    NamedTuple,
    Optional,
    Union,
    Callable,
    Iterable,
)
from string import ascii_lowercase, ascii_uppercase
from functools import cached_property, lru_cache

from loosey import get_data_filepath
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
    | Literal['oneof']
)

# Part consists of: (part_type, part_value)
GrammarPatternPart = tuple[GrammarPatternPartType, Union[str, 'GrammarPattern']]

class GrammarPattern(NamedTuple):
    name: Optional[str]
    parts: list[GrammarPatternPart]

    def prettystring(self) -> str:
        s_parts = []
        if self.name:
            s_parts.append(f'{self.name}:')
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
                elif part_type == 'oneof':
                    s_parts.append('[ ' + ' '.join(map(repr, part_value)) + ' ]')
                else:
                    s_parts.append(part_value)
        visit(self)
        return ' '.join(s_parts)

    def downstream_rules(self) -> list[str]:
        downstream_rules = []
        def visit(pattern):
            for part_type, part_value in pattern.parts:
                if part_type == 'rule':
                    downstream_rules.append(part_value)
                elif part_type in ('maybe', 'star'):
                    visit(part_value)
        visit(self)
        return downstream_rules


class GrammarRule(NamedTuple):
    name: str
    patterns: list[GrammarPattern]

    def pprint(self):
        print(self.name)
        for i, pattern in enumerate(self.patterns):
            print('    | ' + pattern.prettystring())
        print('    ;')

    def downstream_rules(self) -> list[str]:
        downstream_rules = []
        for pattern in self.patterns:
            downstream_rules.extend(pattern.downstream_rules())
        return downstream_rules


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
        ...         | bool: [ 'true' 'false' ]
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
            | bool: [ 'true' 'false' ]
            | array
            ;
        array
            | '[' ( value ( ',' value )* )? ']'
            ;

        >>> print_rule_graph(rules)
        digraph {
          rankdir = "LR";
          "value" [label="RULE: value"];
          "value.0" [label="PAT value[0]: NUMBER"];
          "value" -> "value.0";
          "value.1" [label="PAT value[1]: negative: '-' value"];
          "value" -> "value.1";
          "value.2" [label="PAT value[2]: bool: [ 'true' 'false' ]"];
          "value" -> "value.2";
          "value.3" [label="PAT value[3]: array"];
          "value" -> "value.3";
          "array" [label="RULE: array"];
          "array.0" [label="PAT array[0]: '[' ( value ( ',' value )* )? ']'"];
          "array" -> "array.0";
          "value.1" -> "value";
          "value.3" -> "array";
          "array.0" -> "value";
          "array.0" -> "value";
        }

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
                raise error(f"Rule has no patterns: {rule.name}")
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
            elif c in '([':
                pattern_stack.append((c, pattern_parts))
                pattern_parts = []
            elif c in ')]':
                if token == ')?':
                    part_type = 'maybe'
                elif token == ')*':
                    part_type = 'star'
                elif token == ']':
                    part_type = 'oneof'
                else:
                    raise unexpected(token)
                if not pattern_stack:
                    raise unexpected(token)
                old_c, old_parts = pattern_stack.pop()
                expected_c = ')]'['(['.index(old_c)]
                if c != expected_c:
                    raise error(f"Expected {expected_c!r}, got {c!r}")
                if part_type == 'oneof':
                    bad_parts = [part for part in pattern_parts
                        if part[0] != 'tokvalue']
                    if bad_parts:
                        raise error(f"Entries of [...] should all be exact token matches, but got: {bad_parts}")
                    values = [part[1] for part in pattern_parts]
                    old_parts.append((part_type, values))
                else:
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


def get_reachable_rules(rules: dict[str, GrammarRule], from_rules: Iterable[str]) -> set[str]:
    if isinstance(from_rules, str):
        from_rules = [from_rules]
    rules_to_visit = set(from_rules)
    visited_rules = set()
    while rules_to_visit:
        rule_name = rules_to_visit.pop()
        visited_rules.add(rule_name)
        rule = rules[rule_name]
        for other_rule_name in rule.downstream_rules():
            if other_rule_name not in visited_rules:
                rules_to_visit.add(other_rule_name)
    return visited_rules


def get_rule_graph(rules: dict[str, GrammarRule], *, from_rules: Iterable[str] = ()) -> list[str]:
    if from_rules:
        rules = {name: rules[name]
            for name in get_reachable_rules(rules, from_rules)}
    lines = []
    lines.append('digraph {')
    lines.append('  rankdir = "LR";')
    def escape(s: str) -> str:
        """Escape a string for use in Graphviz's DOT syntax"""
        return ('"' + s
            .replace('\n', r'\n')
            .replace('\\', r'\\')
            .replace('"', r'\"')
        + '"')
    def get_rule_node(rule_name) -> str:
        return escape(rule_name)
    def get_pattern_node(rule_name, pattern_i) -> str:
        return escape(f'{rule_name}.{pattern_i}')
    for rule_name, rule in rules.items():
        rule_node = get_rule_node(rule_name)
        label = f"RULE: {rule_name}"
        lines.append(f'  {rule_node} [label={escape(label)}];')
        for pattern_i, pattern in enumerate(rule.patterns):
            pattern_node = get_pattern_node(rule_name, pattern_i)
            label = f'PAT {rule_name}[{pattern_i}]: {pattern.prettystring()}'
            lines.append(f'  {pattern_node} [label={escape(label)}];')
            lines.append(f'  {rule_node} -> {pattern_node};')
    for rule_name, rule in rules.items():
        rule_node = get_rule_node(rule_name)
        for pattern_i, pattern in enumerate(rule.patterns):
            pattern_node = get_pattern_node(rule_name, pattern_i)
            for other_rule_name in pattern.downstream_rules():
                other_rule_node = get_rule_node(other_rule_name)
                lines.append(f'  {pattern_node} -> {other_rule_node};')
    lines.append('}')
    return lines


def print_rule_graph(rules: dict[str, GrammarRule], **kwargs):
    for line in get_rule_graph(rules, **kwargs):
        print(line)


def render_rule_graph(
        rules: dict[str, GrammarRule],
        *,
        ext='svg',
        view=True,
        viewer='xdg-open',
        **kwargs):
    with NamedTemporaryFile('w', delete=False) as file:
        print(f"=== Writing graph to: {file.name}")
        for line in get_rule_graph(rules, **kwargs):
            file.write(line)
            file.write('\n')
    ofile = f'{file.name}.{ext}'
    print(f"=== Rendering graph to: {ofile}")
    os.system(f'dot -T{ext} {file.name} -o {ofile}')
    if view:
        print(f"=== Opening: {ofile}")
        os.system(f'{viewer} {ofile}')


class ParseMatchKey(NamedTuple):
    """Cache key for GrammarParser.match_pattern"""
    rule_name: str
    pattern_i: int
    token_i: int


# (rule_name or '.', pattern_name or '.', suffix)
_FindPart = tuple[str, Optional[str], str]


@lru_cache
def _parse_find_parts(spec: str) -> list[_FindPart]:
    # Parse the argument to ParseMatch.find() (the "spec") into "parts",
    # each part being a tuple:
    #   (rule_name, pattern_name, suffix)
    # ...where suffix is a regex suffix '*', '+', '?', or ''.
    parts: list[_FindPart] = []
    if not spec:
        return parts
    for part_s in spec.split(' '):
        if part_s[-1] in '*+?':
            suffix = part_s[-1]
            part_s = part_s[:-1]
        else:
            suffix = ''
        if ':' in part_s:
            pattern_name, rule_name = part_s.split(':', 1)
            if not pattern_name:
                pattern_name = None
            if not rule_name:
                rule_name = '.'
        else:
            rule_name = part_s
            pattern_name = '.'
        if not rule_name:
            raise Exception(f"Bad find syntax (no rule name): {part_s!r}")
        parts.append((rule_name, pattern_name, suffix))
    return parts


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

    def __repr__(self):
        return f'{self.__class__.__name__}({self.prettystring()})'

    def prettystring(self):
        if self.children:
            children_s = ' '.join(child.prettystring() for child in self.children)
            return f'{self.spec} ({children_s})'
        else:
            return f'{self.spec} {self.token.value}'

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

    @property
    def spec(self) -> str:
        return f"{self.pattern_name or ''}:{self.rule_name}"

    @property
    def handler_name(self) -> str:
        return GrammarEvaluator.get_handler_name(self.rule_name, self.pattern_name)

    def missing_handler(self) -> ParseError:
        # For when we're missing the GrammarEvaluator method which would
        # have handled evaluating this match...
        return ParseError(self.token, f"Missing handler: {self.handler_name}")

    def find(self, spec: str, **kwargs) -> Optional['ParseMatch']:
        matches = self.findall(spec, **kwargs)
        return None if not matches else matches[0]

    def findall(self, spec: str, *, verbose: bool = False) -> list['ParseMatch']:

        # Parse the spec into "parts", each part being a tuple:
        #   (rule_name, pattern_name, suffix)
        # ...where suffix is a regex suffix '*', '+', '?', or ''.
        parts: list[_FindPart] = _parse_find_parts(spec)

        matches = [self]
        for part in parts:
            rule_name, pattern_name, suffix = part
            if verbose:
                print(f"Filtering {len(matches)} matches by: {pattern_name}:{rule_name}{suffix}")
            # Prepare to enter the loop...
            if suffix and suffix in '*?':
                # Even zero applications of this part are ok, i.e. whatever
                # matches we already had, we should keep!
                iteration_matches = matches.copy()
            else:
                iteration_matches = matches
                matches = []
            while True:
                # We may go through several iterations of a loop, generating
                # matches each time around it.
                if verbose:
                    print(f"  Iterating on {len(matches)} matches")
                child_matches = []
                for match in iteration_matches:
                    if verbose:
                        print(f"    Considering children of: {match.prettystring()}")
                    for child in match.children:
                        if (
                            (rule_name == '.' or child.rule_name == rule_name) and
                            (pattern_name == '.' or child.pattern_name == pattern_name)
                        ):
                            if verbose:
                                print(f"      Accepted: {child.prettystring()}")
                            child_matches.append(child)
                        else:
                            if verbose:
                                print(f"      Rejected: {child.prettystring()}")
                # Save the matches from this loop iteration
                matches.extend(child_matches)
                # Potentially continue applying this same part to the matches
                # from this loop iteration
                if suffix and suffix in '*+' and child_matches:
                    # We had some matches, now consider their children!
                    iteration_matches = child_matches
                    continue
                else:
                    break
            if not matches:
                # If we're out of potential matches, then we're done, exit
                # early, applying more parts of the spec wouldn't result in
                # any matches
                break
        # If we're out of parts, then we've successfully applied the entire
        # spec, so return whatever matches we have
        return matches


# Something which happens when the indicated rule is entered/exited
PatternEnterCallback = Callable[[Token], None]
PatternExitCallback = Callable[[Token, Optional[ParseMatch]], None]

# A pair (rule_name, pattern_name) which maps to a Pattern{Enter,Exit}Callback
PatternCallbackKey = tuple[str, Optional[str]]

# Decides something about the given token
TokenPredicate = Callable[[Token], bool]


# Internal type used by GrammarParser.match_pattern.
# Represents a tuple (children, token_i)
_MatchResult = tuple[list[ParseMatch], int]


class _LongestMatch(NamedTuple):
    rule_name: str
    pattern: GrammarPattern
    token_i: int


class GrammarParser:
    """A parser for the grammar specified by rules given to the constructor.

        >>> rules = parse_rules('''
        ...
        ...     value
        ...         | NUMBER
        ...         | negative: '-' value
        ...         | bool: [ 'true' 'false' ]
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
        ...     return parser.match_rule(rule_name)

        >>> def test(text, **kwargs):
        ...     match = parse(text, **kwargs)
        ...     if match is not None:
        ...         match.pprint()

        >>> test('1')
        1

        >>> test('-1')
        negative: value
          1

        Matching a prefix of the input:
        >>> test('1 other stuff')
        1

        No match:
        >>> test('x')

        >>> test('[]')
        value
          [

        >>> test('[1]')
        value
          array
            1

        >>> test('[1,]')

        >>> test('[1, 2]')
        value
          array
            1
            2

        >>> test('[1, [2, 3], 4]')
        value
          array
            1
            value
              array
                2
                3
            4

        >>> test('[1, [2, -3], -4, []]', squash_children=True)
        array
          1
          array
            2
            negative: value
              3
          negative: value
            4
          [

    Using match.find() and match.findall():

        Calling match.find('') always returns match as-is:
        >>> parse('1').find('').pprint()
        1

        >>> match = parse('[[1, [2, 3], -4], 99]', squash_children=True)
        >>> match.pprint()
        array
          array
            1
            array
              2
              3
            negative: value
              4
          99

        >>> match.find('array value').pprint()
        1

        >>> match.find('array nonexistant')

        >>> for child in match.findall('array value'): child.pprint()
        1
        negative: value
          4

        >>> for child in match.findall('array .'): child.pprint()
        1
        array
          2
          3
        negative: value
          4

        >>> for child in match.findall('array :value'): child.pprint()
        1

        >>> for child in match.findall('array negative:value'): child.pprint()
        negative: value
          4

        >>> for child in match.findall('. value'): child.pprint()
        1
        negative: value
          4

        >>> for child in match.findall('.? value'): child.pprint()
        99
        1
        negative: value
          4

        >>> for child in match.findall('.+ value'): child.pprint()
        1
        negative: value
          4
        2
        3
        4

        >>> for child in match.findall('.* value'): child.pprint()
        99
        1
        negative: value
          4
        2
        3
        4

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
            pattern_callbacks: dict[PatternCallbackKey, tuple[PatternEnterCallback, PatternExitCallback]] = None,
            toktype_predicates: dict[str, TokenPredicate] = None,
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
        self.pattern_callbacks = pattern_callbacks or {}
        self.toktype_predicates = toktype_predicates or {}

        if main_rule_name is None:
            main_rule_name = next(reversed(self.rules), None)
        self.main_rule_name = main_rule_name

        self.match_depth = 0
        self.match_stack: list[ParseMatchKey] = []
        self.match_cache: dict[ParseMatchKey, Optional[ParseMatch]] = {}

        self.longest_match: Optional[_LongestMatch] = None

    def get_parse_error(self, msg: Optional[str] = None) -> Optional[ParseError]:
        """After a failed parse returns None, we can attempt to produce
        a parse error based on the longest successful partial match

            >>> rules = parse_rules('''
            ...     value
            ...         | NUMBER
            ...         | '(' value '+' value ')'
            ...         ;
            ... ''')

            >>> GrammarParser(rules, '(1 + 2)').fullmatch().pprint()
            value
              1
              2

            >>> GrammarParser(rules, '(1 + (2 +').fullmatch(raise_on_no_match=True)
            Traceback (most recent call last):
             ...
            loosey.pplex.ParseError: <fakefile>:1:9: Parsed up to here

        """
        if self.longest_match is None:
            return ParseError(None, msg or "Not even a partial match!")
        rule_name = self.longest_match.rule_name
        rule = self.rules[rule_name]
        pattern = self.longest_match.pattern
        token = self.tokens[self.longest_match.token_i]
        return ParseError(token, msg or "Parsed up to here")

    def fullmatch(self, **kwargs) -> Optional[ParseMatch]:
        return self.match_rule(full=True, **kwargs)

    def increase_match_depth(self):
        self.match_depth += 1
        if self.max_match_depth is not None and self.match_depth >= self.max_match_depth:
            raise Exception(f"Exceeded max match depth: {self.max_match_depth}")

    def decrease_match_depth(self):
        self.match_depth -= 1

    def match_rule(
            self,
            rule_name: Optional[str] = None,
            token_i: int = 0,
            *,
            full: bool = False,
            raise_on_no_match: bool = False,
            ) -> Optional[ParseMatch]:
        if rule_name is None:
            if self.main_rule_name is None:
                raise Exception("No rule specified")
            rule_name = self.main_rule_name
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
                        break
                    # We have a match for the rule!
                    return match
            # No patterns matched, so the rule doesn't match!
            if raise_on_no_match:
                raise self.get_parse_error()
            else:
                return None
        finally:
            self.decrease_match_depth()

    def match_pattern(self, rule_name: str, pattern_i: int, token_i: int) -> Optional[ParseMatch]:
        rule = self.rules[rule_name]
        pattern = rule.patterns[pattern_i]
        if self.verbose:
            print('. ' * self.match_depth + f"PATTERN {pattern_i}: {pattern.prettystring()}")

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

        token = self.tokens[token_i]

        if cache_key in self.match_stack:
            cache_key_index = self.match_stack.index(cache_key)
            msg = ' -> '.join(
                f"{self.rules[rule_name].patterns[pattern_i].name or ''}:{rule_name}"
                for rule_name, pattern_i, token_i
                in self.match_stack[cache_key_index:])
            raise ParseError(token, f"Circular match: {msg}")

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
                            print('. ' * self.match_depth + f"SUB-PATTERN ({part_type}): {part_value.prettystring()}")
                        result = match_subpattern(part_value, token_i)
                        if result:
                            sub_children, token_i = result
                            children.extend(sub_children)
                    elif part_type == 'star':
                        # Zero or more matches of subpattern
                        if self.verbose:
                            print('. ' * self.match_depth + f"SUB-PATTERN ({part_type}): {part_value.prettystring()}")
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
                        if self.longest_match is None or token_i > self.longest_match.token_i:
                            self.longest_match = _LongestMatch(
                                rule_name=rule_name,
                                pattern=subpattern,
                                token_i=token_i,
                            )
                        token = self.tokens[token_i]
                        if self.verbose:
                            print('. ' * self.match_depth + f"TOKEN: {token.location()}: {token.value!r}")
                        if part_type == 'toktype':
                            # Match against token's toktype
                            toktype_predicate = self.toktype_predicates.get(part_value)
                            if (
                                token.toktype != part_value
                                if toktype_predicate is None else
                                not toktype_predicate(token)
                            ):
                                if self.verbose:
                                    print('. ' * self.match_depth + "NOT MATCH")
                                return None
                        elif part_type == 'tokvalue':
                            # Match against token's value
                            if token.value != part_value:
                                if self.verbose:
                                    print('. ' * self.match_depth + "NOT MATCH")
                                return None
                        elif part_type == 'oneof':
                            if token.value not in part_value:
                                if self.verbose:
                                    print('. ' * self.match_depth + "NOT MATCH")
                                return None
                        else:
                            # We should never get here...
                            raise Exception(f"Unrecognized pattern part type: {part_type!r}")
                        # ...we matched against a single token!
                        token_i += 1
                if self.verbose:
                    thing = 'RULE' if subpattern is pattern else 'SUB-PATTERN'
                    print('. ' * self.match_depth + f"{thing} MATCHED!")
                return children, token_i
            finally:
                self.decrease_match_depth()

        # HACK: maybe kick off some arbitrary code when we enter/exit the
        # rule.
        # Used for C's gross typedef shenanigans, see:
        # https://en.wikipedia.org/wiki/Lexer_hack
        callback_key = (rule_name, pattern.name)
        enter_callback, exit_callback = self.pattern_callbacks.get(
            callback_key, (None, None))

        # Match the pattern...
        original_token_i = token_i
        if enter_callback is not None:
            enter_callback(token)
        self.match_stack.append(cache_key)
        match = None
        try:
            result = match_subpattern(pattern, token_i)
            if result is None:
                return cached(None)
            children, token_i = result

            # Create a match object
            if (
                self.squash_children
                and len(children) == 1
                and not pattern.name # don't squash named patterns!
            ):
                match = cached(children[0]._replace(
                    token_i=original_token_i,
                    n_tokens=token_i - original_token_i,
                ))
            else:
                match = cached(ParseMatch(
                    rule_name=rule_name,
                    pattern_name=pattern.name,
                    token=self.tokens[original_token_i],
                    token_i=original_token_i,
                    n_tokens=token_i - original_token_i,
                    children=children,
                ))
            return match
        finally:
            assert self.match_stack.pop() == cache_key
            if exit_callback is not None:
                exit_callback(token, match)


class GrammarEvaluator:
    """Base class which can be extended to evaluate expressions of a
    particular grammar.

        >>> rules = parse_rules('''
        ...
        ...     value
        ...         | NUMBER
        ...         | negative: '-' value
        ...         | bool: [ 'true' 'false' ]
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
        ...     def on_bool__value(self, match):
        ...         return {'true': True, 'false': False}[match.token.value]
        ...     def on_value(self, match):
        ...         return int(match.token.value)
        ...     def on_array(self, match):
        ...         return [self.on(child) for child in match.children]

        >>> evaluator = ValueEvaluator()

        >>> evaluator.eval('1')
        1

        >>> evaluator.eval('-1')
        -1

        >>> evaluator.eval('true')
        True

        >>> evaluator.eval('false')
        False

        >>> evaluator.eval('[]')
        []

        >>> evaluator.eval('[1, 2, [-3, -4]]')
        [1, 2, [-3, -4]]

        >>> evaluator.eval('1 2 3')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: Couldn't parse as: value

    """

    grammar_filename: Optional[str] = None
    main_rule_name: Optional[str] = None
    squash_children: bool = False

    pattern_callbacks: dict[PatternCallbackKey, tuple[PatternEnterCallback, PatternExitCallback]] = None
    toktype_predicates: dict[str, TokenPredicate] = None

    def __init__(self):
        self.validate()

    @staticmethod
    def get_handler_name(rule_name: str, pattern_name: Optional[str] = None) -> str:
        return (
            f'on_{pattern_name}__{rule_name}' if pattern_name
            else f'on_{rule_name}')

    def get_unimplemented_handlers(self) -> list[str]:
        # NOTE: use a dict to remove duplicates (unlike list) while
        # preserving order (unlike set)
        possible_handler_names = {
            self.get_handler_name(rule_name, pattern.name): True
            for rule_name, rule in self.grammar_rules.items()
            for pattern in rule.patterns}
        return [name for name in possible_handler_names
            if not hasattr(self, name)]

    def validate(self):
        bad_handler_names = []
        possible_handler_names = {
            self.get_handler_name(rule_name, pattern.name)
            for rule_name, rule in self.grammar_rules.items()
            for pattern in rule.patterns}
        for attr in dir(self):
            if attr.startswith('on_'):
                if attr not in possible_handler_names:
                    bad_handler_names.append(attr)
        if bad_handler_names:
            raise Exception(f"Handler methods for missing rules/patterns: {', '.join(bad_handler_names)}")

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

    def parse(
            self,
            tokens: list[Token] | str,
            rule_name: Optional[str] = None,
            *,
            verbose: bool = False,
            partial: bool = False,
            raise_on_no_match: bool = False,
            max_match_depth: Optional[int] = None,
            ) -> Optional[ParseMatch]:
        tokens = self.coerce_tokens(tokens)
        parser = GrammarParser(
            self.grammar_rules,
            tokens,
            squash_children=self.squash_children,
            pattern_callbacks=self.pattern_callbacks,
            toktype_predicates=self.toktype_predicates,
            verbose=verbose,
            max_match_depth=max_match_depth,
        )
        return parser.match_rule(
            rule_name or self.main_rule_name,
            full=not partial,
            raise_on_no_match=raise_on_no_match,
        )

    def no_match(self, tokens: list[Token], rule_name: str) -> Optional[ParseMatch]:
        # NOTE: subclasses may want to override this method with custom
        # error message, or to return a value instead of raising an exception
        first_token = tokens[0] if tokens else None
        raise ParseError(first_token, f"Couldn't parse as: {rule_name}")

    def eval(self, tokens: list[Token] | str, rule_name: Optional[str] = None):
        tokens = self.coerce_tokens(tokens)
        rule_name = rule_name or self.main_rule_name
        match = self.parse(tokens, rule_name)
        if match is None:
            # NOTE: this may return a ParseMatch, or None, or raise
            # ParseError, etc... it's up to subclasses to decide
            return self.no_match(tokens, rule_name)
        return self.on(match)

    def default(self, match: ParseMatch):
        # NOTE: subclasses may want to override this method
        raise match.missing_handler()

    def on(self, match: ParseMatch):
        handler_name = self.get_handler_name(match.rule_name, match.pattern_name)
        handler = getattr(self, handler_name, None)
        if handler is not None:
            return handler(match)
        else:
            return self.default(match)


def get_grammar_filenames():
    return [os.path.relpath(get_data_filepath(filename))
        for filename in os.listdir(get_data_filepath())]


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
