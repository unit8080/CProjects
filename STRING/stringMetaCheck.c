#include <stdio.h>
#include <string.h>

void checkMeta (char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL) {
        printf("%d\n", 0);
        return;
    }
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        printf("%d\n", 0);
        return;
    }
    int loc[2] = {-1}, idx = 0;
    int count = 0, i = 0; 
    while (str1[i] != '\0')
    {
        if (str1[i] != str2[i]) {
            count++;
            if (count > 2) {
                printf("%d\n", 0);
                return;
            }
            loc[idx++] = i;
        }
        i++;
    }
    if (count != 2) {
        printf("%d\n", 0);
        return;
    }
    if (str1[loc[0]] == str2[loc[1]] && str1[loc[1]] == str2[loc[0]])
        printf("%d\n", 1);
    else 
        printf("%d\n", 0);
}
int main() {
    //code
    int count = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        char  str1[1000];
        char  str2[1000];
        scanf("%s", str1);
        scanf("%s", str2);
        checkMeta(str1, str2);
    }
    return 0;
}
