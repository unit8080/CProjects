#include <stdio.h>

#define M 3
#define N 3
int mat[M][N];
int paths[M+N];

void printMat (int *mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %d", *(mat + i*n + j));
        printf("\n");
    }
    printf("\n");
}

void printPathsUtil (int *mat, int i, int j, int m, int n, int *paths, int pi)
{
    if (i == m -1) {
        for (int k = j; k < n; k++)
            paths[pi + k - j] = *((mat + i*n) + k);
        for (int k = 0; k < pi + n - j; k++)
            printf(" %d", paths[k]);
        printf("\n");
        return;
    }
    if (j == n -1) {
        for (int k = i; k < m; k++)
            paths[pi + k - i] = *((mat + k*n) + j);
        for (int l = 0; l < pi + m - i; l++)
            printf(" %d", paths[l]);
        printf("\n");
        return;
    }
    paths[pi] = *((mat + i*n) + j);
    printPathsUtil(mat, i+1, j, m , n, paths, pi + 1);
    printPathsUtil(mat, i, j+1, m , n, paths, pi + 1);
}

void printPaths (int *mat, int m, int n)
{
    printPathsUtil(mat, 0, 0, m, n, paths, 0);
}

int main ()
{
    int c = 1;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = c++;

    printMat(*mat, M, N);
    printPaths(*mat, M, N);
}

