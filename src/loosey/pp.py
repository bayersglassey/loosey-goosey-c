"""

    This file implements the C preprocessor.

    I used the following documentation as a rough guide (mostly the GCC one):
    * https://gcc.gnu.org/onlinedocs/cpp/index.html
    * https://en.cppreference.com/c/preprocessor
    * https://home.cs.colorado.edu/~main/cs1300/doc/gnu/cpp_toc.html

"""

import sys
from typing import NamedTuple, Iterable, Iterator, Optional
from argparse import ArgumentParser

from loosey.iter import FancyIterator
from loosey.pplex import (
    INCLUDE_REGEX,
    ParseError,
    Token,
    Lexer,
    tokenize_file,
    to_string_literal,
)
from loosey.recursion import debug_recursion


class Macro(NamedTuple):
    """A macro, i.e. the thing produced by the #define directive"""
    name: str
    token: Token
    body: list[Token]

    # If None, this is an "object-like macro".
    # If not None, this is a "function-like macro".
    params: Optional[list[str]] = None

    @property
    def is_function_like(self) -> bool:
        """Function-like macros take parameters, i.e. `#define M()` as
        opposed to just `#define M`"""
        return self.params is not None

    @property
    def is_variadic(self) -> bool:
        """Variadic macro, e.g. `#define M(X, Y, ...)`.
        The param name is defined as '...' but is '__VA_ARGS__' in the body."""
        return self.params is not None and self.params[-1] == '__VA_ARGS__'

    def pprint(self, *, inline: bool = False):
        msg = f'#define {self.name}'
        if self.params is not None:
            msg += f"({', '.join(self.params)})"
        if inline:
            print(f"{msg}: {' '.join(token.value for token in self.body)}")
        else:
            print(msg)
            for token in self.body:
                token.pprint(indent='  ')


class MacroExpansionError(ParseError):
    """For when an error happens while expanding a macro"""

    def __init__(self, macro: Macro, token: Token, msg: str):
        ParseError.__init__(self, token,
            f"While expanding macro {macro.name} (defined at {macro.token.location()}): {msg}")
        self.macro = macro
        self.original_msg = msg


class Preprocessor:
    r"""An implementation of the C preprocessor.
    Processes pre-tokenized lines of C code into zero or more lines of tokens.

        >>> pp = Preprocessor()
        >>> test_i = 0
        >>> def process(text):
        ...     global test_i
        ...     test_i += 1
        ...     yield from pp.process(Lexer(f'input-{test_i}').tokenize(text))

        Most preprocessor directives don't have any output of their own:
        >>> for token in process(r'''
        ...     #define K 1024
        ...     #define SIZE 3 * K
        ...     #define DUMMY hello
        ...     #undef DUMMY
        ...     #define MALLOC(VAR, _SIZE) \
        ...         VAR = malloc(_SIZE);
        ...     #define NOTHING
        ...     # /* The "null directive"! */
        ...     #define VV0(...) [__VA_ARGS__]
        ...     #define VV1(X, ...) X[__VA_ARGS__]
        ... '''):
        ...     token.pprint()

        The macros are stored for use in subsequent processing:
        >>> for name, macro in pp.macros.items():
        ...     macro.pprint()
        #define K
          input-1:2:15: NUMBER('1024')
        #define SIZE
          input-1:3:18: NUMBER('3')
          input-1:3:20: PUNCTUATION('*')
          input-1:3:22: IDENTIFIER('K')
        #define MALLOC(VAR, _SIZE)
          input-1:7:9: IDENTIFIER('VAR')
          input-1:7:13: PUNCTUATION('=')
          input-1:7:15: IDENTIFIER('malloc')
          input-1:7:21: PUNCTUATION('(')
          input-1:7:22: IDENTIFIER('_SIZE')
          input-1:7:27: PUNCTUATION(')')
          input-1:7:28: PUNCTUATION(';')
        #define NOTHING
        #define VV0(...)
          input-1:10:22: PUNCTUATION('[')
          input-1:10:23: IDENTIFIER('__VA_ARGS__')
          input-1:10:34: PUNCTUATION(']')
        #define VV1(X, ...)
          input-1:11:25: IDENTIFIER('X')
          input-1:11:26: PUNCTUATION('[')
          input-1:11:27: IDENTIFIER('__VA_ARGS__')
          input-1:11:38: PUNCTUATION(']')

        The definitions are expanded in the usual way.
        Object-like macros take no parameters:
        >>> for token in process(r'''
        ...     size_t size = SIZE;
        ... '''):
        ...     token.pprint()
        input-2:2:5: IDENTIFIER('size_t')
        input-2:2:12: IDENTIFIER('size')
        input-2:2:17: PUNCTUATION('=')
        input-2:2:19: NUMBER('3')
        input-2:2:19: PUNCTUATION('*')
        input-2:2:19: NUMBER('1024')
        input-2:2:23: PUNCTUATION(';')

        Tokens track their "parent" tokens, e.g. references to macros and
        their parameters:
        >>> for token in process(r'''
        ...     size_t size = SIZE;
        ... '''):
        ...     token.pprint(with_parents=True)
        input-3:2:5: IDENTIFIER('size_t')
        input-3:2:12: IDENTIFIER('size')
        input-3:2:17: PUNCTUATION('=')
        input-3:2:19: NUMBER('3')
         ...from:
          input-3:2:19: IDENTIFIER('SIZE')
          input-1:3:18: NUMBER('3')
        input-3:2:19: PUNCTUATION('*')
         ...from:
          input-3:2:19: IDENTIFIER('SIZE')
          input-1:3:20: PUNCTUATION('*')
        input-3:2:19: NUMBER('1024')
         ...from:
          input-3:2:19: IDENTIFIER('SIZE')
          input-1:3:22: NUMBER('1024')
           ...from:
            input-1:3:22: IDENTIFIER('K')
            input-1:2:15: NUMBER('1024')
        input-3:2:23: PUNCTUATION(';')

        Function-like macros are "called" with parameters:
        >>> for token in process(r'''
        ...     char *msg;
        ...     MALLOC(msg, SIZE)
        ... '''):
        ...     token.pprint()
        input-4:2:5: IDENTIFIER('char')
        input-4:2:10: PUNCTUATION('*')
        input-4:2:11: IDENTIFIER('msg')
        input-4:2:14: PUNCTUATION(';')
        input-4:3:5: IDENTIFIER('msg')
        input-4:3:5: PUNCTUATION('=')
        input-4:3:5: IDENTIFIER('malloc')
        input-4:3:5: PUNCTUATION('(')
        input-4:3:5: NUMBER('3')
        input-4:3:5: PUNCTUATION('*')
        input-4:3:5: NUMBER('1024')
        input-4:3:5: PUNCTUATION(')')
        input-4:3:5: PUNCTUATION(';')

        Variadic macros are supported:
        >>> for name in ('VV0', 'VV1'): pp.macros[name].pprint(inline=True)
        #define VV0(__VA_ARGS__): [ __VA_ARGS__ ]
        #define VV1(X, __VA_ARGS__): X [ __VA_ARGS__ ]
        >>> for token in process(r'''
        ...     VV0(1, 2, 3)
        ...     VV1(1, 2, 3)
        ... '''):
        ...     token.pprint()
        input-5:2:5: PUNCTUATION('[')
        input-5:2:5: NUMBER('1')
        input-5:2:5: PUNCTUATION(',')
        input-5:2:5: NUMBER('2')
        input-5:2:5: PUNCTUATION(',')
        input-5:2:5: NUMBER('3')
        input-5:2:5: PUNCTUATION(']')
        input-5:3:5: NUMBER('1')
        input-5:3:5: PUNCTUATION('[')
        input-5:3:5: NUMBER('2')
        input-5:3:5: PUNCTUATION(',')
        input-5:3:5: NUMBER('3')
        input-5:3:5: PUNCTUATION(']')

    Possible errors:

        >>> list(Preprocessor().process('#error "Ka-boom!"'))
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:1: "Ka-boom!"

        >>> list(Preprocessor().process('#define X(Y Z)'))
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:13: Expected ',' or ')', got: IDENTIFIER('Z')

        >>> list(Preprocessor().process('#define X(1, 2)'))
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:11: Expected identifier or ')', got: NUMBER('1')

        >>> list(Preprocessor().process('#undef X Y'))
        Traceback (most recent call last):
         ...
        loosey.pplex.ParseError: <fakefile>:1:10: Extra tokens after directive arguments

    """

    def __init__(self, *, verbose: bool = True):
        self.verbose = verbose

        # Defined macros
        self.macros: dict[str, Macro] = {}

        # The "call stack" for macro expansion
        self.expanding_macros: list[str] = []

        # Currently bound macro params, i.e. the current "values" of macro
        # parameters, which are lists of tokens
        self.bound_macro_params: dict[str, list[Token]] = {}

    def warn(self, token: Token, msg: str):
        if self.verbose:
            print(f"{token.location()}: {msg}", file=sys.stderr)

    @debug_recursion()
    def process(self, lines: Iterable[list[Token]] | str) -> Iterator[Token]:
        """Process lines of C code"""
        if isinstance(lines, str):
            # Support caller passing us a string, handy for doctests
            lines = Lexer().tokenize(lines)
        for line in lines:
            yield from self.process_line(line)

    def process_side_effects(self, lines: Iterable[list[Token]] | str):
        """Process lines of C code, for their side effects alone.
        Use this e.g. to define macros."""
        for token in self.process(lines): pass

    @debug_recursion()
    def process_line(self, line: list[Token]) -> Iterator[Token]:
        """Processes the given line of C code, yielding zero or more lines.
        Why zero or more?.. because most preprocessor directives don't produce
        any tokens at all, and #include can produce many!..
        Also, we might be in the middle of an #if...#endif construct, in which
        case we might not produce any lines.
        """

        # Strip out comments
        tokens = [token for token in line if token.toktype != 'COMMENT']
        if not tokens:
            return

        # Process directives, if any
        first_token = tokens[0]
        if first_token.toktype == 'IMPORT':
            # Handle the #import directive
            if len(tokens) > 1:
                raise ParseError(first_token, f"Unexpected tokens after {first_token.value}")
            match = INCLUDE_REGEX.fullmatch(token.value)
            filespec = match.group(1)
            is_system = filespec[0] == '<'
            filename = filespec[1:-1]
            # TODO: have a whitelist of places it's ok to import from, or
            # just allow all "local" imports, etc.
            self.warn(first_token, "Ignoring {'system' if is_system else 'local'} #include of {filename!r}")
        elif first_token.value == '#':
            if len(tokens) == 1:
                # A '#' on a line by itself must be silently eaten.
                # https://gcc.gnu.org/onlinedocs/cpp/Other-Directives.html
                #
                #   The null directive consists of a ‘#’ followed by a
                #   newline, with only whitespace (including comments) in
                #   between.
                #   A null directive is understood as a preprocessing
                #   directive but has no effect on the preprocessor output.
                #
                return
            # Handle preprocessor directives other than #import
            directive = tokens[1].value
            if directive == 'define':
                self._process_define_directive(tokens)
            elif directive == 'undef':
                if len(tokens) < 3 or tokens[2].toktype != 'IDENTIFIER':
                    raise ParseError(first_token, f"Expected a macro name after #{directive}")
                elif len(tokens) > 3:
                    raise ParseError(tokens[3], "Extra tokens after directive arguments")
                name = tokens[2].value
                self.macros.pop(name, None)
            elif directive == 'warning':
                self.warn(first_token, ' '.join(token.value for token in tokens[2:]))
            elif directive == 'error':
                raise ParseError(first_token, ' '.join(token.value for token in tokens[2:]))
            elif directive in ('if', 'ifdef', 'ifndef', 'elif', 'else', 'endif'):
                self.warn(first_token, f"TODO: implement #{directive}")
            elif directive in ('pragma', 'line'):
                self.warn(first_token, f"Ignoring #{directive}")
            else:
                raise ParseError(first_token, f"Unknown directive: #{directive!r}")
        else:
            # This line was not a preprocessor directive!
            # Return the tokens, with any macros expanded
            yield from self.expand(tokens)

    @debug_recursion()
    def _process_define_directive(self, tokens: list[Token]):
        """Process the line of tokens for a #define directive"""
        first_token = tokens[0]

        # Get macro name
        if len(tokens) < 3 or tokens[2].toktype != 'IDENTIFIER':
            raise ParseError(first_token, f"Expected a macro name after #define")
        name = tokens[2].value

        # Check for redefinition
        if name in self.macros:
            existing_macro = self.macros[name]
            self.warn(first_token,
                f"Redefining {name!r} (previously defined at {existing_macro.token.location()})")

        # The macro is function-like if an open parenthesis appears
        # *immediately* after the name token, i.e. like `#define NAME(`,
        # but *not* like `#define NAME (`
        is_function_like = (
            len(tokens) >= 4 and
            tokens[3].value == '(' and
            tokens[3].col == tokens[2].col + len(tokens[2].value)
        )

        # Iterate over the tokens, possibly consuming the parameter list,
        # and leaving the token body
        rest_of_tokens = iter(tokens)
        next(rest_of_tokens) # '#'
        next(rest_of_tokens) # 'define'
        next(rest_of_tokens) # name

        # Parse parameters, if any
        params = None
        if is_function_like:
            # Parse macro parameter list
            params = []
            next(rest_of_tokens) # '('
            expected = 'i)' # next, we expect an identifier or ')'
            def check(token: Token, c: str):
                if c not in expected:
                    msg = ' or '.join('identifier' if c == 'i' else repr(c) for c in expected)
                    raise ParseError(token, f"Expected {msg}, got: {token.prettystring()}")
            for token in rest_of_tokens:
                if token.value == ')':
                    check(token, ')')
                    break
                elif token.value == ',':
                    check(token, ',')
                    expected = 'i)'
                elif token.toktype == 'IDENTIFIER':
                    check(token, 'i')
                    param_name = token.value
                    if param_name in params:
                        raise ParseError(token, f"Duplicate parameter name: {param_name!r}")
                    params.append(param_name)
                    expected = ',)'
                elif token.value == '...':
                    params.append('__VA_ARGS__')
                    expected = ')'
                else:
                    # Raises ParseError
                    check(token, 'FAIL')
            if token.value != ')':
                raise ParseError(first_token, "Missing closing ')' for macro parameters")

        # Yaaay let's define a macro
        self.macros[name] = Macro(
            name=name,
            token=first_token,
            body=list(rest_of_tokens),
            params=params,
        )

    @debug_recursion()
    def expand(self, tokens: Iterable[Token]) -> Iterator[Token]:
        # We want our tokens to be in a "fancy" iterator, so that we can e.g.
        # peek at the next one without actually consuming it!
        tokens = FancyIterator(tokens)

        for token in tokens:
            # NOTE: there's not much point to factoring self._expand_token
            # out of the loop here, except that it allows the token to show
            # up in the output of debug_recursion, which is super useful!
            yield from self._expand_token(token, tokens)

    @debug_recursion()
    def _expand_token(self, token: Token, tokens: FancyIterator[Token]) -> Iterator[Token]:
        ident = token.identifier()
        if ident == '__FILE__':
            yield Token.from_parents((token,), 'STRING',
                to_string_literal(token.filename))
        elif ident == '__LINE__':
            yield Token.from_parents((token,), 'NUMBER', str(token.row))
        elif ident in self.bound_macro_params:
            # We found a reference to a bound macro parameter, so use its
            # tokens...
            # NOTE: we re-expand the tokens here, even though they were
            # already expanded when the macro was called!
            # See: https://gcc.gnu.org/onlinedocs/cpp/Argument-Prescan.html
            for expanded_token in self.expand(self.bound_macro_params[ident]):
                yield expanded_token.copy_with_parents((token,))
        elif ident in self.macros:
            # We found a reference to a macro!
            if ident in self.expanding_macros:
                # Macros do not recurse!..
                # See: https://gcc.gnu.org/onlinedocs/cpp/Self-Referential-Macros.html
                yield token
            else:
                # Expand the macro
                self.expanding_macros.append(ident)
                try:
                    for expanded_token in self._expand_macro(token, tokens):
                        yield expanded_token.copy_with_parents((token,))
                finally:
                    assert self.expanding_macros.pop() == ident
        else:
            # Regular token, yield it as-is!
            yield token

    @debug_recursion()
    def _expand_macro(self, name_token: Token, tokens: FancyIterator[Token]) -> Iterator[Token]:
        r"""Expands a reference to a macro.

            >>> pp = Preprocessor()
            >>> test_i = 0
            >>> def process(text):
            ...     global test_i
            ...     test_i += 1
            ...     return list(pp.process(Lexer(f'input-{test_i}').tokenize(text)))
            >>> _ = process('#define M(X, Y, Z) Z Y X')

            >>> for token in process('M(,,)'):
            ...     token.pprint()

            >>> for token in process('M(1, 2, 3)'):
            ...     token.pprint()
            input-3:1:1: NUMBER('3')
            input-3:1:1: NUMBER('2')
            input-3:1:1: NUMBER('1')

            >>> for token in process('M(a 1, b 2, c 3)'):
            ...     token.pprint()
            input-4:1:1: IDENTIFIER('c')
            input-4:1:1: NUMBER('3')
            input-4:1:1: IDENTIFIER('b')
            input-4:1:1: NUMBER('2')
            input-4:1:1: IDENTIFIER('a')
            input-4:1:1: NUMBER('1')

            Commas inside parentheses are not treated as param separators:
            >>> for token in process('M((a, 1), (b, 2), (c, 3))'):
            ...     token.pprint()
            input-5:1:1: PUNCTUATION('(')
            input-5:1:1: IDENTIFIER('c')
            input-5:1:1: PUNCTUATION(',')
            input-5:1:1: NUMBER('3')
            input-5:1:1: PUNCTUATION(')')
            input-5:1:1: PUNCTUATION('(')
            input-5:1:1: IDENTIFIER('b')
            input-5:1:1: PUNCTUATION(',')
            input-5:1:1: NUMBER('2')
            input-5:1:1: PUNCTUATION(')')
            input-5:1:1: PUNCTUATION('(')
            input-5:1:1: IDENTIFIER('a')
            input-5:1:1: PUNCTUATION(',')
            input-5:1:1: NUMBER('1')
            input-5:1:1: PUNCTUATION(')')

        TODO:

            A macro call can span multiple lines:
            >>> for token in process('M(1,\n2,\n3)'):
            ...     token.pprint()

        """
        name = name_token.value
        macro = self.macros[name]
        if macro.is_function_like:
            # Function-like macro!
            # See: https://gcc.gnu.org/onlinedocs/cpp/Function-like-Macros.html

            # Attempt to parse the parameters being passed to the macro if
            # it's being "called", i.e. if there are parentheses after the
            # the macro name, like `MACRO(...)`.
            param_values = self._parse_macro_call(macro, tokens)
            if param_values is None:
                # There are no parentheses after the macro name.
                # So we're referring to the macro, but not "calling" it.
                # In this case, we just emit its name.
                yield name_token
                return

            # Map parameter names to values, i.e. token sequences
            param_values_dict = {}
            for param_name, param_tokens in zip(macro.params, param_values):
                # NOTE: we re-expand the tokens here, even though they were
                # already expanded when the macro was called!
                # See: https://gcc.gnu.org/onlinedocs/cpp/Argument-Prescan.html
                param_values_dict[param_name] = param_tokens

            # Now, we store the parameter values in a dict on self, so that
            # they can be referred to while the macro body is being expanded
            old_params = self.bound_macro_params
            self.bound_macro_params = old_params.copy()
            self.bound_macro_params.update(param_values_dict)
            try:
                # Expand the macro's body!
                # NOTE: we do this twice: once here, re-expand the tokens here, even though they were
                # already expanded when the macro was called!
                # See: https://gcc.gnu.org/onlinedocs/cpp/Argument-Prescan.html
                yield from self.expand(macro.body)
            finally:
                # ...and roll back the parameter values, now that the
                # macro body has been expanded
                self.bound_macro_params = old_params
        else:
            # Object-like macro! Just expand its body.
            # See: https://gcc.gnu.org/onlinedocs/cpp/Object-like-Macros.html
            yield from self.expand(macro.body)

    def _parse_macro_call(self, macro: Macro, tokens: FancyIterator[Token]) -> Optional[list[list[Token]]]:
        r"""Parse a macro call, i.e. `MACRO(...)`.
        If there are no parentheses after the macro name, i.e. just `MACRO`,
        that's fine, we just return None.

            >>> def test(text: str, n: int, v: bool = False):
            ...     pp = Preprocessor()
            ...     line = next(Lexer().tokenize(text))
            ...     tokens = FancyIterator(line)
            ...     params = list(map(str, range(n)))
            ...     if v: params[-1] = '__VA_ARGS__'
            ...     macro_token = Token.fake('IDENTIFIER', '<fakemacro>')
            ...     macro = Macro(name='<fakemacro>', token=macro_token,
            ...         body=[], params=params)
            ...     param_values = pp._parse_macro_call(macro, tokens)
            ...     if param_values is None:
            ...         print("Not a macro call!")
            ...         return
            ...     for i, param_tokens in enumerate(param_values):
            ...         print(f"=== Param {i + 1}:")
            ...         for token in param_tokens:
            ...             token.pprint(indent='  ')

            >>> test('hello', 1)
            Not a macro call!

            >>> test('()', 1)
            === Param 1:

            >>> test('(,)', 2)
            === Param 1:
            === Param 2:

            >>> test('(1,2)', 2)
            === Param 1:
              <fakefile>:1:2: NUMBER('1')
            === Param 2:
              <fakefile>:1:4: NUMBER('2')

            >>> test('((1, 2),(3, 4))', 2)
            === Param 1:
              <fakefile>:1:2: PUNCTUATION('(')
              <fakefile>:1:3: NUMBER('1')
              <fakefile>:1:4: PUNCTUATION(',')
              <fakefile>:1:6: NUMBER('2')
              <fakefile>:1:7: PUNCTUATION(')')
            === Param 2:
              <fakefile>:1:9: PUNCTUATION('(')
              <fakefile>:1:10: NUMBER('3')
              <fakefile>:1:11: PUNCTUATION(',')
              <fakefile>:1:13: NUMBER('4')
              <fakefile>:1:14: PUNCTUATION(')')

            For a variadic macro call, the last parameter consumes even ','
            tokens:
            >>> test('(1,2,3)', 2, True)
            === Param 1:
              <fakefile>:1:2: NUMBER('1')
            === Param 2:
              <fakefile>:1:4: NUMBER('2')
              <fakefile>:1:5: PUNCTUATION(',')
              <fakefile>:1:6: NUMBER('3')

        Possible errors:

            >>> test('(1,2)', 1) #doctest: +NORMALIZE_WHITESPACE
            Traceback (most recent call last):
             ...
            loosey.pp.MacroExpansionError: <fakefile>:1:3:
            While expanding macro <fakemacro> (defined at <fakefile>:1:1):
            Expected to receive 1 parameters, but already got that many

            >>> test('(1)', 2) #doctest: +NORMALIZE_WHITESPACE
            Traceback (most recent call last):
             ...
            loosey.pp.MacroExpansionError: <fakefile>:1:3:
            While expanding macro <fakemacro> (defined at <fakefile>:1:1):
            Expected to receive 2 parameters, but only got 1

            >>> test('(1,', 2) #doctest: +NORMALIZE_WHITESPACE
            Traceback (most recent call last):
             ...
            loosey.pp.MacroExpansionError: <fakefile>:1:3:
            While expanding macro <fakemacro> (defined at <fakefile>:1:1):
            Missing closing ')' for macro call

        """

        # ********************************************
        # ** TODO: HANDLE MULTI_LINE MACRO CALLS!.. **
        # ********************************************
        #
        # Per: https://gcc.gnu.org/onlinedocs/cpp/Macro-Arguments.html
        #
        #   The invocation of the macro need not be restricted to a single
        #   logical line—it can cross as many lines in the source file as
        #   you wish.
        #
        # ...hmmmm.
        # We could do it by turning this into a generator function, and then
        # instead of getting tokens from an iterator which is passed in, we
        # would instead get them using `token = yield`.
        # And then the processor would have a `self.macro_call_parser`
        # attribute, which would be either None or a generator.
        #
        # ...BUT NO, because we need to peek/unget tokens, in the sense
        # of FancyIterator.push.
        # We can't un-yield something!..
        # Sooooo....
        #
        # Omfg, the open paren can even be on the next line. O_o
        #
        #   $ echo -e "#define M(X) X X\nM\n(1)" | cpp -P
        #   1 1
        #
        # That's WILD.
        # Okay, let's think about what we really need out of this.
        # We definitely need to stream lines in; I don't think we need to
        # stream individual characters or anything.
        # But currently, we're streaming lines out; and maybe we don't need
        # to do that, maybe we can stream tokens out.
        # Does the preprocessor output ever need to include newlines?..
        # NO IT DOES NOT! The preprocessor converts all whitespace into
        # single spaces.
        # So okay, let's make that change first, then come back here and
        # see if handling macro calls becomes any easier.
        #
        # Hmmmm actually, we could have a "macro call buffer".
        # Store up tokens until we hit that final ')', then parse the params
        # all in one go.
        # But actually never mind, I don't think we gain much -- looking at
        # the code below, next(tokens) is only called twice: once explicitly
        # at the start, and then implicitly each time around the for loop.
        # So I think the number of possible "states" is actually quite small,
        # so we don't need to mess around with generators and send().

        # Check for the opening '(' of the call, if any
        token = next(tokens, None)
        if token is None or token.value != '(':
            # Not a macro call, just a macro reference.
            # That's fine, just return None.
            # But push the non-'(' token we got back onto the iterator first!
            if token is not None:
                tokens.push(token)
            return None

        param_values = []
        param_value = []
        paren_depth = 1
        for token in tokens:
            if token.value == ')':
                paren_depth -= 1
                if paren_depth < 1:
                    break
            elif token.value == '(':
                paren_depth += 1
            if (
                paren_depth <= 1 and
                token.value == ',' and
                not (
                    macro.is_variadic and
                    len(param_values) >= len(macro.params) - 1
                )
            ):
                param_values.append(param_value)
                if len(param_values) >= len(macro.params):
                    raise MacroExpansionError(macro, token,
                        f"Expected to receive {len(macro.params)} parameters, "
                        f"but already got that many")
                param_value = []
            else:
                param_value.append(token)
        else:
            raise MacroExpansionError(macro, token,
                "Missing closing ')' for macro call")
        param_values.append(param_value)
        if len(param_values) < len(macro.params):
            raise MacroExpansionError(macro, token,
                f"Expected to receive {len(macro.params)} parameters, "
                f"but only got {len(param_values)}")
        return param_values


def main():
    parser = ArgumentParser()
    parser.add_argument('filename', default='-', help="Use '-' for stdin")
    parser.add_argument('-t', '--tree', action='store_true')
    parser.add_argument('-l', '--lex-only', action='store_true')
    args = parser.parse_args()
    filename = args.filename
    try:
        lines = tokenize_file(filename)
        if args.lex_only:
            tokens = (token for line in lines for token in line)
        else:
            tokens = Preprocessor().process(lines)
        for token in tokens:
            if args.tree:
                print(' ' * (token.col - 1) + token.value)
            else:
                print(f"{token.row}:{token.col}: {token.prettystring()}")
    except BrokenPipeError:
        # So we can pipe ourselves into "less" and quit before lexing the
        # whole file, etc
        pass


if __name__ == '__main__':
    main()
