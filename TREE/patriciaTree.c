#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the Patricia trie
struct Node {
    int bit;         // skipped bits
    char* prefix;    // prefix key is stored here
    char* nextHop;
    struct Node* left;   // Left node location with an address bit 0
    struct Node* right;  // Right node location with an address bit 1
};

// Patricia Trie structure
struct Patricia {
    struct Node* head;
    struct Node* BMP;
    int numberOfNodesVisited;  // Number of nodes accessed when a lookup operation is performed
    int numberOfNodeCreated;   // Total number of nodes created in the trie
    int longestLength;
};

// Function to create a new node
struct Node* createNode(int bit, char* prefix, char* nextHop) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->bit = bit;
    newNode->prefix = strdup(prefix);
    newNode->nextHop = strdup(nextHop);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to initialize the Patricia trie
struct Patricia* initializePatricia() {
    struct Patricia* patricia = (struct Patricia*)malloc(sizeof(struct Patricia));
    if (patricia == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    patricia->head = createNode(-1, NULL, NULL);
    patricia->BMP = NULL;
    patricia->numberOfNodesVisited = 0;
    patricia->numberOfNodeCreated = 0;
    patricia->longestLength = -1;
    return patricia;
}

// Function to find the Best Matching Prefix node for the given destination address
struct Node* findBMP(struct Node* h, char* destinationAddress, int b, struct Patricia* patricia) {
    if (h->bit <= b)
        return patricia->BMP;
    if (h->prefix != NULL && strlen(h->prefix) >= patricia->longestLength && strncmp(destinationAddress, h->prefix, patricia->longestLength) == 0) {
        patricia->BMP = h;
        patricia->longestLength = strlen(h->prefix);
    }
    if (!isSet(destinationAddress, h->bit)) {
        patricia->numberOfNodesVisited++;
        return findBMP(h->left, destinationAddress, h->bit, patricia);
    } else {
        patricia->numberOfNodesVisited++;
        return findBMP(h->right, destinationAddress, h->bit, patricia);
    }
}

// Function to search the Patricia trie for the given key
struct Node* searchR(struct Node* h, char* key, int i) {
    if (h->bit <= i)
        return h;
    if (!isSet(key, h->bit))
        return searchR(h->left, key, h->bit);
    else
        return searchR(h->right, key, h->bit);
}

// Function to insert a key-value pair into the Patricia trie
void put(struct Node* head, char* prefix, char* nextHop) {
    struct Node* node = searchR(head->left, prefix, -1);
    char* existing = NULL;
    if (node != NULL) {
        existing = node->prefix;
        if (strcmp(prefix, existing) == 0) {
            node->nextHop = strdup(nextHop);
            return;
        }
    }
    int bit = 0;
    while (isSet(prefix, bit) == isSet(existing, bit)) {
        ++bit;
    }
    head->left = insertR(head->left, prefix, nextHop, bit, head);
}

// Function to insert a key-value pair into the Patricia trie (recursive)
struct Node* insertR(struct Node* h, char* key, char* nextHop, int i, struct Node* p) {
    if (h->bit >= i || h->bit <= p->bit) {
        struct Node* t = createNode(i, key, nextHop);
        patricia->numberOfNodeCreated++;
        int isSet = isSet(key, t->bit);
        t->left = isSet ? h : t;
        t->right = isSet ? t : h;
        return t;
    }
    if (!isSet(key, h->bit)) {
        h->left = insertR(h->left, key, nextHop, i, h);
    } else {
        h->right = insertR(h->right, key, nextHop, i, h);
    }
    return h;
}

// Function to check if the key's bit at the given bit index is set
int isSet(char* key, int bitIndex) {
    if (key == NULL)
        return 0;
    int index = bitIndex / 8;
    int bit = bitIndex % 8;
    if (index >= strlen(key))
        return 0;
    int mask = 1 << (7 -
    return (key[index] & mask) != 0;
}

// Function to get the number of nodes visited during a lookup operation
int getNumberOfNodesVisited(struct Patricia* patricia) {
    return patricia->numberOfNodesVisited;
}

// Function to get the total number of nodes created in the trie
int getNumberOfNodeCreated(struct Patricia* patricia) {
    return patricia->numberOfNodeCreated + 1;
}
