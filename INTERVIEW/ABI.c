#include <stdio.h>

int main (void)
{

    printf(" int size : %d \n", sizeof(int));
    printf(" int * size : %d \n", sizeof(int *));
    printf(" long int size :%d \n", sizeof(long int));
    printf(" %d \n", (int *)(2+3));

}

