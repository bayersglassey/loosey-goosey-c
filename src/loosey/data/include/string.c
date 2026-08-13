
// This file is #included by our string.h.
// NOTE: some of the string.h functions may be defined in Python, not here!
// See the CStdlib Python class

static int strcmp(const char *s1, const char *s2) {
    for (;;) {
        char c1 = *s1, c2 = *s2;
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        // they are equal so far...
        if (!c1) return 0; // one is NUL, so both are NUL, so entire string is equal
        s1++; s2++;
    }
}

static int strncmp(const char *s1, const char *s2, size_t n) {
    char i = 0;
    while (i++ < n) {
        char c1 = *s1, c2 = *s2;
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        // they are equal so far...
        if (!c1) return 0; // one is NUL, so both are NUL, so entire string is equal
        s1++; s2++;
    }
    return 0;
}
