#include <stdio.h>

f(x, y) {
    if (x == 1) {
        printf("ONE\n");
    } else if(x == 2) {
        if (y == 1) {
            printf("TWO, ONE\n");
        } else if (y == 2) {
            printf("TWO, TWO\n");
        } else {
            printf("TWO, THREE\n");
        }
    } else {
        printf("THREE\n");
    }
}

main() {
    f(1, 1);
    f(2, 1);
    f(2, 2);
    f(2, 3);
    f(3, 1);
}
