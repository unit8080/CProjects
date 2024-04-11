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

void reverseList (struct node **head) 
{
    struct node *prev = NULL, *curr = *head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (prev !=NULL)
        *head = prev;
}

struct node *createNode (int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

struct node * interleaveList (struct node *n)
{
    struct node *slow = n;
    struct node *fast = slow;

    while (fast != NULL & fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct node *head1 = n;
    struct node *head2 = slow->next;
    
    slow->next = NULL;
    reverseList(&head2);
    struct node *head = createNode(0); // dummy node
    struct node *curr = head;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL) {
            curr->next = head1;
            head1 = head1->next;
            curr = curr->next;
        }
        if (head2 != NULL)
        {
            curr->next = head2;
            head2 = head2->next;
            curr = curr->next;
        }
    }
    return head->next;
}

/*
 * Swap the alternate node (current node with next node)
 * 1->2->3->4->5->6->7->NULL
 * 2->1->4->3->6->5->7->NULL
 */
void swapAlternateNodeList(struct node **head)
{
    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return;

    struct node *prev, *curr1, *curr2, *next;

    prev = NULL;
    curr1 = *head;
    curr2 = curr1->next;
    next = curr2->next;
    *head = curr2;

    while (curr1 != NULL && curr2 != NULL) {

        if (prev != NULL) {
            prev->next = curr2;
        }
        prev = curr1;
        curr2->next = curr1;
        curr1->next = next;

        curr1 = next;
        if (curr1 != NULL) {
            curr2 = curr1->next;
            if (curr2 != NULL) 
                next = curr2->next;
            else 
                next = NULL;
        } else {
            curr2 = NULL;
        }
    }
}

void deleteNum ( struct node **head, int val)
{
    if (head == NULL || *head == NULL)
        return;
    struct node *curr;
    struct node *prev;
    struct node *next;
    curr = *head;
    prev = NULL;
    while (curr != NULL) {
        next = curr->next;
        if (curr->data == val) {
            if (*head == curr) {
                *head = next;
            }
            if (prev != NULL)
                prev->next = next;
            free(curr);
        } else {
            prev = curr;
        }
        curr = next;
    }
}

struct node*
sortedIntersect (struct node *a, struct node *b)
{
    if (a == NULL || b == NULL)
        return NULL;

    if (a->data < b ->data)
        return sortedIntersect(a->next, b);
    if (a->data > b->data)
        return sortedIntersect(a, b->next);

    // both have same data.
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = a->data;
    temp->next = sortedIntersect(a->next, b->next);
    return temp;
}

int getCount (struct node *h)
{
    int count = 0;
    while (h != NULL) {
        count++;
        h = h->next;
    }
    return count;
}

int _getIntersect (int d, struct node *h1, struct node *h2)
{
    struct node *cur1 = h1;
    struct node *cur2 = h2;

    for (int i = 0; i < d; i++)
    {
        if (cur1 == NULL)
            return -1;
        cur1 = cur1->next;
    }
    while (cur1 != NULL && cur2 != NULL) {
        if (cur1 == cur2)
            return cur1->data;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return -1;
}
int getIntersect (struct node *h1, struct node *h2)
{
    int c1 = getCount(h1);
    int c2 = getCount(h2);

    int d;
    if (c1 > c2) {
        d = c1 - c2;
        return _getIntersect(d, h1, h2);
    } else {
        d = c2 - c1;
        return _getIntersect(d, h2, h1);
    }
}

void printReverse (struct node *a)
{
    if (a == NULL)
        return;
    printReverse(a->next);
    printf(" %d ", a->data);
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
    //swapAlternateNodeList(&head);
    //printList(head);
        //printMiddle(head);
    }
    struct node *h = interleaveList(head);
    printList(h);
    getchar();
    printMiddle(head);
    swapAlternateNodeList(&head);
    printList(head);
    struct node *a = NULL;
    struct node *b = NULL;
    //int A[] = { };
    //int A[] = { 2, 2, 2, 2, 2};
    //int A[] = { 2};
    //int A[] = { 3};
    //int A[] = { 2, 4, 3, 2, 5, 6, 7, 4, 5, 2 };
    int A[] = {8, 6, 4, 2, 0};
    int B[] = {7, 6, 4, 3, 1};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++)
        push(&a, A[i]);
    printf("\nA list: "); printList(a); printf("\n");
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++)
        push(&b, B[i]);
    printf("\nB list: "); printList(b); printf("\n");
    struct node *c = sortedIntersect(a, b);
    printf("\n Intersect : "); printList(c); printf("\n");
    printf("\n Reverse : "); printReverse(a); printf("\n");
    getchar();
    printf("Intersection node : %d\n", getIntersect(a, b));


    deleteNum(&a, 2);
    printList(a);
    return 0;
}
