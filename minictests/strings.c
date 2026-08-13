#include <stdio.h>
#include <string.h>


int clamp_cmp(int cmp) {
    // strcmp and strncmp are allowed to return arbitrary negative/positive
    // numbers, not just -1 and 1.
    // We want unit tests that work for gcc and loosey, so we clamp the
    // output to -1..1
    return cmp < 0? -1: cmp > 0? 1: 0;
}
#define STRCMP(X, Y) printf("strcmp(%s, %s) = %i\n", #X, #Y, clamp_cmp(strcmp(X, Y)));
#define STRNCMP(X, Y, N) printf("strncmp(%s, %s, %i) = %i\n", #X, #Y, N, clamp_cmp(strncmp(X, Y, N)));


int main() {

    printf("=== STRCMP:\n");
    STRCMP("", "")
    STRCMP("a", "")
    STRCMP("", "a")
    STRCMP("a", "a")
    STRCMP("abc", "abc")
    STRCMP("abz", "abc")
    STRCMP("abz", "abz")
    STRCMP("abcc", "abc")
    STRCMP("abc", "abcc")

    printf("=== STRNCMP:\n");
    STRNCMP("", "", 0)
    STRNCMP("", "", 1)
    STRNCMP("a", "", 0)
    STRNCMP("a", "", 1)
    STRNCMP("", "a", 0)
    STRNCMP("", "a", 1)
    STRNCMP("a", "a", 1)
    STRNCMP("abcc", "abc", 3)
    STRNCMP("abcc", "abc", 4)
    STRNCMP("abc", "abcc", 3)
    STRNCMP("abc", "abcc", 4)

    return 0;
}
