#include <stdio.h>

int test(void)
{
   static int count;

   count++;
   return count;
}

int main ( void)
{
   static int x;
   printf ("%d ", test());
   printf ("%d ", test());

   printf("x = %d", x);
   getchar();
}


