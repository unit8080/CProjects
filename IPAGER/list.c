/*
 * Linked List library functions.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include "hash.h"
#include <sys/time.h>
/*
 * Global declaration
 */
List base_list;
HashTable *table; 

uint64_t current_timestamp() {
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    uint64_t milliseconds = te.tv_sec*1000LL + 
                                te.tv_usec/1000; // caculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

void list_init(List *base)
{
    base->head = NULL;
    base->tail = NULL;
    base->counts = 0;
}
ListNode *newNode (unsigned int ipaddr, unsigned int tmo)
{
    ListNode *new_node;
    new_node = malloc(sizeof(ListNode));
    if (!new_node) {
        return (NULL);
    }
    new_node->ipaddr = ipaddr;
    new_node->tmo = tmo;
    new_node->expirytime = current_timestamp() + tmo;
    new_node->next = NULL;
    new_node->prev = NULL;
    time(&(new_node->start));
    return(new_node);
}
ListNode *ListInsertSorted(List *list, ListNode *new)
{
    ListNode *n = list->head;
    while (n != NULL && new->tmo > n->tmo) {
        n = n->next;
    }
    //assert - no mem
    if (n == NULL) {
        if (list->tail != NULL) {
            list->tail->next = new;
            new->prev = list->tail;
            list->tail = new;
        } else {
            list->tail = new;
        }
        if (list->head == NULL)
            list->head = new;
    } else {
        // insert before node n
        if (new->tmo <= n->tmo) {
            new->next = n;
            new->prev = n->prev;
            if (n->prev != NULL)
                n->prev->next = new;
            n->prev = new;
            if (list->head == n) {
                list->head = new;
            }
        } else {
        // insert after node n
            new->next = n->next;
            new->prev = n;
            if (n->next != NULL) {
                n->next->prev = n;
            }
            n->next = new;
            if (list->tail == n)
                list->tail = new;
        }
    }
    return new;
}
ListNode *ListRemove (List *list, ListNode *remove)
{
    ListNode *prev = remove->prev;
    ListNode *next = remove->next;

    if (prev != NULL) {
        prev->next = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }
    if (list->head == remove) {
        list->head = next;
    }
    if (list->tail == remove) {
        list->tail = prev;
    }
    return remove;
}
void InsertListNode (List *list, unsigned int ipaddr, unsigned int tmo)
{
    // insert node (ipaddr) in sorted list based on tmo
    HashNode *hashNode = HashFind(table, ipaddr);
    if (hashNode != NULL) {
        printf("Ip exists \n");
        // this is tricky - refresh received
        ListNode *remove = ListRemove(list, hashNode->listnode);
        remove->next = remove->prev = NULL;
        remove->tmo = tmo; // new tmo
        remove->expirytime = current_timestamp() + tmo; // new tmo
        ListInsertSorted(list, hashNode->listnode);
    } else {
        hashNode = HashInsert(table, ipaddr);
        ListNode *new = newNode(ipaddr, tmo);
        ListNode *node = ListInsertSorted(list, new);
        hashNode->listnode = node; // back reference
    }
}
// wrapper function
void AddIpAddr (unsigned int ipaddr, unsigned int tmo)
{
    InsertListNode(&base_list, ipaddr, tmo);
}
void ipager_init()
{
    table = hashListInit();
    list_init(&base_list);
}
