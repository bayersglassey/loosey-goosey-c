from typing import Optional

from loosey import get_data_filename
from loosey.pplex import (
    Token,
    Lexer,
    ParseError,
    from_char_literal,
)
from loosey.grammar import (
    GrammarEvaluator,
    ParseMatch,
)


GRAMMAR_FILENAME = get_data_filename('ppexpr-grammar.txt')


SINGLE_OPS = {
    'and_expression': '&',
    'exclusive_or_expression': '^',
    'inclusive_or_expression': '|',
    'logical_and_expression': '&&',
    'logical_or_expression': '||',
}


def _parse_number(token: Token) -> int:
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


class ConditionalExpressionEvaluator(GrammarEvaluator):
    r"""Parses and evaluates C preprocessor conditional expressions

        >>> evaluator = ConditionalExpressionEvaluator()

        >>> evaluator.parse('x < 3? ~!y + 2: 2 * 3 * 4 + 10, 99').pprint()
        expression
          conditional_expression
            relational_expression
              x
              <
              3
            additive_expression
              unary_expression
                ~
                !
                y
              +
              2
            additive_expression
              multiplicative_expression
                2
                *
                3
                *
                4
              +
              10
          99

    Evaluation examples:

        >>> evaluator.eval("1")
        1

        >>> evaluator.eval("+1")
        1

        >>> evaluator.eval("-1")
        -1

        Identifers are all treated as the value 0.
        Macro expansion is expected to have been done before attempting to
        parse the expression.
        >>> evaluator.eval("x")
        0

        >>> evaluator.eval("'a'")
        97

        >>> evaluator.eval(r"'\0'")
        0

        >>> evaluator.eval('1 + 2')
        3

        >>> evaluator.eval('1 + -1')
        0

        >>> evaluator.eval('2 * 3 + 1')
        7

        >>> evaluator.eval('2 * (3 + 1)')
        8

        >>> evaluator.eval('1 + 3 * 2')
        7

        >>> evaluator.eval('(1 + 3) * 2')
        8

        >>> evaluator.eval('1 + 2 + 3')
        6

        >>> evaluator.eval('1 << 3')
        8

        >>> evaluator.eval('!0')
        1

        >>> evaluator.eval('!!0')
        0

        >>> for x in (0, 1):
        ...     for y in (0, 1):
        ...         print(f'{x} == {y} -> ' + str(evaluator.eval(f'{x} == {y}')))
        ...         print(f'{x} != {y} -> ' + str(evaluator.eval(f'{x} != {y}')))
        ...         print(f'{x} && {y} -> ' + str(evaluator.eval(f'{x} && {y}')))
        ...         print(f'{x} || {y} -> ' + str(evaluator.eval(f'{x} || {y}')))
        ...         print(f'{x} < {y} -> ' + str(evaluator.eval(f'{x} < {y}')))
        ...         print(f'{x} <= {y} -> ' + str(evaluator.eval(f'{x} < {y}')))
        ...         print(f'{x} > {y} -> ' + str(evaluator.eval(f'{x} > {y}')))
        ...         print(f'{x} >= {y} -> ' + str(evaluator.eval(f'{x} >= {y}')))
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

        >>> evaluator.eval('1 + .3')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:5: Floats not allowed in preprocessor expressions: '.3'

        >>> evaluator.eval('1 + 2e6')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:5: Couldn't parse as number: '2e6'

        >>> evaluator.eval('* 2')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: Couldn't parse as preprocessor expression: * 2

        >>> evaluator.eval('2 *')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: Couldn't parse as preprocessor expression: 2 *

        >>> evaluator.eval('(')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: Couldn't parse as preprocessor expression: (

        >>> evaluator.eval(')')
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: Couldn't parse as preprocessor expression: )

    """

    grammar_filename = GRAMMAR_FILENAME
    squash_children = True

    def no_match(self, tokens: list[Token], rule_name: str) -> Optional[ParseMatch]:
        # TODO: need to get enough info back from GrammarParser that we
        # can show a decent error message here...
        # Example from GCC:
        #
        #   $ echo -e '#if ++x\nOK\n#endif' | cpp -P
        #   <stdin>:1:5: error: token "++" is not valid in preprocessor expressions
        #
        first_token = tokens[0] if tokens else None
        tokens_s = ' '.join(token.value for token in tokens)
        raise ParseError(first_token, f"Couldn't parse as preprocessor expression: {tokens_s}")

    def on_expression(self, match: ParseMatch) -> int:
        # Comma operator, value is that of last argument
        return self.on(match.children[-1])

    def on_primary_expression(self, match: ParseMatch) -> int:
        token = match.token
        if token.toktype == 'NUMBER':
            return _parse_number(token)
        elif token.toktype == 'CHAR':
            c = from_char_literal(token.value)
            return ord(c)
        else:
            # Identifiers all have the value 0, because they were supposed
            # to have been expanded before being passed in to parse_pp_expr
            return 0

    def on_unary_expression(self, match: ParseMatch) -> int:
        children = reversed(match.children)
        value = self.on(next(children))
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

    def on_conditional_expression(self, match: ParseMatch) -> int:
        # Ternary operator
        condval = self.on(match.children[0])
        return self.on(match.children[1 if condval else 2])

    def default(self, match: ParseMatch) -> int:
        # Binary expression
        single_op = SINGLE_OPS.get(match.rule_name)
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            if single_op:
                op = single_op
            else:
                op = child.token.value
                child = next(children)
            arg = self.on(child)
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
