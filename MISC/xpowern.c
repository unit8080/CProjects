#include <stdio.h>
#include <stdbool.h>

#if 0
int XpowerN(int x, int n)
{
    static int y;
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2 == 0) {
        y = XpowerN(x, n/2);
        y = y*y;
    } else
        y = x*XpowerN(x, (n-1));
    printf("%d ", y);
    return y;
}
#endif

int isPowerOf2 (int x)
{
    if ((x & (x -1)) == 0) return true;
    else return false;
}

int main ()
{
    printf("%d \n", isPowerOf2(63));
#if 0
    int n,  x;
    printf("x (power) n = ");
    scanf("%d %d", &x, &n);
    printf("%d (power) %d = %d \n", x, n, XpowerN(x, n));
#endif
}

