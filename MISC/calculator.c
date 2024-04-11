// Binary tree calculator implementation
// (c) Sanjeev Singh July 2017
#include <stdio.h>
#include <stdlib.h>

typedef struct _treeNode {
    char value; // assuming single digit number or binary operator.
    struct _treeNode *left;
    struct _treeNode *right;
} treeNode;

int calculate (treeNode *node)
{
    if (node == NULL)
        return 0;
    if ((node->left == NULL) && (node->right == NULL)) {
        return (atoi((const char *)&node->value));
    } else {
        int result = 0;
        int lh, rh;

        switch (node->value) {
        case '+':
            lh = calculate(node->left);
            rh = calculate(node->right);
            result = lh + rh;
            break;
        case '-':
            lh = calculate(node->left);
            rh = calculate(node->right);
            result = lh - rh;
            break;
        case '*':
            lh = calculate(node->left);
            rh = calculate(node->right);
            result = lh * rh;
            break;
        case '/':
            lh = calculate(node->left);
            rh = calculate(node->right);
            result = lh/rh;
            break;
        }
        return result;;
    }
}
int main()
{
}
