#include <stdio.h>
#include <string.h>

char str[] = "10000012111001111"; // max sum or prod

int maxSumRProd (char str[])
{
    if (str == NULL || str[0] == '\0')
        return -1;
    int i = 0;
    int result = str[i++] - '0'; 
    while (str[i] != '\0') {
        int n = str[i] - '0';
        if (result == 0 || result == 1 || n == 0 || n == 1)
            result += n; 
        else 
            result *= n;
        i++;
    }
    return result;
}
int main (void)
{
    printf(" %s , %d \n", str, maxSumRProd(str));
}



