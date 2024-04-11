#include <stdio.h>
#include <stdbool.h>

bool find2sum (int A[], int n, int sum, int *i, int *j)
{
    *i = 0;
    *j = n-1; // array legnth -1
    while (*i < *j)
    {
        if (A[*i] + A[*j] == sum) {
            return true;
        } else if (A[*i] + A[*j] > sum) {
            (*j)--;
        } else {
            (*i)++;
        }
    }
    return false;
}

int main ()
{
    int A[] = { 2, 3, 5, 7, 8, 11, 15, 17, 19};
    int n = sizeof(A)/sizeof(A[0]);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("Enter sum = ");
    int sum;
    scanf("%d", &sum);
    printf("Array[] = ");
    int i, j;
    bool exists = find2sum( A, n, sum, &i, &j);
    if (exists) {
        printf("\nsum %d is found at index %d and %d\n", sum, i, j);
    } else {
        printf("\nsum %d is not found\n", sum);
    }
}
