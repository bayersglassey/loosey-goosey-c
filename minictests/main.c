#include <stdio.h>

int main(int argc, char **argv) {
    int i = 1;
    while (i < argc) {
        printf("Arg %i: %s\n", i, argv[i]);
        i += 1;
    }
}
