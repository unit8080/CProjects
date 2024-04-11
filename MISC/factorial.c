#include <stdio.h>

/*
 * Factorial Program
 * 0! = 1
 * 1! = 1
 * 2! = 2 (2*1)
 * 3! = 6 (3*2*1)
 */
int factorial (int n)
{
    if (n == 0) {
        return (1);
    } else {
        return (n * factorial(n-1));
    }
}

int main() 
{
   int  number;

   printf("\nEnter number to calculate the fatorial of :");
   scanf("%d", &number);
   printf("%d!  -> %d\n", number, factorial(number)); 

   return (0);
}
