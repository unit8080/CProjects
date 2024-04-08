#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char *s = "abcbc";
char *p = "a*c";

bool pContainsSpecial (char *p) {
    while (*p != '\0') {
        if (*p == '*' || *p == '?')
            return true;
        p++;
    }
    return false;
}
bool isMatch(char* s, char* p) {
    if (s == NULL && p == NULL)
        return true;
    if (s == NULL || p == NULL)
        return false;
    size_t slen = strlen(s);
    size_t plen = strlen(p);
    
    bool special = false;
    if (slen != plen && !(special = pContainsSpecial(p)))
        return false;
    
    while (*s != '\0' && *p != '\0') {
        if (*p == '?') {
            // just skip both, do nothing
        } else if (*p == '*') {
            if (*(p + 1) == '\0') {
                return true;
            } else {
                p++;
                //keep skipping in s
                while (*s != '\0' && *s != *(p)) {
                    s++;
                }
                if  (*s == '\0')
                    return false;
            }
        } else if (*p != *s) {
            return false;
        }
        s++;
        p++;
    }
    
    return (*s=='\0' && *p == '\0');
}
int main (void)
{
    printf("Matched ? : %s \n", isMatch(s, p) ? "Yes" : "No"); 
}

