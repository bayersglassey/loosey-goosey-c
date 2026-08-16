import os
import sys
import inspect
from typing import Optional, TypeVar
from contextlib import contextmanager
from functools import wraps
from argparse import ArgumentParser

from loosey import get_data_filepath, bool_env_var
from loosey.grammar import ParseMatch
from loosey.pplex import Token, ParseError, KEYWORDS
from loosey.pp import (
    GrammarEvaluatorWithPreprocessor,
    get_local_dir_from_args,
)
from loosey.stdlib import CStdlib
from loosey.runtime import (
    Value,
    BaseType,
    Declaration,
    Declarator,
    InitDeclarator,
    CTagged,
    CStructlike,
    CEnum,
    Function,
    PythonFunction,
    TypeDef,
    MemoryBlock,
    Struct,
    Pointer,
    ControlFlow,
    Return,
    Continue,
    Break,
    Goto,
    Exit,
    pprint_value,
    value_as_bool,
    value_as_char,
    value_as_int,
    value_as_pointer,
    copy_value,
    coerce_pointers_for_comparison,
)


NO_DEFAULT = object()

TYPE_NAME_GUESSING = bool_env_var('LOOSEY_TYPE_NAME_GUESSING')

GRAMMAR_FILENAME = get_data_filepath('ansi-c-grammar.txt')

Initializer = Value | list['Initializer']


# Maps rule names to operators
# NOTE: only lists rules which correspond to a single operator.
# As an example of a rule which is not listed here, additive_expression
# corresponds to operators '+' and '-', so we have to extract those
# from the ParseMatch.
BINARY_EXPRESSION_OPS = {
    'and_expression': '&',
    'exclusive_or_expression': '|',
    'inclusive_or_expression': '^',
    'logical_and_expression': '&&',
    'logical_or_expression': '||',
}


class _TypeNameGuessScope:
    found_base_type: bool = False
    type_name: Optional[str] = None

DEBUG_TYPE_NAME_GUESSING = bool_env_var('LOOSEY_DEBUG_TYPE_NAME_GUESSING')
@contextmanager
def debug_type_name_guessing():
    """Use this when you want to debug type name guessing for a specific
    block of code"""
    global DEBUG_TYPE_NAME_GUESSING
    original = DEBUG_TYPE_NAME_GUESSING
    DEBUG_TYPE_NAME_GUESSING = True
    try:
        yield
    except Exception as ex:
        print(ex)
    finally:
        DEBUG_TYPE_NAME_GUESSING = original


T = TypeVar('T')
def _with_parse_cache(cache_attr: str):
    # NOTE: cache_attr is an attribute of MiniC
    def decorator(func):
        @wraps(func)
        def wrapped_func(self, match: ParseMatch) -> T:
            cache: dict[str, T] = getattr(self, cache_attr)
            key = match.unique_id
            obj: T = cache.get(key)
            if obj is None:
                obj = func(self, match)
                cache[key] = obj
            return obj
        return wrapped_func
    return decorator


class MiniC(GrammarEvaluatorWithPreprocessor):
    r"""Miniature C interpreter, which can use many Python objects and
    functions directly, and whose objects and functions can be used
    directly from Python.

    Comes with its own C preprocessor, can parse all of ANSI C, and can
    run... some C code. It's a work in progress.

        >>> mini = MiniC()

        >>> mini.eval('1 + 2')
        3

        Watch out for parentheses when you're using macros, of course!..
        >>> mini.eval('#define DOUBLE(X) X + X')
        >>> mini.eval('10 * DOUBLE(2)')
        22

        >>> mini.eval('int add(int x, int y) { return x + y; }')
        add(x, y)

        >>> mini.eval('int x = 1, y = 2;')
        {'x': 1, 'y': 2}

        >>> mini.eval('int total = add(x, y);')
        {'total': 3}

        >>> mini.eval('int total = add(2, 3);')
        {'total': 5}

        We can use Python values directly!
        >>> mini.set_var('x', 99)
        >>> mini.set_var('ten', lambda x: x * 10)
        >>> mini.eval('int total = ten(x);')
        {'total': 990}

        The C preprocessor is available too!
        >>> mini.eval('#define DOUBLE(X) X + X')
        >>> mini.eval('int x = DOUBLE(3);')
        {'x': 6}

    Accessing attributes and methods of Python objects:

        >>> from types import SimpleNamespace

        >>> add_struct_fields = mini.eval('''
        ... int add_struct_fields(struct t *obj) {
        ...     return obj->x + obj->y;
        ... }''')
        >>> add_struct_fields(SimpleNamespace(x=1, y=2))
        3

        >>> add_dict_keys = mini.eval('''
        ... int add_dict_keys(struct t *obj) {
        ...     return obj->get("x") + obj->get("y");
        ... }''')
        >>> add_dict_keys({'x': 1, 'y': 2})
        3

    Allocating and interacting with memory & pointers:

        # Creating a pointer in Python and passing it to C code:
        >>> ptr = Pointer(3)
        >>> mini.eval('void f(void *ptr) { *ptr += 1; }')(ptr)
        >>> ptr
        Pointer(4)

        # Dynamically allocating a data structure in C code and returning
        # it to Python:
        >>> mkobj = mini.eval('''
        ... void *mkobj() {
        ...     void *ptr = malloc(1);
        ...     ptr->x = 3;
        ...     ptr->y = 4;
        ...     return ptr;
        ... }''')
        >>> mkobj()
        Pointer(Struct({'x': 3, 'y': 4}))

    """

    grammar_filename = GRAMMAR_FILENAME
    main_rule_name = 'repl_commands'
    squash_children = True
    eval_empty_ok = True
    pass_through_exceptions = (
        Return,
        Continue,
        Break,
        Goto,
        Exit,
    )
    handler_prefixes = ('reference',)

    def __init__(self,
            *,
            type_name_guessing: bool = TYPE_NAME_GUESSING,
            **kwargs):
        super().__init__(**kwargs)

        self.type_name_guessing = type_name_guessing

        # Define some default macros, which GCC seems to define on my system
        self.pp.execute('#define __restrict')
        self.pp.execute('#define __extension__')
        self.pp.execute('#define __attribute__(...)')
        self.pp.execute('#define _Float32 float')
        self.pp.execute('#define _Float64 float')
        self.pp.execute('#define _Float128 float')
        self.pp.execute('#define _Float32x float')
        self.pp.execute('#define _Float64x float')
        self.pp.execute('#define __asm__(...) ;')

        # NOTE: this is the "call stack" for variables during evaluation
        self.global_scope: dict[str, Pointer] = {}
        self.scopes: list[dict[str, Pointer]] = [self.global_scope]

        # Add some helper functions
        self.add_python_func(self.runtime_error, '__loosey_error__')
        self.add_python_func(self.trace, '__loosey_trace__')
        self.add_python_func(print)
        self.add_python_func(pprint_value, 'pprint')

        # Add some default stdlib functions
        self.stdlib = CStdlib()
        for name, value in self.stdlib.registry.items():
            self.add_global(value, name)

        # The rules for parsing C typedefs are awful, because they're not
        # purely based on the structure of the grammar, they're also based
        # on whether the given identifier was declared as a typedef...
        # See: https://en.wikipedia.org/wiki/Lexer_hack
        # Anyway, the typedef_blocks and related callbacks here are used to
        # handle that.
        # Basically, when we enter/exit the parsing of a statement which
        # introduces a new variable scope, we push/pop a "typedef block".
        # Each typedef block just stores which variables it has seen to
        # definitely be or not be typedefs.
        self.typedef_blocks: list[dict[str, bool]] = []
        self.pattern_callbacks = {

            # Enter/exit typedef blocks
            ('compound_statement', 'block'):
                (self.enter_typedef_block, self.exit_typedef_block),
            ('selection_statement', 'if'):
                (self.enter_typedef_block, self.exit_typedef_block),
            ('selection_statement', 'switch'):
                (self.enter_typedef_block, self.exit_typedef_block),
            ('iteration_statement', 'while'):
                (self.enter_typedef_block, self.exit_typedef_block),
            ('iteration_statement', 'for'):
                (self.enter_typedef_block, self.exit_typedef_block),
            ('iteration_statement', 'do'):
                (self.enter_typedef_block, self.exit_typedef_block),

            # Other stuff
            ('declaration', 'decl'):
                (None, self.exit_declaration),
            ('function_definition_start', 'start'):
                (None, self.exit_function_definition_start),
        }
        self.toktype_predicates = {
            'IDENTIFIER': self.is_identifier_token,
            'TYPE_NAME': self.is_type_name_token,
            'NON_TYPE_NAME': self.is_non_type_name_token,
        }

        # If "type name guessing" is enabled, we register more parser
        # callbacks.
        # E.g. if we see `T x;`, we can infer that T must be a typedef.
        # Thus we would set self.typedef_blocks[-1]['x'] = True.
        # Similarly, from `int x;` we can infer that x is *not* a typedef.
        # Thus we would set self.typedef_blocks[-1]['x'] = False.
        # Etc...
        self.type_name_guess_scopes: list[_TypeNameGuessScope] = []
        if type_name_guessing:
            self.pattern_callbacks.update({
                # Enter/exit "type name guessing" scopes
                ('declaration_specifiers', 'declspec'):
                    (self.enter_type_name_guess_scope, self.exit_type_name_guess_scope),
                ('field_declaration_specifiers', 'declspec'):
                    (self.enter_type_name_guess_scope, self.exit_type_name_guess_scope),
                ('type_name', None):
                    (self.enter_type_name_guess_scope, self.exit_type_name_guess_scope),

                # Found a non type name specifier
                ('type_specifier', 'builtin'):
                    (None, self.exit_type_specifier),
                ('type_specifier', None):
                    (None, self.exit_type_specifier),
            })

        self.parsed_declarators: dict[str, Declarator] = {}
        self.parsed_declarations: dict[str, Declaration] = {}
        self.parsed_structlikes: dict[str, CStructlike] = {}
        self.parsed_functions: dict[str, Function] = {}

        self.validate_pattern_callbacks()

    def validate_pattern_callbacks(self):
        for rule_name, pattern_name in self.pattern_callbacks:
            if rule_name not in self.grammar_rules:
                raise Exception(f"Unknown rule name: {rule_name}")
            if pattern_name and not any(pattern.name == pattern_name
                for pattern in self.grammar_rules[rule_name].patterns
            ):
                raise Exception(f"Unknown pattern name for rule {rule_name}: {pattern_name}")

    def parse(self, *args, **kwargs):
        typedef_block = {}
        for scope in self.scopes:
            for name, ptr in scope.items():
                typedef_block[name] = isinstance(ptr.contents, TypeDef)
        self.typedef_blocks.append(typedef_block)
        try:
            return super().parse(*args, **kwargs)
        finally:
            assert self.typedef_blocks.pop() is typedef_block

    def add_global(self, value, name):
        if inspect.isfunction(value):
            return self.add_python_func(value, name)
        else:
            self.global_scope[name] = Pointer(value)

    def add_python_func(self, func, name=None):
        if not isinstance(func, PythonFunction):
            func = PythonFunction(func, name)
        self.global_scope[func.name] = Pointer(func)

    def globals(self) -> dict[str, Value]:
        return {name: ptr.contents
            for name, ptr in self.global_scope.items()}

    def _type_name_guess_log(self, msg: str):
        print('  ' * len(self.type_name_guess_scopes) + msg)

    def enter_typedef_block(self, token: Token):
        self.typedef_blocks.append({})

    def exit_typedef_block(self, token: Token, match: Optional[ParseMatch]):
        self.typedef_blocks.pop()

    def enter_type_name_guess_scope(self, token: Token):
        assert self.type_name_guessing
        if DEBUG_TYPE_NAME_GUESSING:
            self._type_name_guess_log("ENTER GUESS SCOPE")
        self.type_name_guess_scopes.append(_TypeNameGuessScope())

    def exit_type_name_guess_scope(self, token: Token, match: Optional[ParseMatch]):
        assert self.type_name_guessing
        if DEBUG_TYPE_NAME_GUESSING:
            self._type_name_guess_log("EXIT GUESS SCOPE")
        type_name_guess_scope = self.type_name_guess_scopes.pop()
        if match and type_name_guess_scope.type_name:
            if DEBUG_TYPE_NAME_GUESSING:
                self._type_name_guess_log(f"GUESSED: {type_name_guess_scope.type_name}")
            self.typedef_blocks[-1][type_name_guess_scope.type_name] = True

    def exit_declaration(self, token: Token, match: Optional[ParseMatch]):
        if match is None:
            return

        # NOTE: technically, we should be marking names as being typedefs as
        # soon as we've parsed *each individual declarator*, not the
        # declaration as a whole!..
        # E.g. the following is supposed to work:
        #
        #   typedef int
        #     I,         // now I is a typedef for int
        #     IF(I i);   // now IF is a typedef for functions int(int i)
        #
        # ...but that's crazy. I'm not gonna support that.
        # Please tell me nobody actually does that.
        declaration = self.parse_declaration(match)
        typedef_block = self.typedef_blocks[-1]
        for init_declarator in declaration.init_declarators:
            typedef_block[init_declarator.name] = declaration.is_typedef

    def exit_function_definition_start(self, token: Token, match: Optional[ParseMatch]):
        if match is None:
            return
        # We have just parsed a function definition, up to and including
        # its opening '{', but no further!
        # Before we proceed into the body, we mark the function's name and
        # parameters as not being type names.
        func = self.parse_function(match)
        typedef_block = self.typedef_blocks[-1]
        typedef_block[func.name] = False
        for param in func.params:
            typedef_block[param] = False

    def exit_type_specifier(self, token: Token, match: Optional[ParseMatch]):
        assert self.type_name_guessing
        if match is None:
            return
        if DEBUG_TYPE_NAME_GUESSING:
            self._type_name_guess_log(f"FOUND BASE TYPE: {token.value}")
        type_name_guess_scope = self.type_name_guess_scopes[-1]
        type_name_guess_scope.found_base_type = True

    def is_identifier_token(self, token: Token) -> bool:
        """This method is registered as a callback for the parser, when it
        needs to determine if the given token is of toktype 'IDENTIFIER'"""
        return token.toktype == 'IDENTIFIER' and token.value not in KEYWORDS

    def is_type_name_token(self, token: Token) -> bool:
        """This method is registered as a callback for the parser, when it
        needs to determine if the given token is of toktype 'TYPE_NAME'.
        There is no such toktype, except for "virtually" based on the output
        of this method!.."""
        is_type_name = (
            token.toktype == 'IDENTIFIER' and
            token.value not in KEYWORDS and
            self.is_type_name(token.value)
        )
        if is_type_name and self.type_name_guess_scopes:
            type_name_guess_scope = self.type_name_guess_scopes[-1]
            type_name_guess_scope.found_base_type = True
            type_name_guess_scope.type_name = token.value
        return is_type_name

    def is_non_type_name_token(self, token: Token) -> bool:
        """This method is registered as a callback for the parser, when it
        needs to determine if the given token is of toktype 'NON_TYPE_NAME'.
        There is no such toktype, except for "virtually" based on the output
        of this method!.."""
        return (
            token.toktype == 'IDENTIFIER' and
            token.value not in KEYWORDS and
            not self.is_type_name(token.value, False)
        )

    def is_type_name(self, name: str, default: bool = True) -> bool:
        """Check whether the given identifier is a type name (e.g. because it
        was declared as such in a typedef).
        See also: https://en.wikipedia.org/wiki/Lexer_hack

            >>> mini = MiniC()

            In the examples below, when Integer is *not* a typedef,
            `Integer *x` is interpreted as a multiplication; when it's a
            typedef, `Integer *x` is interpreted as a variable declaration:

            >>> mini.parse('Integer * x;').rule_name
            'multiplicative_expression'

            >>> mini.parse('typedef int Integer; Integer * x;').children[1].rule_name
            'declaration'

            Similarly, if we evaluate a typedef, it exists in our globals, and
            is taken into account when parsing:
            >>> mini.eval('typedef int Integer;')
            {'Integer': TypeDef('Integer')}
            >>> mini.parse('Integer * x;').rule_name
            'declaration'

        TYPE NAME GUESSING: when this is enabled, we attempt to infer when an
        identifier must be a type name, even if we haven't seen an explicit
        typedef declaration for it.

            >>> mini = MiniC(type_name_guessing=True)

            Here, T is clearly an identifier, not a type name:
            >>> mini.parse_declaration(mini.parse('int T;')).pprint()
            int():
              T()

            Here, T is clearly a type name:
            >>> mini.parse_declaration(mini.parse('T t;')).pprint()
            type_name T():
              t()

            Here, we have used T inconsistently.
            It will be marked as an identifier, leading to a parse error for
            the second declaration:
            >>> mini.parse('int T; T t;')
            Traceback (most recent call last):
             ...
            loosey.pplex.ParseError: <fakefile>:1:11: Parsed up to here ...

            Here, we have the reverse inconsistency, where T is a type name:
            >>> mini.parse_declaration(mini.parse('T t; int T;'))
            Traceback (most recent call last):
             ...
            loosey.pplex.ParseError: <fakefile>:1:10: Multiple base types: int and T

            This could be a declaration or a multiplication; we assume the
            former.
            >>> mini.parse('x * y;', 'statement').rule_name
            'declaration'

            Here's a tricky case we need to make sure we get right:
            technically, f(x) could be a function call or a type declaration,
            depending on whether f is a type name or not.
            And we want to make sure we guess that it's *not* a type name.
            >>> mini.parse('f(x);', 'statement').rule_name
            'postfix_expression'

            On the other hand, if there are no parentheses, then we should of
            course guess that f is a type name, and that this is a declaration:
            >>> mini.parse('f x;', 'statement').rule_name
            'declaration'

            Another tricky edge case is cast expressions.
            Technically, (f)(x) could make sense as a cast of x to type f, or
            a function call; we assume the latter.
            >>> mini.parse('(f)(x);', 'statement').rule_name
            'postfix_expression'

            Since we use magically auto-growing Struct objects as the default
            value for uninitialized variables, it's often fine if we assume a
            type name, without actually "knowing" what it represents:
            >>> mini.eval('SOME_TYPE obj; obj.x = 3; obj')
            Struct({'x': 3})

            ...however, there are some cases where this doesn't work, like
            in initializer lists.
            There's no way around this, since in order to map the list's items
            onto struct fields, we would need to know the field names!..
            >>> mini.eval('SOME_TYPE obj = {3, 4};') #doctest: +NORMALIZE_WHITESPACE
            Traceback (most recent call last):
             ...
            loosey.pplex.ParseError: <fakefile>:1:1:
            Can't use initializer list with non-array/struct/union type
            ('type_name', 'SOME_TYPE'). List was: [3, 4]

        """

        # E.g. 'while' can never be a type name
        if name in KEYWORDS:
            return False

        # Check if we know for sure whether name is or is not a typedef
        if DEBUG_TYPE_NAME_GUESSING:
            self._type_name_guess_log(f"IS TYPE NAME? {name}")
        for block in reversed(self.typedef_blocks):
            if name in block:
                if DEBUG_TYPE_NAME_GUESSING:
                    self._type_name_guess_log(f"IT'S OFFICIAL: {block[name]}")
                is_type_name = block.get(name)
                if is_type_name is not None:
                    return is_type_name

        # If we're not doing "type name guessing", return False, since we
        # haven't an explicit declaration that this is a type name.
        if not self.type_name_guessing:
            return False

        # If we are in a "declspec" (declaration specifiers sequence, like
        # `extern int` or `const T`), did we already find a base type (like
        # `int` or `T`)?..
        # If so, then subsequent identifiers can't be type names.
        # So for instance, when parsing `int x`, we don't want to guess that
        # `x` is a type name, because we already saw a base type `int`!
        # Whereas in `extern T`, we're okay guessing that T is a type name,
        # because `extern` is a storage class, not a base type.
        # NOTE: we only look at the current "guess scope", just for simplicity
        # and speed.
        # Nested "guess scopes" are e.g. in `const struct { T t; int x; }`,
        # where the struct definition is inside a "guess scope" but there is
        # also a "guess scope" for each field declaration inside it.
        if self.type_name_guess_scopes:
            type_name_guess_scope = self.type_name_guess_scopes[-1]
            if type_name_guess_scope.found_base_type:
                if DEBUG_TYPE_NAME_GUESSING:
                    self._type_name_guess_log("CAN'T BE, WE ALREADY FOUND A BASE TYPE")
                return False

        if default:
            # Let's try saying that this might be a type name, and see what
            # happens!..
            if DEBUG_TYPE_NAME_GUESSING:
                self._type_name_guess_log("SURE!")
            return True
        else:
            # We were trying to figure out if this was *not* a type name,
            # and since we haven't seen evidence to suggest that it is,
            # let's assume it's not.
            if DEBUG_TYPE_NAME_GUESSING:
                self._type_name_guess_log("NAAAH")
            return False

    @contextmanager
    def new_scope(self) -> dict[str, Pointer]:
        scope = {}
        self.scopes.append(scope)
        try:
            yield scope
        finally:
            assert self.scopes.pop() is scope

    def var_lookup_error(self, name: str) -> Exception:
        names_msg = ' '.join(f"{{{' '.join(scope)}}}" for scope in self.scopes)
        raise Exception(f"Object not found: {name!r} (names currently in scope: {names_msg})")

    def have_var(self, name: str) -> bool:
        for scope in reversed(self.scopes):
            if name in scope:
                return True
        return False

    def get_var_ref(self, name: str, raise_ex: bool = True) -> Pointer:
        """Get a reference to the indicated variable"""
        for scope in reversed(self.scopes):
            if name in scope:
                return scope[name]
        if raise_ex:
            raise self.var_lookup_error(name)
        else:
            return None

    def get_var(self, name: str, default=NO_DEFAULT) -> Value:
        """Get the value of the indicated variable (including functions,
        typedefs, etc)"""
        for scope in reversed(self.scopes):
            if name in scope:
                return scope[name].contents
        if default is NO_DEFAULT:
            raise self.var_lookup_error(name)
        else:
            return default

    def set_var(self, name: str, value: Value):
        """Sets the value of the indicated variable (including functions,
        typedefs, etc).
        Uses an existing variable if found, otherwise declares one within
        the current scope."""
        ptr = self.get_var_ref(name, False)
        if ptr is None:
            scope = self.scopes[-1]
            scope[name] = Pointer(value)
        else:
            ptr.contents = value

    def declare_var(self, name: str, value: Value):
        """Sets the value of the indicated variable (including functions,
        typedefs, etc) within the current scope, creating it if necessary."""
        scope = self.scopes[-1]
        if name in scope:
            scope[name].contents = value
        else:
            scope[name] = Pointer(value)

    def declare_tagged(self, tagged: CTagged):
        # Struct/union/enum tags use the same scoping mechanism as everything
        # else, but have a different "namespace".
        # We implement this by reusing our exising scopes, but using a 'tag:'
        # prefix to turn tags into "identifiers" which don't clash with real
        # identifiers.
        self.declare_var('tag:' + tagged.tag, tagged)

    def get_tagged(self, tag: str, default=NO_DEFAULT) -> CTagged:
        return self.get_var('tag:' + tag, default)

    def complete_tagged(self, tagged: CTagged) -> CTagged:
        """Get the completed definition of a struct/union/enum, e.g. expand
        `struct T` to the full definition with fields, if such a definition
        is found in scope"""
        if not tagged.empty:
            return tagged
        expanded = self.get_tagged(tagged.tag, None)
        if expanded is None:
            raise Exception("{tagged.kind} {tagged.tag!r} has incomplete type")
        return expanded

    @_with_parse_cache('parsed_declarators')
    def parse_declarator(self, match: ParseMatch) -> Declarator:
        """Parse a "declarator", e.g. in `int x, *y[3]`, the `x` and `*y[3]`
        are declarators.

            >>> mini = MiniC()

            >>> def test(text, rule_name='declarator'):
            ...     match = mini.parse(text, rule_name)
            ...     decl = mini.parse_declarator(match)
            ...     return decl.name, decl.kinds

            >>> test('x')
            ('x', [])

            >>> test('(x)')
            ('x', [])

            >>> test('*x')
            ('x', ['pointer'])

            >>> test('*(x)')
            ('x', ['pointer'])

            >>> test('(*x)')
            ('x', ['pointer'])

            >>> test('**x')
            ('x', ['pointer', 'pointer'])

            >>> test('x[]')
            ('x', ['array'])

            >>> test('(x)[]')
            ('x', ['array'])

            >>> test('(x[])')
            ('x', ['array'])

            >>> test('x[][]')
            ('x', ['array', 'array'])

            >>> test('x()')
            ('x', ['func'])

            >>> test('(x)()')
            ('x', ['func'])

            >>> test('(x())')
            ('x', ['func'])

        The most obnoxious distinction in C's entire type system: function
        pointer vs function returning pointer:

            >>> test('(*x)()')
            ('x', ['pointer', 'func'])

            >>> test('*x()')
            ('x', ['func', 'pointer'])

            >>> test('*(x)()')
            ('x', ['func', 'pointer'])

        Another tricky distinction: array of pointers vs pointer to array:

            >>> test('*x[]')
            ('x', ['array', 'pointer'])

            >>> test('(*x)[]')
            ('x', ['pointer', 'array'])

        This all needs to also work when parsing abstract declarators:

            >>> test('*', 'abstract_declarator')
            (None, ['pointer'])

            >>> test('**', 'abstract_declarator')
            (None, ['pointer', 'pointer'])

            >>> test('* const *', 'abstract_declarator')
            (None, ['pointer', 'pointer'])

            >>> test('*(*)', 'abstract_declarator')
            (None, ['pointer', 'pointer'])

            >>> test('*((*))', 'abstract_declarator')
            (None, ['pointer', 'pointer'])

            >>> test('[]', 'abstract_declarator')
            (None, ['array'])

            >>> test('*[]', 'abstract_declarator')
            (None, ['array', 'pointer'])

            >>> test('(*)[]', 'abstract_declarator')
            (None, ['pointer', 'array'])

        This all needs to also work when parsing declarators within struct or
        union declarations:

            >>> test('(*x)[]', 'field_declarator')
            ('x', ['pointer', 'array'])

            Also, we need to handle bitfields:
            >>> test('x: 4', 'field_declarator')
            ('x', ['bitfield'])

        """
        assert match.rule_name in (
            'declarator',
            'abstract_declarator',
            'field_declarator',
        ), match

        declarator_rule_name = 'declarator'
        if match.rule_name == 'abstract_declarator':
            declarator_rule_name = 'abstract_declarator'
        suffix_rule_name = declarator_rule_name + '_suffix'

        is_bitfield = match.pattern_name == 'bitfield'

        # Find the stuff within the innermost set of parentheses...
        # 1. `*(*(**x[3])[])()` -> `**x[3]`
        # 2. `*(*(x)[])()` -> `*(x)[]`
        #    ...note how we don't count the parentheses around `(x)`, since
        #    they don't affect the type of x!.. e.g. `*((x))` is a pointer.
        child = match
        kinds = ['bitfield'] if is_bitfield else []
        while True:
            # Do we start with a pointer, i.e. `*`?..
            ptr_child = child.find('pointer')
            while ptr_child:
                kinds.append('pointer')
                ptr_child = ptr_child.find('pointer')

            # Do we have a suffix, i.e. `[...]` or `(...)`?
            suffix_match = child.find(suffix_rule_name)
            if suffix_match is not None:
                if suffix_match.pattern_name == 'array':
                    for suffix_child in suffix_match.children:
                        kinds.append('array')
                elif suffix_match.pattern_name == 'params':
                    kinds.append('func')
                else:
                    # Should never happen
                    raise ParseError(suffix_match.token, f"Unknown suffix: {suffix_match}")

            # Burrow further into the declarator...
            next_child = child.find(declarator_rule_name)
            if next_child is None:
                # We reached the "center" of the declarator!..
                # We should find a variable name here, unless we are an
                # abstract declarator, in which case we should find nothing.
                # In either case, we're done parsing!
                name_match = child.find('declare:.')
                name = name_match and name_match.token.value
                break
            child = next_child

        # We appended to kinds while traversing the declarator from the
        # "outside in", as it were; but we want the list of kinds to describe
        # it from the inside out.
        # E.g. we want ['pointer', 'array'] to mean pointer-to-array.
        kinds.reverse()

        return Declarator(
            match=match,
            name=name,
            kinds=kinds,
        )

    @_with_parse_cache('parsed_declarations')
    def parse_declaration(self, match: ParseMatch) -> Declaration:
        assert match.rule_name in ('declaration', 'field_declaration'), match

        # Init declarators, e.g. `x`, `*x[3]`, `x = 2`, etc
        init_declarators: list[InitDeclarator] = []
        for child in match.children[1:]:
            assert child.rule_name in ('init_declarator', 'field_declarator'), child
            if child.rule_name == 'init_declarator':
                initializer = child.children[1] if len(child.children) > 1 else None
                child = child.children[0] # now child is the declarator
            else:
                # For field_declarator, there is never an initializer
                initializer = None
            is_bitfield = child.pattern_name == 'bitfield'
            if is_bitfield and len(child.children) == 1:
                # Anonymous bitfield!.. just used for padding, we ignore
                # it completely
                continue
            declarator = self.parse_declarator(child)
            init_declarators.append(InitDeclarator(declarator, initializer))

        return Declaration(
            match=match,
            init_declarators=init_declarators,
        )

    @_with_parse_cache('parsed_functions')
    def parse_function(self, match: ParseMatch) -> Function:
        if match.rule_name == 'function_definition':
            body = match.children[1:]
            match = match.children[0]
        else:
            # We're just parsing a Function from the *start* of a function
            # declaration, i.e. everything up to and including the opening
            # '{' of its body.
            body = []
        assert match.rule_name == 'function_definition_start', match

        declarator = self.parse_declarator(match.find('declarator'))
        if declarator.kind != 'func':
            raise ParseError(match.token, "Trying to define a function using non-function variable")
        name = declarator.name
        params_match = declarator.match.find('params:.')
        params = [child.token.value for child in
            # NOTE: might be a parameter_type_list, i.e. (int x, int y), or
            # might be a list of param_identifier, i.e. just (x, y)
            params_match.findall('.* declare:.', sorted=True)]
        variadic = declarator.match.children[1].find('.* ellipsis') is not None
        return Function(
            match=match,
            name=name,
            params=params,
            variadic=variadic,
            body=body,
            call=self.call_func,
        )

    def runtime_error(self, msg: str):
        # NOTE: this function is available to C code as __loosey_error__
        raise Exception(msg)

    def trace(self):
        # NOTE: this function is available to C code as __loosey_trace__
        import ipdb
        ipdb.set_trace()

    ###########################################################################
    # GRAMMAR HANDLER METHODS

    def on_funcdef__function_definition(self, match: ParseMatch) -> Function:
        func = self.parse_function(match)
        self.declare_var(func.name, func)
        return func

    def on_cast__cast_expression(self, match: ParseMatch) -> Value:
        # TODO: handle conversions between char* and other things...
        # I think the way to do it will be to have sizeof X always be 1,
        # and then have a MagicCharPointer class...
        # The idea being that the representation of any value by char* will
        # be an instance of MagicCharPointer, which behaves like a pointer
        # to a single-char array {0xFF}, but also has a reference to an
        # arbitrary object, which is extracted when we cast to anything
        # other than char *.
        return self.on(match.children[1])

    def on_enum__enum_specifier(self, match: ParseMatch) -> CEnum:
        """

            >>> mini = MiniC()

            >>> mini.eval('enum E', 'enum_specifier').pprint()
            enum E

            >>> mini.eval('enum { x }', 'enum_specifier').pprint()
            enum:
              x = 0

            >>> mini.eval('enum E { x, y = 2, z, }', 'enum_specifier').pprint()
            enum E:
              x = 0
              y = 2
              z = 3

            Evaluating an enum specifier also declares it in the tag namespace,
            and adds its values to the current scope:
            >>> mini.get_tagged('E').values['y']
            2
            >>> mini.get_var('y')
            2

            NOTE: if no values are declared, we don't store the enum, since
            that could overwrite a previous definition of it which had values:
            >>> E2 = mini.eval('enum E2', 'enum_specifier')
            >>> mini.get_tagged('E2', None)

        """

        tag_match = match.find('struct_or_union_or_enum_tag')
        tag = None if tag_match is None else tag_match.token.value

        values_match = match.find('enumerator_list')
        if values_match:
            values = {}
            next_value = 0
            for child in values_match.children:
                if child.children:
                    # e.g. `x = 1`
                    name = child.children[0].token.value
                    value = self.on(child.children[1])
                else:
                    # e.g. `x`
                    name = child.token.value
                    value = next_value
                if name in values:
                    raise ParseError(child.token, "Duplicate enum name: {name!r}")
                values[name] = value
                next_value = value + 1
        else:
            values = {}

        # Turn the enum values into variables!..
        # We don't currently have a way to mark them as "constant", so it will
        # actually be possible to take their address, like regular variables.
        # Also, note that these values are *not* necessarily global!..
        # Typedefs, variables, functions, and enum values all use the same
        # "namespace":
        #
        #   enum { X = 1 };
        #
        #   main() {
        #       printf("%i\n", X); // prints 1
        #       {
        #           enum { X = 2 };
        #           printf("%i\n", X); // prints 2
        #       }
        #       printf("%i\n", X); // prints 1 again
        #   }
        #
        for name, value in values.items():
            self.declare_var(name, value)

        enum = CEnum(match, tag, values)
        if tag is not None and values:
            self.declare_tagged(enum)
        return enum

    def on_struct_or_union_specifier(self, match: ParseMatch) -> CStructlike:
        """

            Evaluating a struct or union specifier also declares it in the tag
            namespace:
            >>> mini = MiniC()

            >>> T = mini.eval('struct T { int x; }', 'struct_or_union_specifier')
            >>> mini.get_tagged('T') is T
            True

            NOTE: if no fields are declared, we don't store the struct, since
            that could overwrite a previous definition of it which had fields:
            >>> T2 = mini.eval('struct T2', 'struct_or_union_specifier')
            >>> mini.get_tagged('T2', None)

        """
        # NOTE: assumes match is of the correct rule name
        structlike = self.parse_structlike(match)
        if structlike.tag is not None and structlike.field_declarations:
            self.declare_tagged(structlike)
        return structlike

    @_with_parse_cache('parsed_structlikes')
    def parse_structlike(self, match: ParseMatch) -> CStructlike:
        """

            >>> mini = MiniC()

            >>> def test(text):
            ...     match = mini.parse(text, 'struct_or_union_specifier')
            ...     mini.parse_structlike(match).pprint()

            >>> test('struct T')
            struct T

            >>> test('struct { int x; }')
            struct:
              x

            >>> test('struct T { int x; }')
            struct T:
              x

            >>> test('struct { const int x, y; int data[]; }')
            struct:
              const x, y
              data(array)

            Bitfields are supported:
            >>> test('struct { int x, flag:2, :4, y; }')
            struct:
              x, flag(bitfield), y

        """
        assert match.rule_name == 'struct_or_union_specifier', match

        kind = match.children[0].token.value # 'struct' or 'union'

        tag_match = match.find('struct_or_union_or_enum_tag')
        tag = None if tag_match is None else tag_match.token.value

        fields_match = match.find('field_declaration_list')
        fields = () if fields_match is None else fields_match.children

        declarations = []
        for child in fields:
            declarations.append(self.parse_declaration(child))

        return CStructlike(
            match=match,
            kind=kind,
            tag=tag,
            field_declarations=declarations,
        )

    def on_declaration_list(self, match: ParseMatch) -> dict[str, Value]:
        intialized_values = {}
        for child in match.children:
            intialized_values.update(self.on(child))
        return intialized_values

    def on_decl__declaration(self, match: ParseMatch) -> dict[str, Value]:
        """

            >>> mini = MiniC()
            >>> mini.eval('int x;')
            {'x': Struct()}
            >>> mini.eval('int x = 1;')
            {'x': 1}
            >>> mini.eval('int x;')
            {'x': 1}
            >>> mini.eval('char *s = "abc";')
            {'s': Pointer(0..2)}
            >>> mini.eval('char s[] = "abc";')
            {'s': Pointer(0..2)}
            >>> mini.eval('char c = "abc"[1];')
            {'c': 98}
            >>> mini.eval('typedef int Integer;')
            {'Integer': TypeDef('Integer')}
            >>> mini.eval('int add();')
            {'add': add(...)}
            >>> mini.eval('int data[3];')
            {'data': Pointer(0..0)}
            >>> mini.eval('int data[] = {1, 2, 3, 4};')
            {'data': Pointer(0..3)}
            >>> mini.eval('data[2]')
            3
            >>> mini.eval('int data[][2] = {{1, 2}, {3, 4}, {5, 6}};')
            {'data': Pointer(0..2)}
            >>> mini.eval('data[1][1]')
            4
            >>> mini.eval('data[1]')
            Pointer(0..1)

            Evaluating a declaration causes any struct, union, and enum
            declarations within it to be evaluated as well:
            >>> mini.eval('struct T { int x; };')
            {}
            >>> list(mini.get_tagged('T').fields)
            ['x']
            >>> mini.eval('enum E { x, y };')
            {}
            >>> mini.get_tagged('E').values
            {'x': 0, 'y': 1}

        """
        intialized_values = {}

        declaration = self.parse_declaration(match)

        # Handle struct, union, enum declarations
        for child in declaration.declspec.children:
            if child.rule_name in (
                'enum_specifier',
                'struct_or_union_specifier',
            ):
                self.on(child)

        if declaration.is_typedef:
            # Handle typedefs
            for init_declarator in declaration.init_declarators:
                name = init_declarator.name
                value = TypeDef(
                    name=name,
                    declaration=declaration,
                    declarator=init_declarator.declarator,
                )
                self.declare_var(name, value)
                intialized_values[name] = value
        else:
            # Handle variable initializations
            for init_declarator in declaration.init_declarators:
                name = init_declarator.name
                initializer = init_declarator.initializer
                if initializer is not None:
                    is_initializer_list = initializer.spec == 'initializer_list:initializer'
                    if is_initializer_list:
                        # E.g. `= {0}`, `= {1, 2}`, `= {{1, 2}, {3, 4}}`, etc
                        value = self.convert_initializer(
                            declaration,
                            init_declarator.declarator,
                            self.on(initializer),
                            initializer.token,
                        )
                    else:
                        # E.g. `= 3`, `= "hello"`, etc
                        value = copy_value(self.on(initializer), initializer=True)
                    self.declare_var(name, value)
                else:
                    scope = self.scopes[-1]
                    if name in scope:
                        # This variable is already initialized!.. so don't
                        # overwrite with a fresh Struct.
                        # In particular, we don't want to have function
                        # prototypes overwrite the actual functions!..
                        value = scope[name].contents
                    else:
                        # Uninitialized variables are assigned a reasonable
                        # default value
                        value = self._create_uninitialized_value(
                            init_declarator.declarator.match.token,
                            name,
                            init_declarator.declarator.kind,
                        )
                        self.declare_var(name, value)
                intialized_values[name] = value

        return intialized_values

    def _create_uninitialized_value(self, token: Token, name: str, kind: Optional[str]) -> Value:
        if kind == 'array':
            # Array variables are initialized to pointers
            # backed by an auto-growing memory block
            return Pointer(MemoryBlock())
        elif kind == 'func':
            # Functions are initialized to a function which
            # tells you that it's uninitialized
            def func(*args):
                raise ParseError(token,
                    f"Function {name!r} was never defined!")
            return PythonFunction(func, name)
        elif kind == 'pointer':
            # Pointers default to NULL, of course
            return 0
        else:
            # Other kinds of variable are initialized to a
            # magic Struct object
            return Struct()

    def on_declspec__declaration_specifiers(self, match: ParseMatch):
        # E.g. for struct definitions, like `struct t { int x; };`
        pass

    def get_reference(self, match: ParseMatch) -> Pointer:
        with self.use_handler_prefix('reference'):
            return self.on(match)

    def dereference(self, value: Value) -> Value:
        # If value is a pointer, dereference it!..
        # Otherwise, we return value as-is, which is especially handy if we
        # want to pass arbitrary Python objects to C code.
        if isinstance(value, Pointer):
            return value.contents
        else:
            return value

    def expand_type(self, declaration: Declaration, declarator: Declarator) -> tuple[BaseType, list[str]]:
        """

            >>> mini = MiniC()
            >>> mini.eval(
            ...     'typedef struct T { int x, xs[]; } T;'
            ...     'typedef T *T_PTRS[];' # An array of pointers
            ...     'typedef union U { int x, xs[]; } U;'
            ... )

            >>> declaration = mini.parse_declaration(
            ...     # A pointer to a function returning an array of pointers
            ...     mini.parse('T_PTRS (*x)(int);', 'declaration'))
            >>> declarator = declaration.init_declarators[0].declarator
            >>> base_type, kinds = mini.expand_type(declaration, declarator)
            >>> kinds # A pointer to a function returning an array of pointers
            ['pointer', 'func', 'array', 'pointer']
            >>> base_type[0]
            'struct'
            >>> mini.parse_structlike(base_type[1]).pprint()
            struct T:
              x, xs(array)

            >>> declaration = mini.parse_declaration(
            ...     mini.parse('U *u;', 'declaration'))
            >>> declarator = declaration.init_declarators[0].declarator
            >>> base_type, kinds = mini.expand_type(declaration, declarator)
            >>> kinds, base_type[0]
            (['pointer'], 'union')

            When "type name guessing" is enabled, we might guess that a given
            name represents a type, yet be unable to expand it:
            >>> mini = MiniC(type_name_guessing=True)
            >>> declaration = mini.parse_declaration(
            ...     mini.parse('SOME_TYPE *u;', 'declaration'))
            >>> declarator = declaration.init_declarators[0].declarator
            >>> base_type, kinds = mini.expand_type(declaration, declarator)
            >>> kinds, base_type
            (['pointer'], ('type_name', 'SOME_TYPE'))

        """
        kinds = []
        while True:
            # Expand typedefs
            kinds += declarator.kinds
            base_type, typedef_name = declaration.base_type
            if base_type != 'type_name':
                break
            typedef = self.get_var(typedef_name, None)
            if typedef is None:
                # We can get here e.g. if "type name guessing" is enabled
                break
            declaration = typedef.declaration
            declarator = typedef.declarator
        return declaration.base_type, kinds

    def on_initializer_list__initializer(self, match: ParseMatch) -> list[Initializer]:
        return [self.on(child) for child in match.children]

    def convert_initializer(
            self,
            declaration: Declaration,
            declarator: Declarator,
            initializer: Initializer,
            initializer_token: Optional[Token] = None,
            ) -> Value:
        r"""Figures out what the value of an initializer is.
        That wouldn't be a hard problem... except when we need to match
        initializer list elements onto struct fields!..

            >>> mini = MiniC()

            >>> mini.eval('int i1 = 1, i2 = 2;')
            {'i1': 1, 'i2': 2}
            >>> declaration = mini.parse_declaration(mini.parse(
            ...     'int x = 99, xs[] = {1, 2}, *ptrs[] = {&i1, &i2};'))

            >>> def test(declaration, i):
            ...     declarator, initializer_match = declaration.init_declarators[i]
            ...     initializer = mini.on(initializer_match)
            ...     value = mini.convert_initializer(
            ...         declaration, declarator, initializer,
            ...         initializer_match.token)
            ...     print(f"=== {declarator.name}:")
            ...     pprint_value(value)

            >>> test(declaration, 0)
            === x:
              0x0: 99

            >>> test(declaration, 1)
            === xs:
              0x0: Pointer (offset=0) into memory:
              0x1:   As a C string: b'\x01\x02'
              0x2:   0: 1
              0x3:   1: 2

            >>> test(declaration, 2)
            === ptrs:
              0x0: Pointer (offset=0) into memory:
              0x1:   0: Pointer (offset=0) into memory:
              0x2:     As a C string: b'\x01'
              0x3:     0: 1
              0x4:   1: Pointer (offset=0) into memory:
              0x5:     As a C string: b'\x02'
              0x6:     0: 2

            Making sure typedefs work as expected:
            >>> mini.eval('typedef int Integer;')
            {'Integer': TypeDef('Integer')}
            >>> declaration = mini.parse_declaration(mini.parse(
            ...     'Integer x = 99;'))
            >>> test(declaration, 0)
            === x:
              0x0: 99

            Typedefs combined with arrays:
            >>> mini.eval('typedef int IntArray[];')
            {'IntArray': TypeDef('IntArray')}
            >>> declaration = mini.parse_declaration(mini.parse(
            ...     'IntArray xs[] = {{1, 2}, {3, 4}};'))
            >>> test(declaration, 0)
            === xs:
              0x0: Pointer (offset=0) into memory:
              0x1:   0: Pointer (offset=0) into memory:
              0x2:     As a C string: b'\x01\x02'
              0x3:     0: 1
              0x4:     1: 2
              0x5:   1: Pointer (offset=0) into memory:
              0x6:     As a C string: b'\x03\x04'
              0x7:     0: 3
              0x8:     1: 4

            Unions:
            >>> declaration = mini.parse_declaration(mini.parse(
            ...     # Only the first member of a union can be initialized
            ...     # within an initializer list
            ...     'union { int x, xs[]; } u = {99};'))
            >>> test(declaration, 0)
            === u:
              0x0: Struct:
              0x1:   'x': 99
            >>> declaration = mini.parse_declaration(mini.parse(
            ...     # Only the first member of a union can be initialized
            ...     # within an initializer list
            ...     'union { int xs[], x; } u = {{1, 2}};'))
            >>> test(declaration, 0)
            === u:
              0x0: Struct:
              0x1:   'xs': Pointer (offset=0) into memory:
              0x2:     As a C string: b'\x01\x02'
              0x3:     0: 1
              0x4:     1: 2

            Structs:
            >>> declaration = mini.parse_declaration(mini.parse('''
            ...     struct { const char *name; int age; }
            ...         jim = {"jim", 3}, sue = {0};'''))
            >>> test(declaration, 0)
            === jim:
              0x0: Struct:
              0x1:   'name': Pointer (offset=0) into memory:
              0x2:     As a C string: b'jim'
              0x3:     0: 106
              0x4:     1: 105
              0x5:     2: 109
              0x6:   'age': 3
            >>> test(declaration, 1)
            === sue:
              0x0: Struct:
              0x1:   'name': 0
              0x2:   'age': Struct:

            Typedefs combined with structs and arrays:
            >>> mini.eval('''
            ...     typedef struct T { int x, xx[2]; } T;
            ...     typedef struct Y { struct T t; T tt[2]; } Y;
            ...     typedef Y YY[];
            ... ''')
            >>> declaration = mini.parse_declaration(mini.parse(
            ...     # make sure t.xx is initialized as an array
            ...     'T t = {0};'))
            >>> test(declaration, 0)
            === t:
              0x0: Struct:
              0x1:   'x': Struct:
              0x2:   'xx': Pointer (offset=0) into memory:
              0x3:     0: Struct:
            >>> declaration = mini.parse_declaration(mini.parse('''
            ...     // array of array of Y
            ...     YY yy[] = {{{
            ...         {1, {2, 3}}, // .t
            ...         {{4, {5, 6}}, {7, {8, 9}}} // .tt
            ...     }}};
            ... '''))
            >>> test(declaration, 0)
            === yy:
              0x0: Pointer (offset=0) into memory:
              0x1:   0: Pointer (offset=0) into memory:
              0x2:     0: Struct:
              0x3:       't': Struct:
              0x4:         'x': 1
              0x5:         'xx': Pointer (offset=0) into memory:
              0x6:           As a C string: b'\x02\x03'
              0x7:           0: 2
              0x8:           1: 3
              0x9:       'tt': Pointer (offset=0) into memory:
              0xa:         0: Struct:
              0xb:           'x': 4
              0xc:           'xx': Pointer (offset=0) into memory:
              0xd:             As a C string: b'\x05\x06'
              0xe:             0: 5
              0xf:             1: 6
             0x10:         1: Struct:
             0x11:           'x': 7
             0x12:           'xx': Pointer (offset=0) into memory:
             0x13:             As a C string: b'\x08\t'
             0x14:             0: 8
             0x15:             1: 9

        """

        base_type, kinds = self.expand_type(declaration, declarator)
        base_type, base_type_arg = base_type

        def visit(initializer: Initializer, kind_i: int = 0) -> Value:
            kind = None if kind_i >= len(kinds) else kinds[kind_i]

            if not isinstance(initializer, list):
                if initializer == 0 and not isinstance(initializer, Struct):
                    # As a special case, initializing stuff to 0 always
                    # produces an "uninitialized" value, e.g. a magic
                    # Struct... this is to support the `= {0}` idiom,
                    # which e.g. for a struct, should *not* necessarily
                    # assign the number 0 to its first field!.. consider:
                    #
                    #   struct t { int x; };
                    #   struct { struct t child; } parent = {0};
                    #
                    # ...in this example, parent.child shouldn't be the
                    # number 0, rather it should be a struct t with its
                    # memory "zeroed out", which for us means it should
                    # be an initialized value, i.e. a fresh Struct.
                    return self._create_uninitialized_value(
                        initializer_token, declarator.name, kind)
                # Initializer is already a value, just use it as-is!
                # ...except, take a copy of it first, which also converts from
                # e.g. Python str to Pointer
                return copy_value(initializer, initializer=True)

            if kind is None:
                if base_type not in ('struct', 'union'):
                    raise ParseError(declaration.match.token,
                        f"Can't use initializer list with non-array/struct/union type {base_type, base_type_arg}. "
                        f"List was: {initializer!r}")
                structlike = self.parse_structlike(base_type_arg)
                structlike = self.complete_tagged(structlike)
                if base_type == 'union':
                    # Union initializer
                    # NOTE: unions can only be initialized to their first member
                    if len(initializer) != 1:
                        raise ParseError(initializer_token,
                            f"Expected 1 initializer element for union defined at {structlike.token.location()}, "
                            f"got: {initializer!r}")
                    field_name, (field_declaration, field_declarator) = next(
                        iter(structlike.fields.items()))
                    field_value = self.convert_initializer(
                        field_declaration,
                        field_declarator,
                        initializer[0],
                        initializer_token,
                    )
                    return Struct({field_name: field_value})
                else:
                    # Struct initializer
                    if len(initializer) < len(structlike.fields):
                        # Pad the initializer out with zeros if need be.
                        # This ensures that all fields are initialized with
                        # the proper "kind" -- in particular, array fields
                        # should be initialized to Pointer, not Struct
                        initializer += [0] * (len(structlike.fields) - len(initializer))
                    field_values = {
                        field_name: self.convert_initializer(
                            field_declaration,
                            field_declarator,
                            child_initializer,
                            initializer_token,
                        )
                        for child_initializer, (field_name,
                            (field_declaration, field_declarator))
                        in zip(initializer, structlike.fields.items())}
                    return Struct(field_values)
            elif kind == 'array':
                # Array initializer
                # Convert initializer list into an array value, i.e. a pointer
                # to an initialized block of memory
                mem = MemoryBlock()
                mem.update(enumerate(visit(child_initializer, kind_i + 1)
                    for child_initializer in initializer))
                return Pointer(mem)
            else:
                # E.g. if kind in ('pointer', 'func')
                raise ParseError(declaration.match.token,
                    f"Can't use initializer list with {kind}. List was: {initializer!r}")

        return visit(initializer)

    def on_unary_expression(self, match: ParseMatch) -> Value:
        op = match.children[0].token.value
        if op == '&':
            return self.get_reference(match.children[1])
        value = self.on(match.children[1])
        if op == '+':
            return +value
        elif op == '-':
            return -value
        elif op == '~':
            return ~value
        elif op == '!':
            return not value_as_bool(value)
        elif op == '*':
            return self.dereference(value)
        else:
            # Should never happen!
            raise ParseError(match.token, f"Dunno prefix operator: {op!r}")

    def on_reference__unary_expression(self, match: ParseMatch) -> Pointer:
        op = match.children[0].token.value
        if op == '*':
            with self.use_handler_prefix(None):
                return self.on(match.children[1])
        else:
            raise ParseError(match.token, f"Can't produce an lvalue: {op!r}")

    def _postfix_operator(self, value: Value, match: ParseMatch) -> Value:
        assert match.rule_name == 'postfix_operator'
        if match.pattern_name == 'index':
            value = value_as_pointer(value)
            index = value_as_int(self.on(match.children[0]))
            return value[index]
        elif match.pattern_name == 'call':
            if isinstance(value, Function):
                param_values = [copy_value(self.on(child))
                    for child in match.children]
            else:
                # Don't use copy_value if we're not calling C code!..
                # This lets us do things like `d->get("x")` in C where d is
                # a Python dict, and we want the Python string "x" to be
                # passed along as-is, not converted to a Pointer.
                param_values = [self.on(child)
                    for child in match.children]
            value = self.dereference(value) # handle function pointers
            return value(*param_values)
        elif match.pattern_name in ('dot', 'arrow'):
            attr = match.children[0].token.value
            if match.pattern_name == 'arrow':
                value = self.dereference(value)
            if isinstance(value, Struct):
                return value[attr]
            else:
                return getattr(value, attr)
        else:
            # Should never happen!
            raise ParseError(match.token, f"Dunno postfix operator: {match.prettystring()}")

    def on_inc__postfix_increment_expression(self, match: ParseMatch) -> Value:
        ptr = self.get_reference(match.children[0])
        value = ptr.contents
        ptr.contents += 1
        return value # the un-incremented value

    def on_dec__postfix_increment_expression(self, match: ParseMatch) -> Value:
        ptr = self.get_reference(match.children[0])
        value = ptr.contents
        ptr.contents -= 1
        return value # the un-decremented value

    def _postfix_reference_operator(self, value: Value, match: ParseMatch) -> Pointer:
        assert match.rule_name == 'postfix_operator'
        assert self.handler_prefix is None # we are *NOT* in 'reference' prefixed mode
        if match.pattern_name == 'index':
            # e.g. &(x[3]), i.e. &(*(x + 3)), i.e. x + 3
            value = value_as_pointer(value)
            index = value_as_int(self.on(match.children[0]))
            return value + index
        elif match.pattern_name in ('dot', 'arrow'):
            attr = match.children[0].token.value
            if match.pattern_name == 'arrow':
                # e.g. &(x->y), i.e. &((*x).y))
                value = self.dereference(value)
            if not isinstance(value, Struct):
                field_msg = ('->' if match.pattern_name == 'arrow' else '.') + attr
                raise ParseError(match.token,
                    f"Can only get address-of-field ({field_msg}) from Struct, "
                    f"not from {type(value)}")
            return value.get_or_create_field(attr)
        else:
            raise ParseError(match.token,
                f"Can't produce an lvalue: {match.prettystring()}")

    def on_postfix_expression(self, match: ParseMatch) -> Value:
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            value = self._postfix_operator(value, child)
        return value

    def on_reference__postfix_expression(self, match: ParseMatch) -> Pointer:
        # When trying to get a reference from a series of postfix operations,
        # e.g. x.y->z[3], it's only the last operation, i.e. `[3]` in this
        # example, which needs to produce a reference.
        # The rest are producing rvalues as usual.
        # So, we deactivate the 'reference' handler prefix for the remainder
        # of this function, so we can calculate lvalues normally:
        with self.use_handler_prefix(None):
            # Find the rvalue from which to extract a reference...
            value = self.on(match.children[0])
            for child in match.children[1:-1]:
                value = self._postfix_operator(value, child)

            # ...and extract a reference from it!
            return self._postfix_reference_operator(value, match.children[-1])

    def call_func(self, func: Function, *param_values) -> Value:
        with self.new_scope() as scope:
            n_missing_params = len(func.params) - len(param_values)
            if n_missing_params:
                # Missing parameters default to magic Struct objects, for
                # maximum permissiveness
                original_param_values = param_values
                param_values = list(original_param_values) + [
                    Struct() for name in func.params[-n_missing_params:]]
            elif len(param_values) > len(func.params):
                self.warn(f"Calling {func} with {len(param_values)} parameters, extras will be ignored")
            for param_name, param_value in zip(func.params, param_values):
                scope[param_name] = Pointer(param_value)

            statements = func.body
            while True:
                try:
                    for child in statements:
                        self.on(child)
                except Return as ret:
                    return ret.value
                except Goto as goto:
                    label_match = func.labels.get(goto.label_name)
                    if label_match is None:
                        labels_msg = (
                            "from top-level labels: " + ' '.join(func.labels)
                            if func.labels else
                            "function has no top-level labels")
                        raise ParseError(goto.match.token,
                            f"Top-level label {goto.label_name!r} not found in func: "
                            f"{func} ({labels_msg})")
                    label_index = func.body.index(label_match)
                    # Go around the loop again, starting from the labeled
                    # child of the function body...
                    # NOTE: we don't support "deep" gotos at the moment, only
                    # gotos whose labels live at the top level of the function
                    # body.
                    statements = func.body[label_index:]
                except ControlFlow as ex:
                    raise ParseError(ex.match.token,
                        "Uncaught control flow: {ex.__class__.__name__}")
                else:
                    break

    def on_literal__primary_expression(self, match: ParseMatch) -> Value:
        token = match.token
        if token.toktype == 'NUMBER':
            return token.parse_number()
        elif token.toktype == 'STRING':
            return token.parse_string()
        elif token.toktype == 'CHAR':
            return value_as_char(token.parse_char())
        else:
            # This should never happen
            raise ParseError(token, f"Dunno literal: {match.prettystring()}")

    def _eval_children(self, match: ParseMatch) -> Value:
        value = None
        for child in match.children:
            value = self.on(child)
        return value

    on_translation_unit = _eval_children
    on_expression = _eval_children
    on_expression_statement = _eval_children
    on_trailing__repl_expression = _eval_children

    def on_block__compound_statement(self, match: ParseMatch) -> Value:
        value = None
        with self.new_scope() as scope:
            for child in match.children:
                value = self.on(child)
        return value

    def on_label__labeled_statement(self, match: ParseMatch) -> Value:
        return self.on(match.children[1])

    def on_return__jump_statement(self, match: ParseMatch) -> Value:
        if match.children:
            value = self.on(match.children[0])
        else:
            value = None
        raise Return(match, value)

    def on_ident__primary_expression(self, match: ParseMatch) -> Value:
        return self.get_var(match.token.value)

    def on_reference__ident__primary_expression(self, match: ParseMatch) -> Pointer:
        return self.get_var_ref(match.token.value)

    def on_goto__jump_statement(self, match: ParseMatch):
        raise Goto(match, label_name=match.children[0].token.value)

    def on_continue__jump_statement(self, match: ParseMatch):
        raise Continue(match)

    def on_break__jump_statement(self, match: ParseMatch):
        raise Break(match)

    def on_inc__unary_expression(self, match: ParseMatch) -> Value:
        ptr = self.get_reference(match.children[0])
        value = ptr.contents + 1
        ptr.contents = value
        return value

    def on_dec__unary_expression(self, match: ParseMatch) -> Value:
        ptr = self.get_reference(match.children[0])
        value = ptr.contents - 1
        ptr.contents = value
        return value

    def on_conditional_expression(self, match: ParseMatch) -> Value:
        cond = value_as_bool(self.on(match.children[0]))
        if cond:
            return self.on(match.children[1])
        else:
            return self.on(match.children[2])

    def on_reference__conditional_expression(self, match: ParseMatch) -> Pointer:
        with self.use_handler_prefix(None):
            cond = value_as_bool(self.on(match.children[0]))
        if cond:
            return self.on(match.children[1])
        else:
            return self.on(match.children[2])

    def _on_binary_expression(self, match: ParseMatch) -> Value:
        children = iter(match.children)
        value = self.on(next(children))
        for child in children:
            if match.rule_name in BINARY_EXPRESSION_OPS:
                op = BINARY_EXPRESSION_OPS[match.rule_name]
            else:
                op = child.token.value
                child = next(children)
            if op in ('&&', '||'):
                # Short-circuiting logic!.. only evalute the argument if
                # we need to, see below...
                pass
            else:
                arg = self.on(child)
            if op == '+':
                value += arg
            elif op == '-':
                value -= arg
            elif op == '*':
                value *= arg
            elif op == '/':
                if isinstance(value, int) and isinstance(arg, int):
                    value //= arg
                else:
                    value /= arg
            elif op == '%':
                value %= arg
            elif op == '<<':
                value <<= arg
            elif op == '>>':
                value >>= arg
            elif op == '<':
                value, arg = coerce_pointers_for_comparison(value, arg)
                value = value < arg
            elif op == '>':
                value, arg = coerce_pointers_for_comparison(value, arg)
                value = value > arg
            elif op == '<=':
                value, arg = coerce_pointers_for_comparison(value, arg)
                value = value <= arg
            elif op == '>=':
                value, arg = coerce_pointers_for_comparison(value, arg)
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
                # Short-circuiting logic: self.on(child) is only evaluated
                # if needed
                return value_as_bool(value) and value_as_bool(self.on(child))
            elif op == '||':
                # Short-circuiting logic: self.on(child) is only evaluated
                # if needed
                return value_as_bool(value) or value_as_bool(self.on(child))
            else:
                # We should never get here...
                raise ParseError(match.token, f"Dunno binary op {op!r}")
        return value

    on_additive_expression = _on_binary_expression
    on_multiplicative_expression = _on_binary_expression
    on_shift_expression = _on_binary_expression
    on_relational_expression = _on_binary_expression
    on_equality_expression = _on_binary_expression
    on_and_expression = _on_binary_expression
    on_exclusive_or_expression = _on_binary_expression
    on_inclusive_or_expression = _on_binary_expression
    on_logical_and_expression = _on_binary_expression
    on_logical_or_expression = _on_binary_expression

    def on_sizeof_expr__unary_expression(self, match: ParseMatch) -> Value:
        # Currently, sizeof always returns 1, which allows us to freely
        # grow our objects (see the Struct class) without messing up the
        # pointer math?..
        # It's weird, and it'll have very strange results for code which
        # assumes (correctly, according to the standard) that e.g. int is
        # always greater than one byte...
        # It might be better if we decided to have sizeof always return 4,
        # so we could at least handle C libraries which know about 32-bit
        # math.
        # But then we run into the question of whether to support 64-bit
        # "long long" values, and then pretty soon we probably just need
        # a more complicated system than what we have at the moment!..
        return 1

    on_sizeof_type__unary_expression = on_sizeof_expr__unary_expression

    def on_assign__assignment_expression(self, match: ParseMatch) -> Value:
        lhs = self.get_reference(match.children[0])
        op = match.children[1].token.value
        rhs = self.on(match.children[2])
        if op == '=':
            value = copy_value(rhs)
        elif op == '*=':
            value = lhs.contents * rhs
        elif op == '/=':
            value = lhs.contents / rhs
        elif op == '%=':
            value = lhs.contents % rhs
        elif op == '+=':
            value = lhs.contents + rhs
        elif op == '-=':
            value = lhs.contents - rhs
        elif op == '<<=':
            value = lhs.contents << rhs
        elif op == '>>=':
            value = lhs.contents >> rhs
        elif op == '&=':
            value = lhs.contents & rhs
        elif op == '^=':
            value = lhs.contents ^ rhs
        elif op == '|=':
            value = lhs.contents | rhs
        else:
            # Should never happen...
            raise ParseError(match.token, f"Dunno binary op {op!r}")
        lhs.contents = value
        return value

    def on_if__selection_statement(self, match: ParseMatch):
        with self.new_scope() as scope:
            cond_value = self.on(match.children[0])
            if value_as_bool(cond_value):
                self.on(match.children[1])
            elif len(match.children) >= 3:
                else_branch = match.children[2]
                assert else_branch.rule_name == 'else_statement'
                self.on(else_branch.children[0])

    def on_switch__selection_statement(self, match: ParseMatch):
        with self.new_scope() as scope:
            value_match = match.children[0]
            body = match.children[1:]

            # Collect the switch cases and default
            case_matches = []
            default_match = None
            for child in body:
                if child.pattern_name == 'case':
                    case_matches.append(child)
                elif child.pattern_name == 'default':
                    if default_match is not None:
                        raise ParseError(child.token, "Multiple defaults for a single switch!")
                    default_match = child

            value = self.on(value_match)

            # Find a case_match, which is either one of the case_matches, or the
            # default_match, or None
            for case_match in case_matches:
                case_value = self.on(case_match.children[0])
                if case_value == value:
                    break
            else:
                case_match = default_match

            if case_match is None:
                # We didn't match any of the cases, and we don't have a default
                return

            # Now evaluate all statements in the switch body from case_match
            # onwards:
            case_index = body.index(case_match)
            try:
                for child in body[case_index:]:
                    if child.pattern_name in ('case', 'default'):
                        self.on(child.children[-1])
                    else:
                        self.on(child)
            except Break:
                pass

    def on_while__iteration_statement(self, match: ParseMatch):
        with self.new_scope() as scope:
            cond_match, body_match = match.children
            while True:
                cond_value = self.on(cond_match)
                if not value_as_bool(cond_value):
                    break
                try:
                    self.on(body_match)
                except Continue:
                    pass
                except Break:
                    break

    def on_do__iteration_statement(self, match: ParseMatch):
        with self.new_scope() as scope:
            body_match, cond_match = match.children
            while True:
                try:
                    self.on(body_match)
                except Continue:
                    pass
                except Break:
                    break
                cond_value = self.on(cond_match)
                if not value_as_bool(cond_value):
                    break

    def on_empty_expression_statement(self, match: ParseMatch):
        return None

    def on_for__iteration_statement(self, match: ParseMatch):
        with self.new_scope() as scope:
            if len(match.children) == 4:
                init_match, cond_match, extra_match, body_match = match.children
            elif len(match.children) == 3:
                init_match, cond_match, body_match = match.children
                extra_match = None
            else:
                # Should never happen
                raise ParseError(match.token,
                    f"For-loop with unexpected number of children: {match}")

            if cond_match.rule_name == 'empty_expression_statement':
                cond_match = None

            self.on(init_match)
            while True:
                if cond_match is not None:
                    cond_value = self.on(cond_match)
                    if not value_as_bool(cond_value):
                        break
                try:
                    self.on(body_match)
                except Continue:
                    pass
                except Break:
                    break
                if extra_match is not None:
                    self.on(extra_match)

    def on_repl_commands(self, match: ParseMatch) -> Value:
        last_child = match.children[-1]
        value = None
        for child in match.children:
            value = self.on(child)
        if last_child.rule_name in ('function_definition', 'repl_expression'):
            return value
        else:
            return None


def main():
    parser = ArgumentParser()
    parser.add_argument('-f', '--filename', default='-')
    parser.add_argument('--progname')
    parser.add_argument('--local-dir', help="Directory used for #include \"...\"")
    parser.add_argument('-I', '--include-sys', default=[], action='append')
    parser.add_argument('-v', '--verbose', default=False, action='store_true')
    parser.add_argument('-p', '--parse-only', default=False, action='store_true')
    parser.add_argument('-s', '--parse-silent', default=False, action='store_true')
    parser.add_argument('--partial', default=False, action='store_true')
    parser.add_argument('main_args', nargs='*') # NOTE: takes everything after '--'
    args = parser.parse_args()

    if args.main_args and '--' not in sys.argv:
        print(f"ERROR: got extra arguments: {args.main_args}")
        print("If this was intentional, put an explicit '--' before them.")
        print("Or if they were a filename, put a '-f' in front of them.")
        sys.exit(1)

    pp_kwargs = dict(
        local_dir=get_local_dir_from_args(args),
        sys_dirs=args.include_sys,
    )

    mini = MiniC(pp_kwargs=pp_kwargs)
    if args.parse_only or args.parse_silent:
        match = mini.parse_file(
            args.filename,
            verbose=args.verbose,
            partial=args.partial,
        )
        if not args.parse_silent:
            # Handy if you want to see the parser's verbose output, but not
            # the pprint of a successful match
            match.pprint()
    else:
        mini.eval_file(args.filename)
        main_func = mini.globals().get('main')
        if main_func is None:
            raise Exception("No main() function found!")
        progname = args.progname or (args.filename if args.filename != '-' else 'main')
        argv = [progname] + args.main_args
        retcode = main_func(len(argv), argv)
        if retcode is None:
            retcode = 0
        elif not isinstance(retcode, int):
            raise Exception(f"Got non-integer exit code from main(): {retcode!r}")
        sys.exit(retcode)


if __name__ == '__main__':
    main()
