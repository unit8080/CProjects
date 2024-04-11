#include <stdio.h>
// Inputs
//int A[] = {10, 2, 5, 15, 6, 10, 3};
int A[] = {10, 2, 5, 15, 6, 10};

int findEquilibrium (int A[], int len)
{
    int i = 0;
    int j = len -1;
    int lh = A[i];
    int rh = A[j];

    while (i < j) {
        if (lh == rh) {
            lh += A[i];
            rh += A[i];
            i++; 
            j--;
        } else if (lh < rh) {
            lh += A[i];
            i++;
        } else {
            rh += A[j];
            j--;
        }
    }
    return i;
}

int main()
{
    int len = sizeof(A)/sizeof(A[0]);
    int idx = findEquilibrium(A, len);
    for (int i =0; i < len; i++)
        printf(" %d", A[i]);
    printf("\n Equilirium index : %d, value : %d\n", idx, A[idx]);
}
