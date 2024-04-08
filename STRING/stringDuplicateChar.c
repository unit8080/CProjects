#include <stdio.h>
#include <string.h>

//char str[] = "Javsfghj";
char str[] = "JavaJv";
void printDupChar (char *str)
{
    if (str == NULL)
        return;
    int len = strlen(str);
    if (len == 0)
        return;
    char dups[256];
    for (int i = 0; i < 256; i++)
        dups[i] = 0;
    int i = 0;
    while (str[i] != '\0') {
            dups[str[i]] = dups[str[i]] + 1;;
        i++;
    } 
    for (int i = 0; i < 256; i++)
        if (dups[i] > 1 ) {
            printf(" %c : %d \n", (char) i, dups[i]);
        }
}

int main (void)
{
    printf("String:  %s\n", str);
    printDupChar(str);
}
