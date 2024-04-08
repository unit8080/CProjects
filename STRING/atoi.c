#include <stdio.h>
int atoi(const char str[])
{
    int i=0;  int val = 0;
    while (str[i] != '\0')
    {
       //val = val*10 + str[i] -'0'; 
       val = (val << 3) + (val << 1) + str[i] -'0'; 
       i++;
    }
    return val;
}
int main()
{
    char str[] = "1234";
    printf("atoi(%s) = %d \n", str, atoi(str));
}

