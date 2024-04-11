#include <stdio.h>

void hindex(int A[], int len)
{
    int low, high, mid;
    low = 0; high = len-1;
    while (low <= high) {
        mid = low + (high - low)/2;
        if ((A[mid] >= mid+1) && (A[mid+1] < mid+2)) {
            printf("h-index = %d\n", mid+1);
            return;
        } else if (A[mid] >= mid+1) {
            low = mid + 1;
        } else {
            high = mid -1;
        }
        printf("Low = %d, mid = %d, high = %d \n", low, mid, high);
    }
    printf("No valid h-index\n");
    return;
}
int main()
{
    int A[] = {10, 8, 5, 4, 3};  // h-index = 4
    int B[] = {25, 8, 5, 3, 3};  // h-index = 3
    hindex(A, 5);
    hindex(B, 5);
}

