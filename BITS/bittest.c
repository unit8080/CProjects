#include <stdio.h>

#define BIT_MASK(pos)        (1UL << (pos))
#define BIT_TEST(num, pos)  ((num) & (1UL << pos))
#define BIT_SET(num, pos)   ((num) | (1UL << pos))
#define BIT_CLEAR(num, pos) ((num) & (~(1UL << pos)))
#define BIT_FLIP(num, pos)  ((num) ^ (1UL << pos))

int
main (int argc, char *argv[])
{
    int num, pos;
    int mask;

    printf("Please enter integer and bit position: ");
    scanf("%d %d", &num, &pos);

    mask = BIT_MASK(pos);
    if (BIT_TEST(num, pos)) {
        printf("Bit %d is set in integer %d\n", pos, num);
    } else {
        printf("Bit %d is not set in integer %d\n", pos, num);
    }
    int num1 = BIT_FLIP(num, pos);
    printf("Bit %d is flipped in integer %d to become %d\n",
           pos, num, num1);
    int num2 = BIT_SET(num1, pos);
    printf("Bit %d is set in integer %d to become %d\n",
           pos, num1, num2);
    int num3 = BIT_CLEAR(num2, pos);
    printf("Bit %d is cleared in integer %d to become %d\n",
           pos, num2, num3);
    return 0;
}
