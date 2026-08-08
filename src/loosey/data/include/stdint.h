#ifndef __LOOSEY_STDINT__
#define __LOOSEY_STDINT__

// This file is heavily based on https://en.cppreference.com/c/header/stdint

typedef char int8_t;
typedef int int16_t;
typedef int int32_t;
typedef int int64_t;

typedef char int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
typedef int int_fast64_t;

typedef char int_least8_t;
typedef int int_least16_t;
typedef int int_least32_t;
typedef int int_least64_t;

typedef int intmax_t;
typedef int intptr_t;

typedef unsigned char uint8_t;
typedef unsigned uint16_t;
typedef unsigned uint32_t;
typedef unsigned uint64_t;

typedef unsigned char uint_fast8_t;
typedef unsigned uint_fast16_t;
typedef unsigned uint_fast32_t;
typedef unsigned uint_fast64_t;

typedef unsigned char uint_least8_t;
typedef unsigned uint_least16_t;
typedef unsigned uint_least32_t;
typedef unsigned uint_least64_t;

typedef unsigned uintmax_t;
typedef unsigned uintptr_t;


#define INT8_WIDTH 8
#define UINT8_WIDTH 8
#define INT8_MIN (-(2 << UINT8_WIDTH) / 2 + 1)
#define INT8_MAX ((2 << UINT8_WIDTH) / 2)
#define UINT8_MAX ((2 << UINT8_WIDTH) - 1)

#define INT_FAST8_WIDTH INT8_WIDTH
#define UINT_FAST8_WIDTH UINT8_WIDTH
#define INT_FAST8_MIN INT8_MIN
#define INT_FAST8_MAX INT8_MAX
#define UINT_FAST8_MAX UINT8_MAX

#define INT_LEAST8_WIDTH INT8_WIDTH
#define UINT_LEAST8_WIDTH UINT8_WIDTH
#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST8_MAX INT8_MAX
#define UINT_LEAST8_MAX UINT8_MAX


#define INT16_WIDTH 16
#define UINT16_WIDTH 16
#define INT16_MIN (-(2 << UINT16_WIDTH) / 2 + 1)
#define INT16_MAX ((2 << UINT16_WIDTH) / 2)
#define UINT16_MAX ((2 << UINT16_WIDTH) - 1)

#define INT_FAST16_WIDTH INT16_WIDTH
#define UINT_FAST16_WIDTH UINT16_WIDTH
#define INT_FAST16_MIN INT16_MIN
#define INT_FAST16_MAX INT16_MAX
#define UINT_FAST16_MAX UINT16_MAX

#define INT_LEAST16_WIDTH INT16_WIDTH
#define UINT_LEAST16_WIDTH UINT16_WIDTH
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST16_MAX INT16_MAX
#define UINT_LEAST16_MAX UINT16_MAX


#define INT32_WIDTH 32
#define UINT32_WIDTH 32
#define INT32_MIN (-(2 << UINT32_WIDTH) / 2 + 1)
#define INT32_MAX ((2 << UINT32_WIDTH) / 2)
#define UINT32_MAX ((2 << UINT32_WIDTH) - 1)

#define INT_FAST32_WIDTH INT32_WIDTH
#define UINT_FAST32_WIDTH UINT32_WIDTH
#define INT_FAST32_MIN INT32_MIN
#define INT_FAST32_MAX INT32_MAX
#define UINT_FAST32_MAX UINT32_MAX

#define INT_LEAST32_WIDTH INT32_WIDTH
#define UINT_LEAST32_WIDTH UINT32_WIDTH
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST32_MAX INT32_MAX
#define UINT_LEAST32_MAX UINT32_MAX


#define INT64_WIDTH 64
#define UINT64_WIDTH 64
#define INT64_MIN (-(2 << UINT64_WIDTH) / 2 + 1)
#define INT64_MAX ((2 << UINT64_WIDTH) / 2)
#define UINT64_MAX ((2 << UINT64_WIDTH) - 1)

#define INT_FAST64_WIDTH INT64_WIDTH
#define UINT_FAST64_WIDTH UINT64_WIDTH
#define INT_FAST64_MIN INT64_MIN
#define INT_FAST64_MAX INT64_MAX
#define UINT_FAST64_MAX UINT64_MAX

#define INT_LEAST64_WIDTH INT64_WIDTH
#define UINT_LEAST64_WIDTH UINT64_WIDTH
#define INT_LEAST64_MIN INT64_MIN
#define INT_LEAST64_MAX INT64_MAX
#define UINT_LEAST64_MAX UINT64_MAX


#define INTMAX_WIDTH INT64_WIDTH
#define UINTMAX_WIDTH UINT64_WIDTH
#define INTMAX_MIN INT64_MIN
#define INTMAX_MAX INT64_MAX
#define UINTMAX_MAX UINT64_MAX

#define INTPTR_WIDTH INT64_WIDTH
#define UINTPTR_WIDTH UINT64_WIDTH
#define INTPTR_MIN INT64_MIN
#define INTPTR_MAX INT64_MAX
#define UINTPTR_MAX UINT64_MAX

#define PTRDIFF_WIDTH INT64_WIDTH
#define PTRDIFF_MIN INT64_MIN
#define PTRDIFF_MAX INT64_MAX
#define SIZE_WIDTH UINT64_WIDTH
#define SIZE_MAX UINT64_MAX

#endif
