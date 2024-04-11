#include <stdio.h>
#include <iostream>

using namespace std;
// in-place sorting algorithm. O(nlogn) worst case O(n2)
// partition is an arrangement such that elements left
// to pivot is smaller and right to pivot is larger.
int partition(int A[], int start, int end)
{
    int pivot = A[end];         // pick right most element
    int partitionIndex = start; // partitionIndex initialized to "start"
    for (int i = start; i < end; i++) {
        if (A[i] <= pivot) {
            swap(A[i], A[partitionIndex]);
            partitionIndex = partitionIndex + 1;
        }
    }
    swap(A[partitionIndex], A[end]);
    return partitionIndex;
}
void qsort(int A[], int start, int end)
{
    // base case
    if (start < end) {
        int pIndex = partition(A, start, end);
        qsort(A, start, pIndex-1);
        qsort(A, pIndex+1, end);
    }
}
int main()
{
    int A[] = {7, 3, 2, 1, 5, 8, 6, 4};
    int n = sizeof(A)/sizeof(A[0]);

    printf("size=%d\n", n);
    printf("A=");
    for(int i=0; i < n; i++)
        printf(" %d ", A[i]);
    qsort(A, 0, n-1);
    printf("\nA=");
    for(int i=0; i < n; i++)
        printf(" %d ", A[i]);
}
