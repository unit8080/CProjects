/*
 * Function prototypes for bitwise operations.
 *
 * June 21, 2012 (c) Sanjeev Singh
 */
#ifndef BITWISE_H
#define BITWISE_H
/*
 * Get the BIT MASK for given bit index 31...0
 */
#define BIT_MASK(bit) \
    ( 1UL << bit ) 
/*
 * Read bit field value from register.
 * Input:
 *   reg : register
 *   offset: offset of the bits in the register
 *   bits: number of required bits
 *
 * Output: the required value.
 */
#define READ_VALUE( reg, offset, bits ) \
    ((reg >> (offset)) & ((1 << bits) -1))
/*
 * Write the bit field value to a register.
 * Input:
 *     reg: register
 *     offset: offset of the bits in the register
 *     bits: number of required bits
 *     value: value to be written
 *
 * Solution:
 *    1. get the bits ((1 << bits) -1)
 *    2. move above bits to offset
 *    3. clear the value at offset by inversing the bits
 *    4. follow step 3 for value and 
 *       insert/set the value at the offest.
 *
 * Output: None
 */
#define WRITE_VALUE( reg, offset, bits, value )         \
    do {                                                \
        reg &= ~(((1 << bits) -1) << offset);           \
        reg |= ((value & ((1 << bits) - 1)) << offset); \
    } while (0);

#endif /* BITWISE_H */
