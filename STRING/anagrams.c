#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char A[26];

bool checkAnagrams(char str1[], char str2[])
{
    for (int i=0; i < 26; i++) // init hash array
        A[i] = 0;
    int m = strlen(str1);
    if ( m != strlen(str2) ) {// string size should match
        printf("String size mismatch \n");
        return false;
    }
    for (int i=0; i < m; i++) { // account all char
        A[str1[i] - 'a']++;
    }
    for (int i=0; i < m; i++) { // decrement matched one.
        A[str2[i] - 'a']--;
        if (A[str2[i] - 'a'] < 0) // if goes -ve, not an anagram, 
            return false;
    }
    for (int i=0; i<m; i++) { // check all matched.
        if (A[i] > 0)
            return false;
    }
    return true;
}
int main()
{
//    char str1[] = "aasdf"; // not anagram
//    char str2[] = "wadf";  // not anagram
    char str1[] = "asdf";    // anagram
    char str2[] = "fdsa";    // anagram
    printf("strings are %s Anagram\n", checkAnagrams(str1, str2) ? "" : "Not");
}
