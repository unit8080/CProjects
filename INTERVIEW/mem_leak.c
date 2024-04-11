/* code with memory leak */
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int *ptr = (int*)malloc(10);
 
    return 0;
}
