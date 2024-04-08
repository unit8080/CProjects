/* Program to check if a linked list is palindrome */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
/* Link list node */
struct node
{
    char data;
    struct node* next;
};
 
/* Push a node to linked list. Note that this function
  changes the head */
void push(struct node** head_ref, char new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
/* Push a node to linked list. Note that this function
  changes the head */
void pop(struct node** head_ref, char *new_data)
{
    struct node* top_node = *head_ref;
 
    *new_data = (*head_ref)->data;;
    (*head_ref)    = (*head_ref)->next;
    free(top_node);
}
// A utility function to print a given linked list
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int checkPalindrome(char str[], int first_pos, int last_pos)
{
    if (first_pos >= last_pos)
        return 1;

    return ((str[first_pos] == str[last_pos] ) && 
            checkPalindrome(str, first_pos+1, last_pos -1));
}
int isPalindrome(char str[])
{
    unsigned int len = strlen(str);
    return checkPalindrome(str, 0, len -1);
}
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    //char str[] = "abacaba";
    char str[] = "dalda";
    char str1[] = "level";
    int i;
 
    printf("String %s is %s\n", str, isPalindrome(str) ? "Palindrome" : "not Palindrome");
    printf("String %s is %s\n", str1, isPalindrome(str1) ? "Palindrome" : "not Palindrome");
#if 0
    // Using stack method
    for (i = 0; str[i] != '\0'; i++)
    {
       push(&head, str[i]);
       printList(head);
    }
    for (i = 0; str[i] != '\0'; i++)
    {
       char poped_data;
       pop(&head, &poped_data);
       if (str[i] != poped_data) {
           printf("poped = %c != %c --- mismathed\n", poped_data, str[i]);
           printf("Not Palindrome\n\n");
           return 0;
       } else {
           printf("poped = %c = %c --- matched \n", poped_data, str[i]);
       }
    }
    printf("Palindrome !!!\n");
#endif
    return 0;
}
