/*
 * Linked List library functions.
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

/* Data Structure 
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
} List;
*/

/*
 * Global declaration
 */
List base_list;
List new_list;

void list_init(List *base)
{
    base->head = NULL;
    base->tail = NULL;
    base->counts = 0;
    base->max = INT_MAX;
}

Node *addNode (int data)
{
    Node *new_node;

    new_node = malloc(sizeof(Node));
    if (!new_node) {
        return (NULL);
    }
    new_node->data = data;
    new_node->next = NULL;
    return(new_node);
}

void BuildListFromArray (List *base, int *array, int len)
{
    Node *new;
    Node *cur;
    int index = 0;
    
    list_init(base);
    new = addNode(array[index]);
    if (!new) {
        return;
    }
    index++;
    base->head = new;
    base->tail = new;
    base->counts = 1; /* first node */
    cur = new;
    while (index < len) {
        new = addNode(array[index]);
        if (!new) {
            base->tail = cur;
            return;
        }
        cur->next = new;
        cur = new;
        index++;
        base->counts++;
    }
    base->tail = cur;
}

static void PrintOneTwoThree (List *base)
{
    Node *cur_node;

    cur_node = base->head;
    printf("List[] = ");
    while (cur_node != NULL) {
        printf("%d->", cur_node->data);
        cur_node = cur_node->next;
    }
    printf("NULL\n");
    printf("Total Nodes = %d  ", base->counts);
    if (base->head) {
        printf("Head data = %d : ", base->head->data);
        printf("Tail data = %d\n", base->tail->data);
    }
}

static void BuildOneTwoThree (List *base)
{
    Node *new_node;
    Node *cur_node;

    new_node = (Node *) malloc(sizeof(Node));
    base->head = new_node;
    base->tail = new_node;
    base->counts++;
    new_node->data = 1;
    new_node->next = NULL;

    cur_node = new_node;

    new_node = (Node *) malloc(sizeof(Node));
    base->tail = new_node;
    base->counts++;
    cur_node->next = new_node;
    new_node->data = 2;
    new_node->next = NULL;

    cur_node = new_node;

    new_node = (Node *) malloc(sizeof(Node));
    base->tail = new_node;
    base->counts++;
    cur_node->next = new_node;
    new_node->data = 3;
    new_node->next = NULL;
}

static void reverse_list(Node **headRef)
{
    Node *first;
    Node *rest;

    if (*headRef == NULL) return;

    first = *headRef;  // {1, 2, 3}
    rest = first->next; // {2, 3}

    reverse_list(&rest);
    first->next->next = first;
    first->next = NULL;

    *headRef = rest;
}

#if 1
static void ReverseListRecur(List *base)
{
    Node *node;

    printf("Now Reversing the Linked List here--->\n");
    node = base->head;
    base->tail = node;
    reverse_list(&base->head);
}
#endif

static void ReverseList (List *base)
{
    Node *prev;
    Node *curr;
    Node *next;

    printf("Now Reversing the Linked List here--->\n");
    curr = base->head; // Initialize the current
    base->tail = curr;

    prev = NULL;       // Initialize the prev
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    base->head = prev;
}

int getListLength (List *base)
{
    Node *curr;
    int count = 0;

    curr = base->head;
    while (curr != NULL) {
        curr = curr->next;
        count++;
    }
    return (count);
}

/*
 * Counts the duplicates in list
 */
int count (List *base, int num)
{
    Node *curr;
    int count = 0;

    if (base == NULL || base->head == NULL) {
        return (-1);
    }
    curr = base->head;
    /*
     * Never use (!curr) in while loop check
     */
    while (curr != NULL) {
        if (curr->data == num) {
            count++;
        }
        curr = curr->next;
    }
    return (count);
}

/*
 * Deletes the node in entrire list.
 */
void deleteList (List *base)
{
    Node *curr;
    Node *next;

    if (base == NULL) {
        return;
    }
    curr = base->head;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    base->head = NULL;
    base->tail = NULL;
    base->counts = 0;
}

/*
 * Get Nth from begining of the list
 */
int GetNth (Node *head, int index)
{
    Node *curr;
    int count = 0;
    
    if (head == NULL) {
        return -1;
    }

    curr = head;
    while (curr != NULL) {
        if (count == index) {
            return curr->data;
        }
        count++;
        curr = curr->next;
    }
    return -1;
}

/* 
 * GetNthfromLast - Get Nth node from last.
 * Algo: 
 *  - Take two pointers and initialize to head
 *  - Move Last-ptr by N-nodes
 *  - then move first-ptr until, last-ptr hits null
 */
int 
getNthFromLast (Node *headRef, const int nth)
{
    Node *first;
    Node *last;

    if (headRef == NULL)
        return -1;
    first = headRef;
    last = headRef;
    int i = 0;
    while ((i++ < nth) && (last != NULL)) {
        last = last->next;
    }
    if (last == NULL) {
        // nth is too large.
        return -1;
    }
    while (last != NULL) {
        first = first->next;
        last = last->next;
    }
    return first->data;
}

int peekList (Node **headRef)
{
    Node *head;
    if (headRef == NULL || *headRef == NULL)
        return -1;
    head = *headRef;
    return head->data;
}

int popList (Node **headRef)
{
    Node *head;
    int  data;

    head = *headRef;
    //assert(head != NULL);
    data = head->data;
    *headRef = head->next;
    free(head);
    return (data);
}

void pushList (Node **headRef, int data)
{
    Node *new;
    new = addNode(data);
    if (!new) {
        return;
    }
    new->next = (*headRef);
    (*headRef) = new;
}

int InsertNthList (Node **headRef, int index, int data)
{
    if (headRef == NULL)
        return -1;
    /*
     * Special case for index = 0
     */
    if (index == 0) {
        pushList(headRef, data);
    } else {
        Node *curr = *headRef;
        int i;

        for (i = 0; i < index-1; i++) {
             if (curr == NULL)
                 return -1;
             curr = curr->next;
        }
        if (curr == NULL)
            return -1;

        pushList(&(curr->next), data);
    }
    return 0;
}

/* 
 * This code is property of the Sanjeev Singh
 * Copyright (c)
 * Copy, dup, use it at your own risk.
 */

void remove_node (Node **headRef, int val, List *base)
{
    // stack variable check
    if (headRef == NULL || *headRef == NULL) {
        return;
    }

    Node *curr = *headRef;
    Node *prev = NULL;

    //  Walk the list and find and delete the node matching val.
    while (curr != NULL) {
        if (curr->data == val) {
            Node *del = curr;
            if (curr == *headRef) {
                *headRef = curr->next;
            } 
            if (prev != NULL) {
                prev->next = curr->next;
                // prev is not updated.
            }
            base->counts--;
            free(del);
        } else { 
            // val does not match - update prev
            prev = curr;
        }
        curr = curr->next;
    } // end of while
    base->tail = prev;
}

void delete_dup_sorted_list (Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *curr = head;
    Node *next = curr->next;

    while ((curr != NULL) && (next != NULL)) {
        if  (curr->data == next->data) {
            Node *del_node = next;

            curr->next = next->next;
            free(del_node);
            next = curr->next;
        } else {
            curr = next;
            if (curr != NULL)
                next = curr->next;
            else 
                next = NULL;
        }
    }
}

int arr_num1[] = {2,3,4,5,6,7,83,45,55,4,3};
int arr_num2[] = {3,3,4,5,6,7,83,45,55,4,3};
//int arr_num3[] = {2,2,3,3,4,4,5,6};
// int arr_num3[] = {2,2};
//int arr_num3[] = {2};
int arr_num3[] = {};
int main(int argc, char *argv[])
{
    int times; 
    int data;

    list_init(&base_list);
#if 1
    BuildOneTwoThree(&base_list);
    PrintOneTwoThree(&base_list);
    ReverseList(&base_list);
    PrintOneTwoThree(&base_list);
    printf("List size is : %d\n", getListLength(&base_list));
#endif 

    BuildListFromArray(&new_list, arr_num1, 11);
    PrintOneTwoThree(&new_list);
    remove_node(&new_list.head, 3, &new_list);
    PrintOneTwoThree(&new_list);
    
    BuildListFromArray(&new_list, arr_num2, 11);
    PrintOneTwoThree(&new_list);
    remove_node(&new_list.head, 3, &new_list);
    PrintOneTwoThree(&new_list);
    printf("Inserting 6 at index 9 in List\n");
    InsertNthList(&(new_list.head), 9, 6); 
    new_list.counts++;
    PrintOneTwoThree(&new_list);

    BuildListFromArray(&new_list, arr_num3, sizeof(arr_num3)/sizeof(arr_num3[0]));
    PrintOneTwoThree(&new_list);
    delete_dup_sorted_list(new_list.head);
    PrintOneTwoThree(&new_list);
#if 1
    times = count(&new_list, 5);
    printf("5 occurred %d times in Linked List\n", times);
    times = count(&new_list, 3);
    printf("3 occurred %d times in Linked List\n", times);
    printf("Inserting  3 in Linked List\n");
    pushList(&(new_list.head), 3);
    new_list.counts++;
    times = count(&new_list, 3);
    printf("3 occurred %d times in Linked List\n", times);
    
    PrintOneTwoThree(&new_list);
    printf("Inserting 3 at index 3 in List\n");
    InsertNthList(&(new_list.head), 3, 3); 
    new_list.counts++;
    PrintOneTwoThree(&new_list);
    data = GetNth(new_list.head, 7);
    printf("7th element in Linked List = %d\n", data);
    data = GetNth(new_list.head, 9);
    printf("9th element in Linked List = %d\n", data);
    times = count(&new_list, 3);
    printf("3 occurred %d times in Linked List\n", times);

    data = popList(&(new_list.head));
    new_list.counts--;
    printf("Poped at head %d in Linked List\n", data);
    PrintOneTwoThree(&new_list);
    printf("getNthFromLast at index 5 = %d\n", getNthFromLast(new_list.head, 5));
    deleteList(&new_list);
    PrintOneTwoThree(&new_list);
#endif
}
