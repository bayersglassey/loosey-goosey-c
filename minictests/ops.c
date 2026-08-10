#include <stdio.h>

#define MATH(X, Y) \
    printf("+ %s = %i\n", #X, + (X)); \
    printf("- %s = %i\n", #X, - (X)); \
    printf("~ %s = %i\n", #X, ~ (X)); \
    printf("! %s = %i\n", #X, ! (X)); \
    printf("%s + %s = %i\n", #X, #Y, (X) + (Y)); \
    printf("%s - %s = %i\n", #X, #Y, (X) - (Y)); \
    printf("%s * %s = %i\n", #X, #Y, (X) * (Y)); \
    printf("%s / %s = %i\n", #X, #Y, (Y) == 0? -999: (X) / (Y)); \
    printf("%s %% %s = %i\n", #X, #Y, (Y) == 0? -999: (X) % (Y)); \
    printf("%s << %s = %i\n", #X, #Y, (X) << (Y)); \
    printf("%s >> %s = %i\n", #X, #Y, (X) >> (Y)); \
    printf("\n");

#define COMPARE_EQ(X, Y) \
    printf("%s == %s = %i\n", #X, #Y, (X) == (Y)); \
    printf("%s != %s = %i\n", #X, #Y, (X) != (Y)); \
    printf("\n");

#define COMPARE_ALL(X, Y) \
    printf("%s == %s = %i\n", #X, #Y, (X) == (Y)); \
    printf("%s != %s = %i\n", #X, #Y, (X) != (Y)); \
    printf("%s <  %s = %i\n", #X, #Y, (X) <  (Y)); \
    printf("%s <= %s = %i\n", #X, #Y, (X) <= (Y)); \
    printf("%s >  %s = %i\n", #X, #Y, (X) >  (Y)); \
    printf("%s >= %s = %i\n", #X, #Y, (X) >= (Y)); \
    printf("\n");

void f(){}
void g(){}

typedef struct T { int x; } T;

int main() {
    int x = 1, y = 2;
    T t = {0};
    MATH(11, 3)
    MATH(t . x, 2)
    MATH(2, t . x)
    COMPARE_ALL(t . x, 0)
    COMPARE_ALL(0, t . x)
    COMPARE_ALL(t . x, 2)
    COMPARE_ALL(2, t . x)
    COMPARE_ALL(1, 1)
    COMPARE_ALL(1, 2)
    COMPARE_ALL(& x, & x)
    COMPARE_ALL(& x, & x + 1)
    COMPARE_ALL(1 + & x, & x + 1)
    COMPARE_EQ(& x, & y)
    COMPARE_EQ(& f, & f)
    COMPARE_EQ(& f, & g)
    {
        int x = 1;
        printf("x = %i\n", x);
        printf("x++ = %i\n", x++);
        printf("x = %i\n", x);
        printf("x-- = %i\n", x--);
        printf("x = %i\n", x);
        printf("++x = %i\n", ++x);
        printf("x = %i\n", x);
        printf("--x = %i\n", --x);
    }
    return 0;
}
