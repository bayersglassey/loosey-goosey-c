#include <stdio.h>

#define PRINT(X) printf("%s = %i\n", #X, X);

int x = 1;

void f(void) {
    int x = 2;
    PRINT(x)
    {
        x = 3;
        PRINT(x)
    }
    PRINT(x)
    {
        int x = 4;
        PRINT(x)
    }
    PRINT(x)
}

int main() {
    PRINT(x)
    f();
    PRINT(x)
    return 0;
}
