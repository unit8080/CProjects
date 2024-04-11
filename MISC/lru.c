#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef struct _listNode {
    struct _listNode *next;
    struct _listNode *prev;
    int key; // required to evict last entry if LRU full
} ListNode;

typedef struct _hashNode {
    int key;
    int value;
    struct _hashNode *next;
    ListNode *listNode;
} HashNode;

typedef struct _hashList {
    HashNode *head;
} HashList;

typedef struct _hashTable {
    int size;
    int modulo;
    HashList *bucket;
    ListNode *head;
    ListNode *tail;
    int maxLRU;
    int count;
} HashTable;

HashTable *hashTable = NULL;
HashTable *HashInit (int size, int modulo) { return NULL; }
HashNode *HashInsert (HashTable *ht, int key, int value) { return NULL; }
HashNode *HashDelete (HashTable *ht, int key) { return NULL; }
HashNode *HashFind (HashTable *ht, int key) { return NULL; }
ListNode *ListInsert (HashTable *ht, int key) { return NULL; }
ListNode *ListDelete (HashTable *ht, ListNode *node) { return NULL; }
ListNode *ListMove (HashTable *ht, ListNode *node) {return NULL;}

void set_value (int key, int value) 
{
    HashNode *hn = HashFind(hashTable, key);
    if (hn == NULL) { // it's new key
        if (hashTable->count >= hashTable->maxLRU) {
            // make space
            ListNode *delNode = hashTable->tail;
            int key = delNode->key;
            HashDelete(hashTable, key);
            ListDelete(hashTable, delNode); 
        }
        hn = HashInsert(hashTable, key, value); // update count
        if (hn == NULL) return;
        ListNode *ln = ListInsert(hashTable, key); // update tail/head
        hn->listNode = ln;
        if (ln == NULL) return;
    } else { // key already present
        hn->value = value; // update new value
        ListNode *node = hn->listNode;
        ListDelete(hashTable, node); // ListMove(hashtable, ln);
        node = ListInsert(hashTable, key); // avoid free/malloc
        hn->listNode = node;
    }
}
int get_value (int key)
{
    HashNode *hn = HashFind(hashTable, key);
    if (hn != NULL) {
        ListNode *ln = hn->listNode;
        //ListDelete(hashTable, ln);
        //ln = ListInsert(hashTable, key);
        ln = ListMove(hashTable, ln);
        hn->listNode = ln;
        return hn->value;
    }
    return -1;
}
int main (void)
{
}
