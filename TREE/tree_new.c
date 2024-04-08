/* 
 * Binary Search Tree (BST) prototype functions
 *
 * (c) Sanjeev Singh, 2012
 */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0
#define MAX_ENTRIES 20
#define max(a, b) (((a) >= (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
void bt2dll (treeNode *root, treeNode **head)
{ // inorder traversal convert to DLL
    static treeNode *curr = NULL;
    if (root == NULL)
        return;
    bt2dll(root->left, head);

    if (curr == NULL) {
        *head = root;
    } else {
        curr->right = root;
        root->left = curr;
    }
    curr = root;

    bt2dll(root->right, head);
}

void minDistanceLeaf (treeNode *root, int dis, int *min)
{ // Pre-order Traversal 
    if (root == NULL)
        return;
    if (root->left == NULL & root->right == NULL) {
        *min = MIN(*min, dis);
    }
    minDistanceLeaf(root->left, dis+1, min);
    minDistanceLeaf(root->right, dis+1, min);
}

treeNode * LowestCommonAncestorBst (treeNode *root, treeNode *node1, treeNode *node2)
{
    if (root == NULL || node1 == NULL || node2 == NULL)
        return NULL;
    if (root->data < node1->data && root->data < node2->data)
        return LowestCommonAncestorBst(root->right, node1, node2);
    else if (root->data > node1->data && root->data > node2->data)
        return LowestCommonAncestorBst(root->left, node1, node2);
    else
        return root;
}

treeNode *LowestCommonAncestor (treeNode *root, treeNode *node1, treeNode *node2)
{ // not-BST
    if (root == NULL)
        return NULL;
    if (root == node1 || root == node2)
        return root;
    treeNode *left = LowestCommonAncestor(root->left, node1, node2);
    treeNode *right = LowestCommonAncestor(root->right, node1, node2);
    if (left != NULL && right != NULL)
        return root;
    if (left == NULL && right == NULL)
        return NULL;
    return (left ? left : right);
}
void distance (treeNode *root, treeNode *node, int dis, int *dist)
{
    if (root == NULL)
        return;
    if (root == node) {
        *dist= dis;
        return;
    }
    distance(root->left, node, dis+1, dist);
    distance(root->right, node, dis+1, dist);
}

int distanceN1N2 (treeNode *root, treeNode *node1, treeNode *node2)
{
    int n1=0, n2= 0, n3=0;
    treeNode  *lca;
    lca = LowestCommonAncestor(root, node1, node2);
    distance(root, node1, n1, &n1);
    distance(root, node2, n2, &n2);
    distance(root, lca, n3, &n3);
    printf(" n1 = %d, n2 = %d, n3 = %d", n1, n2, n3);
    return n1 + n2 - 2*n3;
}

void MorrisInorderTraversal (treeNode *node)
{
    treeNode *current = node;
    printf("\n Morris In order Traversal : ");
    while (current != NULL) {
        if (current->left == NULL) {
            printf(" %d ", current->data);
            current = current->right;
        } else {
            treeNode *predecessor = current->left; // find its predecessor
            while (predecessor->right != current && predecessor->right != NULL) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {// visit left subtree
                predecessor->right = current;
                current = current->left;
            } else {                         // visited left already
                predecessor->right = NULL;
                printf(" %d ", current->data);
                current = current->right;
            }
        }
    }
    printf(" ended \n");
}

treeNode *newTreeNode (int data);
boolean complete (treeNode *node, int total, int root)
{
    if (node == NULL)
        return true; 

    if (root >= total)
        return false;
    int left = 2 * root +1; 
    int right = 2 * root +2;
    return complete(node->left, total, left) 
           && complete(node->right, total, right);
}

boolean pathHasSum (treeNode *root, int sum)
{
    if (root == NULL)
        return FALSE;

    if (root->left == NULL && root->right == NULL) {
        if (sum - root->data == 0)
            return TRUE;
    }
    int subsum = sum - root->data;
    return (pathHasSum(root->left, subsum) || pathHasSum(root->right, subsum));
}

//int A[] = {10, 4, 2, 6, 12, 11};
//int A[] = {10, 4, 2, 6, 12, 13};
int A[] = {10, 4, 2, 1, 6, 12, 11, 13, 14, 15, 16};
//int A[] = {10, 4, 2, 6, 16, 12, 14};
//int A[] = {10, 4, 16, 14};
treeNode *
PreOrderToInOrderUtil (int A[], int *preIndex, int l, int r, int size)
{
    //if (*preIndex >= size || l > r)
    if (l > r)
        return NULL;
    treeNode *node = newTreeNode(A[l]);
    //*preIndex = *preIndex + 1;
    if (l == r) // no need to recur if subarray has one element
        return node; 
    int i = l + 1;
    while (i <= r && A[i] <= A[l]) {
            i++;
    }
    //node->left = PreOrderToInOrderUtil(A, preIndex, *preIndex, i-1, size);
    node->left = PreOrderToInOrderUtil(A, preIndex, l+1, i-1, size);
    node->right = PreOrderToInOrderUtil(A, preIndex, i, r, size);
    return node;
}

treeNode *
PreOrderToInOrder (int A[], int size)
{
    int preIndex = 0;
    return PreOrderToInOrderUtil(A, &preIndex, 0, size -1, size);
}

boolean sameLevelLeaf (treeNode *node, int curLevel, boolean resetLevel)
{
    static int topLevel = -1;

    if (resetLevel)
        topLevel = -1;

    // leaf node
    if ((node->left == NULL) && (node->right == NULL)) {
        if (topLevel == -1) // first time.
            topLevel = curLevel;

        if (topLevel != curLevel)
            return FALSE; 
        return TRUE;
    }

    boolean leftlevel = TRUE;
    boolean rightlevel = TRUE;

    if (node->left != NULL)
        leftlevel = sameLevelLeaf(node->left, curLevel +1, FALSE);

    if (node->right != NULL)
        rightlevel = sameLevelLeaf(node->right, curLevel +1, FALSE);

    if (!leftlevel || !rightlevel)
        return FALSE;

    return TRUE;
}
boolean sameLevelLeafTree (treeNode *n)
{
    if (n == NULL)
        return TRUE;
    return sameLevelLeaf(n, 0, TRUE);
}

int heightBalancedTree (treeNode *node)
{
    if (node == NULL)
        return 0;

    int leftH = heightBalancedTree(node->left);
    if (leftH == -1)
        return -1;

    int rightH = heightBalancedTree(node->right);
    if (rightH == -1)
        return -1;

    if (abs(leftH - rightH) > 1)
        return -1;

    return (1 + max(leftH, rightH));
}

void printKlevelNode(treeNode *node, int k)
{
    if (node == NULL || k < 0)
        return;

    if (k == 0) {
        printf(" %d", node->data);
        return;
    }
    printKlevelNode(node->left, k-1);
    printKlevelNode(node->right, k-1);
}

void KthLargest (treeNode *node, int k, int *c)
{
    if (node == NULL || *c >= k)
        return;

    KthLargest(node->right, k, c);

    *c = *c + 1;
    if (*c == k){
        printf("\n %d largest node : %d\n", k, node->data);
        return;
    }

    KthLargest(node->left, k, c);
}

void KthLargestNode (treeNode *node, int k)
{
    int c = 0;
    KthLargest(node, k, &c);
}

int paths[MAX_ENTRIES];
void printPaths (treeNode *node, int paths[], int plen)
{
    int i;
    if (node == NULL)
        return;
    paths[plen++] = node->data;
    if((node->left == NULL) && (node->right == NULL)) {
        printf("Paths[] = ");
        for (i = 0; i < plen; i++) {
            printf("%d ", paths[i]);
        }
        printf("\n");
    }
    printPaths(node->left, paths, plen);
    printPaths(node->right, paths, plen);
}

boolean treeRoot2LeafSumExist (treeNode *root, int sum, int paths[], int *plen)
{
    if (root == NULL)
        return FALSE;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == sum) {
            paths[(*plen)++] = root->data;
            return TRUE;
        } else {
            return FALSE;
        }
    }
    if (treeRoot2LeafSumExist(root->left, sum - root->data, paths, plen)) {
        paths[(*plen)++] = root->data;
        return TRUE;
    }
    if (treeRoot2LeafSumExist(root->right, sum - root->data, paths, plen)) {
        paths[(*plen)++] = root->data;
        return TRUE;
    }
    return FALSE;
}

QueueHeader *queueH = NULL;
void breadthfirst_traverse (treeNode *node)
{
    treeNode *data, *item;
    treeNode *endoflevel = (treeNode *)-1;
    treeNode *nullnode = (treeNode *)-2;
    int level = 1;

    printf("\n!!! Starting of breadthfirst traverse !!! \n");
    if (node == NULL) {
        printf("\n Node none    !!!! \n");
        printf("!!! End of breadthfirst traverse     !!!! \n");
    }
    printf("Level: %d -> ", level);
    queueEnqueue(queueH, &node);
    queueEnqueue(queueH, &endoflevel);

    while  (!queueEmpty(queueH)) {
        queueDequeue(queueH, &item);
        if (item == (treeNode *)-1) {
            if (queueEmpty(queueH))
                break;
            level++;
            printf("\nLevel: %d ->", level);
            queueEnqueue(queueH, &endoflevel);
        } else if (item == (treeNode *)NULL) {
            printf(" %p", item);
        } else {
            printf(" %d(h=%d)", item->data, item->height);
            queueEnqueue(queueH, &item->left);
            queueEnqueue(queueH, &item->right);
        }
    }
    printf("\n!!! End of breadthfirst traverse     !!!! \n");
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
    node->height = 0;
    node->max_dis = 0;
    return (node);
}

treeNode * insertNode(treeNode *node, int data)
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

treeNode *successorNode (treeNode *node, int data);
int deleteNode (treeNode *node)
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

treeNode * minNode (treeNode *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL)
        node = node->left;
    return (node);
}

treeNode * maxNode (treeNode *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->right != NULL)
        node = node->right;
    return (node);
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
            parent = node->parent;
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
            parent = node->parent;
        }
        return parent;
    }
}

int heightTree (treeNode *node)
{
    static unsigned int max_distance = 0;
    int tmp_height = 0;
    int lh =0;
    int rh = 0;

    if (node == NULL) {
        return 0;
    } 
    lh = heightTree(node->left);
    rh = heightTree(node->right);
    node->height = max(lh, rh) + 1;

    if (node->left !=NULL) 
        tmp_height = node->left->height;
    if (node->right != NULL)
        tmp_height = tmp_height + node->right->height + 1;

    if (tmp_height > max_distance)
        max_distance = tmp_height;
    if (node->height > max_distance)
        max_distance = node->height;

    node->max_dis = max_distance;
    printf ("max-distance = %d\n", node->max_dis);
    return (node->height);
}

void printTreeNode (treeNode *node)
{
    if (node == NULL) {
        return;
    }
    if (node->left != NULL) {
        printTreeNode(node->left);
    }
    // visit node - inorder
    printf(" %d,", node->data);
    if (node->right != NULL) {
        printTreeNode(node->right);
    }
}

int count_leaf (treeNode *node)
{
    static int count = 0;
    
    if (node == NULL)
        return 0;
    if (node->left != NULL)
        count_leaf(node->left);
    if ((node->left == NULL) && (node->right == NULL))
        count += 1;
    if (node->right != NULL)
        count_leaf(node->right);
    return count;
}

int count_nodes (treeNode *node)
{
    static int count;

    if (node == NULL)
        return 0;
    if (node->left != NULL)
        count_nodes(node->left);
    count++;
    if (node->right != NULL)
        count_nodes(node->right);
    return count;
}

treeNode *convertBst2LinkedList (treeNode *node, treeNode **lastNode)
{
    treeNode *current;

    if (node == NULL)
        return NULL;

    current = node;
    if (current->left != NULL) {
        convertBst2LinkedList(current->left, lastNode);
    }
    current->left = *lastNode;
    if (*lastNode != NULL)
        (*lastNode)->right = current;
    *lastNode = current;
    if (current->right != NULL) {
        convertBst2LinkedList(current->right, lastNode);
    }
    return *lastNode;
}

// find the sum of two nodes equals the given value
// Sum is positive number??
boolean isSumOf (treeNode *min, treeNode *max, int sum)
{
    while (min->data < max->data) {
        if ((min->data + max->data) == sum) {
            return TRUE;
        } else {
            if ((min->data + max->data) > sum) {
                max = predecessorNode(max, max->data);
            } else {
                min = successorNode(min, min->data);
            }
        }
    }
    return FALSE;
}

boolean sum_tree (treeNode *node, int sum)
{
    if (node == NULL) {
        return FALSE;
    }
    treeNode *min_node = minNode(node);
    treeNode *max_node = maxNode(node);
    return (isSumOf(min_node, max_node, sum));
}

boolean isValidateBST (treeNode *node, int min, int max)
{
    if (node == NULL)
        return TRUE;
    if (node->data > max || node->data < min)
        return FALSE;
    return (isValidateBST(node->left, min, node->data-1) &&
            isValidateBST(node->right, node->data+1, max));
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

    //int arr[] = {4, 3, 2, 7, 6};
    //int arr[] = {6, 5, 9, 3, 4, 1, 2, 7, 8, 10, 11};
    // array : 10, 6, 9, ...
    //int arr[] = {10, 6, 9, 4, 5, 2, 16, 12, 17, 15};
    int arr[] = {15, 14, 13, 12, 11,  10, 6, 4, 8, 3, 5, 7, 9};
    //int arr[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size, i=0;

    node = PreOrderToInOrder(A, sizeof(A)/sizeof(A[0] ));
    printTreeNode(node);
    MorrisInorderTraversal(node);
    printPaths(node, paths, 0);

#if 1 // bt2dll
    treeNode *head = NULL;
    bt2dll(node, &head);
    printf("\n Binary Tree-to-DLL : ");
    while (head != NULL) {
        printf(" %d ", head->data);
        head = head->right;
    }
    printf("\n");
    getchar();
#endif

    int d1 = 6, d2 = 14; treeNode *n1 = searchNode(node, d1); treeNode *n2 = searchNode(node, d2);
    int dis = 0; distance(node, n2, dis, &dis);
    printf("\n distance (%d - %d): %d\n", node->data, n2->data, dis);
    //printf("\n distance(%d ->%d, %d) : %d\n", node->data, n1->data, n2->data, distanceN1N2(node, n1, n2));
    int min = 20; minDistanceLeaf(node, 0, &min);
    printf("\nMin distance leaf : %d\n", min);
    getchar();
    printf(" LowestCommonAncestorBst of %d & %d : %d \n", d1, d2, (LowestCommonAncestorBst(node, n1, n2))->data);
    printf(" LowestCommonAncestor of %d & %d : %d \n", d1, d2, (LowestCommonAncestor(node, n1, n2))->data);


    printf(" Tree is complete : %s", complete(node, 6, 0) ? "Yes" : "no");
    printf(" \nTree has path Sum = 20 %s \n", pathHasSum(node, 20) ? "Yes" : "No");
    printf(" \nTree has path Sum = 21 %s \n", pathHasSum(node, 21) ? "Yes" : "No");
    printf(" \nTree has path Sum = 33 %s \n", pathHasSum(node, 33) ? "Yes" : "No");
    printf(" \nTree has path Sum = 35 %s \n", pathHasSum(node, 35) ? "Yes" : "No");
    int n =0;
    printf("Root to Leaf Sum present ? %s\n", 
            treeRoot2LeafSumExist(node, 21, paths, &n) ? "yes" : "no");
            //pathHasSum(root, 18) ? "yes" : "no");
            printf("Paths[] = ");
            for (int i = 0; i < n; i++) {
               printf("%d ", paths[i]);
            }
            printf("\n");

    getchar();
#if 0
    // insert 4, 10, 6
    printf("\n insert 4, 10, 6\n");

    node = insertNode(node, 10);
    node = insertNode(node, 4);
    node = insertNode(node, 16);
    node = insertNode(node, 17);
    node = insertNode(node, 1);

    if (sameLevelLeafTree(node))
        printf("\n Same level leafs : True\n");
    else
        printf("\n Same level leafs : False\n");
    for (int i =1; i<4; i++)
        KthLargestNode(node, i);
    printf("\n");
    printTreeNode(node);
    printf("\n");
    printf("\n Height = %d \n", heightTree(node));
    printf("\n node2node max_distance = %d\n", node->max_dis);
    if (heightBalancedTree(node) == -1)
        printf("\n Balanced Tree Height = %s \n", "no");
    else
        printf("\n Balanced Tree Height = %s \n", "Yes");
#endif

    node = NULL;

    size = sizeof(arr)/sizeof(int);
    while (size != 0) {
        node = insertNode(node, arr[i++]);
        size--;
    }

    breadthfirst_traverse(node);
    //printTreeNode(node);
    printf("\n Height = %d \n", heightTree(node));
    printf("\n node2node max_distance = %d\n", node->max_dis);

    printPaths(node, paths, 0);
    for (int i =0; i<11; i++) {
        printf("\n %d level node(s) :", i);
        printKlevelNode(node, i);
    }
    printf("\n");
    if (heightBalancedTree(node) == -1)
        printf("\n Balanced Tree Height = %s \n", "no");
    else
        printf("\n Balanced Tree Height = %s \n", "Yes");

    int sum;
    scanf("%d", &sum);
    boolean isSum = FALSE;
    while (sum != 0) {
        isSum = sum_tree(node, sum);
        printf(" Does Sum exists ? %c\n", isSum ? 'Y' : 'N');
        isSum = FALSE;
        scanf("%d", &sum);
    }

#if 0
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
    int count;
    count = count_leaf(node);
    printf("\nNumber of Leaf nodes = %d\n", count);
    count = count_nodes(node);
    printf("Number of nodes = %d\n", count);
#endif
    /*
     * Case 0: node to be deleted does not exist
     */
    data = 17;
    temp = searchNode(node, data);
    if (temp == NULL) {
        deleted = -1; /* Tree unchanged */
    } else {
        deleted = deleteNode(temp);
    }

    if (deleted == 0) {
        printf("delete %d in Tree : Done \n", data);
        printTreeNode(node);   
    } else {
        printf("delete %d in Tree : not found \n", data);
    }
    // convert BST to Sinlge Linked List
    treeNode *last = NULL;
    convertBst2LinkedList(node, &last);
    while (last != NULL && last->left != NULL) {
        last = last->left;
    }
    treeNode *head = last;

    printf("\nNode(s) in Linked List: ");
    while (head != NULL) {
        printf(" %d", head->data);
        head = head->right;
    }
    printf("\n");
#endif
    return (node);
}

int main (int argc, char *argv[])
{
    treeNode *root;
    int count;
    size_t size;

    queueH = queueCreate(MAX_ENTRIES, sizeof(root));

    root = tree_build123();

    //breadthfirst_traverse(root);
}

