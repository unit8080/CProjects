#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char str1[] = "Army";
char str2[] = "Mary";
char str5[] = "Armyy";
char str6[] = "Maryz";

int map[26];
bool checkAnagrams (char *str1, char *str2)
{
    if (str1 == NULL && str2 == NULL)
        return true;
    if (str1 == NULL || str2 == NULL)
        return false;

    for (int i = 0; i < 26; i++)
        map[i] = 0;
    int i = 0;
    while (str1[i] != '\0')
    {
        if (isalpha(str1[i])) {
            char t = tolower(str1[i]);
            map[t - 'a'] = map[t - 'a'] + 1;
            //printf( "%c : %d \n", t, map[t - 'a']);
        }
        i++;
    }
    i = 0;
    while (str2[i] != '\0')
    {
        if (isalpha(str2[i])) {
            char t = tolower(str2[i]);
            map[t - 'a'] = map[t - 'a'] - 1;;
            if  (map[t - 'a'] < 0)
                return false;
            //printf( "%c : %d \n", t, map[t - 'a']);
        }
        i++;
    }
    for (int j = 0; j < 26; j++) {
        if (map[j] > 0)
            return false;
        j++;
    }
    return true;
}

int main(void)
{
    char *str3 = NULL;
    char *str4 = NULL;
    printf(" Both %s and %s  %s anagrams\n", str1, str2, checkAnagrams(str1, str2) ? "are" : "are not");
    printf(" Both %s and %s  %s anagrams\n", str3, str4, checkAnagrams(str3, str4) ? "are" : "are not");
    printf(" Both %s and %s  %s anagrams\n", str5, str6, checkAnagrams(str5, str6) ? "are" : "are not");
}

