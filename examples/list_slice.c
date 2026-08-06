// From examples/listobject.pp.c

#define __extension__
#define __assert_fail(...)

typedef void
    PyListObject,
    PyTupleObject,
    Py_ssize_t,
    PyObject,
    size_t
;

static int
list_ass_slice(PyListObject *a, Py_ssize_t ilow, Py_ssize_t ihigh, PyObject *v)
{
    PyObject *recycle_on_stack[8];
    PyObject **recycle = recycle_on_stack;
    PyObject **item;
    PyObject **vitem = ((void *)0);
    PyObject *v_as_SF = ((void *)0);
    Py_ssize_t n;
    Py_ssize_t norig;
    Py_ssize_t d;
    Py_ssize_t k;
    size_t s;
    int result = -1;
    if (v == ((void *)0))
        n = 0;
    else {
        if (a == ((PyListObject *)v)) {
            v = list_slice(((PyListObject *)v), 0, Py_SIZE(((PyObject*)((((PyListObject *)v))))));
            if (v == ((void *)0))
                return result;
            result = list_ass_slice(a, ilow, ihigh, v);
            Py_DECREF(((PyObject*)((v))));
            return result;
        }
        v_as_SF = PySequence_Fast(v, "can only assign an iterable");
        if(v_as_SF == ((void *)0))
            goto Error;
        n = (PyType_HasFeature((Py_TYPE(((PyObject*)((v_as_SF))))), ((1UL << 25))) ? PyList_GET_SIZE(((PyObject*)((v_as_SF)))) : PyTuple_GET_SIZE(((PyObject*)((v_as_SF)))));
        vitem = (
            PyType_HasFeature(
                (
                    Py_TYPE(
                        (
                            (PyObject*)((v_as_SF))
                        )
                    )
                ),
                ((1UL << 25))
            ) ? ((PyListObject *)(v_as_SF))->ob_item
            : ((PyTupleObject *)(v_as_SF))->ob_item
        );
    }
    if (ilow < 0)
        ilow = 0;
    else if (ilow > Py_SIZE(((PyObject*)((a)))))
        ilow = Py_SIZE(((PyObject*)((a))));
    if (ihigh < ilow)
        ihigh = ilow;
    else if (ihigh > Py_SIZE(((PyObject*)((a)))))
        ihigh = Py_SIZE(((PyObject*)((a))));
    norig = ihigh - ilow;
    /* We don't support the ({...}) extension yet
    ((void) sizeof ((norig >= 0) ? 1 : 0), __extension__ ({
        if (norig >= 0) ; else __assert_fail ("norig >= 0", "/home/bag/repos/cpython/Objects/listobject.c", 672, __extension__ __PRETTY_FUNCTION__);
    }));
    */
    d = n - norig;
    if (Py_SIZE(((PyObject*)((a)))) + d == 0) {
        Py_XDECREF(((PyObject*)((v_as_SF))));
        return _list_clear(a);
    }
    item = a->ob_item;
    s = norig * sizeof(PyObject *);
    /*
    if (s) {
        if (s > sizeof(recycle_on_stack)) {
            recycle = (PyObject **)PyMem_Malloc(s);
            if (recycle == ((void *)0)) {
                PyErr_NoMemory();
                goto Error;
            }
        }
        memcpy(recycle, &item[ilow], s);
    }
    if (d < 0) {
        Py_ssize_t tail;
        tail = (Py_SIZE(((PyObject*)((a)))) - ihigh) * sizeof(PyObject *);
        memmove(&item[ihigh+d], &item[ihigh], tail);
        if (list_resize(a, Py_SIZE(((PyObject*)((a)))) + d) < 0) {
            memmove(&item[ihigh], &item[ihigh+d], tail);
            memcpy(&item[ilow], recycle, s);
            goto Error;
        }
        item = a->ob_item;
    }
    else if (d > 0) {
        k = Py_SIZE(((PyObject*)((a))));
        if (list_resize(a, k+d) < 0)
            goto Error;
        item = a->ob_item;
        memmove(&item[ihigh+d], &item[ihigh],
            (k - ihigh)*sizeof(PyObject *));
    }
    for (k = 0; k < n; k++, ilow++) {
        PyObject *w = vitem[k];
        item[ilow] = _Py_XNewRef(((PyObject*)((w))));
    }
    for (k = norig - 1; k >= 0; --k)
        Py_XDECREF(((PyObject*)((recycle[k]))));
    result = 0;
 Error:
    if (recycle != recycle_on_stack)
        PyMem_Free(recycle);
    Py_XDECREF(((PyObject*)((v_as_SF))));
    return result;
    */
}
