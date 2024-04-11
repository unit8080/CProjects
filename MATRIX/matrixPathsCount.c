#include <stdio.h>

// Path from cell 1,1 to cell m,n 
// can go either right or down.
// total path to reach cell m,n

#define M 4
#define N 4

char mat[M][N];
int totalPathsMatrix (int m, int n)
{
    if ((m == 1) || (n == 1))
        return 1;

    return totalPathsMatrix(m-1, n) + totalPathsMatrix(m, n-1);
}

int pathCounts (int m, int n)
{
    int count[M][N];
    for (int i=0; i < m; i++)
        count[i][0] = 1;
    for (int j=0; j < n; j++)
        count[0][j] = 1;

    for (int i=1; i < m; i++)
        for (int j=1; j < n; j++)
            count[i][j] = count[i-1][j] + count[i][j-1];

    return count[m-1][n-1];
}

int main()
{
    printf("\n Total paths in matrix %d x %d : %d (%d)\n", M, N, totalPathsMatrix(M, N), pathCounts(M, N));
}


