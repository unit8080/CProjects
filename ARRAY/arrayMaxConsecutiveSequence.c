#include <stdio.h>

//int A[] = {};
int A[] = { 2,3, 1, 5, 6, 7, 8, 0,  7, 8, 9, 10, 11, 1}; // Ans = 6+8+9 = 24
//int A[] = { 2, 5, 6, 7, 0, 6, 8, 9}; // Ans = 6+8+9 = 18 
//int A[] = { 11, 2, 5, 7, 6, 8, 13, 7, 0, 6, 8, 10, 9}; // 13
//int A[] = { 14, 2, 5, 7, 6, 8, 13, 7, 0, 6, 8, 10, 9}; // 14
//int A[] = { 11, 2, 5, 7, 6, 8, 13, 7, 0, 6, 8, 10, 9, 15};  // 15
int len = sizeof(A)/sizeof(A[0]);

int findMaxConsecutiveCount (int A[], int len)
{
    if (A == NULL)
        return -1;
    if (len < 2)
        return len;
    int max = 1, count = 1;
    int i = 1;
    while (i < len) {
        if (A[i] == A[i-1] + 1) {
            count ++;
            if (max < count)
                max = count;
        } else {
            count = 1;
        }
        i++;
    }
    return max;
}

int getMaxSumOfConsecutive (int A[], int len)
{
    if (len <= 0) return -1;
    int sum = A[0];
    int max = sum;
    int i = 1;
    while (i < len) {
        if (A[i] == A[i-1] +1) {
            sum = sum + A[i];
            if (sum > max)
                max = sum;
        } else {
            sum = A[i];
            if (sum > max)
                max = sum;
        }
        i++;
    }
    return max;
}
int main()
{
    for (int i = 0; i < len; i++) printf(" %d ", A[i]);
    printf("\n %d\n", getMaxSumOfConsecutive(A, len));
    printf("\n %d\n", findMaxConsecutiveCount(A, len));
}
