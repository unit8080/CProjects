#include <stdio.h>
#include <stdbool.h>
int circularSearch ( int A[], int len, int x)
{
    int low = 0, high = len -1;

    while (low <= high) {
        int mid = low + (high -low)/2;
        if (A[mid] == x)
            return mid;
        if (A[mid] <= A[high]) { // right is sorted
            if (A[mid] < x && A[high] >= x) {
                low = mid + 1;
            } else {
                high = mid -1;
            }
        } else { // left is sorted
            if (A[mid] > x && x >= A[low]) {
                high = mid -1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int rotation_index (int A[], int N)
{
    int low = 0;
    int high = N -1;
    int mid;
    while (low <= high) {
        // sorted array is not rotated, already sorted
        if (A[low] <= A[high]) 
            return low;
        mid = low + (high-low)/2;
        int next = (mid + 1) % N;
        int prev = (mid + N - 1) % N;
        if ((A[mid] <= A[next]) && (A[mid] <= A[prev] )) {
            return mid; // found rotation index
        } else if (A[mid] <= A[high]) {
            high = mid -1;
        } else if (A[mid] >= A[low]) {
            low = mid +1;
        }
    }
    return -1;
}
bool binarySearch (int A[], int low , int high, int t)
{
   int mid;
    while (low <= high) {
        mid = low + (high -low)/2;
        if (A[mid] == t) {
            return true;
        } else if (t > A[mid]) {
            low = mid +1;
        } else {
            high = mid -1;
        }
    }
    return false;
}
int main ()
{
    int A[] = { 5, 6, 7, 8, 9, 2, 3, 4};
    int n = sizeof(A)/sizeof(A[0]);

    int x = 6;
    int tidx = circularSearch(A, n, x);
    printf("Number %d @ %d\n", x, tidx);
    getchar();
    // rotation index 
    int r = rotation_index(A, n);
    printf("rotation index = %d\n", r);
    int target = 2;
    bool found = false;
    if (target < A[r]) { // less than low
        found = false;
    } else if (target > A[(r -1 + n)%n]) { // greater than high
        found = false;
    } else if (target <= A[n-1]) {
        found = binarySearch(A, r, n-1, target);
    } else { 
        found = binarySearch(A, 0, r-1, target);
    }
    printf("Number %d is %s\n", target, found ? "Found" : "Not Found");
}
