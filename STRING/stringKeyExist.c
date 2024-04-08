#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkKeyExist (const char *str)
{
    if (str == NULL)
        return false;
    if (strlen(str) < 4)
        return false;
    bool keys[10000]; // for 0000 to 9999 distinct keys
    for (int j = 0; j < 10000; j++) keys[j] = false;
    char *s = (char *)str;
    int i = 3;
    int key = (s[i-3] - '0') * 1000 +
              (s[i-2] - '0') * 100 +
              (s[i-1] - '0') * 10 ; 
    while(s[i] != '\0') {
        key = key + (s[i] - '0');
        keys[key] = true;
        key = key - (s[i-3] - '0') * 1000;
        key = key * 10;
        i++;
    }
    for (int i = 0; i < 1000; i++)
        if (keys[i] == false)
            return false;
    return true; // all possible keys covered.
}
int main (void)
{
    char str[] = "002217189731971919193";
    printf("valid key present in string %s\n", 
            checkKeyExist(str) ? "yes" : "No");
}
