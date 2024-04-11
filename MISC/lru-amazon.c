#include <stdio.h>
#include <stdlib.h>
//function foo(items) {
//  var i;
//  for (i = 0; i < items.length; i++) {
//    alert("Welcome To HireOn " + items[i]);
//  }
//}
typedef struct _listNode {
    struct _listNode *next;
    struct _listNode *prev;
    int key;
} ListNode;

typedef struct _hashNode {
    struct _hashNode *next;
    int key;
    int value;
    ListNode *listNode;
} HashNode;

typedef struct _hassList {
    HashNode *head;
} HashList;

typedef struct _hashTable {
    int size;
    int modulo;
    HashList *bucket;
    ListNode *head;
    ListNode *tail;
    int maxLru;
    int count;
} HashTable;

HashTable *ht;
HashNode * HashFind(HashTable *ht, int key);
void HashDelete(HashTable *ht, int key);
void ListDelete (HashTable *ht, ListNode *ln)
{
    if (ht == NULL || ln == NULL || ht->count == 0)
        return;
    if (ht->tail == ln) {
        if (ht->tail == ht->head)
            ht->head = NULL;
        ht->tail = ht->tail->next;
        ht->tail->prev = NULL;
    } else if (ht->head == ln) {
        ht->head = ht->head->prev;
        ht->head->next = NULL;
    } else {
        ln->next->prev = ln->prev;
        ln->prev->next = ln->next;
    }
    free((void *)ln);
}
void deleteNode (HashTable *ht, int key)
{
    HashNode *hn = HashFind(ht, key);
    if (hn == NULL)
        return;
    ListNode *ln = hn->listNode;
    ListDelete(ht, ln);
    HashDelete(ht, key); // updates count
}
int main (void)
{
}
