/*
Simple BITMAP Allocator

Implement a bitmap allocator which uses an array of 8B flits (aka type
uint64_t) for the bitmap memory.  Each bit in the map represents an ID
that can be allocated.  The ID value is the bit position in the array,
so the range of the IDs is 0..max_valid_id.

The inputs to your allocator are the bitmap data struct pointer, and
the desired ID to be allocated.  Validate the ID by ensuring the ID is
within the range of the bitmap, and that it is not already allocated.
If the ID is not valid, then return -1.  If the ID is valid, then set
the appropriate bit and return 0.

Stretch goal: implement the free function.

Assumptions:

The bitmap data struct is already allocated...
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// #include <malloc.h>
#include <assert.h>

enum {
        BITS_PER_BYTE = 8,
        BITS_PER_FLIT = sizeof(uint64_t) * BITS_PER_BYTE,
};

struct bitmap {
        /* bitmap memory */
        uint64_t *bits;

        /* the number of flits in bitmap */
        uint64_t num_flits;

        /* the largest valid id that can be allocated */
        uint64_t max_valid_id;
};

int bitmap_alloc(struct bitmap *bm, uint64_t id);
int bitmap_free(struct bitmap *bm, uint64_t id);


/* Add bitmap_alloc() here */

int bitmap_alloc(struct bitmap *bm, uint64_t id ) {
    
    if (!bm) 
        return -1;
    if (id > bm->max_valid_id) 
        return -1;
    
    int index = id/BITS_PER_FLIT;
    int pos = id % BITS_PER_FLIT; // 0..63
    
    uint64_t bits = bm->bits[index];
    uint64_t mask = (uint64_t) 0x1 << pos;
    
    if (bits & mask) {
        return -1;
    } else {
        // bits = bits | mask;
        bm->bits[index] |= mask;
    }
    return 0;
}

int bitmap_free(struct bitmap *bm, uint64_t id) {
    if (!bm) 
        return -1;

    if (id > bm->max_valid_id) 
        return -1;

    int index = id/BITS_PER_FLIT;
    int pos = id % BITS_PER_FLIT;
    uint64_t mask = (uint64_t)0x1;

    mask = mask << pos;
    mask = ~mask;
    bm->bits[index] &= mask;

    return 0;
}

int main() {
    struct bitmap *bm = malloc(sizeof(struct bitmap));
    if (!bm) 
        return -1;
    
    uint64_t max_valid_id = 123;
     
    uint64_t num_flits = max_valid_id/BITS_PER_FLIT + 1;
    bm->max_valid_id = max_valid_id;
    bm->num_flits = num_flits;
    bm->bits = malloc(sizeof(uint64_t)*num_flits);
    if (!bm->bits)
        return -1;
        
    int bit_pos = 0;
    printf("%llu\n", num_flits);
    printf("%llu\n", bm->bits[0]);
    bitmap_alloc(bm, bit_pos);
    printf("%llu\n", bm->bits[0]);
    bitmap_free(bm, bit_pos);
    printf("%llu\n", bm->bits[0]);

    return 0;
}