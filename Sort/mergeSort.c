#include <stdio.h>

int A[] = { 5, 3, 6, 2, 0, 8, 4, 9, 10, 3, 2};
//int A[] = { 2, 4, 1, 6, 8, 4, 9, 10 };
int len = sizeof(A)/sizeof(A[0]);

void mergeHalves (int A[], int temp[], int leftstart, int rightend)
{
    int leftend = (leftstart + rightend) / 2;
    int rightstart = leftend + 1;

    int left = leftstart;
    int right = rightstart;
    int index = leftstart;

    while (left <= leftend && right <= rightend) {
        if (A[left] <= A[right]) {
            temp[index] = A[left];
            left ++;
        } else {
            temp[index] = A[right];
            right ++;
        }
        index ++;
    }
    while (left <= leftend) {
        temp[index] = A[left];
        index ++; left ++;
    }
    while (right <= rightend) {
        temp[index] = A[right];
        right ++;
        index ++;
    }
    int i = leftstart;
    while (i <= rightend) {
        A[i] = temp[i];
        i++;
    }
}
void mergeSortRecur(int A[], int temp[], int leftstart, int rightend)
{
    if (leftstart >= rightend)
        return;
    int mid = (leftstart + rightend) / 2;
    mergeSortRecur(A, temp, leftstart, mid);
    mergeSortRecur(A, temp, mid+1, rightend);
    mergeHalves(A, temp, leftstart, rightend);
}
void mergeSort( int A[], int len)
{
    int temp[len]; // temp array
    mergeSortRecur(A, temp, 0, len -1);
}

int main (void)
{
    printf("\n");
    for (int i = 0; i < len; i++) printf(" %d ", A[i]); 
    printf("\n");
    mergeSort(A, len);
    for (int i = 0; i < len; i++) printf(" %d ", A[i]); 
}
