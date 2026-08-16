#include <stdio.h>

void f(x) {
    printf("START: %i\n", x);
    switch(x) {
        case 1: printf("ONE\n");
        case 2: printf("TWO\n"); break;
        default: printf("DEFAULT\n");
        case 3: printf("THREE\n");
    }
}

int main() {
    f(1);
    f(2);
    f(3);
    f(4);
    return 0;
}
