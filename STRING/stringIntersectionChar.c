#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char s1[] = "xslkdjskjdjdkjd";
char s2[] = "skxjsss";    
void getStringIntersection (char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL)
	return;
    int len1; int len2;
    if ((len1 = strlen(s1)) == 0 || (len2 = strlen(s2)) == 0)
	return;
    char *sm, *bg;
    if (len1 > len2) {
	bg = s1;
	sm = s2;
    } else {
	bg = s2;
	sm = s1;
    }
    int i = 0;
    int map[26];
    while (i < 26) {
	map[i] = 0;
    	i++;
    }
    i = 0;
    while (bg[i] != '\0') {
	map[bg[i] - 'a'] += 1;
	i++;
    }
    i = 0;
    while (sm[i] != '\0')
    {
	if (map[sm[i] - 'a'] > 0) {
	    printf("%c ", sm[i]);
	    map[sm[i] - 'a'] -= 1;
	}
	i++;
    }
    printf("\n");
}
int main (void)
{
    getStringIntersection(s1, s2);
}
