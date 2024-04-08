#include <stdio.h>
#include <string.h>
#include <stdint.h>

char *s1 = NULL;
char s2[]  = "";
char s3[]  = "  This is a test. ";
char s4[]  = " word ";
char s5[]  = "     ";

void swap (char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
void reverseString (char *s, int start, int end)
{
    while (start < end) {
        swap(&s[start], &s[end]);
        start++;
        end--;
    }
}
int main (void)
{
    char *str = s3;
    printf(" %s : ", str); 
    if (str == NULL || strlen(str) == 0)
        return 0;
    reverseString(str, 0, strlen(str) -1);
    printf(" %s \n ", str);  
    int i = 0;
    while (str[i] != '\0') {
        while ((str[i] == ' ' || str[i] == '.') && str[i] != '\0' ) i++;
        if (str[i] == '\0') break;
        int start = i;
        while (str[i] != ' ' &&  str[i] != '\0') i++;
        int end = i - 1;
        reverseString(str, start, end);
    }
    printf(" %s \n ", str);  
}

