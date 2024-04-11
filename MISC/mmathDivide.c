#include <stdio.h>

int main(void)
{
//    int dividend = 8, int divisor = 2;
    int dividend = 15, divisor = -3;
//    int dividend = 7, int divisor = 3;
    int div = dividend; // for print
    int dis = divisor;
    if (divisor == 0)
        printf("divide by zero\n");

    int sign; 
    if ((dividend < 0 && divisor > 0) ||
            (dividend >= 0 && divisor < 0))
        sign = -1;
    if (dividend < 0) dividend = -dividend;
    if (divisor < 0) divisor = -divisor;

#if 1
    int n = 1; // find quotient between n & 2n
    while (dividend >= (n << 1) * divisor) {
        n  = n << 1;
    }

    int result = 0; // between [n, 2n]
    while (n > 0 && dividend > 0) {
        if (dividend - n * divisor >= 0) {
            dividend = dividend - n*divisor;
            result = result + n;
        }
        n = n >> 1;
    }
#endif
    printf(" dividend: %d divisor: %d result: %d \n", div, divisor, result*sign);
}
