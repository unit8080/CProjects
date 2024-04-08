/*
 * Trie implementation
 * (c) Sanjeev Singh - Jan 2016 
 * T = O(key_length)
 * S = O(ALPHABET_SIZE * key_length * N) 
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_SIZE (26)
#define INDEX(c)  ((int)c - (int)'a')
typedef struct TrieNode_ {
    int value;
    struct TrieNode_ *keys[ALPHABET_SIZE];
} TrieNode;
typedef struct Trie_ {
    int count;
    TrieNode *root;
} Trie;

TrieNode *newTrieNode(void)
{
    TrieNode *node = (TrieNode *) malloc(sizeof(TrieNode));
    if (node) {
        node->value = 0;
        for (int i=0; i < ALPHABET_SIZE; i++)
           node->keys[i] = NULL;
    }
    return node;
}
Trie *TrieInit (void)
{
    Trie *trie = (Trie *) malloc(sizeof(Trie));
    trie->count = 0;
    trie->root = newTrieNode();
    return trie;
}    
void TrieInsert (Trie *trie, char str[])
{
    int len = strlen(str);
    int index;
    TrieNode *node;
    trie->count++;
    node = trie->root;
    for (int level = 0; level < len; level++)
    {
        index = INDEX(str[level]);
        if (node->keys[index] == NULL) {
            node->keys[index] = newTrieNode();
        }
        node = node->keys[index];
    }
    /* mark last node as leaf */
    node->value = trie->count;
}
int TrieSearch (Trie *trie, char key[])
{
    TrieNode *node = trie->root;
    int index; 
    int len = strlen(key);
    for (int level = 0; level < len; level++)
    {
        index = INDEX(key[level]);
        if (node->keys[index] == NULL)
            return 0;
        node = node->keys[index];
    }
    //return ((node != NULL) && (node->value));
    if ((node != NULL) && (node->value))
        return 1;
    else 
        return 0;
}

bool isItFreeNode (TrieNode *node)
{
    for (int i=0; i<ALPHABET_SIZE; i++) {
        if (node->keys[i] != NULL) 
            return false;
    } 
    return true;
}
bool LeafNode (TrieNode *node)
{
    if (node->value)
        return true;
    else
        return false;
}
bool deleteHelper (TrieNode *node, char str[], int level, int len)
{
    if (node != NULL) {
        if (level == len) { //base case
            if (LeafNode(node)) {
                if (isItFreeNode(node))
                    return true;
                 else 
                     return false;
            }
        } else { // recursive case
            int index = INDEX(str[level]);
            if (deleteHelper(node->keys[index], str, level+1, len) ) {
                free(node->keys[index]);
                node->keys[index] = NULL;
                return (!LeafNode(node) && isItFreeNode(node));
            }
        }
    }
    return false;
}
void TrieDelete (Trie *trie, char str[])
{

    int len = strlen(str);
    TrieNode *node = trie->root;
    deleteHelper(node, str, 0, len);
}
Trie *trie;
int main()
{
    char keys[][9] = {"the", "ab", "ans", "there", "answer", "any", "by", "bye", 
                        "their"};
    char output[][32] = {"Not present in Trie", "present in trie"};

    trie = TrieInit();
    for (int i= 0; i < 9; i++) {
        printf("Inserting %s\n", keys[i]);
        TrieInsert(trie, keys[i]);
    }
    printf("%s ..... %s\n", "the", output[TrieSearch(trie, "the")]);
    printf("%s ..... %s\n", "thereis", output[TrieSearch(trie, "thereis")]);
    printf("%s ..... %s\n", "and", output[TrieSearch(trie, "and")]);
    printf("%s ..... %s\n", "answer", output[TrieSearch(trie, "answer")]);
    printf("%s ..... %s\n", "ans", output[TrieSearch(trie, "ans")]);
    printf("%s ..... %s\n", "an", output[TrieSearch(trie, "and")]);
    printf("%s ..... %s\n", "any", output[TrieSearch(trie, "and")]);
    printf("%s ..... %s\n", "ab", output[TrieSearch(trie, "and")]);
    printf("Deleting %s\n", "the");
    TrieDelete(trie, "the");
    printf("Deleting %s\n", "answer");
    TrieDelete(trie, "answer");
    printf("%s ..... %s\n", "answer", output[TrieSearch(trie, "answer")]);
    printf("%s ..... %s\n", "the", output[TrieSearch(trie, "and")]);
}
