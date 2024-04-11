#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    uint32_t a = 0x90909090;
    int count = 0;
    while (a > 0) {
        count++;
        a = (a) & (a-1);
    }
    printf("Number of bits set = %d \n", count);
}
