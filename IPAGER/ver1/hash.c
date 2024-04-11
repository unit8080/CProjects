#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "hash.h"

#define HASH_BUCKET_SIZE 20
#define HASH_MODULO      257

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
int hashIndex ( HashTable *table, int ipaddr )
{
    int hash = 0;
    unsigned char *c = (unsigned char *)&ipaddr;
    for (int i = 0; i < sizeof(ipaddr); i++) {
        hash = (hash +  c[i]) % table->modulo;
    }
    return hash % table->size;
}
HashNode *newHashNode (unsigned int ipaddr)
{
    HashNode *node = (HashNode *) malloc( sizeof(HashNode));
    node->ipaddr = ipaddr;
    node->next = NULL;
    node->listnode = NULL;
    return node;
}
HashNode* HashInsert (HashTable *table, int ipaddr)
{
    HashNode *node = newHashNode(ipaddr);
    int hashIdx = hashIndex(table, ipaddr);
    node->next = table->array[hashIdx].head;
    table->array[hashIdx].head = node;
    return node;
}
HashNode* HashFind (HashTable *table, int ipaddr)
{
    HashNode *node; 
    int hashIdx = hashIndex(table, ipaddr);
    node = table->array[hashIdx].head;
    while (node != NULL) {
        if (node->ipaddr == ipaddr)
            return node;
        node = node->next;
    }
    return NULL;
}
void showAgerTableEntry(HashNode *node, FILE *fp, char *str) 
{
    time_t t;
    unsigned int ipaddr = node->ipaddr;
    str = ctime(&(node->listnode->start));
    str[20] = '\0';
    printf("%s : ", str);
    time(&t);
    str = ctime(&t);
    str[20] = '\0';
    printf("%s : ", str);
    printf(" IpAddr = ");
    printf("%02x.%02x.%02x.%02x\t%d\n", (ipaddr & 0xff000000) >> 24,
            (ipaddr & 0x00ff0000) >> 16,
            (ipaddr & 0x0000ff00) >> 8,
            (ipaddr & 0x000000ff), node->listnode->tmo);
}
void showAgerTable ( HashTable *table )
{
    FILE * fp;
    fp = fopen("output.txt", "w");
    char *str = (char *)malloc(sizeof(char)*26);
    for (int i=0; i<table->size; i++) {
        HashNode *node = table->array[i].head;
        printf("Table->array[%d] :\n", i);
        while (node != NULL) {
            showAgerTableEntry(node, fp, str);
            node = node->next;
        }
    }
    fclose(fp);
}
HashTable* hashListInit()
{
    HashTable *table = createHashTable(HASH_BUCKET_SIZE, HASH_MODULO);
#if 0
    HashInsert(table, 0xffffffff);
    HashInsert(table, 0x0f0f0f0f);
    HashInsert(table, 0x01020304);
    HashInsert(table, 0x05060708);
    HashInsert(table, 0x05060709);
    sleep(5);
    showAgerTable(table);
#endif
    return table;
}

#if 0
int main()
{
    hashListInit();
}
#endif

