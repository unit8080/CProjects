#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int A[] = {11, 4, 3, 10, 14, 7, 9, 3, 2, 8, 1};
int len = sizeof(A)/sizeof(A[0]);
int kthL[20] = {0};
void swap (int *a, int *b)
{
    int temp = *a; *a = *b; *b = temp;
}
void heapifyMin (int A[], int len, int root)
{
    if (root >= len)
        return;
    int min = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < len && A[left] < A[min])
        min = left;
    if (right < len && A[right] < A[min])
        min = right;
    if (min != root) {
        swap(&A[root], &A[min]);
        heapifyMin(A, len, min);
    }
}
void heapifyMax (int A[], int len, int root)
{
    if (root >= len)
        return;
    int max = root; 
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < len && A[left] > A[max])
        max = left;
    if (right < len && A[right] > A[max])
        max = right;

    if ( max != root) {
        swap(&A[max], &A[root]);
        heapifyMax(A, len, max);
    }
}
void heapBuild (int A[], int len)
{
    for (int i = len/2; i >= 0; i--)
        heapifyMax(A, len, i);
}
void heapSort (int A[], int len)
{
    for (int i = len-1; i > 0; i--)
    {
        swap(&A[i], &A[0]);
        heapifyMax(A, i, 0);
    }
}
void insertHeap (int A[], int *len, int data, bool minHeap) 
{
    A[(*len)] = data;
    *len = *len +1;
    for (int i = *len/2; i >=0 ; i--)
        if (minHeap) 
            heapifyMin(A, *len, i);
        else
            heapifyMax(A, *len, i);
}
void deleteHeap (int A[], int *len, bool minHeap)
{
    int data = A[(*len)- 1];
    *len = *len -1;
    A[0] = data;
    if (minHeap) 
        heapifyMin(A, *len, 0);
    else 
        heapifyMax(A, *len, 0);
}
void rebalance(int maxHeap[], int *maxSz, int minHeap[], int *minSz)
{
    if (abs(*minSz - *maxSz) <= 1) {
        return;
    } else {
        if (*minSz > *maxSz) {
            int data = minHeap[0];
            deleteHeap(minHeap, minSz, true);
            insertHeap(maxHeap, maxSz, data, false);
        } else {
            int data = maxHeap[0];
            deleteHeap(maxHeap, maxSz, false);
            insertHeap(minHeap, minSz, data, true);
        }
    }
}
void getMedian (int A[], int len) 
{
    if (len < 1 )
        return;
    int maxHeap[len/2 +1];
    int minHeap[len/2 +1];
    double median[len];

    int minSz = 0, maxSz = 0; 
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            insertHeap(minHeap, &minSz, A[i], true);
            median[i] = A[i];
        } else {
            if (A[i] >= minHeap[0]) {
                insertHeap(minHeap, &minSz, A[i], true);
            } else {
                insertHeap(maxHeap, &maxSz, A[i], false);
            }
            rebalance(maxHeap, &maxSz, minHeap, &minSz);
            if (minSz > maxSz) {
                median[i] = minHeap[0];
            } else if (minSz < maxSz) {
                median[i] = maxHeap[0];
            } else {
                median[i] = (double) (maxHeap[0] + minHeap[0])/2;
            }
        }
        for(int j = 0; j <= i; j++)
            printf(" %d ", A[j]);
        printf(" maxSz: %d minSz: %d ", maxSz, minSz);
        printf (" : %.2f \n", median[i]);
    }
}
int KthLargest (int A[], int *len, int data, int kth)
{
    if (*len == 0) { // first element 
        A[*len] = data;
        *len = *len +1;
    } else if (*len < kth) {
        A[*len] = data;
        *len = *len + 1;
        for (int i = *len/2; i >=0; i--)
            heapifyMin(A, *len, i);
    } else if (data > A[0]) {
        A[0] = data; // evict root=0
        heapifyMin(A, *len, 0); 
    }
    if (*len == kth) return A[0];
    else return -1;
}

int main()
{
    for (int i=0; i < len; i++)
        printf(" %d ", A[i]);
    printf("\n");
    getMedian(A, len);
    getchar();
    printf("\n");  heapBuild(A, len);
    for (int i=0; i < len; i++)
        printf(" %d", A[i]);
    printf("\n"); heapSort(A, len);
    for (int i=0; i < len; i++)
        printf(" %d ", A[i]);

    int kth = 4;
    int size = 0;
    for (int i = 0; i < len; i++) {
        printf("\nKth(%d) Largest (insert %d) : %d -->  ", kth, A[i],
                KthLargest(kthL, &size, A[i], kth));
        for (int j = 0; j < size; j++)
            printf(" %d ", kthL[j]);
        printf("\n");
    }
}
