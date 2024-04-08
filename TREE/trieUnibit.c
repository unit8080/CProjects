// (c) Sanjeev Singh, 2017

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct _TrieNode {
    int nexthop;              // if prefix node
    struct _TrieNode *left;  // left node with address bit '0' 
    struct _TrieNode *right; // right node with address bit  "1" 
} TrieNode;

TrieNode *root;
TrieNode *BMP;
int numberOfNodeVisited;
TrieNode *searchTrie(TrieNode *node, const char *dest, int b);
TrieNode *insertTrie (TrieNode *node, const char *dest, int nh, int b);

int longestPrefixMatch (const char *destinationAddress) 
{
    numberOfNodeVisited = 0;
    BMP = NULL;
    BMP = searchTrie(root, destinationAddress, 0);
    if (BMP == NULL)
        return -1;
    return BMP->nexthop;
}

TrieNode *searchTrie (TrieNode *node, const char *dest, int b)
{
    if (node == NULL)        // base NULL condition
        return BMP;
    if (node->nexthop != -1) // Cache BMP
        BMP = node;
    if (b == strlen(dest))   // if reached prefix length.
        return BMP;
    if (*(dest + b) == '0') {  // recurse left
        numberOfNodeVisited++;
        return searchTrie(node->left, dest, b+1);
    }
    else // recurse right
    {
        numberOfNodeVisited++;
        return searchTrie(node->right, dest, b+1);
    }
}

TrieNode *newNode ()
{
    TrieNode *new = malloc(sizeof(TrieNode));
    new->nexthop = -1;
    new->left = NULL;
    new->right = NULL;
    return new;
}

TrieNode *insertTrie (TrieNode *node, const char *dest, int nh, int b)
{
    if (node == NULL) {
        node = newNode();
    }
    if (b == strlen(dest)) {
        node->nexthop = nh;
        return node;
    }
    if (*(dest + b) == '0') {
        node->left = insertTrie(node->left, dest, nh, b+1);
    } else {
        node->right = insertTrie(node->right, dest, nh, b+1); 
    }
    return node;
}

void addPrefix (const char *prefix, int nexthop)
{
    root = insertTrie(root, prefix, nexthop, 0);
}

void printKlevelNode(TrieNode *node, int k)
{
    if (node == NULL || k < 0)
        return;

    if (k == 0) {
        printf(" %d", node->nexthop);
        return;
    }
    printKlevelNode(node->left, k-1);
    printKlevelNode(node->right, k-1);
}
int main()
{
    root = newNode();
    root->nexthop = 1;
    addPrefix("1", 2);
    addPrefix("00", 3);
    addPrefix("101", 4);
    addPrefix("111", 5);
    addPrefix("1000", 6);
    addPrefix("11101", 7);
    addPrefix("111001", 8);
    addPrefix("1000011", 9);

    for (int i =0; i<10; i++) {
        printf("\n %d level node(s) :", i);
        printKlevelNode(root, i);
    }
    printf("\n");
}

