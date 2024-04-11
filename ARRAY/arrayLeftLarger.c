#include <stdio.h>
int A[] = {1, 4, 5, 6, 7};
//int A[] = {2, 4, 1, 3, 5, 8, 4, 0}; // Ans = 2, 4, 5, 8

void printLargerThanLeft (int A[], int len)
{
    int max = -1;
    int i =0;
    while (i < len) {
        if (A[i] > max) {
            max = A[i];
            printf(" %d ", A[i]);
        }
        i++;
    }
}
int main ()
{
    int len = sizeof(A)/sizeof(A[0]);

    printLargerThanLeft(A, len);
}
