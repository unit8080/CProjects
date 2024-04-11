#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void rotateArray(int* A, int n1, int B, int *len)
{
    //uint32_t *ret = (uint32_t *) malloc(n1 * (sizeof(uint32_t)));
    int xyz[8];
    *len = n1;
    printf("n1 = %d\n", n1);
    printf("B = %d\n", B);
    if (B >= n1)
        B = B % n1;
    printf("B = %d\n", B);
    int i;
    for (i = 0; i < (n1-B); i++) {
        xyz[i] = A[(i + B)];
        printf("%d ", xyz[i]);
    }
    for (i = 0; i < B; i++) {
        xyz[(B+i)] = A[i];
        printf("%d ", xyz[(B+i)]);
    }
    for (i = 0; i < n1; i++)
        printf("%d ", xyz[i]);
}
int main()
{
    int A[] = { 28, 68, 100, 90, 46, 58, 54, 74 };
    int sz = sizeof(A)/sizeof(A[0]);
    for (int i = 0; i < sz; i++) printf("%d ", A[i]);
    printf("\n");
    int len;
    rotateArray(A, sz, 78, &len);
    printf("\n");
    printf("len = %d\n", len);
    //for (int i = 0; i < len; i++) printf("%d ", B[i]);
    //free(B);
    return 0;
}

