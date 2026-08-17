
// This file is #included by our string.h.
// NOTE: some of the string.h functions may be defined in Python, not here!
// See the CStdlib Python class

size_t strlen(const char* s) {
    size_t i = 0;
    while (*s++) i++;
    return i;
}

size_t strnlen(const char* s, size_t n) {
    size_t i = 0;
    while (n-- && *s++) i++;
    return i;
}

char* strcpy(char* restrict s1, const char* restrict s2) {
    char *s0 = s1;
    char c;
    while (c = *s2++) *(s1++) = c;
    *s1 = '\0';
    return s0;
}

char* strncpy(char* restrict s1, const char* restrict s2, size_t n) {
    char *s0 = s1;
    char c;
    while (n-- && (c = *s2++)) *(s1++) = c;
    n++;
    while (n--) *(s1++) = '\0';
    return s0;
}

char* strcat(char* restrict s1, const char* restrict s2) {
    char *s0 = s1;
    char c;
    while (*s1) s1++; // find the end of the string to be appended to
    while (c = *s2++) *(s1++) = c;
    *s1 = '\0';
    return s0;
}

char* strncat(char* restrict s1, const char* restrict s2, size_t n) {
    char *s0 = s1;
    char c;
    while (*s1) s1++; // find the end of the string to be appended to
    while (n-- && (c = *s2++)) *(s1++) = c;
    *s1 = '\0';
    return s0;
}

char* strdup(const char* s) {
    size_t len = strlen(s);
    char *new_s = malloc(len + 1);
    if (new_s) strcpy(new_s, s);
    return new_s;
}

char* strndup(const char* s, size_t n) {
    size_t len = strnlen(s, n);
    char *new_s = malloc(len + 1);
    if (new_s) {
        strncpy(new_s, s, len);
        new_s[len] = '\0';
    }
    return new_s;
}

char* strchr(char* s, int c) {
    char c2;
    while (c2 = *s) {
        if (c2 == c) return s;
        s++;
    }
    return NULL;
}

char* strstr(char* s1, const char* s2) {
    // s1 is the haystack, s2 the needle
    size_t n = strlen(s2);
    while (*s1) {
        if (!strncmp(s1, s2, n)) return s1;
        s1++;
    }
    return NULL;
}

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
