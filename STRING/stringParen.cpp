#include <stdio.h>
#include <stdbool.h>
#include <stack>
#include <iostream>
const char *str = "(ab{c}) [[d]]";
using namespace std;
bool isOpenBracket (const char c) 
{
    switch (c) {
        case '(': return true;
        case '{': return true;
        case '[': return true;
    }
    return false;
}
char openToClose (const char c)
{
    switch (c) {
        case ')': return '(';
        case '}': return '{';
        case ']': return '[';
    }
    return '0';
}
bool isValid (const char *str) 
{
    if (str == NULL)
        return true;
    stack <char> stk;
    while (*str != '\0') {
        if (isOpenBracket(*str)) {
            stk.push(*str);
        } 
        char c = openToClose(*str);
        if (c == '0') {
            str++;
            continue;
        }
        if (stk.empty() )
            return false;
        char top = stk.top();
        stk.pop();
        if (top != c)
            return false;
        str++;
    }
    return stk.empty();
}
int main (void)
{
    printf("isValid : %s %s\n", str, isValid(str) ? "yes" : "no");
}
