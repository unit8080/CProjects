#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//char str1[] = "abcde\b\b";
//char str2[] = "abcc\bd\be\b";
//char str1[] = "a\bc\b";
//char str2[] = "ab\b\b";
char str1[] = "a\bbef\b\b\b"; 
char str2[] = "aef\b\b";
void parseString (char *str)
{
    if (str == NULL)
        return;
    int wridx = 0;
    int rdidx = 0;
    //printf("rdidx= %d, wridx= %d", rdidx, wridx);
    while (str[rdidx] != '\0') {
        //printf("rdidx= %d, wridx= %d", rdidx, wridx);
        if (str[rdidx] != '\b') { 
            if (wridx != rdidx)
                str[wridx] = str[rdidx];
            wridx++;  
            rdidx++;
        } else {
            if (wridx > 0) {
               wridx--;
            }
            rdidx++;
        }
    }
    str[wridx] = '\0';
    return;
}
bool compare (char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1++ != *str2++)
            return false;
        //str1++;
        //str2++;
    }
    return (*str1 == *str2);
}
bool checkStrings (char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    printf("%d %d\n", len1, len2);
    int i = len1 -1;
    int j = len2 -1;
    int count = 0;
    while (i >= 0 && j >= 0) {
        count = 0;
        while (i >= 0 && str1[i] == '\b') {
            count++;
            i--;
        }
        i = i - count;
        printf("i = %d\n", i);
        if (i >= 0 && str1[i] == '\b')
            continue;
        count = 0;
        while (j >= 0 && str2[j] == '\b') {
            count++;
            j--;
        }
        j = j - count;
        printf("j = %d\n", j);
        if (j >= 0 && str1[j] == '\b')
            continue;
        if (i >=0 && j >= 0) {
            if (str1[i] != str2[j]) {
                return false;
            } else {
               i--;
               j--;
            }
        }
    }
    return i == j;
}
int main (void)
{
    printf("a= %s\n", str1);
    printf("b= %s\n", str2);
    parseString(str1);
    parseString(str2);
    printf("Matches ? %s\n", compare(str1, str2) ? "Yes" : "No");
    printf("a=%s\n", str1);
    printf("b=%s\n", str2);
    //printf("Matches ? %s\n", checkStrings(str1, str2) ? "Yes" : "No");

}
