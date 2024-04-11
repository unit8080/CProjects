#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct _node {
    struct _node *next;
    char data;
} Node;
Node * reverseList(Node *);
bool palindrome (Node *head) {
    Node *node;
    // find mid point
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
           prev = slow;
           slow = slow->next;
           fast = fast->next->next;
    }
    Node *head2;
    if (fast == NULL) {
        head2 = slow;
    } else {
        head2 = slow->next;
    }
    prev->next = NULL;
    head = reverseList(head);
    node = head;
    while (node != NULL) {
        printf("%c-> ", node->data);
        node = node->next;
    }
    printf("NULL \n");

    node = head2;
    while (node != NULL) {
        printf("%c-> ", node->data);
        node = node->next;
    }
    printf("NULL \n");
    
    while (head2 != NULL) {
        if (head->data != head2->data)
            return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
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
    D->data = 'B';
    Node *E = malloc(sizeof(Node));
    E->data = 'A';
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
    printf("%s\n", palindrome(A) ? "Yes" : "no");
    /* Node *newHead = reverseList(A); */
    node = A;
    while (node != NULL) {
        printf("%c-> ", node->data);
        node = node->next;
    }
    printf("NULL \n"); 
}
