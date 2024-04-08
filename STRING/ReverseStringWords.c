#include <stdio.h>
#include <string.h>

void reverse( char str[], int start, int end)
{
    for (int i=0; i < (end - start)/2; i++)
    {
        char temp = str[start + i];
        str[start + i] = str[end -i -1];
        str[end -i - 1] = temp;
    }
}
void reverseString(char str[], int len)
{
    int i, j;
    reverse(str, 0, len);
    for (i= 0, j = 0; j <= len; j++)
    {
        if (j == len || str[j] == ' ') {
            reverse(str, i, j);
            i = j + 1;
        }
    }
}
int main ()
{
    char str[] = "This is my notebook mac";
    int len = strlen(str);
    printf("Given String = %s\n", str);
    reverseString(str, len);
    printf("Reversed String = %s\n", str);
}

