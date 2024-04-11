#include <stdio.h>
#define M 4
#define N 5
int mat[4][5] = { {1, 0, 1, 0, 1},
                  {1, 0, 0, 0, 0},
                  {0, 1, 0, 0, 0},
                  {0, 0, 0, 1, 0} };
void getLonelyPixel (int mat[M][N], int row, int col)
{
    int rowc[M]= {0,0,0,0};
    int colc[N]= {0,0,0,0,0};

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
             rowc[r] += mat[r][c];
    for (int c = 0; c < col; c++)
        for (int r = 0; r < row; r++)
             colc[c] += mat[r][c];
    for (int r = 0; r < row; r++) {
        if (rowc[r] != 1)
            continue;
        for (int c = 0; c < col; c++) {
            if (colc[c] == 1 && mat[r][c] == 1)
                printf("row : col %d %d\n", r, c);
        }
    }
    return;
}
int getCellSize (int mat[M][N], int row, int col, int r, int c)
{
    static int count0 = 0;
    static int count1 = 0;
    static int count2 = 0;
    static int count3 = 0;
    count0++;
    if (r < 0 || r >= row || c < 0 || c >=col)
        return 0;
    if (mat[r][c] == 0)
        return 0;
    int size = 1;
    mat[r][c] = 0;
    count1++;
    for (int i = r -1; i <= r+1; i++) {
        for (int j = c-1; j <= c+1; j++)
        {
            count2++;
            if (i != r || j != c) {
                count3++;
                size = size + getCellSize(mat, row, col, i, j);
            }
        }
    }
    printf("\n0. Times invoked : %d\n", count0);
    printf("1. Times invoked :    %d \n", count1);
    printf("2. Times invoked :    %d \n", count2);
    printf("3. Times invoked :    %d \n", count3);
    return size;
}
int getMaxCellSize (int mat[M][N], int row, int col)
{
    int maxcells = 0;
    int clusters = 0;
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c ++)
        {
            if (mat[r][c] == 1) {
                clusters++;
                int size = getCellSize(mat, row, col, r, c);
                if (size > maxcells)
                    maxcells = size;
            }
        }
    printf(" Clusters %d \n", clusters);
    return maxcells;
}
int main (void)
{
    getLonelyPixel(mat, M, N);
    int maxregion = getMaxCellSize(mat, M, N);
    printf("%d\n", maxregion);
}
