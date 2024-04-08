/* 
 * Binary Search Tree (BST) prototype functions
 *
 * (c) Sanjeev Singh, 2012
 */


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "tree.h"

#include <string.h>
#include <errno.h>
#include "queue.h"
#include <stack>
#include <queue>
#include <stdbool.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_ENTRIES 20

using namespace std;
QueueHeader *queueH = NULL;
#define max(a, b) (((a) >= (b)) ? (a) : (b))

int findClosestNumber(treeNode *root, int val)
{
    int closestVal = INT_MAX;
    int minDiff = INT_MAX;

    while (root != NULL) {
        int diff = abs(root->data - val);
        if (diff < minDiff) {
            minDiff = diff;
            closestVal = root->data;
        }
        if (minDiff == 0) {
            return closestVal;
        } else if (val < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return closestVal;
}

void printTopViewLeft(treeNode *root)
{
    if (root == NULL)
        return;
    printTopViewLeft(root->left);
    printf("%d ", root->data);
}
void printTopViewRight(treeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    printTopViewRight(root->right);
}
void printTopView(treeNode *root)
{
    if (root == NULL)
        return;
    printTopViewLeft(root);
    printTopViewRight(root->right);
}

bool treeIsBstIter (treeNode *root)
{
    if (root == NULL)
        return true;
    treeNode *prevRoot = NULL;

    stack<treeNode *> stack;
    while (!stack.empty() || root != NULL) {
        if (root != NULL) {
            stack.push(root);
            root = root->left;
        } else {
            root = stack.top();
            stack.pop();
            if (prevRoot != NULL && root->data < prevRoot->data)
                return false;
            prevRoot = root;
            root = root->right;
        }
    }
    return true;
}

boolean treeIsBst (treeNode *root)
{
   static treeNode *prev = NULL;
   if (root == NULL)
       return TRUE;

   if (!treeIsBst(root->left)) {
       return FALSE; 
   }
   if (prev != NULL && root->data <= prev->data)
       return FALSE;
   prev = root;

   return treeIsBst(root->right);
}

int printHeight (treeNode *root) 
{
   if (root == NULL)
       return 0;

   return (max(printHeight(root->left), printHeight(root->right)) +1);
}

void breadthfirst_traverse (treeNode *node)
{
    treeNode *item;
    treeNode *endoflevel = (treeNode *)-1;
    int level = 1;

    printf("\nStarting of breadthfirst traverse !!! \n");
    if (node == NULL) 
        return;
    printf("\nLevel: %d -> ", level);
    queueEnqueue(queueH, &node);
    queueEnqueue(queueH, &endoflevel);

    treeNode *prev = NULL;

    while  (!queueEmpty(queueH)) {
        queueDequeue(queueH, &item);

        if (item == (treeNode *)-1) {
            level++;
            if (level >4)
                break;
            printf("\nLevel: %d ->", level);
            queueEnqueue(queueH, &endoflevel);
            if (prev)
                prev->next = NULL;
            prev = NULL;
        } else {
            printf(" %d", item->data);
            if (prev == NULL) {
                prev = item;
            } else {
                prev->next = item;
                prev = item;
            }
            if (item->left != NULL)
                queueEnqueue(queueH, &item->left);
            if (item->right != NULL)
                queueEnqueue(queueH, &item->right);
        }
    }
    printf("\nEnd of breadthfirst traverse     !!!! \n");
}

treeNode *newTreeNode (int data)
{
    treeNode *node;

    node = (treeNode *) malloc(sizeof(treeNode));
    // assert(node != NULL);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->next = NULL;

    return (node);
}

/*
 * Iterative insert needs parent pointer.
 */
treeNode *insertNodeIter(treeNode *root, int data)
{

    if (root == NULL)
        return newTreeNode(data);

    treeNode *current, *parent;
    parent = NULL;
    current = root;

    while (current != NULL) {
        parent = current;
        if (current->data < data) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    if (parent->data < data) {
        parent->right = newTreeNode(data);
        parent->right->parent = parent;
    } else {
        parent->left = newTreeNode(data);
        parent->left->parent = parent;
    }
    return root;
}

treeNode *insertNode(treeNode *node, int data)
{
    // 1. Handle special case when Tree empty.
    // 2. Process this node.
    // 3. go left or right

    if (node == NULL) {
        return (newTreeNode(data));
    } else {
        treeNode *temp;

        if (data <= node->data) {
            temp = insertNode(node->left, data);
            node->left = temp;
            temp->parent = node;
        } else {
            temp = insertNode(node->right, data);
            node->right = temp;
            temp->parent = node;
        }
    }
    return (node);
}

treeNode * minNode (treeNode *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return (node);
}

treeNode * maxNode (treeNode *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->right != NULL) {
        node = node->right;
    }
    return (node);
}

/*
 * For given data, find in tree.
 *      - first verify the initial condition.
 *      - return NULL if no nodes 
 *      - return node if found
 *      - go left or right of node
 */
treeNode *searchNode (treeNode *node, int data)
{

    if (node == NULL) {
        return NULL;  /* unsuccessful search */
    }

    if (node->data == data) {
        return node;
    } else {

        if (data > node->data) {
            return searchNode(node->right, data);
        } else {
            return searchNode(node->left, data);
        }
    }
}

/*
 * http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
 */
treeNode *successorNode (treeNode *node, int data)
{
    node = searchNode(node, data);
    if (node == NULL) {
        return NULL;
    }
    if (node->right != NULL) {
        return minNode(node->right);
    } else {
        treeNode *parent = node->parent;

        while ((parent != NULL) && (node == parent->right)) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

treeNode *predecessorNode (treeNode *node, int data)
{

    node = searchNode(node, data);
    if (node == NULL) {
        return NULL;
    }

    if (node->left != NULL) {
        return maxNode(node->left);
    } else {

        treeNode *parent = node->parent;

        while ((parent != NULL) && (node == parent->left)) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

int heightTree (treeNode *node)
{
    if (node == NULL) {
        return 0;
    } 
    int leftHeight = heightTree(node->left);
    int rightHeight = heightTree(node->right);
    return 1 + max(leftHeight, rightHeight);
}

int
deleteNode (treeNode *node)
{
    treeNode *self;


    self = node;
    /* 
     * Case 1: self has no or just one child 
     *  - update the parent node
     *  - Trick: how to find this node is left or right child.
     */
    if ((self->left == NULL) || (self->right == NULL)) {
        if (self == self->parent->left) {
            /* left child */
            self->parent->left = self->left ? self->left : self->right;
            if (self->parent->left != NULL) {
                self->parent->left->parent = self->parent;
            }
            free(self);
            return 0;

        } else {
            /* right child */
            self->parent->right = self->left ? self->left : self->right;
            if (self->parent->right != NULL) {
                self->parent->right->parent = self->parent;
            }
            free(self);
            return 0;
        }
    }

    /*
     * Case 2: node has two child node 
     * - replace with next_larger node and delete that next larger node.
     */
    treeNode *s;

    s = successorNode(self, self->data);

    self->data = s->data;
    deleteNode(s);

    return 0;
}

void printPreorderTreeNode (treeNode *node)
{

    if (node == NULL) {
        return;
    }

    // visit node - inorder
    printf(" %d,", node->data);

    if (node->left != NULL) {
        printPreorderTreeNode(node->left);
    }

    if (node->right != NULL) {
        printPreorderTreeNode(node->right);
    }
}

void printInorderTreeNode (treeNode *node)
{

    if (node == NULL) {
        return;
    }

    if (node->left != NULL) {
        printInorderTreeNode(node->left);
    }

    // visit node - inorder
    printf(" %d,", node->data);

    if (node->right != NULL) {
        printInorderTreeNode(node->right);
    }
}

void printPostorderTreeNode (treeNode *node)
{

    if (node == NULL) {
        return;
    }

    if (node->left != NULL) {
        printPostorderTreeNode(node->left);
    }

    if (node->right != NULL) {
        printPostorderTreeNode(node->right);
    }

    // visit node - inorder
    printf(" %d,", node->data);
}

int sizeofTree(treeNode *root)
{
    if (root == NULL)
        return 0;
    int leftSize = sizeofTree(root->left);
    int rightSize = sizeofTree(root->right);
    return leftSize + rightSize + 1;
}

int count_nodes (treeNode *node)
{
    static int count;

    if (node == NULL)
        return 0;
    count_nodes(node->left);
    count++;
    count_nodes(node->right);
    return count;
}

int count_leaf (treeNode *node)
{
    static int count;
    
    if (node == NULL)
        return 0;
    count_leaf(node->left);
    if ((node->left == NULL) && (node->right == NULL))
        count++;
    count_leaf(node->right);
    return count;
}

boolean isValidateBST (treeNode *node, int min, int max)
{
    if (node == NULL)
        return TRUE;
    if (node->data > max || node->data < min)
        return FALSE;
    return (isValidateBST(node->left, min, node->data) &&
            isValidateBST(node->right, node->data, max));
}

boolean isBST (treeNode *node)
{
    return (isValidateBST(node, 0 , 50));
}

treeNode *tree_build123(void)
{
    treeNode *node = NULL;
    treeNode *min_node = NULL;
    treeNode *max_node = NULL;
    treeNode *found = NULL;
    treeNode *temp = NULL;
    int data;
    int deleted;

    // array : 10, 6, 9, ...
    int arr[] = {10, 6, 9, 4, 5, 2, 16, 12, 17, 15};
    //int arr1[] = {10, 4, 14, 2, 8, 12, 16, 1, 3, 5, 9, 11, 13, 15, 17};
    int arr1[] = {10, 4, 14, 2, 8, 12, 16};
    int size, i=0;

    // insert 4, 10, 6
    printf("\n insert 4, 10, 6\n");

    node = insertNode(node, 4);
    node = insertNode(node, 10);
    node = insertNode(node, 6);

    printf("\n Inorder Tree traversal : ");
    printInorderTreeNode(node);
    printf("\n Height = %d\n", heightTree(node));

    node = NULL;

    size = sizeof(arr1)/sizeof(int);
    while (size != 0) {
        node = insertNodeIter(node, arr1[i++]);
        size--;
    }
    return node;

    printf("\n Preorder Tree traversal : ");
    printPreorderTreeNode(node);
    printf("\n Inorder Tree traversal : ");
    printInorderTreeNode(node);
    printf("\n Postorder Tree traversal : ");
    printPostorderTreeNode(node);

    printf("\n Height = %d\n", heightTree(node));
    printf("Tree is %s BST\n", isBST(node) ? "" : "not");
    data = 12;
    found = searchNode(node, data);
    if (found != NULL) {
        printf("node %d in Tree : found \n", data);
    } else {
        printf("node %d in Tree : not found \n", data);
    }
    found->data = 70;
    printf("Tree is %s BST\n", isBST(node) ? "" : "not");
    found->data = 12;
    printf("Tree is %s BST\n", isBST(node) ? "" : "not");

    min_node = minNode(node);
    if (min_node != NULL)
        printf("Min Value in Tree : %d\n", min_node->data);
    
    max_node = maxNode(node);
    if (max_node != NULL)
        printf("Max Value in Tree : %d\n", max_node->data);

    data = 12;
    found = searchNode(node, data);
    if (found != NULL) {
        printf("node %d in Tree : found \n", data);
    } else {
        printf("node %d in Tree : not found \n", data);
    }
    data = 13;
    found = searchNode(node, data);
    if (found != NULL) {
        printf("node %d in Tree : found \n", data);
    } else {
        printf("node %d in Tree : not found \n", data);
    }

    data = 6;
    found = successorNode(node, data);
    if (found != NULL) {
        printf("successor of %d in Tree : found %d \n", data, found->data);
    } else {
        printf("successor of %d in Tree : not found \n", data);
    }
    data = 10;
    found = successorNode(node, data);
    if (found != NULL) {
        printf("successor of %d in Tree : found %d \n", data, found->data);
    } else {
        printf("successor of %d in Tree : not found \n", data);
    }

    data = 10;
    found = successorNode(node, data);
    if (found != NULL) {
        printf("successor of %d in Tree : found %d \n", data, found->data);
    } else {
        printf("successor of %d in Tree : not found \n", data);
    }

    data = 10;
    found = predecessorNode(node, data);
    if (found != NULL) {
        printf("predecessor of %d in Tree : found %d \n", data, found->data);
    } else {
        printf("predecessor of %d in Tree : not found \n", data);
    }
    data = 12;
    found = predecessorNode(node, data);
    if (found != NULL) {
        printf("predecessor of %d in Tree : found %d \n", data, found->data);
    } else {
        printf("predecessor of %d in Tree : not found \n", data);
    }
    data = 9;
    found = predecessorNode(node, data);
    if (found != NULL) {
        printf("predecessor of %d in Tree : found %d \n", data, found->data);
    } else {
        printf("predecessor of %d in Tree : not found \n", data);
    }

#if 1
    data = 17;
    /*
     * Case 0: node to be deleted does not exist
     */
    temp = searchNode(node, data);
    if (temp == NULL) {
        deleted = -1; /* Tree unchanged */
    } else {
        deleted = deleteNode(temp);
    }

    if (deleted == 0) {
        printf("delete %d in Tree : Done \n", data);
        printInorderTreeNode(node);   
    } else {
        printf("delete %d in Tree : not found \n", data);
    }
#endif
    return (node);
}

void printBstByLevelAdjacent( treeNode *root) 
{
    treeNode *node;

    queueEnqueue(queueH, &root);
    while(!queueEmpty(queueH)) {
        queueDequeue(queueH, &node);
        printf(" %d->%d ", node->data, (node->next ? node->next->data : 0));
    	if (node->left != NULL)
        	queueEnqueue(queueH, &node->left);
    	if (node->right != NULL)
       		queueEnqueue(queueH, &node->right);
    }
}

void printRoot2LeafSum2(treeNode *root, int sum)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        printf("%d ", sum+root->data);
        return;
    }
    sum = sum+root->data;

    printRoot2LeafSum2(root->left, sum);
    printRoot2LeafSum2(root->right, sum);
}

void printRoot2LeafSum(treeNode *root)
{
   typedef struct qNode {
      treeNode *node;
      int sum;
   } QNode;

   if (root == NULL)
       return;

   QueueHeader *queueHead = queueCreate(MAX_ENTRIES, sizeof(QNode));;
   QNode qnode; /* on stack */

   qnode.node = root;
   qnode.sum = root->data;
   queueEnqueue(queueHead, &qnode);

   while(!queueEmpty(queueHead)) {
      
      QNode qnode;   
      queueDequeue(queueHead, &qnode);
      if (qnode.node->left == NULL && qnode.node->right == NULL) {
          printf ("leaf sum = %d\n", qnode.sum);
      }
      if (qnode.node->left != NULL) {
          QNode qnodeL;
          qnodeL.node = qnode.node->left;
          qnodeL.sum = qnode.sum + qnodeL.node->data;
          queueEnqueue(queueHead, &qnodeL);
      }

      if (qnode.node->right != NULL) {
          QNode qnodeR;
          qnodeR.node  = qnode.node->right;
          qnodeR.sum = qnode.sum + qnodeR.node->data;
          queueEnqueue(queueHead, &qnodeR);
      }
   }
}

bool TreeIdentical ( treeNode *root1, treeNode *root2)
{

    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data) &&
            TreeIdentical(root1->left, root2->left) &&
            TreeIdentical(root1->right, root2->right);
}

void printBstByLevel( treeNode *root) 
{
    treeNode *node;
    queue<treeNode *> myqueue;

    myqueue.push(root);
    while(!myqueue.empty()) {
        node = myqueue.front();
        myqueue.pop();
        printf("%d ", node->data);
    	if (node->left != NULL)
        	myqueue.push(node->left);
    	if (node->right != NULL)
       		myqueue.push(node->right);
    }
}
void TreePostOrderIter( treeNode *root)
{
    stack <treeNode *> stack1; 
    stack <treeNode *> stack2; 

    if (root == NULL)
        return;
    stack1.push(root);
    while(!stack1.empty()) {
        treeNode *node;

        node = stack1.top();
        stack1.pop();
        stack2.push(node);
        if (node->left != NULL)
            stack1.push(node->left);
        if (node->right != NULL)
            stack1.push(node->right);
    }
    treeNode *temp;
    while(!stack2.empty()) {
        temp = stack2.top();
        stack2.pop();
        printf(" %d, ", temp->data);
    }
}

void BST2CirLinkedList(treeNode *p, treeNode **head, treeNode **prev)
{
    if (p == NULL)
        return;

    BST2CirLinkedList(p->left, head, prev);

    p->left = *prev;
    if (*prev != NULL)
        (*prev)->right = p;
    else
        *head = p;

    treeNode *right = p->right; // cache here
    p->right = *head;
    (*head)->left = p;
    *prev = p;

    BST2CirLinkedList(right, head, prev);
}

void deleteTree(treeNode *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    printf("deleting node %d\n", root->data);
    free(root);
}
void TreeSpiralPrint (treeNode *root)
{
    if (root == NULL)
        return;
    stack<treeNode *> stack1;
    stack<treeNode *> stack2;

    printf("Spiral tree printing : ");
    stack1.push(root);
    while (!stack1.empty() || !stack2.empty()) {
        while (!stack1.empty()) {
            treeNode *node = stack1.top();
            stack1.pop();
            printf(" %d ", node->data);
            if (node->left != NULL)
                stack2.push(node->left);
            if (node->right != NULL)
                stack2.push(node->right);
        }
        while (!stack2.empty()) {
            treeNode *node = stack2.top();
            stack2.pop();
            printf(" %d ", node->data);
            if (node->right != NULL)
                stack1.push(node->right);
            if (node->left != NULL)
                stack1.push(node->left);
        }
    }
}
int main (int argc, char *argv[])
{
    treeNode *root;
    int count;
    size_t size;

    queueH = queueCreate(MAX_ENTRIES, sizeof(root));
    //Stack *stack1 = stackCreate( sizeof(root), 10);
    //Stack *stack2 = stackCreate( sizeof(root), 10);

    root = tree_build123();
#if 0
    count = count_leaf(root);
    printf("\nNumber of Leaf nodes = %d\n", count);
    count = count_nodes(root);
    printf("\nNumber of nodes = %d\n", count);
#endif
    
    printf("\nPost order iterartive :");
    TreePostOrderIter(root);
    printf("\nNumber of nodes = %d\n", sizeofTree(root));
    printf("Height of tree : %d\n", printHeight(root));
    printRoot2LeafSum(root);
    printf("print Root2Leaf sum : ");
    int n =0;
    printRoot2LeafSum2(root, n);
    printf("\n");
    n =0;
    TreeSpiralPrint(root); printf("\n");
    printf("Tree is Bst: %s\n", treeIsBstIter(root) ? "TRUE" : "FALSE");

    treeNode *found;
    found = searchNode(root, 8);
    if (found != NULL) {
        printf("node %d in Tree : found \n", 8);
    } else {
        printf("node %d in Tree : not found \n", 8);
    }
    found->data = 3;
    printf("Tree is Bst: %s\n", treeIsBstIter(root) ? "TRUE" : "FALSE");
    printf("\nPrint by level : ");
    printBstByLevel(root);
    breadthfirst_traverse(root);
    printBstByLevelAdjacent(root);
    printf("\nTree Top View : ");
    printTopView(root);
    printf("\n");
    printf("\nTree Identical  ? %s\n", TreeIdentical(root, root) ? "Yes" : "No");
#if 0
    treeNode *head = NULL;
    treeNode *prev = NULL;
    BST2CirLinkedList(root, &head, &prev);
    treeNode *p = head;
    while(p->right != head) {
        printf(" %d ", p->data);
        p = p->right;
    }
#else
    bool flag = true;
    while (flag) {
        int n;
        printf("Enter num for closest (0-exit) : ");
        scanf("%d", &n);
        printf("closest number to %d is %d\n", n, findClosestNumber(root, n)); 
        if (n == 0) flag = false;
    }
    deleteTree(root);
#endif
}
