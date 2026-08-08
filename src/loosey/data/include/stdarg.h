#ifndef __LOOSEY_STDARG__
#define __LOOSEY_STDARG__

// NOTE: this file is heavily based on: https://en.cppreference.com/c/variadic/va_arg

typedef struct __loosey_va_list__ va_list;

// https://en.cppreference.com/c/variadic/va_arg
// "The va_arg macro expands to an expression of type T that corresponds
// to the next parameter from the va_list ap"
#define va_arg(ap, T) "I am a variable argument"

void va_copy(va_list dest, va_list src);
void va_end(va_list ap);
void va_start(va_list ap, ...);

#endif
