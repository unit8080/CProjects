#include <stdio.h> 
#include <string.h>
void removeSpaces (char *str)
{
    if (str == NULL)
        return;
    int len = strlen(str);
    if (len < 2) return;
    int idx = 0, i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[idx++] = str[i];
        }
        i++;
    }
    str[idx] = '\0';
}
int main (void)
{
    char str[] = "  Hi!,    How   are   you.  ";
    printf(" %s \n", str);
    removeSpaces(str);
    printf(" %s \n", str);
}

