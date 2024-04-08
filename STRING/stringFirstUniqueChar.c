#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char str[] = "";
//char str[] = "aFountain";
int map[256]; 


void findFirstChar (char *str) 
{
    if (str == NULL)
        return;
    int len = strlen(str);
    if (len == 0) return; 
    for (int i = 0; i < 256; i++) map[i] = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (isalpha(str[i])) map[str[i]] ++;
        i++;
    }
    i=0;
    while (str[i] != '\0') {
        if ((isalpha(str[i])) && map[str[i]] == 1)
            break;
        i++;
    }
    printf("Unique character: %c \n", str[i]);
}

int main (void)
{
    //printf(" %d %d %d %d", 'a', 'z', 'A', 'Z');
    findFirstChar(NULL);
}
