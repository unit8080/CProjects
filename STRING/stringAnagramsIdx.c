#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char str1[] = "AB";
char str2[] = "ABCDBACDAB";
bool checkAnagram (char *str1, int len, char * str2, int idx)
{
    int map[26];
    int j = 0;
    while (j < 26) {
        map[j] = 0;
        j++;
    }
    j = 0;
    while (j < len) {
       map[str1[j] - 'A'] += 1;
       j++;
    }
    j = 0;
    while (j < len) {
        map[str2[idx + j] - 'A'] -= 1;
        if (map[str2[idx + j] - 'A'] < 0)
            return false;
        j++;
    }
    j = 0;
    while (j < 26) {
        if (map[j] != 0)
            return false;
        j++;
    }
    return true;
}
void findAnagramIndex ( char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL)
        return;
    int len1, len2;
    if ((len1 = strlen(str1)) == 0 || (len2 = strlen(str2)) == 0)
        return;
    if (len1 > len2)
        return;
    int result[10]; // len2/len1 +1
    bool map[26]; for (int i = 0; i < 26; i++) map[i] = false;
    int j = 0; while (str1[j] != '\0') { map[str1[j] - 'A'] = true; j++;}
    int i =0, idx = 0;
    while ((i +len1) <= len2) {
        if (map[str2[i] - 'A']) {
            if (checkAnagram(str1, len1, str2, i)) {
                result[idx++] = i;
            }
        }
        i++;
    }
    i = 0;
    while (i < idx) {
        printf(" %d ", result[i]);
        i++;
    }
}
int main (void)
{
    findAnagramIndex(str1, str2);
    return 0;
}
