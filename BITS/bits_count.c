#include <stdio.h>
int
main (int argc, char *argv[])
{
    int num, number;
    int count = 0;

    printf("Enter the integer to find number of bits set : ");
    scanf("%d", &num);
    number = num;

    while (num) {
        count++;
        num = num & (num -1);
    }

    printf("Number of bits set in [%d] = %d\n", number, count);
    return 0;
}
