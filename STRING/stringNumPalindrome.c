#include <stdio.h>
#include <stdbool.h>

bool isPalindrome (int x)
{
    int num = x;
    int new = 0;
    while (num != 0) {
        new  = new *10 + num % 10;
        num = num/10;
    }
    if (new == x)
        return true;
    else 
        return false;
}

int main(void)
{
    int x = -232;
    printf(" %d\n", isPalindrome(x));
}
