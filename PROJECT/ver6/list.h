/*
 * Linked List Library funcion declarations.
 */
#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <time.h>
typedef struct _Node
{
    unsigned int ipaddr;
    unsigned int tmo;    // position in list
    time_t       start;  // time created 
    uint64_t     expirytime; // absolute time (milsec) in future
    struct _Node *next;
    struct _Node *prev;
} ListNode;

typedef struct _List
{
    ListNode        *head;
    ListNode        *tail;
    int             counts; 
    bool            inPauseLine;
    unsigned int    pauseTmo;
    uint64_t        expirytime;
} List;

extern List base_list;
void list_init(List *);
int getListLength(List *);
void AddIpAddr(unsigned int ipaddr, unsigned int tmo);
void ipager_init();
void showAger(List *base_list);
uint64_t current_timestamp();
void age_ipaddr(bool *);

#endif /* LIST_H */
