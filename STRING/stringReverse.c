#include <stdio.h>
#include <ctype.h>
#include <string.h>

char str1[] = ""; // empty string
char str2[] = "This is a test";
void swap (char *s1, char *s2) {char t = *s1; *s1 = *s2; *s2 = t;}
void reverseString (char *str)
{
    int len;
    if (str == NULL || (len = strlen(str)) == 0)
        return;
    int i = 0, j = len -1;
    while (i < j) {
        swap(&str[i], &str[j]);
        i++; 
        j--;
    }
    printf("%d %s \n", len, str);
    i = 0;
    j = 0;
    while (str[i] != '\0') {
        while ((str[j] != ' ') && (str[j] != '\0'))
            j++;
        int k = j -1;
        while (i < k) {
            swap(&str[i], &str[k]);
            i++; k--; 
        }
        if (str[j] == '\0')
            break;
        i = ++j;
    }
    printf("%d %s \n", len, str);
}

void reverseRecur (char *str, int l, int r)
{
    if (l >= r)
        return;
    swap(&str[l], &str[r]);
    l++; r--;
    reverseRecur(str, l, r);
}

int main (void)  // driver functions
{
    reverseString(NULL); // NULL string
    reverseString(str1); // empty string 
    reverseString(str2); 
    reverseRecur(str2, 0, strlen(str2) -1);
    printf(" %s \n", str2);
    reverseRecur(str2, 0, strlen(str2) -1);
    printf(" %s \n", str2);
}
