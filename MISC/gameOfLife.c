#include <stdio.h>
#include <stdlib.h>
int arr[4][3] = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
int boardRowSize = 4;
int boardColSizes = 3;
// output : {0 0 0 },{1 0 1 },{0 1 1 },{0 1 0 }
int neighbors(int **board, int i, int j, int r, int c) {
    int count = 0;
    if ((i-1) >= 0) // Up
        count += board[i-1][j] ? 1 : 0;
    if ((i+1) < r) // Down
        count += board[i+1][j] ? 1 : 0;
    if ((j-1) >= 0) // back
        count += board[i][j-1] ? 1 : 0;
    if ((j+1) < c) // front
        count += board[i][j+1] ? 1 : 0;
    // diagonal
    if (((i-1) >=0)  && ((j-1) >= 0)) 
        count += board[i-1][j-1] ? 1 : 0;
    if (((i+1) < r) && ((j+1) < c)) 
        count += board[i+1][j+1] ? 1 : 0;
    if (((i-1) >=0) && ((j+1) < c))
        count += board[i-1][j+1] ? 1 : 0;
    if (((i+1) < r) && ((j-1) >= 0))
        count += board[i+1][j-1] ? 1 : 0;
    return count;
}
void gameOfLife(int** board, int boardRowSize, int *boardColSizes) {
    int **p;
    p = (int **) malloc(boardRowSize * sizeof(int *));
    for (int i = 0; i < boardRowSize; i++) {
        p[i] = (int *) calloc(*boardColSizes, sizeof(int));
    }
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < *boardColSizes; j++) {
            int count = neighbors(board, i , j, boardRowSize, *boardColSizes);
            if ((board[i][j]) == 0) {
                if (count == 3)
                    p[i][j] = 1;
            } else {
                if (count < 2)
                    p[i][j] = 0;
                else if (count > 3)
                    p[i][j] = 0;
                else if (count == 2 || count == 3)
                    p[i][j] = 1;
            } 
        }
    } // copy back to board
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < *boardColSizes; j++) {
            board[i][j] = p[i][j];
        }
    } // free p malloc's  here.
}
int main (void)
{
    int **board;
    board = (int **) malloc(boardRowSize * sizeof(int *));
    for (int i = 0; i < boardRowSize; i++) {
        board[i] = (int *) calloc(boardColSizes, sizeof(int));
    }
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSizes; j++) {
            board[i][j] = arr[i][j];
        }
    }   
    for (int i = 0; i < boardRowSize; i++) {
        printf("{");
        for (int j = 0; j < boardColSizes; j++) {
            printf("%d ", board[i][j]);
        }
        printf("}");
        printf("\n");
    }   
    gameOfLife(board, boardRowSize, &boardColSizes);
    for (int i = 0; i < boardRowSize; i++) {
        printf("{");
        for (int j = 0; j < boardColSizes; j++) {
            printf("%d ", board[i][j]);
        }
        printf("}");
        printf(",");
    }   
}
