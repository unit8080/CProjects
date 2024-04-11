#include <stdio.h>
#include <stdlib.h>

void suffleArray(int A[], int len)
{
    if (A == NULL || len < 2)
        return;
    for (int i = 0; i < len; i++)
    {
        int index = (random()%(len - i)) + i; //random(i, len);
        int t = A[i];
        A[i] = A[index];
        A[index] = t;
    }
}
int main ()
{
    int A[] = { 2, 4, 2, 5, 6, -1, 4, 3, 8, 9};
    int len = sizeof(A)/sizeof(A[0]);
    printf(" \nbefore suffle A[] = ");
    for (int i = 0; i < len; i++)
        printf(" %d ", A[i]);
    printf("\n");
    int n =0;
    while ( n < 10) {
       suffleArray(A, len); 
       printf(" \nAfter suffle A[%d] = ", n);
       for (int i = 0; i < len; i++)
           printf(" %d ", A[i]);
       printf("\n");
       n++;
    }
}
