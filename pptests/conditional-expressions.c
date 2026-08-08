
#if 0
    BAD
#endif

#if 1
    OK
#endif

#if 1 - 1
    BAD
#endif

#if 0 + 1
    OK
#endif

#if 'a'
    OK
#endif

#if '\0'
    BAD
#endif

#if 'a' - 'a'
    BAD
#endif

#define YES 1
#if YES
    OK
#endif

#if NO
    BAD
#endif

#define ZERO 0
#if ZERO
    BAD
#endif

#if defined ZERO
    OK
#endif

#if defined(ZERO)
    OK
#endif

#define ADD(X, Y) X + Y
#if ADD(1, 1)
    OK
#endif

#if ADD(1, -1)
    BAD
#endif
