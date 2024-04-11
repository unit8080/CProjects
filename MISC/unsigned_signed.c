#include <stdio.h>

int main()
{
    unsigned int x;
    signed int y;

    x = ~0;
    y = ~0;

    printf("x = %u, y = %d\n", x, y);
    printf("x = %x, y = %x\n", x, y);
}
