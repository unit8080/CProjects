#include <stdio.h>
#include <string.h>
#include <stdbool.h>

    char *text = "eororsssdadas";
    char *patt = "dadas";
int strstrfind(char text[], char patt[])
{
    if (text == NULL && patt == NULL)
        return true; // both empty str match
    int n = strlen(text);
    int m = strlen(patt);
    if (m > n)
        return -1;
    int i, j, k;
    for (i=0; i < n-m+1; i++) 
    {
        k = i;
        for (j=0; j < m;  j++) {
            if (patt[j] != text[k++])
                break;
        }
        if (j == m) {
            printf("Found string at %d\n", i);
            return true;
        }
    }
    printf("string not found\n");
    return false;
}
int main()
{
    strstrfind(text, patt);
}
