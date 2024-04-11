/*
 * Linked List Library funcion declarations.
 */
#ifndef LIST_H
#define LIST_H

typedef struct _Node
{
    int          data;
    struct _Node *next;
} Node;

typedef struct _List
{
    Node *head;
    Node *tail;
    int  counts; 
    int  max;
} List;

void list_init(List *);
int getListLength(List *);

#endif /* LIST_H */
