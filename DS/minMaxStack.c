#include <stdio.h>
#include <stdbool.h>
#include <stack>

using namespace std;

void minMaxPop (stack<int>& main, stack<int>& min, stack<int>& max)
{
    int val = main.top();
    if (val == max.top() ) {
        max.pop();
    } 
    if (val == min.top()) {
        min.pop();
    }
    main.pop();
}

void minMaxPush (stack<int>& main, stack<int>& min, stack<int>& max)
{
    int val = main.top();
    if (max.empty()) 
        max.push(val);
    else {
        if (val >= max.top()) {
            max.push(val);
        }
    }
    if (min.empty()) 
        min.push(val);
    else {
        if (val <= min.top()) {
            min.push(val);
        }
    }
}

int main ()
{
    stack<int> main;
    stack<int> min;
    stack<int> max;
    int A[] = { 2, 3, 0, 5, 1, 7, 4, 3, 2, 1, 9, 0, 2, 10 };
    int sz = sizeof(A)/sizeof(A[0]);
    for (int i=0; i<sz; i++)
    {
        main.push(A[i]);
        minMaxPush(main, min, max);
    }
    printf("Min = %d, Max = %d\n", min.top(), max.top());
    minMaxPop(main, min, max);
    printf("Min = %d, Max = %d\n", min.top(), max.top());
    minMaxPop(main, min, max);
    printf("Min = %d, Max = %d\n", min.top(), max.top());
    minMaxPop(main, min, max);
    printf("Min = %d, Max = %d\n", min.top(), max.top());
    minMaxPop(main, min, max);
    printf("Min = %d, Max = %d\n", min.top(), max.top());
    main.push(11);
    minMaxPush(main, min, max);
    printf("Min = %d, Max = %d\n", min.top(), max.top());
    main.push(-1);
    minMaxPush(main, min, max);
    printf("Min = %d, Max = %d\n", min.top(), max.top());
    minMaxPop(main, min, max);
    printf("Min = %d, Max = %d\n", min.top(), max.top());
    minMaxPop(main, min, max);
    printf("Min = %d, Max = %d\n", min.top(), max.top());
}
