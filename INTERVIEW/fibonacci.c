#include <stdio.h>

int fib (int n)
{
    if (n < 2)
        return n;
    return (fib(n-1) + fib(n-2));
}


int
main(int argc, char *argv[])
{
    int n;
    int fibn;

    scanf("%d", &n);
    fibn = fib(n);
    printf("fib(%d) = %d", n, fibn);
    return 0;
}
   
