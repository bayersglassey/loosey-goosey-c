import os
from functools import lru_cache

from loosey.pplex import (
    Token,
    Lexer,
    ParseError,
    from_char_literal,
)
from loosey.grammar import (
    GrammarRule,
    GrammarParser,
    ParseMatch,
    parse_rules_from_file,
)


GRAMMAR_FILENAME = os.path.join(os.path.dirname(__file__), 'data', 'ppexpr-grammar.txt')


SINGLE_OPS = {
    'and_expression': '&',
    'exclusive_or_expression': '^',
    'inclusive_or_expression': '|',
    'logical_and_expression': '&&',
    'logical_or_expression': '||',
}


@lru_cache
def get_grammar_rules() -> dict[str, GrammarRule]:
    """The rules for the pp expression grammar"""
    return parse_rules_from_file(GRAMMAR_FILENAME)


def parse_pp_expr(tokens: list[Token] | str) -> ParseMatch:
    if isinstance(tokens, str):
        # Support caller passing us a string, handy for doctests
        tokens = [token for line in Lexer().tokenize(tokens)
            for token in line]
    rules = get_grammar_rules()
    parser = GrammarParser(rules, tokens, squash_children=True)
    return parser.match()


def parse_number(token: Token) -> int:
    text = token.value
    if '.' in text:
        raise ParseError(token, f"Floats not allowed in preprocessor expressions: {text!r}")
    try:
        if text.startswith('0x'):
            return int(text[2:], 16)
        elif len(text) > 1 and text.startswith('0'):
            return int(text[1:], 8)
        else:
            return int(text)
    except ValueError:
        raise ParseError(token, f"Couldn't parse as number: {text!r}")


def eval_match(match: ParseMatch) -> int:
    if match.rule_name == 'expression':
        # Comma operator, value is that of last argument
        value = eval_match(match.children[-1])
    elif match.rule_name == 'primary_expression':
        token = match.token
        if token.toktype == 'NUMBER':
            return parse_number(token)
        elif token.toktype == 'CHAR':
            c = from_char_literal(token.value)
            return ord(c)
        else:
            # Identifiers all have the value 0, because they were supposed
            # to have been expanded before being passed in to parse_pp_expr
            return 0
    elif match.rule_name == 'unary_expression':
        children = reversed(match.children)
        value = eval_match(next(children))
        for child in children:
            op = child.token.value
            if op == '+':
                value = +value
            elif op == '-':
                value = -value
            elif op == '~':
                value = ~value
            elif op == '!':
                value = not value
            else:
                # Should never happen
                raise Exception(f"Unrecognized unary operator: {op!r}")
        return value
    elif match.rule_name == 'conditional_expression':
        # Ternary operator
        condval = eval_match(match.children[0])
        return eval_match(match.children[1 if condval else 2])
    else:
        # Binary expression
        single_op = SINGLE_OPS.get(match.rule_name)
        children = iter(match.children)
        value = eval_match(next(children))
        for child in children:
            if single_op:
                op = single_op
            else:
                op = child.token.value
                child = next(children)
            arg = eval_match(child)
            if op == '*':
                value *= arg
            elif op == '/':
                value /= arg
            elif op == '%':
                value %= arg
            elif op == '+':
                value += arg
            elif op == '-':
                value -= arg
            elif op == '<<':
                value <<= arg
            elif op == '>>':
                value >>= arg
            elif op == '<':
                value = value < arg
            elif op == '>':
                value = value > arg
            elif op == '<=':
                value = value <= arg
            elif op == '>=':
                value = value >= arg
            elif op == '==':
                value = value == arg
            elif op == '!=':
                value = value != arg
            elif op == '&':
                value &= arg
            elif op == '^':
                value ^= arg
            elif op == '|':
                value |= arg
            elif op == '&&':
                value = value and arg
            elif op == '||':
                value = value or arg
            else:
                # Should never happen
                raise Exception(f"Unrecognized binary operator: {op!r}")
        return value


def eval_pp_expr(tokens: list[Token] | str) -> int:
    r"""

        >>> eval_pp_expr("1")
        1

        >>> eval_pp_expr("+1")
        1

        >>> eval_pp_expr("-1")
        -1

        Identifers are all treated as the value 0.
        Macro expansion is expected to have been done before attempting to
        parse the expression.
        >>> eval_pp_expr("x")
        0

        >>> eval_pp_expr("'a'")
        97

        >>> eval_pp_expr(r"'\0'")
        0

        >>> eval_pp_expr('1 + 2')
        3

        >>> eval_pp_expr('1 + -1')
        0

        >>> eval_pp_expr('2 * 3 + 1')
        7

        >>> eval_pp_expr('2 * (3 + 1)')
        8

        >>> eval_pp_expr('1 + 3 * 2')
        7

        >>> eval_pp_expr('(1 + 3) * 2')
        8

        >>> eval_pp_expr('1 + 2 + 3')
        6

        >>> eval_pp_expr('1 << 3')
        8

        >>> eval_pp_expr('!0')
        1

        >>> eval_pp_expr('!!0')
        0

        >>> for x in (0, 1):
        ...     for y in (0, 1):
        ...         print(f'{x} == {y} -> ' + str(eval_pp_expr(f'{x} == {y}')))
        ...         print(f'{x} != {y} -> ' + str(eval_pp_expr(f'{x} != {y}')))
        ...         print(f'{x} && {y} -> ' + str(eval_pp_expr(f'{x} && {y}')))
        ...         print(f'{x} || {y} -> ' + str(eval_pp_expr(f'{x} || {y}')))
        ...         print(f'{x} < {y} -> ' + str(eval_pp_expr(f'{x} < {y}')))
        ...         print(f'{x} <= {y} -> ' + str(eval_pp_expr(f'{x} < {y}')))
        ...         print(f'{x} > {y} -> ' + str(eval_pp_expr(f'{x} > {y}')))
        ...         print(f'{x} >= {y} -> ' + str(eval_pp_expr(f'{x} >= {y}')))
        0 == 0 -> True
        0 != 0 -> False
        0 && 0 -> 0
        0 || 0 -> 0
        0 < 0 -> False
        0 <= 0 -> False
        0 > 0 -> False
        0 >= 0 -> True
        0 == 1 -> False
        0 != 1 -> True
        0 && 1 -> 0
        0 || 1 -> 1
        0 < 1 -> True
        0 <= 1 -> True
        0 > 1 -> False
        0 >= 1 -> False
        1 == 0 -> False
        1 != 0 -> True
        1 && 0 -> 0
        1 || 0 -> 1
        1 < 0 -> False
        1 <= 0 -> False
        1 > 0 -> True
        1 >= 0 -> True
        1 == 1 -> True
        1 != 1 -> False
        1 && 1 -> 1
        1 || 1 -> 1
        1 < 1 -> False
        1 <= 1 -> False
        1 > 1 -> False
        1 >= 1 -> True

    Possible errors:

        >>> eval_pp_expr('1 + .3')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:5: Floats not allowed in preprocessor expressions: '.3'

        >>> eval_pp_expr('1 + 2e6')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:5: Couldn't parse as number: '2e6'

        >>> eval_pp_expr('* 2')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: Couldn't parse as preprocessor expression: * 2

        >>> eval_pp_expr('2 *')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: Couldn't parse as preprocessor expression: 2 *

        >>> eval_pp_expr('(')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: Couldn't parse as preprocessor expression: (

        >>> eval_pp_expr(')')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: Couldn't parse as preprocessor expression: )

    """
    if isinstance(tokens, str):
        # Support caller passing us a string, handy for doctests
        tokens = [token for line in Lexer().tokenize(tokens)
            for token in line]
    first_token = tokens[0] if tokens else None
    match = parse_pp_expr(tokens)
    if match is None:
        # TODO: need to get enough info back from GrammarParser that we
        # can show a decent error message here...
        # Example from GCC:
        #
        #   $ echo -e '#if ++x\nOK\n#endif' | cpp -P
        #   <stdin>:1:5: error: token "++" is not valid in preprocessor expressions
        #
        tokens_s = ' '.join(token.value for token in tokens)
        raise ParseError(first_token, f"Couldn't parse as preprocessor expression: {tokens_s}")
    return eval_match(match)
