#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_HASH_SIZE 911
typedef struct _hashNode {
    int key;
    int value;
    struct _hashNode *next;
} HashNode;
typedef struct _HashTable {
    int size;
    HashNode *hashList;
} HashTable;
HashTable *ht = NULL;
int hash_index (HashTable *self, int key)
{
    return key % self->size;
}
HashTable *hash_init (void)
{
    ht = (HashTable *) malloc(sizeof(HashTable));
    assert(ht != NULL);
    ht->size = MAX_HASH_SIZE;
    ht->hashList = (HashNode *) malloc(sizeof(HashNode) * ht->size);
    assert(ht->hashList != NULL);
    for (int i = 0; i < ht->size; i++) {
        ht->hashList[i].next = NULL;
    }
    return ht;
}
void hash_free (HashTable *self)
{
    for (int i = 0; i < self->size; i++) {
        HashNode *p = self->hashList[i].next;
        while (p != NULL) {
            HashNode *next = p->next;
            free(p);
            p = next;
        }
    }
    free(self->hashList);
    free(self);
}
void hash_insert (HashTable *ht, int key, int value) 
{
    int idx = hash_index(ht, key);
    HashNode *p = ht->hashList + idx;
    HashNode *hnode = (HashNode *) malloc(sizeof(HashNode));
    assert(hnode != NULL);
    hnode->key = key;
    hnode->value = value;
    hnode->next = p->next;
    p->next = hnode;
}
int hash_find (HashTable *ht, int key) 
{
    int idx = hash_index(ht, key);
    HashNode *p = ht->hashList + idx;
    while (p->next != NULL) {
        p = p->next;
        if (p->key == key)
            return p->value;
    }
    return -1;
}
int * sum2target (int *arr, int size, int target) 
{
    ht = hash_init();
    for (int i = 0; i < size; i++) {
        int num = arr[i];
        int index = hash_find(ht, target - num);
        if (index != -1) { // found other partner
            int *result = (int *) malloc(2 * sizeof(int));
            assert(result != NULL);
            result[0] = index;
            result[1] = i;
            hash_free(ht);
            return result;
        } else {
            hash_insert(ht, num, i);
        }
    }
    hash_free(ht);
    return NULL;
}
int main (void)
{
    int size = 5, target = 9;
    int arr[] = { 1, 7, 2, 4, 5};
    int *result = sum2target(arr, size, target);
    if (result) {
        printf(" %d %d\n", result[0], result[1]);
        free(result);
    }
}
