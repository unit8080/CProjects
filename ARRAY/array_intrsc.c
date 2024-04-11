/*
 * (C) Sanjeev Singh,  April 2013
 *
 * Find the intersection for given two array. Both arrays are 
 * Asorted in increasing oder.
 *
 * Example: For {1,2,3,4} and {2,3,4,5}, intersecion is {2,3,4}.
 */
#include <stdio.h>
#include <stdlib.h>
/* Two arrays */
int A[] = {1, 2, 3, 4, 6, 8, 13};
int B[] = {2, 3, 4, 5, 11, 13};
void array_union(int A[], int B[], int m, int n)
{
    int i=0, j=0;
    while (i < m && j < n) {
        if ( A[i] == B[j]) {
            printf(" %d ", A[i]);
            i++; j++;
        } else if (A[i] < B[j]) {
            printf(" %d ", A[i]);
            i++;
        } else {
            printf(" %d ", B[j]);
            j++;
        }
    }
    while (i < m) {
        printf(" %d ", A[i]);
        i++;
    }
    while (j < n) {
        printf(" %d ", B[j]);
        j++;
    }
}
void array_intrsc(int A[], int B[], int m , int n)
{
    int i=0, j=0;
    while (i < m && j < n) {
        if ( A[i] == B[j] ) {
            printf(" %d ", A[i]);
            i++;
            j++;
        } else if ( A[i] > B[j] ) {
            j++;
        } else {
            i++;
        }
    }
}
int binary_search (int arr[], int size, int num)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start)/2;
        if (num == arr[mid]) {
            return mid; /* found */
        } else if (num > arr[mid]) { 
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1; /* not found */
}
int main (int argc, char *argv[])
{
    int found;
    int num;
    int m = sizeof(A)/sizeof(A[0]);
    printf("\nA[] = ");
    for (int i = 0; i < m; i++)
        printf(" %d, ", A[i]); 
    int n = sizeof(B)/sizeof(B[0]);
    printf("\nB[] = ");
    for (int i = 0; i < n; i++)
        printf(" %d, ", B[i]); 

    printf("\nArray Union : ");
    array_union(A, B, m, n);
    printf("\nArray Intersection : ");
    array_intrsc(A, B, m, n);
    printf("\n Enter number : ");
    scanf("%d", &num);
    while (num != 0) {
        found = binary_search(A, m, num);
        printf("\nnumber %d  %s found at index %d\n", num, 
                found == -1 ? "not" : "", found);
        printf("\n Enter number : ");
        scanf("%d", &num);
    }
}
