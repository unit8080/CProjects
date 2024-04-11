#include <stdio.h>
#include <stdbool.h>
#include <stack>

using namespace std;
void enqueue(stack<int>& main, stack<int>& temp, int val)
{
    while (!main.empty()) {
        temp.push(main.top());
        main.pop();
    }
    temp.push(val);
    while (!temp.empty()) {
        main.push(temp.top());
        temp.pop();
    }
}
int dequeue(stack<int>& main, stack<int>& temp)
{
    int val = main.top();
    main.pop();
    return val;
}
bool empty(stack<int>& push, stack<int>& pop)
{
    return push.empty();
}
int main()
{
    stack<int> mainStack;
    stack<int> tempStack;

    int A[] = { 2, 4, 2, 5, 6, 8, 3, 9 };
    int n = sizeof(A)/sizeof(A[0]);
    for (int i=0; i<n; i++) 
    {
        enqueue(mainStack, tempStack, A[i]);
    }
    printf("Queue = ");
    while (!empty(mainStack, tempStack)) {
        printf("%d ", dequeue(mainStack, tempStack));
    }
    printf("\n");
}
