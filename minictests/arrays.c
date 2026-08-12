#include <stdio.h>

void print_data(int *data, int n) {
    int i;
    for (i = 0; i < n; i += 1) printf("  [%i] = %i\n", i, data[i]);
}

void increment_test() {
    int data[] = {1, 2, 3};
    int i = 0;
    printf("Increment Test:\n");
    printf("data =\n");
    print_data(data, 3);

    data[i++] = 10; // data[0]
    data[++i] = 30; // data[2]

    printf("data =\n");
    print_data(data, 3);
}

int main() {
    int data[] = {1, 2, 3, 4};
    int data2[][2] = {{1, 2}, {3, 4}};
    int i, j;

    for (i = 0; i < 4; i += 1) printf("data[%i] = %i\n", i, data[i]);
    printf("\n");

    printf("data =\n"); print_data(data, 4);
    printf("\n");

    for (i = 0; i < 2; i += 1) {
        for (j = 0; j < 2; j += 1) printf("data2[%i][%i] = %i\n", i, j, data2[i][j]);
        printf("data2[%i] =\n", i); print_data(data2[i], 2);
    }
    printf("\n");

    increment_test();
    printf("\n");

    return 0;
}
