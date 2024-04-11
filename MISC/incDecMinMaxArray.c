#include <stdio.h>
#include <stdbool.h>
// this find the min and max number in given array
// with increasing then decreasing number
void findMinMax(int A[], int sz, int *min, int *max)
{
    int low, high, mid;
    low = 0; 
    high = sz -1;
    while (low <= high) {
        mid = low + (high - low)/2;
        if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1]) {
            *max = A[mid];// found max
            break;
        } else if (A[mid] < A[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    *min = (A[0] < A[sz-1] ? A[0] : A[sz - 1]);
}
int main ()
{
    int A[] = { 2, 4, 6, 8, 9, 10, 5, 4, 3, 0 };
    int sz = sizeof(A)/sizeof(A[0]);
    int min, max;
    printf("A[] = ");
    for (int i=0; i < sz; i++) printf("%d ", A[i]);
    printf("\n");
    findMinMax(A, sz, &min, &max);
    printf("Min = %d, Max = %d\n", min, max);
}
