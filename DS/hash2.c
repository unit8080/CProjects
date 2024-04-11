#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "list.h"

#define HASH_DEFAULT 0

typedef struct _hashNode {
    struct _hashNode *next;
    unsigned int ipaddr;
    int freq;
} HashNode;

typedef struct hashList {
    HashNode *head;
} HashList;

typedef struct hashTable_ {
    int size;
    int modulo;
    int hashType;
    HashList *array;
} HashTable;

HashNode *newHashNode (unsigned int ipaddr)
{
    HashNode *node = (HashNode *) malloc( sizeof(HashNode));
    node->ipaddr = ipaddr;
    node->next = NULL;
    return node;
}
HashTable *createHashTable( int size, int modulo, int hashType)
{
    HashTable *table = (HashTable *) malloc(sizeof(HashTable)); // nomem
    table->size = size;
    table->modulo = modulo;
    table->hashType = hashType;
    table->array = (HashList *) malloc(sizeof(HashList *) * size); // nomem
    if (table->array == NULL)
        printf("Error - no memory\n");
    for (int i = 0; i < size; i++)
        table->array[i].head = NULL;
    return table;
}
int hashIndex ( HashTable *table, int ipaddr )
{
    int hash = 0;
    if (table->hashType == HASH_DEFAULT) {
        unsigned char *c = (unsigned char *)&ipaddr;
       for (int i = 0; i < sizeof(ipaddr); i++) {
            hash = (hash +  c[i]) % table->modulo;
       }
    }
    return hash % table->size;
}
int max =0;
int result =0;
void HashInsert (HashTable *table, int ipaddr)
{
    int hashIdx = hashIndex(table, ipaddr);
    HashNode *n = table->array[hashIdx].head;
    while (n != NULL) {
        // already exists
        if (n->ipaddr == ipaddr) {
            n->freq++;
            if (n->freq > max) {
                max = n->freq;
                result = ipaddr;
            }
            break; 
        }
        n = n->next;
    }
    if (n == NULL) {
        HashNode *node = newHashNode(ipaddr);
        node->next = table->array[hashIdx].head;
        table->array[hashIdx].head = node;
        node->freq = 1;
    }
}

#if 1
void showAgerEntry(HashNode *node, FILE *fp, char *str) 
{
    time_t t;
    unsigned int ipaddr = node->ipaddr;
    //str = ctime(&node->start);
    //str[20] = '\0';
    //printf("%s : ", str);
    time(&t);
    str = ctime(&t);
    str[20] = '\0';
    printf("%s : ", str);
    printf(" IpAddr = ");
    printf("%02x.%02x.%02x.%02x\t%d\n", (ipaddr & 0xff000000) >> 24,
            (ipaddr & 0x00ff0000) >> 16,
            (ipaddr & 0x0000ff00) >> 8,
            (ipaddr & 0x000000ff), 0);//node->tmo);

    //str = ctime(&node->start);
    //str[20] = '\0';
    //fprintf(fp, "%s : ", str);
    time(&t);
    str = ctime(&t);
    str[20] = '\0';
    fprintf(fp, "%s : ", str);
    fprintf(fp, "%02x.%02x.%02x.%02x\t %d\n", (ipaddr & 0xff000000) >> 24,
            (ipaddr & 0x00ff0000) >> 16,
            (ipaddr & 0x0000ff00) >> 8,
            (ipaddr & 0x000000ff), 0);//node->tmo);
    
}
void showAger ( HashTable *table )
{
    FILE * fp;
    fp = fopen("output.txt", "w");
    char *str = (char *)malloc(sizeof(char)*26);
    for (int i=0; i<table->size; i++) {
        HashNode *node = table->array[i].head;
        printf("Table->array[%d] :\n", i);
        while (node != NULL) {
            showAgerEntry(node, fp, str);
            node = node->next;
        }
    }
    fclose(fp);
}
#endif
#define HASH_BUCKET_SIZE 20
#define HASH_MODULO      257
int main()
{
    HashTable *table = createHashTable(HASH_BUCKET_SIZE, HASH_MODULO, HASH_DEFAULT);
    int arr[] = {2, 3, 3, 5, 3, 4, 1, 7, 1, 2, 1, 1, 1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    for (int i =0; i < sz; i++) {
        HashInsert(table, arr[i]);
    }
    printf ("result = %d, freq = %d\n", result, max);
#if 0   
    HashInsert(table, 0xffffffff);
    HashInsert(table, 0x0f0f0f0f);
    HashInsert(table, 0x01020304);
    HashInsert(table, 0x05060708);
    HashInsert(table, 0x05060709);
    sleep(5);
    showAger(table);
#endif
}

