#include <stdio.h>
#include <string.h>
const char text[] = "junk word word   word junk wordjunk ";
//const char text[] = "junk junk wordjunk ";
//const char text[] = "";
char pat[] = "word";

// output = 2
// NULL string
// word may not be present - 0
// otherwise return counts 0 or more

int getWordCount (const char T[], char pat[]) {
    char *text = (char *) T;
    int i = 0;
    int count = 0;
    if (text == NULL ||  pat == NULL )
        return 0;
    int len = strlen(pat);
    if (len == 0)
        return count;
    while (text[i] != '\0') {
        while (text[i] == ' ' && text[i] != '\0') i++;
        if ((text[i+len] == ' ' || text[i+len] == '\0') && (strncmp(pat, text+i, len) == 0))
            count++;
        while (text[i] != '\0' && text[i] != ' ') i++;
    }
    return count; 
}
// 1. NULL text or NULL pattern, count = 0
// pat not preset, return count =0;
// path is present, 

// 2.
// how you will change code if text is const. And this func will be 
// called a lot. 
int main (void) {
    int count = getWordCount(text, pat);
    printf(" count = %d \n", count);
}
