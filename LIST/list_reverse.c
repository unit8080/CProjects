#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 

// A utility function to print a given linked list
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
void printMiddle(struct node *head)
{
   struct node *slow;
   struct node *fast;

   if (head != NULL) {
   slow = fast = head;
   while (fast != NULL && fast->next != NULL)
   {
      fast = fast->next->next;
      slow = slow->next;
   }
   printf("\n Middle Node = %d\n", slow->data);   
   }
}

void  list_reverse(struct node **head_ref)
{
   struct node *current;
   struct node *next;
   struct node *prev = NULL;
   if (head_ref == NULL || *head_ref == NULL)
       return;
   current = *head_ref;
   while ( current != NULL) {
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
   }
   if (prev != NULL)
       *head_ref = prev; 
}

void recurseReverseList2(struct node *p, struct node **head)
{
    if (p->next == NULL)
    {
        *head = p;
        return;
    }
    recurseReverseList2(p->next, head);
    //p->next->next = p;
    struct node *q = p->next;
    q->next = p;
    p->next = NULL;
}

void recurseReverseList(struct node **head )
{
    if ((*head) == NULL)
        return;
    struct node *first = *head;
    struct node *rest = first->next;

    if (rest == NULL) {
        return;
    }
    recurseReverseList(&rest);
    first->next->next = first;
    first->next = NULL;
    *head = rest;
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    int i;
 
    for (i=7; i>0; i--)
    {
        push(&head, i);
        printList(head);
    }
#if 0
    list_reverse(&head);
    printList(head);
    list_reverse(&head);
    printList(head);
    recurseReverseList(&head);
    printList(head);
    recurseReverseList(&head);
    printList(head);
#else
    printList(head);
    recurseReverseList2(head, &head);
    printList(head);
    recurseReverseList2(head, &head);
    printList(head);
#endif
 
    return 0;
}
