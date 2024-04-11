#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// refer following definition in error.h
//#define	EPERM		 1	/* Operation not permitted */
//#define	ENOENT		 2	/* No such file or directory */
//#define	EAGAIN		11	/* Try again */
//#define	ENOMEM		12	/* Out of memory */
//#define	EINVAL		22	/* Invalid argument */

typedef unsigned char boolean;
int errno;
#define TRUE 1
#define FALSE 0

typedef struct _StackArr
{
    unsigned int dataLen;
    unsigned int top;
    unsigned int maxEntries;
    unsigned char item[0];
} StackArr;

StackArr * 
stackCreateArray(unsigned int dataLen, unsigned int maxEntries)
{
    StackArr  *stack;

    stack = (StackArr *) malloc (sizeof(StackArr) + sizeof(maxEntries*dataLen));
    if (stack == NULL) {
        errno = ENOMEM;
        perror(NULL);
        return (NULL);
    }
    stack->dataLen = dataLen;
    stack->maxEntries = maxEntries;
    stack->top = 0;
    return (stack);
}

boolean 
stackEmptyArray (StackArr *s)
{
    if (s == NULL) {
        errno = EINVAL;
        perror(NULL);
        return (TRUE);
    }
    if (s->top == 0) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

boolean 
stackFullArray (StackArr *s)
{
    if (s == NULL) {
        errno = EINVAL;
        perror(NULL);
        return (TRUE);
    }
    if (s->top >= s->maxEntries) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

void 
stackPushArray (StackArr *s, void *data)
{
    if (s == NULL || data == NULL) {
        errno = EINVAL;
        perror(NULL);
        return;
    }
    if (stackFullArray(s)) {
        errno = ENOENT;
        perror(NULL);
        return;
    }
    int index;
    /* push at top */
    index = s->top; 
    memcpy(s->item+index, data, s->dataLen);
    s->top += s->dataLen;
}

void stackPopArray (StackArr *s, void *data)
{
    if (s == NULL || data == NULL) {
        errno = EINVAL;
        perror(NULL);
        return;
    }
    if (stackEmptyArray(s)) {
        errno = ENOENT;
        perror(NULL);
        return;
    }
    int index;
    index = s->top - s->dataLen;
    memcpy(data, s->item+index, s->dataLen);
    s->top = index;
}

#define MAX_ENTRIES  10
int main ()
{
    StackArr  *stack1;
    unsigned long data;
    unsigned long item;

    stack1 = stackCreateArray(sizeof(data), MAX_ENTRIES);

    data = 286900999;
    printf("Push %l\n", data);
    stackPushArray(stack1, &data);
    data = 586900999;
    printf("Push %d\n", data);
    stackPushArray(stack1, &data);
    data = 786900999;
    printf("Push %d\n", data);
    stackPushArray(stack1, &data);

    stackPopArray(stack1, &item);
    printf("Pop %d\n", item);
    stackPopArray(stack1, &item);
    printf("Pop %d\n", item);
    stackPopArray(stack1, &item);
    printf("Pop %d\n", item);
}
