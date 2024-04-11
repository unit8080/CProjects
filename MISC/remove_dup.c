/* 12:23
 * This code is property of the Sanjeev Singh
 * Copyright (c) 
 * Copy, dup, use it at your own risk.
 */

#include <stdio.h>

typedef struct _node {
    struct _node *next;
    int data;
} Node;

void remove_node (Node **headRef, int val)
{

    Node *curr = NULL;
    Node *prev = NULL;


    /*
     * stack variable check
     */
    if (headRef == NULL) {
        return;
    }

    curr = *headRef;
    prev = curr;

    /*
     * Walk the list and find and delete the node matching val.
     */
    while (curr != NULL) {
        if (curr->data == val) {
            if (curr == headRef) {
                prev = curr->next;
                *headRef = prev;
                free(curr);
                curr = prev;
            } else {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
                /* prev is not updated. */
            }
        } else { /* val does not match */
            prev = curr;
            curr = curr->next;
        }
    } /* end of while */
} /* 12.41 *


int main (void) 
{
  
}

