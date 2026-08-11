#include <stdio.h>

#define PRINT(X) printf("%s = %i\n", #X, X);

typedef enum E {
    ZERO,
    TWO = 2,
    THREE,
} E;

enum { x = 111 };

int main() {
    PRINT(ZERO)
    PRINT(TWO)
    PRINT(THREE)

    // NOTE: enum values use the same "namespace" as variables, functions,
    // and typedefs!..
    PRINT(x)
    {
        enum { x = 999 };
        PRINT(x)
    }
    PRINT(x)

    return 0;
}
