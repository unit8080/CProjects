#include <stdio.h>


int 
main ()
{
    char *str = "Hello!";
    str[0] = 'z';  // this will cause Seg-fault due 
                   // to write into readonly literal. 
    printf("%s", str);
    return 0;
}

