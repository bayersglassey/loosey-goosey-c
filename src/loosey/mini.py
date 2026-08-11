import sys
import inspect
from typing import Optional
from contextlib import contextmanager
from argparse import ArgumentParser

from loosey import get_data_filepath
from loosey.grammar import ParseMatch
from loosey.pplex import Token, ParseError
from loosey.pp import (
    GrammarEvaluatorWithPreprocessor,
    get_local_dir_from_args,
)
from loosey.stdlib import CStdlib
from loosey.runtime import (
    Value,
    Declaration,
    Declarator,
    InitDeclarator,
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
    value_as_bool,
    copy_value,
    coerce_pointers_for_comparison,
)


NO_DEFAULT = object()

GRAMMAR_FILENAME = get_data_filepath('ansi-c-grammar.txt')


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

        Parsing of typedefs is handled correctly!
        See: https://en.wikipedia.org/wiki/Lexer_hack
        In the examples below, when Integer is not a typedef, `Integer *x`
        is interpreted as a multiplication; when it's a typedef, `Integer *x`
        is interpreted as a variable declaration:
        >>> f = mini.eval('void f() { Integer *x; }')
        >>> for child in f.body.children: child.pprint()
        multiplicative_expression
          ident: Integer
          *
          ident: x
        >>> f = mini.eval('void f() { typedef int Integer; Integer *x; }')
        >>> for child in f.body.children: child.pprint()
        declaration_list
          decl: declaration
            declspec: declaration_specifiers
              typedef
              int
            decl: init_declarator
              decl: declarator
                declare: Integer
          decl: declaration
            declspec: declaration_specifiers
              Integer
            decl: init_declarator
              decl: declarator
                pointer: *
                declare: x

        Similarly, if we evaluate a typedef, it exists in our globals, and
        is taken into account when parsing:
        >>> mini.parse('T *x;').pprint()
        multiplicative_expression
          ident: T
          *
          ident: x
        >>> mini.eval('typedef struct t T;')
        {'T': TypeDef('T')}
        >>> mini.parse('T *x;').pprint()
        decl: declaration
          declspec: declaration_specifiers
            T
          decl: init_declarator
            decl: declarator
              pointer: *
              declare: x

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
        Pointer(Struct(x=3, y=4))

    """

    grammar_filename = GRAMMAR_FILENAME
    main_rule_name = 'repl_commands'
    squash_children = True
    pass_through_exceptions = (
        Return,
        Continue,
        Break,
        Goto,
        Exit,
    )
    handler_prefixes = ('reference',)

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

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
        self.typedef_blocks: list[set[str]] = []
        self.pattern_callbacks = {
            ('compound_statement', 'block'):
                (self.enter_typedef_block, self.exit_typedef_block),
            ('declaration', 'decl'):
                (None, self.exit_declaration),
        }
        for rule_name, pattern_name in self.pattern_callbacks:
            if rule_name not in self.grammar_rules:
                raise Exception(f"Unknown rule name: {rule_name}")
        self.toktype_predicates = {
            'TYPE_NAME': self.is_type_name_token,
        }

        self.parsed_declarators: dict[str, Declarator] = {}
        self.parsed_declarations: dict[str, Declaration] = {}

    def parse(self, *args, **kwargs):
        block = set()
        self.typedef_blocks.append(block)
        try:
            return super().parse(*args, **kwargs)
        finally:
            assert self.typedef_blocks.pop() is block

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

    def no_match(self, tokens: list[Token], rule_name: str) -> Optional[ParseMatch]:
        if not tokens:
            # If we got no tokens from parsing, that might mean e.g. that
            # user hit Enter at the REPL without typing anything, or that
            # they entered some valid C preprocessor stuff which didn't
            # generate any tokens, like a #define.
            # That's all good!
            return None
        return super().no_match(tokens, rule_name)

    def enter_typedef_block(self, token: Token):
        self.typedef_blocks.append(set())

    def exit_typedef_block(self, token: Token, match: Optional[ParseMatch]):
        self.typedef_blocks.pop()

    def exit_declaration(self, token: Token, match: Optional[ParseMatch]):
        if match is None:
            return
        if not self.typedef_blocks:
            return
        declaration = self.parse_declaration(match)
        if not declaration.is_typedef:
            return
        typedef_block = self.typedef_blocks[-1]
        for init_declarator in declaration.init_declarators:
            typedef_block.add(init_declarator.name)

    def is_type_name_token(self, token: Token) -> bool:
        if token.toktype != 'IDENTIFIER':
            return False
        name = token.value
        if self.typedef_blocks and any(
            name in block for block in reversed(self.typedef_blocks)
        ):
            return True
        elif isinstance(self.get_var(name, None), TypeDef):
            return True
        else:
            return False

    @contextmanager
    def new_scope(self) -> dict[str, Pointer]:
        scope = {}
        self.scopes.append(scope)
        try:
            yield scope
        finally:
            assert self.scopes.pop() is scope

    def have_var(self, name: str) -> bool:
        for scope in reversed(self.scopes):
            if name in scope:
                return True
        return False

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

    def get_var_ref(self, name: str) -> Pointer:
        """Get a reference to the indicated variable"""
        for scope in reversed(self.scopes):
            if name in scope:
                return scope[name]
        raise self.var_lookup_error(name)

    def var_lookup_error(self, name: str) -> Exception:
        names_msg = ' '.join(f"{{{' '.join(scope)}}}" for scope in self.scopes)
        raise Exception(f"Object not found: {name!r} (names currently in scope: {names_msg})")

    def set_var(self, name: str, value: Value):
        scope = self.scopes[-1]
        if name in scope:
            scope[name].contents = value
        else:
            scope[name] = Pointer(value)

    def parse_declarator(self, match: ParseMatch) -> Declarator:
        key = match.unique_id
        declarator = self.parsed_declarators.get(key)
        if declarator is None:
            declarator = self._parse_declarator(match)
            self.parsed_declarators[key] = declarator
        return declarator

    def _parse_declarator(self, match: ParseMatch) -> Declarator:
        """

            >>> mini = MiniC()

            >>> def test(text):
            ...     match = mini.parse(text, 'declarator')
            ...     decl = mini.parse_declarator(match)
            ...     return decl.name, decl.kind

            >>> test('x')
            ('x', None)

            >>> test('(x)')
            ('x', None)

            >>> test('*x')
            ('x', 'pointer')

            >>> test('*(x)')
            ('x', 'pointer')

            >>> test('(*x)')
            ('x', 'pointer')

            >>> test('x[]')
            ('x', 'array')

            >>> test('(x)[]')
            ('x', 'array')

            >>> test('(x[])')
            ('x', 'array')

            >>> test('x()')
            ('x', 'func')

            >>> test('(x)()')
            ('x', 'func')

            >>> test('(x())')
            ('x', 'func')

        The most obnoxious distinction in C's entire type system: function
        pointer vs function returning pointer:

            >>> test('(*x)()')
            ('x', 'pointer')

            >>> test('*x()')
            ('x', 'func')

            >>> test('*(x)()')
            ('x', 'func')

        Another tricky distinction: array of pointers vs pointer to array:

            >>> test('*x[]')
            ('x', 'array')

            >>> test('(*x)[]')
            ('x', 'pointer')

        """
        assert match.rule_name == 'declarator'

        # Find the stuff within the innermost set of parentheses...
        # 1. `*(*(**x[3])[])()` -> `**x[3]`
        # 2. `*(*(x)[])()` -> `*(x)[]`
        #    ...note how we don't count the parentheses around `(x)`, since
        #    they don't affect the type of x!.. e.g. `*((x))` is a pointer.
        child = innermost_match = match
        while True:
            if len(child.children) > 1:
                innermost_match = child
            next_child = child.find('declarator')
            if next_child is None:
                name = child.find('declare:.').token.value
                break
            child = next_child

        suffix = innermost_match.find('declarator_suffix')
        if suffix:
            if suffix.pattern_name == 'array':
                kind = 'array'
            elif suffix.pattern_name == 'params':
                kind = 'func'
            else:
                # Should never happen
                raise ParseError(match.token, f"Unknown suffix: {suffix}")
        elif innermost_match.find('pointer'):
            kind = 'pointer'
        else:
            kind = None

        return Declarator(
            match=match,
            name=name,
            kind=kind,
        )

    def parse_declaration(self, match: ParseMatch) -> Declaration:
        key = match.unique_id
        declaration = self.parsed_declarations.get(key)
        if declaration is None:
            declaration = self._parse_declaration(match)
            self.parsed_declarations[key] = declaration
        return declaration

    def _parse_declaration(self, match: ParseMatch) -> Declaration:
        assert match.rule_name == 'declaration'

        # The declaration specifiers, e.g. 'int'
        declspec = match.children[0]

        # Looking for specifiers like 'typedef', 'extern', 'const', etc
        specifiers: set[str] = {child.token.value
            for child in
                declspec.findall('storage_class_specifier')
                + declspec.findall('type_qualifier')}

        # Init declarators, e.g. `x`, `*x[3]`, `x = 2`, etc
        init_declarators: list[InitDeclarator] = []
        for child in match.children[1:]:
            assert child.rule_name == 'init_declarator'
            declarator = self.parse_declarator(child.children[0])
            initializer = child.children[1] if len(child.children) > 1 else None
            init_declarators.append(InitDeclarator(declarator, initializer))

        return Declaration(
            match=match,
            declspec=declspec,
            specifiers=specifiers,
            init_declarators=init_declarators,
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

    def on_function_definition(self, match: ParseMatch) -> Value:
        declarator = self.parse_declarator(match.find('declarator'))
        if declarator.kind != 'func':
            raise ParseError(match.token, "Trying to define a function using non-function variable")
        name = declarator.name
        params_match = declarator.match.find('params:.')
        params = [child.token.value for child in
            # NOTE: might be a parameter_type_list, i.e. (int x, int y), or
            # might be a list of param_identifier, i.e. just (x, y)
            params_match.findall('.* declare:.', sorted=True)]
        body = match.find('block:compound_statement')
        variadic = declarator.match.children[1].find('.* ellipsis') is not None
        function = Function(
            name=name,
            params=params,
            variadic=variadic,
            body=body,
            call=self.call_func,
        )
        self.set_var(name, function)
        return function

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

    def on_declaration_list(self, match: ParseMatch) -> dict[str, Value]:
        intialized_values = {}
        for child in match.children:
            intialized_values.update(self.on(child))
        return intialized_values

    def on_decl__declaration(self, match: ParseMatch) -> dict[str, Value]:
        intialized_values = {}

        declaration = self.parse_declaration(match)
        if declaration.is_typedef:
            # Handle typedefs
            for init_declarator in declaration.init_declarators:
                name = init_declarator.name
                value = TypeDef(
                    name=name,
                    declaration=declaration,
                    init_declarator=init_declarator,
                )
                self.set_var(name, value)
                intialized_values[name] = value
        else:
            # Handle variable initializations
            for init_declarator in declaration.init_declarators:
                name = init_declarator.name
                kind = init_declarator.kind
                initializer = init_declarator.initializer
                if initializer is not None:
                    if initializer.spec == 'initializer_list:initializer' and kind != 'array':
                        # TODO: implement struct initialization lists...
                        # HACK: for now, we just make sure `= {0}` works
                        value = self._create_uninitialized_value(
                            name, init_declarator.declarator)
                    else:
                        value = copy_value(self.on(initializer))
                    self.set_var(name, value)
                else:
                    scope = self.scopes[-1]
                    if name in scope:
                        # This variable is already initialized!.. so don't
                        # overwrite with a fresh Struct.
                        # In particular, we don't want to have function
                        # prototypes overwrite the actual functions!..
                        value = scope[name]
                    else:
                        # Uninitialized variables are assigned a reasonable
                        # default value
                        value = self._create_uninitialized_value(
                            name, init_declarator.declarator)
                        self.set_var(name, value)
                intialized_values[name] = value

        return intialized_values

    def _create_uninitialized_value(self, name: str, declarator: Declarator) -> Value:
        kind = declarator.kind
        if kind == 'array':
            # Array variables are initialized to pointers
            # backed by an auto-growing memory block
            return Pointer(MemoryBlock())
        elif kind == 'func':
            # Functions are initialized to a function which
            # tells you that it's uninitialized
            def func(*args):
                raise Exception(
                    f"Function {name!r} "
                    f"declared at {declarator.match.token.location()} "
                    "was never defined!")
            return PythonFunction(func, name)
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

    def on_initializer_list__initializer(self, match: ParseMatch) -> Value:
        values = []
        for child in match.children:
            values.append(self.on(child))
        mem = MemoryBlock()
        for i, value in enumerate(values):
            mem[i] = value
        return Pointer(mem)

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
            index = self.on(match.children[0])
            return value[index]
        elif match.pattern_name == 'call':
            param_values = [copy_value(self.on(child))
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
            index = self.on(match.children[0])
            return value + index
        elif match.pattern_name in ('dot', 'arrow'):
            attr = match.children[0].token.value
            if match.pattern_name == 'arrow':
                # e.g. &(x->y), i.e. &((*x).y))
                value = self.dereference(value)
            if not isinstance(value, Struct):
                field_msg = ('->' if match.pattern_name == 'arrow' else '.') + attr
                raise Exception(f"Can only get address-of-field ({field_msg}) from Struct, not from {type(value)}")
            return value.get_or_create_field(attr)
        else:
            raise ParseError(match.token, f"Can't produce an lvalue: {match.prettystring()}")

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

            body = func.body.children
            while True:
                try:
                    for child in body:
                        self.on(child)
                except Return as ret:
                    return copy_value(ret.value)
                except Goto as goto:
                    label_match = func.labels.get(goto.label_name)
                    if label_match is None:
                        labels_msg = "from top-level labels: " + ' '.join(func.labels) if func.labels else "function has no top-level labels"
                        raise Exception(f"Top-level label {goto.label_name!r} not found in func: {func} ({labels_msg})")
                    label_index = func.label_statements.index(label_match)
                    # Go around the loop again, starting from the labeled
                    # child of the function body...
                    # NOTE: we don't support "deep" gotos at the moment, only
                    # gotos whose labels live at the top level of the function
                    # body.
                    body = func.label_statements[label_index:]
                except ControlFlow as ex:
                    raise ParseError(ex.match.token, "Uncaught control flow: {ex.__class__.__name__}")
                else:
                    break

    def on_literal__primary_expression(self, match: ParseMatch) -> Value:
        token = match.token
        if token.toktype == 'NUMBER':
            return token.parse_number()
        elif token.toktype == 'STRING':
            return token.parse_string()
        elif token.toktype == 'CHAR':
            return ord(token.parse_char())
        else:
            # This should never happen
            raise ParseError(token, f"Dunno literal: {match.prettystring()}")

    def _eval_children(self, match: ParseMatch):
        value = None
        for child in match.children:
            value = self.on(child)
        return value

    on_block__compound_statement = _eval_children
    on_statement_list = _eval_children
    on_translation_unit = _eval_children
    on_expression = _eval_children
    on_expression_statement = _eval_children
    on_trailing__repl_expression = _eval_children

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
        cond_value = self.on(match.children[0])
        if value_as_bool(cond_value):
            self.on(match.children[1])
        elif len(match.children) >= 3:
            else_branch = match.children[2]
            assert else_branch.rule_name == 'else_statement'
            self.on(else_branch.children[0])

    def on_switch__selection_statement(self, match: ParseMatch):
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
        if len(match.children) == 4:
            init_match, cond_match, extra_match, body_match = match.children
        elif len(match.children) == 3:
            init_match, cond_match, body_match = match.children
            extra_match = None
        else:
            # Should never happen
            raise Exception(f"For-loop with unexpected number of children: {match}")

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
            raise_on_no_match=True,
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
