#include <stdio.h>
#include <stdint.h>

#define bit_test(a, b) ((a) & (1U << (b)))
#define bit_flip(a, b) ((a) ^ (1U << (b)))
uint32_t bits_swap (uint32_t num)
{
    if ( num == 0 || num == ~0)
        return num;
    for (int i = 0; i < 16; i++) {
        if (bit_test(num, i) && bit_test(num, 31 - i)) {
            continue;
        } else if ((bit_test(num, i) == 0) && (bit_test(num, 31 - i) == 0)) {
            continue;
        } else {
            num = bit_flip(num, i);
            num = bit_flip(num, 31-i);
        }
    }
    return num;
}
int main(void) 
{
    int num1 = 0xffff1111; // 0x8888ffff
    int num2 = 0x22221111; // 0x88884444
    printf("swap 0x%x -> 0x%x \n", num1, bits_swap(num1));
    printf("swap 0x%x -> 0x%x \n", num2, bits_swap(num2));
    printf("flip 0x%x -> 0x%.8x \n", num1, num1 ^ 0xffffffff);
    printf("flip 0x%x -> 0x%x \n", num2, num2 ^ 0xffffffff);
}
