#include <stdio.h>
//int arr[] = {1,2,3,4,5,101,102,103,104,105};
int arr[] = {1,2,3,4,5,101,102,103,104};
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp; 
}
void suffle (int *arr, int len) 
{
    int start = 1;
    int end;
    int mid; 
    if (len %2 == 0) {  // for even
        end = len - 1; 
        mid = len/2;   
    } else {           // for odd
        end = len;
        mid = len/2 + 1;
    }
    while (start < end) {
        for (int i = start, j = mid; i < mid && j < end; i++, j++)
             swap(&arr[i] , &arr[j]);
        start++;
        end--;
    }
}
int main(void)
{
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    suffle(arr, sizeof(arr)/sizeof(int));
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

