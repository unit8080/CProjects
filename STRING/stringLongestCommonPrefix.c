#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
char *s[] = {"flower","flow","flows"};
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strs == NULL || strsSize == 0 || *strs == NULL)
        return "";
    
    char *result = (char *)malloc(sizeof(char) * 1000);
    assert(result != NULL);
    int index = 0;
    int terminate = false;

    char *str = *(strs + 0);
    while (str[index] != '\0') {
        char c = str[index];
        for (int j = 1; j < strsSize; j++) {
            char *str2 = *(strs + j);
            if (str2[index] == '\0' || c != str2[index]) {
                terminate = true;   
                break;
            }
        }
        if (terminate)
            break;
        result[index++] = c;
    }
    result[index] = '\0';
    return result;
}
int main(void)
{
   printf("%s\n", longestCommonPrefix(s, 3));
}

