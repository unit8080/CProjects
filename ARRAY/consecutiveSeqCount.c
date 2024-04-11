#include <stdio.h>

#define max(a, b)  (a) > (b) ? (a) : (b)
int countMaxSequence (int A[], int len)
{
    if (len <= 1)
        return len;
    int count = 1; int ans = 1;
    for (int i=0; i < len-1; i++) {
        if (A[i] + 1 == A[i+1]) {
            count++;
        } else 
            count = 1;
        ans = max(count, ans); 
    }
    return ans;
}
int main()
{
    int A[] = {5, 2, 3, -1, 4, 5, 6, 7, 8, 9};

    printf("Max Consecutive Sequence = %d \n", countMaxSequence(A, sizeof(A)/sizeof(A[0])));
}
