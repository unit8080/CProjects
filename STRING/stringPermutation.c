#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void permutation(char str[], bool used[], char output[], int len, int position)
{
    if (position == len) {
        printf(" %s \n", output);
        return;
    } 
    for (int i=0; i < len; i++) {
        if (used[i]) {
            printf("Return i=%d", i);
            continue;
        }
        output[position] = str[i];
        used[i] = true;
#if 0
        printf("\n i = %d, pos = %d", i, position);
        for (int j = 0; j < len; j++) 
            if (used[j] == true) printf(" T,");
            else printf(" F,");
#endif
        permutation(str, used, output, len, position+1);
        used[i] = false;
#if 0
        printf("\n i = %d, pos = %d", i, position);
        for (int j = 0; j < len; j++) 
            if (used[j] == true) printf(" T,");
            else printf(" F,");
#endif
    }
}
int main()
{
    char str[] = "aabc";
    char output[5] ={'\0', '\0', '\0', '\0', '\0'};
    bool used[5] = {false, false, false, false, false};

    int len = strlen(str);
    permutation(str, used, output, len, 0);
}
