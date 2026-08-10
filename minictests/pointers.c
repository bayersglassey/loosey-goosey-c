#include <stdio.h>

int main() {
    int x = 1, y = 2, *p1 = &x, *p2 = &y, **pp = &p1;
    printf("**p = %i\n", **pp); // 1
    pp = &p2;
    printf("**p = %i\n", **pp); // 2
    *p1 *= 10;
    *p2 *= 100;
    printf("**p = %i\n", **pp); // 200
    *pp = &x;
    printf("*p1 = %i, *p2 = %i\n", *p1, *p2); // 10, 10
    printf("x = %i, y = %i\n", x, y); // 10, 200
    return 0;
}
