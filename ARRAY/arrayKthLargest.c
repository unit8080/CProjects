#include <stdio.h>

int A[] = { 5, 3, 7, 3, 7 , 2, 1}; // {1, 2, 3, 3, 5, 7, 7}

void findKth (int A[], int start, int end, int k) 
{
    if (start > end)
        return;
    int pivot = end;
    int i = start;
    while (i < pivot) {
        if (A[i] > A[pivot]) {
            int temp = A[i];
            A[i] = A[pivot -1];
            A[pivot -1] = A[pivot];
            A[pivot] = temp;
            pivot = pivot -1;
        } else {
            i = i+1;
        }
    }
    if (pivot < k)
        findKth(A, pivot+1, end, k);
    else if (pivot > k)
        findKth(A, start, pivot -1, k);
    else  
        printf("pivot = %d, %d\n", pivot, A[pivot]);
}
int main(void) 
{
    int kth = 2;
    int len = sizeof(A)/sizeof(A[0]);
    //findKth(A, 0, len-1, len - kth);
    findKth(A, 0, len-1,  kth-1);
}
