#include <stdio.h>
#include <inttypes.h>
#include <arpa/inet.h>

struct packet {
    uint8_t x;
    uint32_t y;
} __attribute__((packed));

int main ()
{
    uint8_t bytes[5] = {1, 0, 0, 0, 2};
    struct packet *p = (struct packet *)bytes;

    // compiler handles misalignment because it knows that
    // "struct packet" is packed
    printf("y=%"PRIX32", ", ntohl(p->y));

    // compiler does not handle misalignment - py does not inherit
    // the packed attribute
    uint32_t *py = &p->y;
    printf("*py=%"PRIX32"\n", ntohl(*py));
    return 0;
}
/*
 * Yes, __attribute__((packed)) (no need for second set of underscores)
 * is a correct way to implement binary (i.e. non-text) network protocols.
 * There will be no gaps between the elements.
 *
 * However you should understand that packed not only packs the structure, but also:
 *
 * - makes its required alignment one byte, and
 * - makes sure that its members, which may get misaligned by the packing
 * and by lack of alignment requirement of the struct itself, are read and
 * written correctly, i.e. misalignment of its fields is dealt with in 
 * software by the compiler.
 *
 * However, the compiler will only deal with misalignment if you access the
 * struct members directly. You should never make a pointer to a member of 
 * a packed struct (except when you know the member's required alignment is 1,
 * like char or another packed struct). The following C code demonstrates the issue:
 *
 * On an x86 system (which does not enforce memory access alignment), 
 * this will produce
 *
 * y=2, *py=2
 *
 * as expected. On the other hand on my ARM Linux board, for example, 
 * it produced the seemingly wrong result
 *
 * y=2, *py=1
 */
