#include <stdio.h>
#include <string.h>

void swap (char *str, int start, int end)
{
    char tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;
}
void reverse (char *str, int start, int end)
{
    while (start < end) {
        swap(str, start, end);
        start++;
        end--;
    }
}
void reverseWords (char *str)
{
    if (str == NULL)
        return;
    int len = strlen(str);
    if (len < 2)
        return;
    int start = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ' && i > 0) {
            reverse(str, start, i-1);
            start = i+1;
        } else if (i == len-1) {
            reverse(str, start, len-1);
        }
    }
    reverse(str, 0, len-1);
}
int main (void)
{
    char str[] = "This is a string";
    printf(" %s\n", str);
    reverseWords(str);
    printf(" %s\n", str);
}
