#include <stdio.h>
#include <string.h>

void getMaxSubString (char *str)
{
    if (str == NULL)
        return;
    int len = strlen(str);
    if (len < 2)
        return;
    int seen[256] = {-1};
    int i = 0, prevIdx = 0, startIdx = 0;
    int currLen = 1, maxLen = 1;
    seen[str[i++]] = 0;
    while (str[i] != '\0') {
        prevIdx = seen[str[i]];
        if (prevIdx == -1 ||  (i - currLen) > prevIdx) {
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
                startIdx = i - maxLen;
            }
            currLen = i - prevIdx;

        }
        seen[str[i]] = i;
        i++;
    }
    if (currLen > maxLen) {
        maxLen = currLen;
        startIdx = len - maxLen;
    }
    i = maxLen;
    while (i > 0) {
        printf("%c", str[startIdx++]);
        i--;
    }
}
int main (void)
{
    char str[] = "ABCDABDEFGCABD";
    printf(" %s\n", str);
    getMaxSubString(str);
    printf("\n %s\n", str);
}
