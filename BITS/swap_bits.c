#include <stdio.h>

#define MASK(bits, pos)  (((1 << (bits)) -1) << pos)
#define read_bit(x, idx) ((x) & MASK(1, (idx)))
    
int main(int agrc, char **argv)
{
    long unsigned int x = 0x1122334455667788;
    int idx1, idx2;
    scanf("%d %d", &idx1, &idx2);
    printf("Input : %lx\n", x);
#if 0
    long unsigned int bit1 = read_bit(x, idx1);
    long unsigned int bit2 = read_bit(x, idx2);

    if (bit1)
        x |= MASK(1, idx2);
    else
        x &= ~MASK(1, idx2);

    if (bit2)
        x |= MASK(1, idx1);
    else
        x &= ~MASK(1, idx1);
#endif
    if (((x >> idx1) & 1) != ((x >> idx2) & 1))
        x ^= (1L << idx1) | (1L << idx2);
    printf("Output: %lx\n", x);
}
