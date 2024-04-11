#include <stdio.h>
//int A[] = {2,2,3,3,4,4,5,5};
//int A[] = {2,2,2,3,3,4,5,5,5,6,7,7, 8};
int A[] = {2,3,4,5,6,7};
int len = sizeof(A)/sizeof(A[0]);

int removeDupsSorted (int A[], int len)
{
    if (len < 2) return 0;
    int j;
    int idx = 1;
    int i = 1;
    while (i < len) {
        if (A[i] == A[i-1]) {
            j = i;
            i++;
            while (i < len && A[i] == A[j]) 
                i++;
            if (i < len) {
                A[idx++] = A[i]; // move-up next value
            }
            i++;
        } else {
            A[idx++] = A[i];
            i++;
        }
    }
    return idx;
}

int main(void)
{
    printf("\n Before: ");
    for (int i = 0; i < len; i++) printf(" %d ", A[i]);
    int l = removeDupsSorted(A, len);
    printf("\n After: ");
    for (int i = 0; i < l; i++) printf(" %d ", A[i]);
    printf("\n");
}
