#include <stdio.h>
#include <stdbool.h>

#define M 6
#define N 6
// Symbols:
// '.' = open
// '#' = blocked
// 'S' = start
// 'G' = goal
// '+' = path
// 'x' = bad path
char maze[M][N] = {
    "S...##",
    "#.#...",
    "#.##.#",
    "..#.##",
    "#...#G",
    "#.#..."
};
bool find_path (int m, int n)
{
    if (m < 0 || m > M -1 || n < 0 || n > N -1) return false;

    if (maze[m][n] == 'G') return true;
    if (maze[m][n] != '.' && maze[m][n] != 'S') return false;

    maze[m][n] = '+'; // mark as valid cell
    // right 
    if (find_path(m, n+1) == true) return true;
    // down
    if (find_path(m+1, n) == true) return true;
    // up
    if (find_path(m-1, n) == true) return true;
    // left
    if (find_path(m, n-1) == true) return true;
    // mark bad cell
    maze[m][n] = 'x';
    return false;
}
void print_maze (void)
{
    for (int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf(" %c ", maze[i][j]);
        printf("\n");
    } printf("\n");
}
int main (void)
{
    print_maze();
    if (find_path(0,0) == true)
        printf(" Sucess \n");
    else
        printf(" Failed \n");
    print_maze();
}
