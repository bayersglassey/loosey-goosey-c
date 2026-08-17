#include <stdio.h>
#include <stdlib.h>


void test_strtol(const char *s, int base) {
    char *s_after;
    long i = strtol(s, &s_after, base);
    printf("strtol(\"%s\", %i) -> %li, \"%s\"\n",
        s, base, i, s_after);
}


int main() {

    printf("=== STRTOL\n");
    test_strtol("12x", 10);
    test_strtol("  12x", 10);
    test_strtol("  +12x", 10);
    test_strtol("  -12x", 10);
    test_strtol("x", 10);
    test_strtol("  x", 10);
    test_strtol("  +x", 10);
    test_strtol("  -x", 10);
    test_strtol("  10", 0);
    test_strtol("  010", 0);
    test_strtol("  0x10", 0);
    test_strtol("  ff", 16);

    return 0;
}
