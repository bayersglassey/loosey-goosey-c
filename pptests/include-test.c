
#define A(X) aaa [ X ]
#define M(X) A ( X ) B ( X )
M(1)

// We expect this to undefine A and define B
#include "include-test.h"

M(2)

###################
aaa [ 1 ] B ( 1 )
A ( 2 ) bbb [ 2 ]
