#include <stdio.h>


int digitSum(int n)
{
    if (n < 10)
        return n;
    return digitSum(n/10) + digitSum(n%10);
}

int main() 
{
    int n;
    scanf("%d", &n);

    printf("Sum of digit for %d = %d\n", n, digitSum(n));
}


