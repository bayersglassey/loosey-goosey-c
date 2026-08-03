#define YES

// Test #ifdef
#ifdef YES
    OK
#else
    BAD
#endif

// Test #ifndef
#ifndef NO
    OK
#else
    BAD
#endif

// Test #else
#ifdef NO
    BAD
#else
    OK
#endif

// Test #if
#if 1
    OK
#else
    BAD
#endif

// Test #elif
#if 0
    BAD
#elif 1
    OK
#else
    BAD
#endif

// Test nesting
#ifdef YES
    #ifdef YES
        OK
    #else
        BAD
    #endif
#else
    #ifdef YES
        BAD
    #else
        BAD
    #endif
#endif

// Test nesting
#ifdef NO
    #ifdef YES
        BAD
    #else
        BAD
    #endif
#else
    #ifdef YES
        OK
    #else
        BAD
    #endif
#endif


#########################
OK OK OK OK OK OK OK
