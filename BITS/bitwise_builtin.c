#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 16;
    int clz = 0;
    int ctz = 0;
    int ones = 0;

    clz = __builtin_clz(num);
    printf("Number of leading zero's in %d is %d\n", num, clz);

    clz = __builtin_clz(-num);
    printf("Number of leading zero's in %d is %d\n", -num, clz);

    ctz = __builtin_ctz(num);
    printf("Number of trailing zero's in %d is %d\n", num, ctz);

    ones = __builtin_popcount(num);
    printf("Number of one's in %d is %d\n", num, ones);
    return 0;
}
