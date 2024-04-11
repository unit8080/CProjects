#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//int arr[] = { 1, 2, 3, 4};
int arr[] = { 8, 9, 9, 9};
int len = 4;
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (digits == NULL || digitsSize <= 0)
        return digits;
    
    bool allNines = true;
    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] != 9)
            allNines = false;
    }
    // compute return size (based on 9's) 
    *returnSize = allNines ? digitsSize + 1 : digitsSize;
    int *arr = (int *)malloc(sizeof(int) * (*returnSize));
    assert(arr != NULL);
    if (allNines) {
        arr[0] = 1;
        for (int i = 1; i < *returnSize; i++)
            arr[i] = 0;
    } else {
        int add = 1;
        for (int i = digitsSize -1; i >= 0; i--) {
            arr[i] = (digits[i] + add) % 10;
            add =  (digits[i] + add) / 10;
        } 
    }
    return arr;
}

int main (void) 
{
   printf("Input [] = ");
   for (int i = 0; i < len; i++) {
	printf(" %d,", arr[i]);
   }
   printf("\n");
   int len1;
   int *arr1 = plusOne(arr, len, &len1);
   printf("Output [] = ");
   for (int i = 0; i < len1; i++) {
	printf(" %d,", arr1[i]);
   }
   printf("\n");

    return 0;
}
