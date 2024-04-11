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
    bool            pauseBreakOut;
    unsigned int    pauseTmo;
    uint64_t        expirytime;
} List;

void list_init(List *);
int getListLength(List *);
void AddIpAddr(unsigned int ipaddr, unsigned int tmo);

//external declaration
void ParseInputFile(void);
 
#endif /* LIST_H */
