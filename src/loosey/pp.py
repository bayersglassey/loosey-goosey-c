"""

    This file implements the C preprocessor.

    I used the following documentation as a rough guide (mostly the GCC one):
    * https://gcc.gnu.org/onlinedocs/cpp/index.html
    * https://en.cppreference.com/c/preprocessor
    * https://home.cs.colorado.edu/~main/cs1300/doc/gnu/cpp_toc.html

    See also: docs/preprocessor.md

"""

import os
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
from loosey.ppexpr import ConditionalExpressionEvaluator
from loosey.recursion import debug_recursion, debug_recursion_log
from loosey.grammar import GrammarEvaluator, ParseMatch


class ConditionalFrame(NamedTuple):
    # The '#' token
    token: Token

    # The value of the token following the '#', e.g. 'if', 'ifdef', 'else', etc
    directive: str

    # Whether the condition evaluated to something truthy
    was_true: bool

    # The #if, #elif, etc for the current #elif, #else, etc.
    # *NOT* the parent frame in terms of nesting!..
    # So, in this example:
    #
    #   #if A
    #     #if B
    #     #elif C
    #     #else D
    #     #endif
    #   #endif
    #
    # ...it's the case that:
    #
    #   B's parent is None (not A!)
    #   C's parent is B
    #   D's parent is C
    #
    parent: Optional['ConditionalFrame'] = None


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


class NoCall:
    """Singleton representing MacroCallParser having detected that a macro
    reference was not a call, i.e. just `MACRO`,  not `MACRO(...)`."""
    def __repr__(self): return 'NO_CALL'
NO_CALL = NoCall()


class MacroCallParser:
    r"""Parses macro calls, i.e. the `(...)` in `MACRO(...)`.
    If there are no parentheses after the macro name, i.e. just `MACRO`,
    that's fine, we just return NO_CALL.
    If we run out of tokens to process, we return None, and wait for
    more input.

        >>> def tokenize(text):
        ...     for line in Lexer().tokenize(text):
        ...         yield from line

        >>> def mkmacro(n: int, v: bool = False) -> Macro:
        ...     params = list(map(str, range(n)))
        ...     if v: params[-1] = '__VA_ARGS__'
        ...     macro_token = Token.fake('IDENTIFIER', '<fakemacro>')
        ...     return Macro(name='<fakemacro>', token=macro_token,
        ...         body=[], params=params)

        >>> def feed(parser, text):
        ...     tokens = FancyIterator(tokenize(text))
        ...     param_values = parser.process(tokens)
        ...     if param_values is None:
        ...         print('Waiting for more input...')
        ...     elif param_values is NO_CALL:
        ...         print("Not a macro call!")
        ...         if not tokens.empty():
        ...             print('Unprocessed tokens:')
        ...             for token in tokens: token.pprint()
        ...     else:
        ...         for i, param_tokens in enumerate(param_values):
        ...             print(f"=== Param {i + 1}:")
        ...             for token in param_tokens:
        ...                 token.pprint(indent='  ')

        >>> def test(text: str, macro: Macro):
        ...     parser = MacroCallParser(macro,
        ...         Token.fake('IDENTIFIER', macro.name))
        ...     feed(parser, text)

        >>> test('hello world', mkmacro(1))
        Not a macro call!
        Unprocessed tokens:
        <fakefile>:1:1: IDENTIFIER('hello')
        <fakefile>:1:7: IDENTIFIER('world')

        >>> test('(1,', mkmacro(2))
        Waiting for more input...

        >>> test('()', mkmacro(0))

        >>> test('()', mkmacro(1))
        === Param 1:

        >>> test('(,)', mkmacro(2))
        === Param 1:
        === Param 2:

        >>> test('(1,2)', mkmacro(2))
        === Param 1:
          <fakefile>:1:2: NUMBER('1')
        === Param 2:
          <fakefile>:1:4: NUMBER('2')

        >>> test('((1, 2),(3, 4))', mkmacro(2))
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

        For a variadic macro call, the last parameter can contain commas:
        >>> test('(1,2,3)', mkmacro(2, True))
        === Param 1:
          <fakefile>:1:2: NUMBER('1')
        === Param 2:
          <fakefile>:1:4: NUMBER('2')
          <fakefile>:1:5: PUNCTUATION(',')
          <fakefile>:1:6: NUMBER('3')

        Multiple lines worth of input can be processed:
        >>> macro = mkmacro(2)
        >>> parser = MacroCallParser(macro,
        ...     Token.fake('IDENTIFIER', macro.name))
        >>> feed(parser, '(')
        Waiting for more input...
        >>> feed(parser, '1')
        Waiting for more input...
        >>> feed(parser, ',')
        Waiting for more input...
        >>> feed(parser, '2')
        Waiting for more input...
        >>> feed(parser, ')')
        === Param 1:
          <fakefile>:1:1: NUMBER('1')
        === Param 2:
          <fakefile>:1:1: NUMBER('2')

    Possible errors:

        >>> test('(1)', mkmacro(0)) #doctest: +NORMALIZE_WHITESPACE
        Traceback (most recent call last):
         ...
        loosey.pp.MacroExpansionError: <fakefile>:1:2:
        While expanding macro <fakemacro> (defined at <fakefile>:1:1):
        Expected no parameters

        >>> test('(1,2)', mkmacro(1)) #doctest: +NORMALIZE_WHITESPACE
        Traceback (most recent call last):
         ...
        loosey.pp.MacroExpansionError: <fakefile>:1:3:
        While expanding macro <fakemacro> (defined at <fakefile>:1:1):
        Expected to receive 1 parameters, but already got that many

        >>> test('(1)', mkmacro(2)) #doctest: +NORMALIZE_WHITESPACE
        Traceback (most recent call last):
         ...
        loosey.pp.MacroExpansionError: <fakefile>:1:3:
        While expanding macro <fakemacro> (defined at <fakefile>:1:1):
        Expected to receive 2 parameters, but only got 1

    """

    def __init__(self, macro: Macro, call_token: Token):
        self.macro = macro

        # The token representing the beginning of the call, e.g. in `M(1, 2)`,
        # the "M" is the call_token.
        self.call_token = call_token

        self.param_values = []
        self.param_value = []
        self.paren_depth = 0

    def finish(self) -> list[list[Token]] | NoCall | None:
        if self.paren_depth:
            raise MacroExpansionError(self.macro, self.call_token,
                "Missing closing ')' for macro call")
        else:
            return NO_CALL

    def process(self, tokens: Iterable[Token]) -> list[list[Token]] | NoCall | None:
        tokens = FancyIterator(tokens)

        if not self.paren_depth:
            # Check for the opening '(' of the call, if any
            token = next(tokens, None)
            if token is None or token.value != '(':
                # Not a macro call, just a macro reference.
                # That's fine, just return None.
                # But push the non-'(' token we got back onto the iterator first!
                if token is not None:
                    tokens.push(token)
                return NO_CALL
            self.paren_depth = 1

        macro = self.macro
        param_values = self.param_values
        param_value = self.param_value

        for token in tokens:
            if token.value == ')':
                self.paren_depth -= 1
                if self.paren_depth < 1:
                    break
            elif len(macro.params) == 0:
                raise MacroExpansionError(macro, token, "Expected no parameters")
            elif token.value == '(':
                self.paren_depth += 1
            if (
                self.paren_depth <= 1 and
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
                self.param_value = param_value = []
            else:
                param_value.append(token)
        else:
            # We ran out of tokens!.. that's ok, just return None for now,
            # and wait for process() to be called again with more input.
            return None

        if len(macro.params) == 0 and not param_values and not param_value:
            # The call's parameter list was totally empty... and that's okay,
            # because the macro didn't expect any parameters!
            pass
        else:
            param_values.append(param_value)

        if len(param_values) < len(macro.params):
            raise MacroExpansionError(macro, token,
                f"Expected to receive {len(macro.params)} parameters, "
                f"but only got {len(param_values)}")

        return param_values


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
        ...     MALLOC // not a call, so will expand to MALLOC
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
        input-4:4:5: IDENTIFIER('MALLOC')

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

    # Attributes shared with sub-processors (i.e. Preprocessor instances created
    # when processing #include directives)
    SHARED_ATTRS = (
        'quiet',
        'warn_stdout',
        'add_debug_nodes',
        'sys_dirs',
        'local_dir',
        'macros',
    )

    def __init__(
            self,
            *,
            quiet: bool = False,
            warn_stdout: bool = False,
            add_debug_nodes: bool = False,
            sys_dirs: Iterable[str] = (),
            local_dir: Optional[str] = None,
            macros: Optional[dict[str, Macro]] = None,
            ):
        self.quiet = quiet
        self.warn_stdout = warn_stdout
        self.add_debug_nodes = add_debug_nodes

        # Directories used for #include <...>
        self.sys_dirs = tuple(sys_dirs)

        # Directory used for #include "..."
        self.local_dir = local_dir

        # Defined macros
        self.macros: dict[str, Macro] = {} if macros is None else macros

        # The "call stack" for macro expansion
        self.expanding_macros: list[str] = []

        # The "call stack" for expansion of bound params
        self.expanding_params: list[str] = []

        # Currently bound macro params, i.e. the current "values" of macro
        # parameters, which are lists of tokens
        self.bound_macro_params: dict[str, list[Token]] = {}

        # While a macro call (e.g. `SOME_MACRO(1, 2)`) is being parsed, this
        # will be non-None
        self.macro_call_parser: Optional[MacroCallParser] = None

        self.ifstack: list[ConditionalFrame] = []

        # If non-zero, we are inside an #if, #ifdef, etc whose condition was
        # false, so we should ignore all lines except #else, #endif, etc.
        self.skip_depth: int = 0

        self.nonempty_line_count: int = 0

        self.ppexpr_evaluator = ConditionalExpressionEvaluator()

    def create_child(self, **kwargs) -> 'Preprocessor':
        for k in self.SHARED_ATTRS:
            if k not in kwargs:
                kwargs[k] = getattr(self, k)
        return Preprocessor(**kwargs)

    @debug_recursion()
    def finish_expand(self) -> Iterator[Token]:
        """To be called when there are no more tokens to be expanded, e.g.
        end of file, end of macro body, etc"""
        call_parser = self.macro_call_parser
        if call_parser is not None:
            if call_parser.finish() is NO_CALL:
                # There are no parentheses after the macro name.
                # So we're referring to the macro, but not "calling" it.
                # In this case, we just emit its name.
                yield call_parser.call_token
            debug_recursion_log(f"Finished parsing non-call reference to macro: {self.macro_call_parser.macro.name}")
            self.macro_call_parser = None

    @debug_recursion()
    def finish_file(self) -> Iterator[Token]:
        """To be called when there are no more tokens to be processed, e.g.
        end of file"""
        yield from self.finish_expand()
        if self.ifstack:
            frame = self.ifstack[-1]
            self.ifstack.clear()
            raise ParseError(frame.token, f"Unterminated #{frame.directive}")

    def warn(self, token: Token, msg: str):
        if not self.quiet:
            fullmsg = f"{token.location()}: {msg}"
            if self.warn_stdout:
                print(fullmsg)
            else:
                print(fullmsg, file=sys.stderr)

    @debug_recursion()
    def process(self, lines: Iterable[list[Token]] | str, *, finish: bool = True) -> Iterator[Token]:
        """Process lines of C code"""
        if isinstance(lines, str):
            # Support caller passing us a string, handy for doctests
            lines = Lexer().tokenize(lines)
        for line in lines:
            yield from self.process_line(line)
        if finish:
            yield from self.finish_file()

    @debug_recursion()
    def execute(self, lines: Iterable[list[Token]] | str, *, finish: bool = True):
        """Process lines of C code for their side effects (i.e. directives)
        alone, e.g. to define macros, include files, etc."""
        for token in self.process(lines, finish=finish):
            pass

    @debug_recursion()
    def process_line(self, line: list[Token]) -> Iterator[Token]:
        """Processes the given line of C code, yielding tokens."""

        # Strip out comments
        tokens = [token for token in line if token.toktype != 'COMMENT']

        # Ignore empty lines
        if not tokens:
            return
        elif len(tokens) == 1 and tokens[0].value == '#':
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

        # NOTE:
        # We could probably optimize "header guards" at some point, i.e. files
        # with this structure:
        #
        #   #ifdef NAME / #define NAME / ...rest of file... / #endif
        #
        # ...but it's actually somewhat complicated to detect: we need to make
        # sure that the same #ifdef at the top of the file matches the #endif
        # at the bottom.
        self.nonempty_line_count += 1

        # Process directives, if any
        first_token = tokens[0]
        if first_token.toktype == 'INCLUDE':
            # Handle the #import directive
            if self.skip_depth > 0:
                # We're inside an #if, #ifdef, etc whose condition was false
                return
            if len(tokens) > 1:
                raise ParseError(tokens[1], "Extra tokens after directive arguments")
            match = INCLUDE_REGEX.fullmatch(first_token.value)
            filespec = match.group(1)
            is_system = filespec[0] == '<'
            filename = filespec[1:-1]
            yield from self.include(filename, is_system, first_token)
        elif first_token.value == '#':
            # Handle preprocessor directives other than #import
            directive = tokens[1].value

            if self.skip_depth > 0:
                # We're inside an #if, #ifdef, etc whose condition was false
                if directive in ('if', 'ifdef', 'ifndef'):
                    self.skip_depth += 1
                elif directive == 'endif':
                    self.skip_depth -= 1
                elif directive in ('elif', 'else'):
                    if self.skip_depth == 1:
                        # The if-branch we were in is done, now we need
                        # to handle its else-branch
                        self.skip_depth = 0

            if self.skip_depth > 0:
                # We're inside an #if, #ifdef, etc whose condition was false
                pass
            elif directive == 'define':
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
                self._handle_conditional(tokens)
            elif directive in ('pragma', 'line'):
                self.warn(first_token, f"Ignoring #{directive}")
            else:
                raise ParseError(first_token, f"Unknown directive: #{directive!r}")
        else:
            # This line was not a preprocessor directive!
            # Return the tokens, with any macros expanded.
            # We pass finish=False, because this is only one line, not yet
            # the end-of-file.
            if self.skip_depth > 0:
                # We're inside an #if, #ifdef, etc whose condition was false
                return
            yield from self.expand(tokens, finish=False)

    @debug_recursion()
    def include(self, filename: str, is_system: bool = False, token: Token = None) -> Iterator[Token]:
        if is_system:
            for sys_dir in self.sys_dirs:
                filepath = os.path.join(sys_dir, filename)
                if os.path.isfile(filepath):
                    break
            else:
                filepath = None
        else:
            if self.local_dir is not None:
                filepath = os.path.join(self.local_dir, filename)
                if not os.path.isfile(filepath):
                    filepath = None
            else:
                filepath = None
        if filepath is None:
            local_or_sys = 'system' if is_system else 'local'
            self.warn(token, f"File not found for {local_or_sys} include: {filename!r}")
            return
        else:
            # Process the file with a "child" preprocessor, which shares a
            # lot of stuff with its parent (e.g. macros), but doesn't share
            # other things (e.g. the "ifstack")
            lines = tokenize_file(filepath)
            child_pp = self.create_child()
            yield from child_pp.process(lines)

    @debug_recursion()
    def _evaluate_conditional_expr(self, tokens: list[Token]) -> bool:
        """Evaluates the conditional expression of #if, #elif, etc.

            >>> pp = Preprocessor()
            >>> pp.execute('#define EXISTS')
            >>> pp.execute('#define ADD(X, Y) (X + Y)')
            >>> def test(line: str) -> bool:
            ...     tokens = Lexer().tokenize_line(line)
            ...     return pp._evaluate_conditional_expr(tokens)

            >>> test('#if 1 + 1')
            True

            >>> test('#if 1 - 1')
            False

            Macros are expanded:
            >>> test('#if ADD(1, 1)')
            True

            >>> test('#if ADD(1, -1)')
            False

            The 'defined' operator is implemented:
            >>> test('#if defined EXISTS')
            True

            >>> test('#if defined NOT_EXISTS')
            False

            The 'defined' operator accepts parentheses:
            >>> test('#if defined(EXISTS)')
            True

            >>> test('#if defined(NOT_EXISTS)')
            False

            >>> test('#if defined EXISTS && ! defined NOT_EXISTS')
            True

            >>> test('#if defined EXISTS && defined NOT_EXISTS')
            False

        Possible errors:

            >>> test('#if defined 1')
            Traceback (most recent call last):
             ...
            loosey.pplex.ParseError: <fakefile>:1:13: Expected IDENTIFIER or '(', got: NUMBER('1')

            >>> test('#if defined()')
            Traceback (most recent call last):
             ...
            loosey.pplex.ParseError: <fakefile>:1:13: Expected IDENTIFIER, got: PUNCTUATION(')')

            >>> test('#if defined(X Y')
            Traceback (most recent call last):
             ...
            loosey.pplex.ParseError: <fakefile>:1:15: Expected ')', got: IDENTIFIER('Y')

            >>> test('#if defined(X')
            Traceback (most recent call last):
             ...
            loosey.pplex.ParseError: <fakefile>:1:1: Expected ')', got: end-of-line

        """

        # Prepare to parse the conditional expression, i.e. the tokens after
        # #if, #elif, etc.
        first_token = tokens[0]
        directive = tokens[1].value
        if len(tokens) < 3:
            raise ParseError(first_token, f"Missing conditional expression for #{directive}")

        # Prepare an iterator of tokens starting at the conditional expression
        tokens_it = iter(tokens)
        next(tokens_it) # '#'
        next(tokens_it) # directive, e.g. 'if', 'elif'

        # State for a simple parser which recognizes the token sequences
        # 'define IDENTIFIER' and 'define(IDENTIFIER)'
        expected = ''
        defined_token = None
        need_close = False
        def unexpected(token: Optional[Token]):
            expected_msg = ' or '.join(
                'IDENTIFIER' if c == 'i' else repr(c)
                for c in expected)
            got_msg = token.prettystring() if token else 'end-of-line'
            msg = f"Expected {expected_msg}, got: {got_msg}"
            return ParseError(token or first_token, msg)

        # Process the tokens, i.e. replace 'define IDENTIFIER' and
        # 'define(IDENTIFIER)' sequences with '1' or '0' depending on whether
        # the indicated identifier is in self.macros
        processed_tokens = []
        for token in tokens_it:
            if not expected:
                if token.value == 'defined':
                    defined_token = token
                    expected = 'i('
                else:
                    processed_tokens.append(token)
            elif token.value == '(':
                if '(' not in expected:
                    raise unexpected(token)
                expected = 'i'
                need_close = True
            elif token.value == ')':
                if ')' not in expected:
                    raise unexpected(token)
                expected = ''
            elif token.toktype == 'IDENTIFIER':
                if 'i' not in expected:
                    raise unexpected(token)
                if token.value in self.macros:
                    # Yes, this identifier *is* defined as a macro
                    value = '1'
                    parents = (defined_token, self.macros[token.value].token)
                else:
                    # No, this identifier *not* defined as a macro
                    value = '0'
                    parents = (defined_token,)
                processed_tokens.append(Token.from_parents(parents, 'NUMBER', value))
                expected = ')' if need_close else ''
                need_close = False
                defined_token = None
            else:
                raise unexpected(token)
        if expected:
            raise unexpected(None)

        # Expand the conditional expression
        # NOTE: we strip 'DEBUG' tokens because the conditional expression
        # parser will be confused by them!
        expanded_tokens = [token
            for token in self.expand(processed_tokens,
                expand_token=first_token,
                expand_msg=f"Expanding conditional for #{directive}")
            if token.toktype != 'DEBUG']

        # Evaluate the conditional expression
        try:
            return bool(self.ppexpr_evaluator.eval(expanded_tokens))
        except ParseError as ex:
            raise ParseError(first_token, f"Couldn't parse conditional expression: {ex}")

    def push_conditional(self, frame: ConditionalFrame):
        if not frame.was_true:
            self.skip_depth += 1
        self.ifstack.append(frame)

    def pop_conditional(self) -> ConditionalFrame:
        return self.ifstack.pop()

    @debug_recursion()
    def _handle_conditional(self, tokens: list[Token]):
        """Handles a line with a conditional directive, e.g. #if, #else,
        #endif, etc

            >>> pp = Preprocessor()
            >>> for token in pp.process('''
            ...     #define SOME_MACRO
            ...     #ifdef SOME_MACRO
            ...       #if defined SOME_MACRO
            ...         A
            ...       #else
            ...         B
            ...       #endif
            ...     #else
            ...       #if defined SOME_MACRO
            ...         C
            ...       #else
            ...         D
            ...       #endif
            ...     #endif
            ... '''): token.pprint()
            <fakefile>:5:9: IDENTIFIER('A')

        """
        first_token = tokens[0]
        directive = tokens[1].value
        if directive in 'if':
            is_true = self._evaluate_conditional_expr(tokens)
            self.push_conditional(ConditionalFrame(
                token=first_token,
                directive=directive,
                was_true=is_true,
            ))
        elif directive in ('ifdef', 'ifndef'):
            if len(tokens) > 3 or tokens[2].toktype != 'IDENTIFIER':
                raise ParseError(first_token, f"Expected a single macro name after #{directive}")
            name = tokens[2].value
            if name in self.macros:
                is_true = True
                parents = (first_token, self.macros[name].token)
            else:
                is_true = False
                parents = (first_token,)
            if directive == 'ifndef':
                is_true = not is_true
            self.push_conditional(ConditionalFrame(
                token=first_token.copy_with_parents(parents),
                directive=directive,
                was_true=is_true,
            ))
        elif directive in ('elif', 'else'):
            if not self.ifstack:
                raise ParseError(first_token, f"No matching #if, etc for #{directive}")
            parent = self.pop_conditional()
            if parent.was_true:
                is_true = False
            elif directive == 'else':
                is_true = True
            else:
                assert directive == 'elif'
                is_true = self._evaluate_conditional_expr(tokens)
            self.push_conditional(ConditionalFrame(
                token=first_token,
                directive=directive,
                was_true=is_true,
                parent=parent
            ))
        elif directive == 'endif':
            if not self.ifstack:
                raise ParseError(first_token, f"No matching #if, etc for #{directive}")
            parent = self.pop_conditional()
        else:
            # We should never get here
            raise ParseError(first_token, f"No implementation for #{directive}")

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
    def expand(
            self,
            tokens: Iterable[Token],
            *,
            finish: bool = True,
            expand_token: Optional[Token] = None,
            expand_msg: Optional[str] = None,
            ) -> Iterator[Token]:
        """Expand the given stream of tokens, i.e. apply macros within them,
        yielding a modified stream of tokens."""

        # We want our tokens to be in a "fancy" iterator, so that we can e.g.
        # peek at the next one without actually consuming it!
        tokens = FancyIterator(tokens)

        if self.add_debug_nodes and expand_msg is not None:
            yield Token.from_parents((expand_token,), 'DEBUG', f"START: {expand_msg}")

        try:
            for token in tokens:
                if self.macro_call_parser is not None:
                    # We're in the midst of parsing a macro call, e.g. `MACRO(...)`
                    # Put the token back onto the iterator, and hand off to the
                    # MacroCallParser to parse from here instead
                    tokens.push(token)
                    yield from self._parse_macro_call(tokens)
                else:
                    # We're not parsing a macro, so do whatever we normally do
                    yield from self._expand_token(token, tokens)

            if finish:
                # This is the end of a token stream, e.g. end of file, or end
                # of macro body, etc.
                # So, we do some checks, and also potentially yield tokens, e.g.
                # if we were parsing a potential macro call, and now discover
                # that it is in fact an object-like macro reference.
                yield from self.finish_expand()
        finally:
            if self.add_debug_nodes and expand_msg is not None:
                yield Token.from_parents((expand_token,), 'DEBUG', f"END: {expand_msg}")

    @debug_recursion()
    def _parse_macro_call(self, tokens: FancyIterator[Token]) -> Iterator[Token]:
        r"""Parse the tokens immediately following a reference to a
        function-like macro.
        That is, we've already consumed a token like `MACRO`, and determined
        that it is function-like, and now we are checking whether it's
        followed by a call, e.g. `(...args...)`.

            >>> pp = Preprocessor()
            >>> test_i = 0
            >>> def process(text):
            ...     global test_i
            ...     test_i += 1
            ...     yield from pp.process(Lexer(f'input-{test_i}').tokenize(text))

            Define a macro for testing:
            >>> for token in process('#define M(X, Y, Z) Z Y X'): pass

            Call with all empty parameters:
            >>> for token in process('M(,,)'):
            ...     token.pprint()

            Call with non-empty parameters:
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

            A macro call can span multiple lines:
            >>> for token in process('M(1,\n2,\n3)'):
            ...     token.pprint()
            input-6:1:1: NUMBER('3')
            input-6:1:1: NUMBER('2')
            input-6:1:1: NUMBER('1')

        """

        call_parser = self.macro_call_parser
        call_token = call_parser.call_token
        macro = call_parser.macro
        assert macro.is_function_like

        param_values = call_parser.process(tokens)

        if param_values is None:
            # The call parser didn't finish parsing yet, so it's waiting
            # for us to pass it the next line of tokens.
            # We don't have that yet either, so for now we do nothing!
            return

        # The call parser returned *something*, so we're done parsing the
        # current call, so remove the parser from the preprocessor.
        self.macro_call_parser = None

        call_type = 'non-call reference' if param_values is NO_CALL else 'call'
        debug_recursion_log(f"Finished parsing {call_type} to macro: {macro.name}")

        if param_values is NO_CALL:
            # There are no parentheses after the macro name.
            # So we're referring to the macro, but not "calling" it.
            # In this case, we just emit its name.
            yield call_parser.call_token
            return

        # Map parameter names to values, i.e. token sequences
        param_values_dict = {}
        for param_name, param_tokens in zip(macro.params, param_values):
            # NOTE: we pre-expand the parameter values here, before passing
            # them into the macro body below.
            # But why?!.. mostly because at this point, the macro we're
            # calling isn't yet in self.expanding_macros, so we can support
            # "nested macro calls", e.g. `M(M(1))`.
            # It's not the same thing as recursion, which would be if M's
            # *body* contained a call to M, and we expanded that.
            # See also: https://gcc.gnu.org/onlinedocs/cpp/Argument-Prescan.html
            param_values_dict[param_name] = [
                expanded_token.copy_with_parents((call_token,))
                for expanded_token in self.expand(param_tokens,
                    expand_token=call_token,
                    expand_msg=f"Pre-expanding param {param_name} of macro: {macro.name}")]

        # Now, we store the parameter values in a dict on self, so that
        # they can be referred to while the macro body is being expanded
        old_params = self.bound_macro_params
        self.bound_macro_params = old_params.copy()
        self.bound_macro_params.update(param_values_dict)
        try:
            yield from self._expand_macro_body(macro, call_token, tokens)
        finally:
            # ...and roll back the parameter values, now that the
            # macro body has been expanded
            self.bound_macro_params = old_params

    @debug_recursion()
    def _expand_macro_body(self, macro: Macro, token: Token, tokens: Iterable[Token]) -> Iterator[Token]:
        # NOTE: macros do not recurse!.. so we have to keep track of
        # which ones we are currently in the process of expanding.
        # See: https://gcc.gnu.org/onlinedocs/cpp/Self-Referential-Macros.html
        self.expanding_macros.append(macro.name)
        try:
            # Expand the macro's body
            for expanded_token in self.expand(macro.body,
                    expand_token=token,
                    expand_msg=f"Expanding body of macro: {macro.name}"):
                yield expanded_token.copy_with_parents((token,))
        finally:
            assert self.expanding_macros.pop() == macro.name

    @debug_recursion()
    def _expand_token(self, token: Token, tokens: FancyIterator[Token]) -> Iterator[Token]:
        ident = token.identifier()
        if ident == '__FILE__':
            yield Token.from_parents((token,), 'STRING',
                to_string_literal(token.filename))
        elif ident == '__LINE__':
            yield Token.from_parents((token,), 'NUMBER', str(token.row))
        elif ident in self.bound_macro_params and ident not in self.expanding_params:
            # We found a reference to a bound macro parameter, so use its
            # tokens...
            self.expanding_params.append(ident)
            try:
                # NOTE: we re-expand the tokens here, even though they were
                # already expanded when the macro was called!
                # See: https://gcc.gnu.org/onlinedocs/cpp/Argument-Prescan.html
                for expanded_token in self.expand(self.bound_macro_params[ident],
                        expand_token=token,
                        expand_msg=f"Expanding bound param: {ident}"):
                    yield expanded_token.copy_with_parents((token,))
            finally:
                assert self.expanding_params.pop() == ident
        elif ident in self.macros and ident not in self.expanding_macros:
            # NOTE: macros do not recurse!.. thus the check for `ident not in
            # self.expanding_macros`.
            # See: https://gcc.gnu.org/onlinedocs/cpp/Self-Referential-Macros.html
            macro = self.macros[ident]
            if macro.is_function_like:
                # Function-like macro!
                # See: https://gcc.gnu.org/onlinedocs/cpp/Function-like-Macros.html

                # Attempt to parse the parameters being passed to the macro if
                # it's being "called", i.e. if there are parentheses after the
                # the macro name, like `MACRO(...)`.
                # NOTE: we just create the parser here, we don't call it yet.
                # That's because a macro call might span multiple lines, and we
                # only have access to a single line's worth of tokens right now.
                # So the "macro call parser" can't be a single function call, it
                # needs to be a thing which lives on the preprocessor, and survives
                # parse all available tokens, then wait for more.
                self.macro_call_parser = MacroCallParser(macro, token)
                debug_recursion_log(f"Parsing potential call to macro: {macro.name}")
            else:
                # Object-like macro! Just expand its body.
                # See: https://gcc.gnu.org/onlinedocs/cpp/Object-like-Macros.html
                yield from self._expand_macro_body(macro, token, tokens)
        else:
            # Regular token, yield it as-is!
            yield token


class GrammarEvaluatorWithPreprocessor(GrammarEvaluator):
    """A GrammarEvaluator subclass which adds a C preprocessor which is used
    when parsing input

        >>> from loosey.grammar import parse_rules

        >>> rules = parse_rules('''
        ...     value
        ...         | NUMBER
        ...         | array
        ...         ;
        ...     array
        ...         | '[' ( value ( ',' value )* )? ']'
        ...         ;
        ... ''')

        >>> class ValueEvaluator(GrammarEvaluatorWithPreprocessor):
        ...     grammar_rules = rules
        ...     main_rule_name = 'value'
        ...     squash_children = True
        ...     def on_value(self, match):
        ...         return int(match.token.value)
        ...     def on_array(self, match):
        ...         return [self.on(child) for child in match.children]

        >>> evaluator = ValueEvaluator()
        >>> evaluator.parse('''
        ...     #define DOUBLE(X) X, X
        ...     #define SOME_MACRO
        ... ''')
        >>> evaluator.eval('''
        ...     #ifdef SOME_MACRO
        ...     [1, DOUBLE(2), 3]
        ...     #else
        ...     [99]
        ...     #endif
        ... ''')
        [1, 2, 2, 3]

    """

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.pp = Preprocessor()

    def coerce_lines(self, lines: list[str]) -> list[Token]:
        return list(self.pp.process(lines))


def main():
    parser = ArgumentParser()
    parser.add_argument('-f', '--filename', default='-', help="Use '-' for stdin")
    parser.add_argument('--local-dir', help="Directory used for #include \"...\"")
    parser.add_argument('-i', '--token-info', default=False, action='store_true')
    parser.add_argument('-I', '--include-sys', default=[], action='append')
    parser.add_argument('-t', '--tree', default=False, action='store_true')
    parser.add_argument('-l', '--lex-only', default=False, action='store_true')
    parser.add_argument('-q', '--quiet', default=False, action='store_true')
    parser.add_argument('-d', '--debug', default=False, action='store_true')
    parser.add_argument('-w', '--warn-stdout', default=False, action='store_true')
    parser.add_argument('-M', '--dump-macros', default=False, action='store_true')
    args = parser.parse_args()
    filename = args.filename
    try:
        if args.local_dir is not None:
            local_dir = args.local_dir
        elif filename != '-':
            local_dir = os.path.dirname(filename)
        else:
            local_dir = '.'
        pp = Preprocessor(
            quiet=args.quiet,
            warn_stdout=args.warn_stdout,
            add_debug_nodes=args.debug,
            local_dir=local_dir,
            sys_dirs=args.include_sys,
        )
        lines = tokenize_file(filename)
        if args.lex_only:
            tokens = (token for line in lines for token in line)
        else:
            tokens = pp.process(lines)

        if args.dump_macros:
            for name, macro in pp.macros.items():
                macro.pprint()
        elif args.debug:
            debug_depth = 0
            for token in tokens:
                if token.toktype == 'DEBUG' and token.value.startswith('END:'):
                    debug_depth -= 1
                if args.tree:
                    print(' ' * (token.col - 1) + token.value)
                elif args.token_info:
                    token.pprint()
                else:
                    print('  ' * debug_depth + token.value)
                if token.toktype == 'DEBUG' and token.value.startswith('START:'):
                    debug_depth += 1
        elif args.token_info:
            for token in tokens:
                token.pprint()
        elif args.tree:
            for token in tokens:
                print(' ' * (token.col - 1) + token.value)
        else:
            for token in tokens:
                print(token.value)
    except BrokenPipeError:
        # So we can pipe ourselves into "less" and quit before lexing the
        # whole file, etc
        pass


if __name__ == '__main__':
    main()
