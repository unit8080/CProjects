/*
 * This program finds whether it is 64 bit or 32 bit platform.
 *
 */
#include <stdio.h>
#include <limits.h>

int main()
{
   printf("This Machine has %ld-bits processor \n",
          sizeof(void *) * CHAR_BIT);
}
