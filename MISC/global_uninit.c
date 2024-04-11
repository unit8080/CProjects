#include <stdio.h>

int val;
static int *ptr;

int
main (int argc, char *argv[])
{
    
    printf("global variable: val = %d, ptr = %d\n", val, ptr);
}
