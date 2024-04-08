#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *readString(FILE *fp)
{
    int size = 80;
    char c;
    char *str;
    int len = 0;
    str = realloc(NULL, sizeof(char)*size);
    if (!str)
        return str;
    while(EOF != (c = fgetc(fp)) && (c != '\n')) {
        str[len++] = c;
        if (len == size) {
            str = realloc(str, sizeof(char)*(size *=2));
            if (str == NULL)
                return str;
        }    
    }
    str[len++] = '\n';
    str = realloc(str, sizeof(char)*len);
    return str;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int L[26];
    int n;
    char *str;
    char a, b;
    int x, y;
    int len;
    scanf("%d", &n);
    fgetc(stdin);
    for (int j=0; j < 26; j++)
            L[j] = 0;
    for (int i = 0; i < n; i++) {
        str = readString(stdin);
        printf("%s\n", str);
        len = strlen(str);
        len--;
        printf("length = %d\n", len);
        if ( (len % 2) != 0) {
            printf("%d\n", -1);
            continue;
        }
        int mid = len/2;
        for (x=0, y=mid; x < mid; x++, y++){
            a = str[x];
            b = str[y];
            L[a - 'a'] = L[a - 'a'] + 1;
            L[b - 'a'] = L[b - 'a'] - 1;
        }
        int changes = 0;
        for (int j=0; j < 26; j++) {
            changes += abs(L[j]);
            L[j] = 0;
        }
        printf("%d\n", changes/2);   
    }
    return 0;
}
