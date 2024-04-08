#include <stdio.h>
#include <stdbool.h>
#include <stack>
#include <queue>

using namespace std;

bool checkBalancedParenthesis(char expr[]) 
{
    int len = strlen(expr);
    stack<char> S;
    queue<char> Q;
    bool result = true;

    for (int i = 0; i < len; i++) {
        // scan the expression array
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            S.push(expr[i]);
            Q.push(expr[i]);
        }
        else if (S.empty() || (S.top() == '(' && expr[i] != ')') ||
                         (S.top() == '{' && expr[i] != '}') ||
                         (S.top() == ']' && expr[i] != ']') ) {
            result = false; //return false;
        } else {
            Q.push(expr[i]);
            S.pop();
        }
    }
    while(!Q.empty()) {
        char c = Q.front();
        Q.pop();
        printf(" %c ", c);
    }

    if (!result || !S.empty())
        return false;

    return true;
}

int main()
{
    char expr[51];

    printf("Enter expression: ");
    scanf("%s", expr);
    printf("Expression has balanced parenthesis : %s\n", 
            checkBalancedParenthesis(expr) ? "Yes" : "No");
}
