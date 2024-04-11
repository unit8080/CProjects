#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    struct _node *next;
    char data;
} Node;
Node * reverseList(Node *);
void interleave (Node *head) {
    Node *node;
    // find mid point
    Node *slow = head;
    Node *fast = head;

    Node *mid;
    while (fast != NULL && fast->next != NULL) {
           slow = slow->next;
           fast = fast->next->next;
    }
    mid = slow->next;
    slow->next = NULL;
    mid = reverseList(mid);
    node = mid;
    while (node != NULL) {
        printf("%c-> ", node->data);
        node = node->next;
    }
    printf("NULL \n");
    Node *next;
    Node *curr = head;
    Node *midNext;
    while (mid != NULL) {
      next = curr->next; 
      curr->next = mid;
      midNext = mid->next;
      mid->next = next;
      curr = next;
      mid = midNext;
    }
}
Node * reverseList(Node *head) {
    if (head == NULL)
        return head;
    // Initialize locals
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int main (void) {
 
    Node *A = malloc(sizeof(Node));
    A->data = 'A';
    Node *B = malloc(sizeof(Node));
    B->data = 'B';
    Node *C = malloc(sizeof(Node));
    C->data = 'C';
    Node *D = malloc(sizeof(Node));
    D->data = 'D';
    Node *E = malloc(sizeof(Node));
    E->data = 'E';
    A->next = B;
    B->next = C;
    //C->next = NULL;
    C->next = D;
    //D->next = NULL;
    D->next = E;
    E->next = NULL;
    Node *node = A;
    while (node != NULL) {
        printf("%c-> ", node->data);
        node = node->next;
    }
    printf("NULL \n");
    interleave(A);
    /* Node *newHead = reverseList(A); */
    node = A;
    while (node != NULL) {
        printf("%c-> ", node->data);
        node = node->next;
    }
    printf("NULL \n"); 
}
