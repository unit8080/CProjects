#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void permutation(char str[], int count[], char output[], int len, int position)
{
    if (position == len) {
        printf(" %s \n", output);
        return;
    } 
    for (int i=0; i < len; i++) {
        if (count[i] == 0) {
            //printf("Return i=%d", i);
            continue;
        }
        output[position] = str[i];
        count[i]--;
#if 0
        printf("\n i = %d, pos = %d", i, position);
        for (int j = 0; j < len; j++) 
            if (used[j] == true) printf(" T,");
            else printf(" F,");
#endif
        permutation(str, count, output, len, position+1);
        count[i]++;
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
    char str[] = "abc";
    char output[5] ={'\0', '\0', '\0', '\0', '\0'};
    int count[3] = {2, 1, 1};

    int len = strlen(str);
    permutation(str, count, output, len, 0);
}
