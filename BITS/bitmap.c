#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* global declaration */
typedef struct bitmap_ {
    int  sz;
    int  bytes;        // Number of bytes needed
    unsigned char *bm; // Notice unsigned here !!!
} bitmap_t;

/* API */
bitmap_t *bitmap_init(int size);
void bitmap_set_bits(bitmap_t *bm, int minbit, int maxbit);
void bitmap_clear_bits(bitmap_t *bm, int minbit, int maxbit);
void bitmap_flip_bits(bitmap_t *bm, int minbit, int maxbit);

void print_bitmap (bitmap_t *bm)
{
    int i;

    printf("bitmap size  = %d bits\n",  bm->sz);
    printf("bitmap bytes = %d bytes\n", bm->bytes);
    for(i = 0; i < bm->bytes; i++)
        printf("char[%d..%d] = 0x%1X\n", i*CHAR_BIT, i*CHAR_BIT+7,
               bm->bm[i]);
}

#define MASK_LOWER(bits, pos) \
    (unsigned char)(((1 << (bits)) - 1) << (pos))
#define MASK_HIGHER(bits, pos) \
    (unsigned char)(((1 << (bits)) - 1) << (CHAR_BIT - (bits)))

void bitmap_set(bitmap_t *bm, int minby, int minbit, int maxby, int maxbit)
{
    int i;
    if (minbit) {
        bm->bm[minby -1] |= MASK_HIGHER(minbit, 0);
    }
    for (i = minby; i < maxby; i++)
        bm->bm[i] = *((unsigned char *)bm->bm +i) | 0xFF;
    if (maxbit) {
        bm->bm[maxby] |= MASK_LOWER(maxbit, 0);
    }
}
void bitmap_clear(bitmap_t *bm, int minby, int minbit, int maxby, int maxbit)
{
    int i;
    if (minbit) {
        bm->bm[minby -1] &= ~MASK_HIGHER(minbit, 0);
    }
    for (i = minby; i < maxby; i++)
        bm->bm[i] = *((unsigned char *)bm->bm +i) & 0x00;
    if (maxbit) {
        bm->bm[maxby] &= ~(MASK_LOWER(maxbit, 0));
    }
}
void bitmap_flip(bitmap_t *bm, int minby, int minbit, int maxby, int maxbit)
{
    int i;
    if (minbit) {
        bm->bm[minby -1] ^= MASK_HIGHER(minbit, 0);
    }
    for (i = minby; i < maxby; i++)
        bm->bm[i] = *((unsigned char *)bm->bm +i) ^ 0xFF;
    if (maxbit) {
        bm->bm[maxby] ^= (MASK_LOWER(maxbit, 0));
    }
}
void bitmap_intsc(bitmap_t *bm1, bitmap_t *bm2, bitmap_t *bm3, int minby, int minbit, int maxby, int maxbit)
{
    int i;
    unsigned char c;
    unsigned char d;

    if (minbit) {
        c = bm1->bm[minby - 1] & MASK_HIGHER(minbit, 0);
        d = bm1->bm[minby - 1] & MASK_HIGHER(minbit, 0);
        bm3->bm[minby -1] = c & d;
    }
    for (i = minby; i < maxby; i++)
        bm3->bm[i] = bm1->bm[i] & bm2->bm[i];
    if (maxbit) {
        c = bm1->bm[maxby] & (MASK_LOWER(maxbit, 0));
        d = bm2->bm[maxby] & (MASK_LOWER(maxbit, 0));
        bm3->bm[maxby] = c & d;
    }
}
void bitmap_union(bitmap_t *bm1, bitmap_t *bm2, bitmap_t *bm3, int minby, int minbit, int maxby, int maxbit)
{
    int i;
    unsigned char c;
    unsigned char d;

    if (minbit) {
        c = bm1->bm[minby - 1] & MASK_HIGHER(minbit, 0);
        d = bm1->bm[minby - 1] & MASK_HIGHER(minbit, 0);
        bm3->bm[minby -1] = c | d;
    }
    for (i = minby; i < maxby; i++)
        bm3->bm[i] = bm1->bm[i] | bm2->bm[i]; 
    if (maxbit) {
        c = bm1->bm[maxby] & (MASK_LOWER(maxbit, 0));
        d = bm2->bm[maxby] & (MASK_LOWER(maxbit, 0));
        bm3->bm[maxby] = c | d;
    }
}

bitmap_t *bm;
bitmap_t *bitmap_init (int size)
{
    bitmap_t *bm;
    
    bm = malloc(sizeof(bitmap_t));
    bm->sz = size;
    bm->bytes = size/CHAR_BIT + (size % CHAR_BIT ? 1 : 0);
    bm->bm = (unsigned char *) malloc(bm->bytes);
    memset(bm->bm, 0, bm->bytes);
    print_bitmap(bm);
    return bm;
}

void bitmap_set_bits(bitmap_t *bm, int min_range, int max_range)
{
    int min_byte;
    int min_bits;
    int max_byte;
    int max_bits;

    printf("Setting bitmap ...\n");

    if ((min_range % CHAR_BIT) == 0)
        min_byte = min_range/CHAR_BIT;
    else
        min_byte = min_range/CHAR_BIT + 1;

    if (min_range % CHAR_BIT)
        min_bits = CHAR_BIT - (min_range % CHAR_BIT); // take higher mask
    else
        min_bits = 0;
    max_byte = (max_range +1)/CHAR_BIT;
    max_bits = (max_range +1) % CHAR_BIT; // take lower mask for this

    bitmap_set(bm, min_byte, min_bits, max_byte, max_bits);
    print_bitmap(bm);
}

void bitmap_clear_bits(bitmap_t *bm, int min_range, int max_range)
{
    int min_byte;
    int min_bits;
    int max_byte;
    int max_bits;

    printf("Clearing bitmap ...\n");
    if ((min_range % CHAR_BIT) == 0)
        min_byte = min_range/CHAR_BIT;
    else
        min_byte = min_range/CHAR_BIT + 1;

    if (min_range % CHAR_BIT)
        min_bits = CHAR_BIT - min_range % CHAR_BIT; // take higher mask
    else
        min_bits = 0;
    max_byte = (max_range +1)/CHAR_BIT;
    max_bits = (max_range +1) % CHAR_BIT; // take lower mask for this
    bitmap_clear(bm, min_byte, min_bits, max_byte, max_bits);
}

void bitmap_flip_bits(bitmap_t *bm, int min_range, int max_range)
{
    int min_byte;
    int min_bits;
    int max_byte;
    int max_bits;

    printf("Flipping bitmap ...\n");
    if ((min_range % CHAR_BIT) == 0)
        min_byte = min_range/CHAR_BIT;
    else
        min_byte = min_range/CHAR_BIT + 1;

    if (min_range % CHAR_BIT)
        min_bits = CHAR_BIT - min_range % CHAR_BIT; // take higher mask
    else
        min_bits = 0;
    max_byte = (max_range +1)/CHAR_BIT;
    max_bits = (max_range +1) % CHAR_BIT; // take lower mask for this
    bitmap_flip(bm, min_byte, min_bits, max_byte, max_bits);
}
int main (int argc, char *argv[])
{
    int size;

    printf("Enter the bitmap size: ");
    scanf("%d", &size);
    // initialize bitmap table
    bm = bitmap_init(size);

    int min_range = 0;
    int max_range = 0;
    printf("Enter the bit ranges: ");
    scanf("%d %d", &min_range, &max_range);
    printf("bit ranges: min = %d, max = %d\n", min_range, max_range);
    /* validate the range here */

    bitmap_set_bits(bm, min_range, max_range);

    int i;
    for (i = 0; i <= bm->bytes; i++)
         bm->bm[i] |= 0xFF;
    print_bitmap(bm);

    bitmap_clear_bits(bm, min_range, max_range);
    print_bitmap(bm);
    bitmap_flip_bits(bm, min_range, max_range);
    print_bitmap(bm);
}
