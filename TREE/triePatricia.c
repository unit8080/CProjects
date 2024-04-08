// (c) Sanjeev Singh, 2017
// Patricia Trie implementation

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct _PatTrieNode {
    int bit;                    // skip bit index
    char prefix[32];            // 0's or 1's
    int nexthop;                // internal prefix node
    struct _PatTrieNode *left;  // left node with address bit '0' 
    struct _PatTrieNode *right; // right node with address bit  "1" 
} Node;

Node *newNode (char *prefix, int nexthop, int bit)
{
    Node *new = malloc(sizeof(Node));
    new->bit = bit;
    strncpy(new->prefix, (const char *)prefix, strlen(prefix));
    new->prefix[strlen(prefix)] = '\0';
    new->nexthop = nexthop;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node *head = NULL;
Node *BMP = NULL;
int numberOfNodesVisited = 0;
int numberOfNodesCreated = 0;
int longestLength = -1;
Node *searchTrie(Node *node, char *dest, int b);
Node *insertTrie (Node *node, char *dest, int nh, int b);

unsigned int MSB = 1 << (sizeof(char) -1);
static bool isSet (char *key, int bitIndex) 
{
    if (key == NULL)
        return false;

    int index = (int) (bitIndex / sizeof(char));
    int bit =   (int) (bitIndex % sizeof(char));

    if (index >= strlen(key))
        return false;

    unsigned int mask = (unsigned int)MSB >> bit;
    return (key[index] & mask) != 0;
}

static bool equals (char *prefix1, char *prefix2) 
{
    if (prefix1 == NULL) {
        return (prefix2 == NULL);
    }
    return strcmp(prefix1, prefix2) == 0;
}

bool startsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? false : strncmp(pre, str, lenpre) == 0;
}

Node *findBMP (Node *node, char *destAddr, int b)
{
    if (node->bit <= b)
        return BMP;

    size_t lenpre = strlen(node->prefix);
    if (lenpre >= longestLength && startsWith(node->prefix, destAddr)) {
        BMP = node;
        longestLength = lenpre;
    }
    if (!isSet(destAddr, node->bit)) {
        numberOfNodesVisited++;
        return findBMP(node->left, destAddr, node->bit);
    } else {
        numberOfNodesVisited++;
        return findBMP(node->right, destAddr, node->bit);
    }
}

int longestPrefixMatch (char *destinationAddress) 
{
    numberOfNodesVisited = 0;
    longestLength = -1;
    BMP = NULL;
    BMP = findBMP(head->left, destinationAddress, -1);
    if (BMP == NULL)
        return -1;
    return BMP->nexthop;
}

Node * searchR (Node *node, char *destAddr, int i)
{
    if (node->bit <= i) {
        return node;
    }
    if (!isSet(destAddr, node->bit)) {
        return searchR(node->left, destAddr, node->bit);
    } else {
        return searchR(node->right, destAddr, node->bit);
    }
}

Node * insertR (Node *node, char *prefix, int nexthop, int i, Node  *p)
{
    if ((node->bit >= i) || (node->bit <= p->bit)) {
        Node *t = newNode(prefix, nexthop, i);
        numberOfNodesCreated ++;

        bool isBitSet = isSet(prefix, t->bit);
        t->left = isBitSet ? node : t;
        t->right = isBitSet ? t : node;
        return t;
    }
    if (!isSet(prefix, node->bit)) {
        node->left = insertR(node->left, prefix, nexthop, i, node);
    } else {
        node->right = insertR(node->right, prefix, nexthop, i, node);
    }
    return node;
}

void put (char *prefix, int nexthop)
{
    Node *node = searchR(head->left, prefix, -1);

    char *existing = NULL;
    if (node != NULL) {
        existing = node->prefix;
        if (equals(prefix, existing)) {
            node->nexthop = nexthop;
            return;
        }
    }
    int bit = 0;
    while (isSet(prefix, bit) == isSet(existing, bit)) {
        ++bit;
    }
    head->left = insertR(head->left, prefix, nexthop, bit, head);
}

void printKlevelNode(Node *node, int k)
{
    if (node == NULL || k < 0)
        return;

    if (k == 0) {
        printf("\n prefix: %s nexthop: %d skip: %d", node->prefix, 
                node->nexthop, node->bit);
        return;
    }
    printKlevelNode(node->left, k-1);
    printKlevelNode(node->right, k-1);
}
int main()
{
    head = newNode("0", -1, -1);
    head->left = head;
#if 1
    put("01", 2);
    put("001", 3);
    put("101", 4);
    put("111", 5);
    put("1000", 6);
    put("11101", 7);
    put("1000011", 9);
    put("111001", 8);
#endif 

    char *destAddr = "111";
    printf("prefix match: %d", longestPrefixMatch(destAddr));
    getchar();
    for (int i =0; i<5; i++) {
        printf("\n\n %d level node(s) :", i);
        printKlevelNode(head->left, i);
    }
    printf("\n");
}

#if 0
Node *searchTrie (Node *node, char *dest, int b)
{
    if (node == NULL)        // base NULL condition
        return BMP;
    if (node->nexthop != -1) // Cache BMP
        BMP = node;
    if (b == strlen(dest))   // if reached prefix length.
        return BMP;
    if (*(dest + b) == '0') {  // recurse left
        numberOfNodesVisited++;
        return searchTrie(node->left, dest, b+1);
    }
    else // recurse right
    {
        numberOfNodesVisited++;
        return searchTrie(node->right, dest, b+1);
    }
}

Node *insertTrie (Node *node, char *dest, int nh, int b)
{
    if (node == NULL) {
        node = newNode(dest, nh, 0); // TBD
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

void addPrefix (char *prefix, int nexthop)
{
    head = insertTrie(head, prefix, nexthop, 0);
}
#endif
