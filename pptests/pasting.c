#define M2(X, Y) [ X ## Y ]
#define M3(X, Y, Z) [ X ## Y ## Z ]
M2(1, 2)
M2(1 2, 3 4)
M2(,)
M2(1,)
M2(,2)
M3(1, 2, 3)
M3(1 2, 3 4, 5 6)
