#include <stdio.h>

#define  MATRIX_SIZE  5

int m[MATRIX_SIZE][MATRIX_SIZE];
void printMatrix()
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf(" %2d ", m[i][j]);
        }
        printf("\n");
    }
}
void swap (int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void rotateMatrix ()
{
    int last = MATRIX_SIZE - 1;
    int level = 0;
    int totNumOfLevels = MATRIX_SIZE / 2;

    while (level < totNumOfLevels) {
        for (int i = level; i < last; ++i) {
            swap(&m[level][i], &m[i][last]);
            swap(&m[level][i], &m[last][last - i + level]);
            swap(&m[level][i], &m[last - i + level][level]);
        }
        level++;
        last--;
    }
}
int main()
{
    int count = 0;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            m[i][j] = count++;
        }
    }
    printf("\n ----------- Original Matrix --------------\n");
    printMatrix();
    rotateMatrix();
    printf("\n ----------- Rotated Matrix --------------\n");
    printMatrix();
}

