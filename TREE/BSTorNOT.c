#include <stdio.h>

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef struct node_ {
    int value;
    struct node_ *left;
    struct node_ *right;
} Node;

int minValue (Node *node)
{
    while (node->left != NULL) {
        node = node->left;
    }
    return (node->value);
}

int maxValue (Node *node)
{
    while (node->right != NULL) {
        node = node->right;
    }
    return (node->value);
}

boolean BSTorNOT (Node *node)
{
    if (node == NULL) 
        return TRUE;

    if ((node->left != NULL) && 
        minValue((Node *)node->left) > node->value) {
        return FALSE;
    }
    if ((node->right != NULL) && 
        maxValue((Node *)node->right) <= node->value) {
        return FALSE;
    }

    if (!BSTorNOT((Node *)node->left) ||  !BSTorNOT((Node *)node->right)) {
        return FALSE;
    }
    return TRUE;
}

int main()
{
    Node *node = NULL;
    boolean bst;

    bst = BSTorNOT(node);
    printf("Tree is %s BST\n", bst ? "" : "not");
}
