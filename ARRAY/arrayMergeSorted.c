#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void mergeSortedArray (int A[], int B[], int F[], int a, int b, int f)
{
    int i=0; int j=0; int k=0;
    while ((i < a) && (j < b)) {
        if (A[i] <= B[j]) {
            F[k] = A[i];
            k++;
            i++;
        } else {
            F[k] = B[j];
            k++;
            j++;
        }
    }
    while (i < a) {
        F[k] = A[i];
        k++;
        i++;
    }
    while (j < b) {
        F[k] = B[j];
        k++;
        j++;
    }
}
#define ARRAY_SIZE(a)  (sizeof(a)/sizeof(a[0]))
int main()
{
    int A[] = { 3, 5, 7, 9, 10 };
    int B[] = { 4, 6, 9, 12, 34};

    int a = ARRAY_SIZE(A);
    int b = ARRAY_SIZE(B);
    int f = a + b;

    int  *F = (int *) malloc(sizeof(int)*f);
    mergeSortedArray(A, B, F, a, b, f);

    for (int i=0; i < f; i++) {
        printf("%d ", F[i]);
    }
}
