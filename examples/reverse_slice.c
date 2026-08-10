/* This file contains a single C function, extracted from CPython's
Objects/listobject.c.
I've then added the minimal amount of #includes, #defines, and typedefs
to allow the function to be correctly parsed and called, and added a
regular Python doctest to the function's existing comment.
- BAG, 2026
*/
#include <stdio.h>

typedef int PyObject;

#define assert(COND) if (!(COND)) { \
    printf("Failed assertion: %s\n", #COND); \
    exit(1); \
}


/* Reverse a slice of a list in place, from lo up to (exclusive) hi.

    >>> from loosey.mini import MiniC, Exit
    >>> mini = MiniC()
    >>> mini.eval_file('examples/reverse_slice.c')
    reverse_slice(lo, hi)

    >>> try: mini.eval('reverse_slice(NULL, NULL)')
    ... except Exit as ex: ex
    Failed assertion: lo && hi
    Exit(1)

    >>> mini.eval("""
    ...     PyObject *objs[] = {1, 20, 30, 40, 5};
    ...     reverse_slice(&objs[1], &objs[4]);
    ...     print(objs.as_list());
    ... """)
    [1, 40, 30, 20, 5]

*/
static void
reverse_slice(PyObject **lo, PyObject **hi)
{
    assert(lo && hi);

    --hi;
    while (lo < hi) {
        PyObject *t = *lo;
        *lo = *hi;
        *hi = t;
        ++lo;
        --hi;
    }
}
