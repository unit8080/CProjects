#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//char str[] = "(((";
//char str[] = ")))";
//char str[] = "ab)(cd)e";
//char str[] = "ab(cd)e";
char str[] = "()ab)(((cd))(e)";  // ()ab(cd)e 
char * removeInvalidParen (char str[])
{
    int opened = 0, closed = 0, oi = 0, ci =0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '(') {
            opened++; oi = i;
        }
        if (str[i] == ')') {
            closed++;
            ci= i;
        }
        if (closed > opened) {
            str[ci] = '.'; closed--;
        }
        i++;
    } // printf("\n opened %d closed %d oi %d ci %d\n",
      // opened, closed, oi, ci);
    int d;
    if (opened > closed) d = opened -closed;
    i = oi;
    while (i >=0 && d > 0) // delete extra open paren
    {
        if (str[i] == '(')
        {
            str[i] = '.';
            d -= 1;
        }
        i -= 1;
    }
    i = 0; int j = 0;
    while (str[i] !='\0') { // skip DELIMITER
        if (str[i] != '.')
            str[j++] = str[i]; 
        i++;
    }
    str[j] = '\0';
    return str;
}
int main(void)
{
    printf("\n %s : ", str);
    char * str1 = removeInvalidParen(str);
    printf("\n %s : ", str1);
}
