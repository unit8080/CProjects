#include <stdio.h>
#include <stdbool.h>

int num[] = {2, 4};
//int num[] = {2, 3, 4, 5, 6, 7};
int findMissing (int A[], int start, int end) 
{
    if (start > end)
        return -1;

    if ( A[end] == (A[start] + end - start)) return 0;

    int mid = (start + end)/2;

    if (num[mid] != (num[start] + mid - start)) {
        if (num[mid] != num[mid-1] + 1 )
            return num[mid] - 1;
        end = mid;
    } else {
        if (num[mid] + 1 != num[mid+1])
            return num[mid] +1;
        start = mid +1;
    }
    return findMissing(A, start, end);
}

bool binarySearchIter(int A[], int low, int high, int x)
{
    int mid;
    while (low <= high) {
        mid = low + (high - low)/2;
        if (A[mid] == x) {
            return true;
        } else if (A[mid] > x ) {
            high = mid -1;
        } else {
            low = mid +1;
        }
    }
    return false; // did not find
}

bool binarySearchRecur(int A[], int low, int high, int x)
{
    // base condition
    if (low > high) {
        return false;
    }
    int mid = low + (high - low)/2;
    if (A[mid] == x) {
        return true;
    } else if (A[mid] > x) {
        high = mid-1;
    } else {
        low = mid+1;
    }
    return binarySearchRecur(A, low, high, x);
}

int main()
{
    int A[] = {2, 4 , 5, 6, 9, 11, 15};
    int n = sizeof(A)/sizeof(A[0]);

    int len = sizeof(num) / sizeof(num[0]);
    for (int i = 0; i < len; i++)
        printf (" %d ", num[i]);
    printf( " missing : %d \n", findMissing(num, 0, len-1));
    getchar();

    printf("A[]= "); 
    for (int i=0; i < n; i++)
       printf("%d ", A[i]); 
    int x;
    printf("\nEnter Number : ");
    scanf("%d", &x);
    bool found = binarySearchRecur(A, 0, n-1, x);
    printf("Number %d is %s found\n", x, found ? "" : "not");
    found = false; 
    found = binarySearchIter(A, 0, n-1, x);
    printf("Number %d is %s found(I)\n", x, found ? "" : "not");
}

