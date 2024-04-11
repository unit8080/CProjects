#include <stdio.h>

static int i; // BSS : unintialized static variable

int a ()
{
    static int j = 5;
    int k = 10;

    printf (" j = %d, k = %d\n", j, k);
    j++;
    k++;
    return 0;
}

int test()
{
  int x = 1, y = 2, z = 3;
  printf(" x = %d, y = %d, z = %d \n", x, y, z);
  {
       int x = 10;
       float y = 20;
       printf(" x = %d, y = %f, z = %d \n", x, y, z);
       {
             int z = 100;
             printf(" x = %d, y = %f, z = %d \n", x, y, z);
       }
  }
  return 0;
}

int 
main ()
{
    a();
    a();

    {
        int m = 10;
    }
    {
       // printf("%d\n", m); // copilation error

    }
    test();
    return 0;
}

