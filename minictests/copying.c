#include <stdio.h>


typedef struct T T;


void modify_via_pointer(T *t, int i) {
    t->x = i;
}

T return_copy_via_pointer(T *t) {
    return *t;
}

T modified_copy(T t, int i) {
    t.x = i;
    return t;
}


int main() {
    T t1, t2;
    t1.x = 1;
    t1.z = 99;

    t2 = t1;
    printf("%i, %i, %i\n", t1.x, t2.x, t2.z); // 1, 1, 99

    t2 = t1;
    t2.x = 2;
    printf("%i, %i, %i\n", t1.x, t2.x, t2.z); // 1, 2, 99

    t2 = t1;
    modify_via_pointer(&t2, 3);
    printf("%i, %i, %i\n", t1.x, t2.x, t2.z); // 1, 3, 99

    t2 = *&t1; // this should be a copy!
    t2.x = 4;
    printf("%i, %i, %i\n", t1.x, t2.x, t2.z); // 1, 4, 99

    t2 = return_copy_via_pointer(&t1);
    t2.x = 5;
    printf("%i, %i, %i\n", t1.x, t2.x, t2.z); // 1, 5, 99

    t2 = modified_copy(t1, 6);
    printf("%i, %i, %i\n", t1.x, t2.x, t2.z); // 1, 6, 99

    {
        T t2 = t1;
        t2.x = 7;
        printf("%i, %i, %i\n", t1.x, t2.x, t2.z); // 1, 7, 99
    }

    return 0;
}
