#include <stdio.h>
#include <stdlib.h>

typedef struct Node_ {
    char alphabet;
    struct Node_ *next;
} Node;

// sorts vowel and other characters and puts in order of 
// vowel followed by rest of the characters.
//
// Input: strings termintaed with '0'
//
void sort_vow_const (Node **headRef)
{
    Node *current = NULL;
    Node *prev= NULL;
    Node *nxtnxt = NULL;
    Node *vowel = NULL; // last vowel

    if (headRef == NULL || *headRef == NULL)
        return;

    current = *headRef;
    nxtnxt = current->next;
   
    while (current != NULL) {
        if (current->alphabet == 'a' ||
            current->alphabet == 'e' ||
            current->alphabet == 'i' ||
            current->alphabet == 'o' ||
            current->alphabet == 'u'  ) {
            if (vowel == NULL) {
                // this is our first vowel
                vowel = current;
                if (*headRef == current) {
                    prev = current;
                    current = current->next;
                    //headref no change
                } else { 
                    // headref is different - need to delink vowel
                    nxtnxt = current->next;
                    if (prev == NULL) {
                        vowel->next = *headRef;
                        //(*headRef)->next = nxtnxt;
                        //prev = current;
                        current = nxtnxt;
                    } else {
                        prev->next = current->next;
                        current = nxtnxt;
                        vowel->next = *headRef;
                    }
                    *headRef = vowel;
                }
            } else {
                // yet another vowel
                Node *new_vowel;

                new_vowel = current;
                prev->next = current->next; // delink here
                //prev = current;
                current = current->next;
                nxtnxt = vowel->next;
                vowel->next = new_vowel;
                new_vowel->next = nxtnxt;
                vowel = new_vowel; // move the last vowel
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int main()
{
    char c;
    Node *headRef = NULL;
    Node  *new;

    scanf("%c", &c);
    while (c != '0') {
        if (c == ' ') {
            scanf("%c", &c);
            continue;
        }
        new = malloc(sizeof(Node));
        new->alphabet = c;
        new->next = headRef;
        headRef = new;
        scanf("%c", &c);
    }
    Node *current = headRef;
    while (current != NULL) {
        printf("%c", current->alphabet);
        current = current->next;
    }
    printf("\n");

    sort_vow_const(&headRef);

    current = headRef;
    while (current != NULL) {
        printf("%c", current->alphabet);
        current = current->next;
    }
}

