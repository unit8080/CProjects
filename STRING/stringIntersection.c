#include <stdio.h>
#include <string.h>
#include <stdint.h>

char s1[] = "sadhaswqabpqrssxz";
char s2[] = "pmhqs";

void qsort (uint8_t *A, int start, int end)
{
    if (start > end)
        return;
    int pivot = end;
    int i = start;
    while (i < pivot) {
        if (A[i] >= A[pivot]) {
            uint8_t temp = A[i];
            A[i] = A[pivot -1];
            A[pivot -1] = A[pivot];
            A[pivot] = temp;
            pivot = pivot -1;
        } else {
            i++;
        }
    }
    qsort(A, start, pivot -1);
    qsort(A, pivot+1, end);
}
char * getStringIntersection (char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return NULL;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 ==0 || len2 == 0)
        return NULL;
    uint8_t *A1 = (uint8_t *) s1;
    uint8_t *A2 = (uint8_t *) s2;
    qsort(A1, 0, len1-1);
    qsort(A2, 0, len2 -1);

    char result[len2];
    int i = 0, j = 0, idx = 0;
    while (i < len1 && j < len2) {
        if (A1[i] == A2[j]) {
            result[idx++] = A1[i];
            i++; j++;
        } else if (A1[i] < A2[j]) {
            i++;
        } else {
            j++;
        }
    }
    result[idx] = '\0';
    return result;
}

int main(void)
{
    printf(" %s %s \n", s1, s2);
    printf(" %s %s : %s \n", s1, s2, getStringIntersection(s1, s2));
}

