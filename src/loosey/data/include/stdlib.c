
// This file is #included by our stdlib.h.
// NOTE: some of the stdlib.h functions may be defined in Python, not here!
// See the CStdlib Python class

#include <ctype.h>

static long strtol(const char *restrict nptr, char **restrict endptr, int base) {
    const char *nptr_digits, *nptr0 = nptr;
    char c;
    int neg;
    long i = 0, digit;

    // Eat any initial whitespace
    while (isspace(c = *nptr)) nptr++;

    // Eat leading '-' or '+', if any
    if ((neg = (c == '-')) || (c == '+')) nptr++;

    // Handle "base prefixes", like "0" for octal or "0x" for hex
    if (base == 0) {
        if (nptr[0] == '0') {
            if (nptr[1] == 'x' || nptr[1] == 'X') {
                nptr += 2;
                base = 16;
            } else {
                nptr += 1;
                base = 8;
            }
        } else base = 10;
    } else if (base == 16) {
        if (nptr[0] == '0' && (nptr[1] == 'x' || nptr[1] == 'X')) nptr += 2;
    }

    nptr_digits = nptr; // mark the start of the first potential digit

    // Now process individual digits
    for (;;) {
        c = *nptr;
        digit =
            c >= '0' && c <= '9'? c - '0':
            c >= 'a' && c <= 'z'? c - 'a' + 10:
            c >= 'A' && c <= 'Z'? c - 'A' + 10:
            -1;
        if (digit < 0 || digit >= base) break;
        i = i * base + digit;
        nptr++;
    }

    if (nptr == nptr_digits) {
        // "If there were no digits at all, strtol() stores the original
        // value of nptr in *endptr (and returns 0)."
        if (endptr) *endptr = nptr0;
        return 0;
    } else {
        // We got a number, so return it!
        if (endptr) *endptr = nptr;
        return neg? -i: i;
    }
}

static int atoi(const char *nptr) { return strtol(nptr, NULL, 10); }
static long atol(const char *nptr) { return strtol(nptr, NULL, 10); }
static long long atoll(const char *nptr) { return strtol(nptr, NULL, 10); }
