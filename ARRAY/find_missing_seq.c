/*
 * This is property of the Sanjeev Singh.
 * Copyright (c) general Use.
 * Free to copy, duplicate and use anywhere at own risk.
 */

#include <stdio.h>


int array1 [] = { 2, 3, 5,  6, 7, 8};
int array2 [] = { 2, 3, 4, 5,  6, 7, 8};

int find_miss_seq_num(int arr[], int length)
{

    int i;

    for (i = 0; i < (length - 1); i++) {
         if ((arr[i] + 1) == arr[i+1]) {
             continue;
         } else {
             return (arr[i] + 1);
         }
    }
    return -1;
}

int main (void)
{

    int miss_num;

    if ((miss_num = find_miss_seq_num(array1, 6)) == 4) {
        printf("Success : %d\n", miss_num);
    } else {
        printf("Failed :\n");

    }
    if ((miss_num = find_miss_seq_num(array2, 7)) == -1) {
        printf("Success : %d\n", miss_num);
    } else {
        printf("Failed :\n");

    }
}
