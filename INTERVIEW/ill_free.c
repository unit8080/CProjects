#include <stdio.h>
#include <stdlib.h>

int
main ()
{
    char *p = malloc(30);

    printf("%p \n", p);
    free(p-15);    // <- segmentation fault occurs
}
