#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int longestPrefix(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) 
            break;
        i++;
    }
    return i;
}
int main()
{
    char str1[] = "xabc";
    char str2[] = "xabcsdf";
    printf("str1[] = %s\n", str1);
    printf("str2[] = %s\n", str2);
    printf("length of LCP = %d\n", longestPrefix(str1, str2));
}
