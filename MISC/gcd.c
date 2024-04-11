#include <stdio.h>

int gcd( int a, int b )
{
    int dividend = a >= b ? a : b;
    int divisor = a >= b ? b : a; 

    while ( divisor != 0 )
    {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}

int main ()
{
    int a, b;
    printf("Enter number to find gcd ");
    scanf("%d %d", &a, &b);
    printf("gcd of (%d, %d) = %d\n", a, b, gcd(a, b));
}

