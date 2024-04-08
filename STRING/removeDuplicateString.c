#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stack>

using namespace std;
char A[26];
int bitmap = 0;
#define MASK(pos)       (1UL << (pos))
#define SET(a, pos)     ((a) | (1UL << (pos)))
#define CLEAR(a, pos)   ((a) & ~(1UL << (pos)))
#define TEST(a, pos)    ((a) & (1UL << (pos)))
#define FLIP(a, pos)    ((a) ^ (1UL << (pos)))

// assumption: all characters are lower case alphabet
char *removeDuplicates(char str[])
{
    stack<char> stack;
    //for (int i=0; i<26; i++)
    //    A[i] = 0;
    int m = strlen(str);
    for (int i= m-1; i >=0; i--) {
        //if (A[str[i] - 'a'] == 0) {
        if (TEST(bitmap, str[i] - 'a') == 0) {
            stack.push(str[i]);
            //A[str[i] - 'a']++;
            bitmap = SET(bitmap, str[i] - 'a');
        }
    }
    int i = 0;
    while(!stack.empty()) {
        str[i++] = stack.top();
        stack.pop();
    }
    str[i] = '\0';
    return str;
}

int main()
{
    char str[] = "helloasdfasdf";
    char *s;
    printf("Original string = %s\n", str);
    s = removeDuplicates(str);
    printf("updated string = %s\n", str);
}
