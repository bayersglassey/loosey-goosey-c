#include <stdio.h>

typedef struct T { int x; int y; int data[2]; } T;
typedef struct Y { int x; T t; T tt[2]; } Y;

void print_T(T *t) {
    printf("{ .x = %i, .y = %i, .data = {%i, %i} }\n",
        t->x, t->y, t->data[0], t->data[1]);
}

void print_Y(Y *y) {
    int i;
    printf("  .x = %i\n", y->x);
    printf("  .t = "); print_T(&y->t);
    for (i = 0; i < 2; i += 1) {
        printf("  .tt[%i] = ", i);
        print_T(&y->tt[i]);
    }
}

int main() {
    T t = {1, 2};
    T tt[] = {{1, 2, {10, 20}}, {3, 4, {30, 40}}};
    int i;
    printf("t = "); print_T(&t);
    for (i = 0; i < 2; i += 1) {
        printf("tt[%i] = ", i);
        print_T(&tt[i]);
    }

    {
        Y y1 = {
            99,
            {1, 2, {10, 20}},
            {
                {1, 2, {10, 20}},
                {3, 4, {30, 40}}
            }
        };
        Y y2 = {99, t, {t, t}};
        printf("y1 =\n"); print_Y(&y1);
        printf("y2 =\n"); print_Y(&y2);
    }

    return 0;
}
