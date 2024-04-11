#include <stdio.h>


int *f()
{
    int *a = NULL;
    return a;
}


int print_ptr() {
  int x[5];
  printf("%p\n", x);
  printf("%p\n", x+1);
  printf("%p\n", &x);
  printf("%p\n", &x+1);
  return 0;
}

void test_ptr()
{
    int *b;

    /*
     * Check the return by value (reference here)
     */
    printf("[] Check the return by value: ");
    if (NULL == (b = f())) {
        printf("NULL Pointer\n");
    } else {
        printf("NOT NULL Pointer\n");
    }
    print_ptr(); 
}


/*
int
main()
{
    test_ptr();
}
*/


