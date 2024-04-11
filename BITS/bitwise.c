/*
 * Function definition for bitwise operations.
 *
 * July 12, 2012 (c) Sanjeev Singh
 */
#include <stdio.h>
#include <stdlib.h>
#include "bitwise.h"

int main (int argc, char *argv[])
{
    int a = 0x48F02456;
    int b = 0;

    printf ("a = 0x%x\n", a);
    /* 
     * write 0x3 in bit field that starts at offset 12, with length 3
     */
    WRITE_VALUE(a, 12, 3, 0x3);

    printf("a = 0x%x\n", a);
    /*
     * Read range value of bit field 12..13 (start at 12, length 2)
     */
    printf("Field 12..13 = 0x%x\n", READ_VALUE(a, 12, 2) );

    /*
     * Generate the bitmask with 4 bits
     */
    b = BIT_MASK(31) | BIT_MASK(12) | BIT_MASK(13) | BIT_MASK(1);
    printf ("b = 0x%x\n", b);
    return 0;
}
