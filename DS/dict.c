#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct hashNode_ {
    char name[12];
    unsigned int phone;
    //ListNode *listnode;
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

HashNode *newHashNode (char name[])
{
    HashNode *node = (HashNode *) malloc( sizeof(HashNode));
    strcpy(node->name, name) ;
    //node->name[11] = '\0';
    node->next = NULL;
    return node;
}
HashTable *createHashTable( int size, int modulo)
{
    HashTable *table = (HashTable *) malloc(sizeof(table)); // nomem
    table->size = size;
    table->modulo = modulo;
    table->array = (HashList *) malloc(sizeof(HashList *) * size); // nomem
    if (table->array == NULL)
        printf("Error - no memory\n");
    for (int i = 0; i < size; i++)
        table->array[i].head = NULL;
    return table;
}
int hashIndex ( HashTable *table, char* name )
{
    int hash = 0;
    int n = strlen(name);
    for (int i = 0; i < n; i++) {
        hash = (hash +  (int)*name) % table->modulo;
        name++;
    }
    return hash % table->size;
}
void HashInsert (HashTable *table, char name[], int phone)
{
    HashNode *node = newHashNode(name);
    node->phone = phone;
    int hashIdx = hashIndex(table, node->name);
    node->next = table->array[hashIdx].head;
    table->array[hashIdx].head = node;
}

void HashFind (HashTable *table, char name[])
{
    int hashIdx = hashIndex(table, name);
    HashNode *node = table->array[hashIdx].head;
    while (node != NULL) {
        if (!strcmp(node->name, name)) {
            printf("%s=%d\n", name, node->phone);
            return;
        }
        node = node->next;
    }
    printf("Not found\n");
}
#define HASH_BUCKET_SIZE 200
#define HASH_MODULO      257
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    int phone;
    char name[12];
    HashTable *table = createHashTable(HASH_BUCKET_SIZE, HASH_MODULO);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        scanf("%d", &phone);
        //printf("Name = %s, phone = %d\n", name, phone);
        HashInsert(table, name, phone);
    }
 
    char name1[12];
    char name2[12];
    char name3[12];
    scanf("%s", name1);
    scanf("%s", name2);
    scanf("%s", name3);
    HashFind(table, name1);
    HashFind(table, name2);
    HashFind(table, name3);
    return 0;
}
