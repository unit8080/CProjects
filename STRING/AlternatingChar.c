/*
Problem Statement

Shashank likes strings in which consecutive characters are different. For example, 
he likes ABABA, while he doesn't like ABAA. Given a string containing characters 
A and B only, he wants to change it into a string he likes. To do this, he is allowed
to delete the characters in the string.

Your task is to find the minimum number of required deletions.

Input Format

The first line contains an integer T, i.e. the number of test cases. 
The next T lines contain a string each.

Output Format

For each test case, print the minimum number of deletions required.

Constraints

1≤T≤10 
1≤ length of string ≤105
Sample Input

5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB
Sample Output

3
4
0
0
4
Explanation

AAAA ⟹ A, 3 deletions
BBBBB ⟹ B, 4 deletions
ABABABAB ⟹ ABABABAB, 0 deletions
BABABA ⟹ BABABA, 0 deletions
AAABBB ⟹ AB, 4 deletions because to convert it to AB we need to delete 2 A's and 2 B's

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void deletions(char str[]) {
    int len = strlen(str);
    int dc=0;
    char last = 'C', c;
    for (int i = 0; i < len; i++) {
        c = str[i];
        if (c == last)
            dc++;
        last = c;
    }
    printf("%d\n", dc);
}

char *readString(FILE *fp) {
    int size = 80;
    char c;
    int len =0;
    char *str = realloc(NULL, sizeof(char)*size);
    if (!str)
        return str;
    while( EOF != (c=fgetc(fp)) && c != '\n') {
        str[len++] = c;
        if (len == size) {
            str = realloc(str, sizeof(char)*(size *= 2));
            if (!str) 
                return str;
        }
    }
    str[len++] = '\n';
    return realloc(str, sizeof(char)*len);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n;
    scanf("%d", &n);
    //char str[100000];
    char *str;
    fgetc(stdin);
    for (int i = 0; i < n; i++)
    {
       //scanf("%s", str);
       str = readString(stdin);
       if (!str)
           return 0;
       deletions(str);
       free(str);
       str = NULL;
    }
    return 0;
}
