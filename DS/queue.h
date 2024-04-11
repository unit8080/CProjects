/*
 * Queue data structure Decalaration - using doubly linked list method.
 */

#ifndef QUEUE_H
#define QUEUE_H

typedef struct _QueueNode
{
    struct _QueueNode *next;
    struct _QueueNode *prev;
    unsigned char data[0];
} QueueNode;

typedef struct _QueueHeader
{
    QueueNode  *head;
    QueueNode  *tail;
    unsigned int maxEntries;
    unsigned int counts;
    unsigned int dataLen;
} QueueHeader;

typedef unsigned char boolean;

extern QueueHeader *
queueCreate (unsigned int maxEntries, unsigned int dataLen);
extern void queueEnqueue(QueueHeader *hdr, void *data);
extern void queueDequeue(QueueHeader *hdr, void *data);
extern boolean queueEmpty (QueueHeader *hdr);
extern void queuePrint(QueueHeader *hdr);
#endif /* QUEUE_H */
