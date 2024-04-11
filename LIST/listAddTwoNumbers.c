#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL)
        return NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    struct ListNode *head = NULL;
    struct ListNode *prev = NULL;
    int add = 0;
    int temp;
    while (l1 != NULL && l2 != NULL) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        assert(node != NULL);
        if (head == NULL)
            head = node;
        if (prev != NULL)
            prev->next = node;
        temp = (l1->val + l2->val  + add);
        add = temp / 10;
        node->val = temp % 10;
        node->next = NULL;
        prev = node;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        assert(node != NULL);
        if (head == NULL)
            head = node;
        prev->next = node;
        temp = (l1->val  + add);
        add = temp / 10;
        node->val = temp % 10;
        node->next = NULL;
        prev = node;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        assert(node != NULL);
        if (head == NULL)
            head = node;
        prev->next = node;
        temp = (l2->val  + add);
        add = temp / 10;
        node->val = temp % 10;
        node->next = NULL;
        prev = node;
        l2 = l2->next;
    }
    if (add != 0) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        assert(node != NULL);
        prev->next = node;
        node->val = add;
        node->next = NULL;
    }
    return head;
}
int main (void) {
}
