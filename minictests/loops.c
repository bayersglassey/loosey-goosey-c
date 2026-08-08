#include <stdio.h>

int main() {
    int i;

    i = 0;
    while (i < 3) {
        printf("While: %i\n", i);
        i += 1;
    }

    i = 0;
    while (1) {
        printf("While: %i\n", i);
        i += 1;
        if (i < 3) continue;
        break;
    }

    i = 0;
    do {
        printf("Do..while: %i\n", i);
        i += 1;
    } while(i < 3);

    i = 0;
    do {
        printf("Do..while: %i\n", i);
        i += 1;
        if (i < 3) continue;
        break;
    } while(1);

    for (i = 0; i < 3; i += 1) {
        printf("For: %i\n", i);
    }

    i = 0;
    for (;;) {
        printf("For: %i\n", i);
        i += 1;
        if (i < 3) continue;
        break;
    }

    return 0;
}
