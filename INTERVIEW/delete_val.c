#include <stdio.h>
#include <stdlib.h>

typedef struct Node_ {
    int data;
    struct Node_ *next;
} Node;

/*
 * delete given value matching node from linked list.
 */
void deleteNode(Node **headRef, int val)
{
    Node *current;
    Node *prev = NULL;

    if (headRef == NULL || *headRef == NULL)
        return;
    current = *headRef;
    while (current != NULL) {
        if (current->data == val) {
            Node *delNode = current;
            if (*headRef == delNode) {
                *headRef = current->next;
            } else {
               prev->next = current->next;
            }
            current = current->next;
            free(delNode);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void reverseList (Node **headRef)
{
    Node *curr;
    Node *prev = NULL;
    Node *this;

    if (headRef == NULL || *headRef == NULL) {
       return;
    }
    curr = *headRef;
    while (curr != NULL) {
        this = curr;
        curr = curr->next;
        this->next = prev;
        prev = this;
    }
    *headRef = prev;
}

void reversePrint(Node *node)
{
   if (node == NULL)
       return;

   if (node->next != NULL)
       reversePrint(node->next);
   printf("%d ", node->data);
}

int
main (int argc, char *argv[])
{
    Node *headRef = NULL;
    int data;

    printf("Enter data: (end with -1) ");
    scanf("%d", &data);
    while (data != -1) {
        Node *new = malloc(sizeof(Node));
        new->data = data;
        new->next = headRef;
        headRef = new;
        scanf("%d", &data);
    }
    reverseList(&headRef);
    Node *current = headRef;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\nReverse print : ");
    reversePrint(headRef);
    printf("\nPlease enter data to delete : ");
    scanf("%d", &data);
    deleteNode(&headRef, data);

    current = headRef;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
    reverseList(&headRef);
    current = headRef;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}
