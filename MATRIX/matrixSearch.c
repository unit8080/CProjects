#include <stdio.h>

#define M 4
#define N 5
int search (int mat[][N], int m, int n, int x)
{
    int i = 0; int j = n-1; // top-right elem
    while (i < m && j >= 0) {
        if (x == mat[i][j]) {
            printf(" %d, %d \n", i, j);
            return 0;
        } else if (x < mat[i][j]) {
            j = j-1;
        } else {
            i = i+1;
        }
    }
    return -1;
}

int main (void)
{
    int m = M;
    int n = N;
    int mat[][N] = {{ 2,  4,  6,  8, 11 },
                    { 3,  5,  7,  9, 12 },
                    { 7, 11, 14, 15, 17 },
                    { 9, 16, 19, 21, 23 }};
    int x = 21;
    search(mat, m, n, x);
}

