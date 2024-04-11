#include <stdio.h>
// Kadane's Algorithm.
// It assumes there is at least one posistive number.
#define max(a, b) (a) > (b) ? (a) : (b)

int main ()
{
    int A[] = { 2, -3, 2, -5, 7, 6, -1, -4, 11, -23}; // 7+6+(-1)+(-4)+11 = 19
    int sum = 0, ans = 0;
    int n = sizeof(A)/sizeof(A[0]);

    for (int i = 0; i < n; i++)
    {
        if (sum + A[i] < 0) {
            sum = 0;
        } else {
            sum += A[i];
        }
        ans = max(ans, sum);
    }
    printf("Max sum subArray = %d\n", ans);
}
