#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "stack.h"

Stack *
stackCreate(unsigned int dataLength, unsigned int maxEntries)
{
    Stack *stack;

    stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL) {
        return(NULL);
    }

    stack->dataLen = dataLength;
    stack->maxEntries = maxEntries;
    stack->top = NULL;
    return(stack);
}

boolean stackFull (Stack *s)
{
    if (s->maxEntries <= 0) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

int errno;

boolean stackEmpty (Stack *s) 
{
    if (s == NULL) {
        return (FALSE);
    }

    if (s->top == NULL) {
        printf("Stack is empty: \n");
        errno = ENOMEM;
        perror(NULL);
        return (TRUE);
    } else {
        return (FALSE);
    }
}

void stackPush (Stack *s, void *data)
{
    StackNode *node = NULL;

    if (s == NULL || data == NULL) {
        return;
    }
    if (stackFull(s)) {
        return;
    }

    node = (StackNode *) malloc(sizeof(StackNode)+s->dataLen);
    if (node == NULL) {
        return;
    }
    
    memcpy(node->item, data, s->dataLen);
    node->next = s->top;
    s->top = node;
    s->maxEntries -= 1;

    return;
}

void 
stackPop (Stack *s, void *data)
{
    StackNode *top;

    if (s == NULL || data == NULL) {
        return;
    }

    if (stackEmpty(s)) {
        return;
    }

    memcpy (data, s->top->item, s->dataLen);
    s->maxEntries += 1;
    top = s->top;
    s->top = s->top->next;
    free(top);
    return; 
}


/* commented due to use as library */
#if 0
#define MAX_ENTRIES 10

#define num_of_sec (365*24*60*60)

int main(void)
{
    Stack *stack1;
    long data;
    long item;

    printf("Num of sec %d\n", num_of_sec);

    stack1 = stackCreate(sizeof(data), MAX_ENTRIES);
    data = 209988708;
    printf("Push %d\n", data);
    stackPush(stack1, &data);
    data = 509988708;
    printf("Push %d\n", data);
    stackPush(stack1, &data);
    data = 709988708;
    printf("Push %d\n", data);
    stackPush(stack1, &data);

    stackPop(stack1, &item);
    printf("Pop %d\n", item);
    stackPop(stack1, &item);
    printf("Pop %d\n", item);
    stackPop(stack1, &item);
    printf("Pop %d\n", item);

    stackPop(stack1, &item);

}
#endif
