/* 
 * stack data structure 
 */
#ifndef STACK_H
#define STACK_H

typedef unsigned char boolean;
#define FALSE 0
#define TRUE 1

typedef struct _StackNode {
    struct _StackNode *next;    
    unsigned char  item[0]; 
} StackNode;


typedef struct _Stack {
    StackNode *top;
    unsigned int dataLen;
    unsigned int maxEntries;
} Stack;
extern 
Stack *
stackCreate(unsigned int dataLength, unsigned int maxEntries);
extern 
boolean stackFull (Stack *s);
extern 
boolean stackEmpty (Stack *s);
extern 
void stackPush (Stack *s, void *data);
extern 
void stackPop (Stack *s, void *data);
#endif /* STACK_H */ 
