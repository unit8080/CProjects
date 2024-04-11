#include <stdio.h>

int main()
{
    int A = -10;
    int B = 20;

    printf("A= %d B= %d\n", A, B);
    A ^=B; B ^=A; A ^=B;
    printf(" A= %d B= %d\n", A, B);
}

