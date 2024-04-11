#include <stdio.h>

int memo[51];
int fib(int n)
{
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}
int main ()
{
   int n;
   printf("Enter number : ");
   scanf("%d", &n);
   for(int i=0; i < 51; i++) {
       memo[i] = -1;
   }
   printf("Fibonaci for %d = %d\n", n, fib(n));
}

