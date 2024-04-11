#include <stdio.h>
#include <stdlib.h>

int array1[] = {3, 2,3,4,5,6,7, 5, 3, 4, 3,8,9};
int array2[] = {2,5,7,9,11,4,15,17};
int array3[] = {2,4,6,8,10,12,14,16};
int zg[]  = { 0, 4, 5, 2, 0, 8, 1, 4, 0, 2, 9, 0, 3, 0, 1};

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort_zero (int A[], int len)
{
    int l = 0;
    int r = len -1;

    while (l < r) {
        if (A[r] == 0) {
            r--;
        } else if (A[l] != 0) {
            l++;
        } else {
            swap(&A[l], &A[r]);
            l++; r--;
        }
    }
}

void sort_group (int arr[], int len)
{
    int i = 0;
    int j = len - 1;

    while (i < j) {
        if ((arr[i] & 0x1) == 0x1) {
            i++;
        } else if ((arr[j] & 0x1) == 0x0) {
            j--;
        } else {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
}

//int arr[] = {-11,-7,-6,-3,-1,2,4,5,9};
int arr[] = {-7,-6,-3, -1, 2,4,5, 6, 8, 9}; // working
void sortSquare (int arr[], int len)
{
    int K = 0; // 1. split point - find index of first positive 
    for (K = 0; K < len; K++)
        if (arr[K] >= 0)
            break;

    int i = K - 1; // negative lowest number index
    int j = K;     // positive lowest number index
    int idx = 0;   // starting index of temp array

    int temp[len];
    while (i >= 0 && j < len)
    {
        if (arr[i] * arr[i] <= arr[j] * arr[j])
        {
            temp[idx] = arr[i] * arr[i];
            i--;
            idx++;
        } else {
            temp[idx] = arr[j] * arr[j];
            j++;
            idx++;
        }
    }
    while (i >= 0) {
        temp[idx] = arr[i] * arr[i];
        i--;
        idx++;
    }
    while (j < len) {
        temp[idx] = arr[j] * arr[j];
        j++;
        idx++;
    }
    for(int i = 0; i < len; i++)
        arr[i] = temp[i];
}

int main (void)
{
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("\nArr [] = " ); 
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n" ); 
    sortSquare(arr, len);
    printf("\nsorted Arr [] = " ); 
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n" ); 


    len = sizeof(zg) / sizeof(zg[0]);
    printf("\n zg[] : "); for (int i = 0; i < len; i++) printf(" %d ", zg[i]); printf("\n");
    sort_zero(zg, len);
    for (int i = 0; i < len; i++) printf(" %d ", zg[i]); printf("\n");

    getchar();

    printf("\nArray1 [] = " ); 
    for (int i = 0; i < sizeof(array1)/sizeof(array1[0]); i++) {
        printf("%d ", array1[i]); 
    }
    printf("\n" ); 
    sort_group(array1, sizeof(array1)/sizeof(array1[0]));
    printf("\ngroupd Array1 [] = " ); 
    for (int i = 0; i < sizeof(array1)/sizeof(array1[0]); i++) {
        printf("%d ", array1[i]); 
    }
    printf("\n" ); 
#if 1
    printf("\nArray2 [] = " ); 
    for (int i = 0; i < 8; i++) {
        printf("%d ", array2[i]); 
    }
    printf("\n" ); 

    sort_group(array2, sizeof(array2)/sizeof(array2[0]));

    printf("\nGrouped Array2 [] = " ); 
    for (int i = 0; i < 8; i++) {
        printf("%d ", array2[i]); 
    }
    printf("\n" ); 


    printf("\nArray3 [] = " ); 
    for (int i = 0; i < 8; i++) {
        printf("%d ", array3[i]); 
    }
    printf("\n" ); 

    sort_group(array3, sizeof(array3)/sizeof(array3[0]));

    printf("\nGrouped Array3 [] = " ); 
    for (int i = 0; i < 8; i++) {
        printf("%d ", array3[i]); 
    }
    printf("\n" ); 
#endif
}



