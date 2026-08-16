#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Basic true/false:\n");
    if (true) printf("OK\n");
    if (false) printf("BAD\n");

    printf("Logical NOT:\n");
    if (!true) printf("BAD\n");
    if (!false) printf("OK\n");

    printf("Logical AND:\n");
    if (true && true) printf("OK\n");
    if (true && false) printf("BAD\n");
    if (false && true) printf("BAD\n");
    if (false && false) printf("BAD\n");

    printf("Logical OR:\n");
    if (true || true) printf("OK\n");
    if (true || false) printf("OK\n");
    if (false || true) printf("OK\n");
    if (false || false) printf("BAD\n");

    printf("Ternary:\n");
    printf("%s\n", true? "OK": "BAD");
    printf("%s\n", false? "BAD": "OK");

    return 0;
}
