#ifndef HASH_H
#define HASH_H

#include "list.h"

typedef struct hashNode_ {
    unsigned int ipaddr;
    ListNode *listnode;
    struct hashNode_ *next;
} HashNode;
typedef struct hashList {
    HashNode *head;
} HashList;
typedef struct hashTable_ {
    int size;
    int modulo;
    HashList *array;
} HashTable;
HashTable * hashListInit();
HashNode* HashInsert (HashTable *table, int ipaddr);
HashNode* HashFind (HashTable *table, int ipaddr);
void showAgerTable ( HashTable *table );

#endif /* HASH_H */

