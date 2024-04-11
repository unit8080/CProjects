/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 911
struct  HashNode {
    int key;
    int val;
    struct HashNode* next;
};

struct Hash {
    int size;
    struct HashNode* hash;
};

void hash_init(       struct Hash* self);
void hash_insert(     struct Hash* self, int key, int val);
int  hash_find( struct Hash* self, int key);
void hash_free(       struct Hash* self);

void hash_init(struct Hash* self) {
    self->size = HASH_SIZE;
    self->hash = (struct HashNode*)malloc(sizeof(struct HashNode)*self->size);
    for (int i = 0; i < self->size; ++i)
        self->hash[i].next = NULL;
}

int hash_get_key_index(struct Hash* self, int key) {
    return abs(key)%self->size;
}

void hash_insert(struct Hash* self, int key, int val) {
    struct HashNode* p        = self->hash + hash_get_key_index(self, key);
    struct HashNode* new_node = (struct HashNode*)malloc(sizeof(struct HashNode));
    new_node->key  = key;
    new_node->val  = val;
    new_node->next = p->next;
    p->next        = new_node;
}

int  hash_find(struct Hash* self, int key) {
    struct HashNode* p = self->hash + hash_get_key_index(self, key);
    while (p->next != NULL) {
        p = p->next;
        if (p->key == key)
            return p->val;
    }
    return -1;
}
void hash_free(struct Hash* self) {
    for (int i = 0; i < self->size; ++i) 
        if (self->hash[i].next != NULL) {
            struct HashNode* p = self->hash[i].next;
            self->hash[i].next = p->next;
            free(p);
        }
}

int* twoSum(int* nums, int numsSize, int target) {
    struct Hash hash;
    hash_init(&hash);
    int *result = (int *)malloc(sizeof(int)*2);
    for (int i = 0; i < numsSize; i++) {
        if ((result[0] = hash_find(&hash, target - nums[i])) != -1) {
            result[1] = i;
            hash_free(&hash);
            return result;
        }
        hash_insert(&hash, nums[i], i);
    }
    free(result);
    hash_free(&hash);
    return NULL;
}

int main (void) 
{
    int arr[5] = {5, 2,7,11,15};
    int target = 9; 

    int *result = twoSum(arr, 4, 9);
    if (result) {
        printf("% d %d\n", result[0], result[1]);
        free(result);
    }
}
