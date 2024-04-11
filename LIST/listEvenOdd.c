#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    struct _node *next;
    char data;
} Node;
void oddEven (Node *head)
{
    if (head == NULL || head->next == NULL || 
        head->next->next == NULL)
        return;
    Node *odd = head;
    Node *evenHead = head->next;;
    Node *even = head->next;
    Node *prevo = NULL;
    Node *preve = NULL;
    while (odd != NULL && even != NULL) {
        odd->next = even->next;
        prevo = odd;
        odd = odd->next;
        if (odd != NULL)
            even->next = odd->next;
        preve = even;
        even = even->next;
    }
    if (even == NULL)
        preve->next = NULL;

    if (odd == NULL)
        prevo->next = evenHead;
    else {
        odd->next = evenHead;
    }
}
int main (void) {
 
    Node *A = malloc(sizeof(Node));
    A->data = '1';
    Node *B = malloc(sizeof(Node));
    B->data = '2';
    Node *C = malloc(sizeof(Node));
    C->data = '3';
    Node *D = malloc(sizeof(Node));
    D->data = '4';
    Node *E = malloc(sizeof(Node));
    E->data = '5';
    Node *F = malloc(sizeof(Node));
    F->data = '6';
    F->next = NULL;

    A->next = B;
    //A->next = NULL;
    B->next = C;
    //B->next = NULL;
    //C->next = NULL;
    C->next = D;
    //D->next = NULL;
    D->next = E;
    //E->next = NULL;
    E->next = F;
    //A = NULL;
    Node *node = A;
    while (node != NULL) {
        printf("%c-> ", node->data);
        node = node->next;
    }
    printf("NULL \n");
    oddEven(A);
    /* Node *newHead = reverseList(A); */
    node = A;
    while (node != NULL) {
        printf("%c-> ", node->data);
        node = node->next;
    }
    printf("NULL \n"); 
}
