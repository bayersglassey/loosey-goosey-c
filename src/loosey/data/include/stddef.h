#ifndef __LOOSEY_STDDEF__
#define __LOOSEY_STDDEF__

// This file is heavily based on: https://en.cppreference.com/c/header/stddef

typedef long ptrdiff_t;
typedef unsigned long size_t;

#define NULL 0

// NOTE: our magic Struct class (in Python) automatically creates new
// fields as they are referred to, so offsetof doesn't make any sense
// for us at the moment.
// We could hardcode it to 0 or something, but for now we explicitly
// raise an error if we encounter offsetof at runtime...
#define offsetof(P, D) __loosey_error__("offsetof not supported")

#endif
