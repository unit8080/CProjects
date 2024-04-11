#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "queue.h"


#define TRUE 1
#define FALSE 0

int errno;

QueueHeader *
queueCreate (unsigned int maxEntries, unsigned int dataLen)
{
    QueueHeader *hdr;

    hdr = (QueueHeader *)malloc(sizeof(QueueHeader));
    if (hdr == NULL) {
        errno = ENOMEM;
        perror(NULL);
        return (NULL);
    }
    hdr->head = NULL;
    hdr->tail = NULL;
    hdr->maxEntries = maxEntries;
    hdr->counts = 0;
    hdr->dataLen = dataLen;
    return (hdr);
}

boolean queueEmpty (QueueHeader *hdr)
{
    if (hdr == NULL) {
        errno = EINVAL;
        perror(NULL);
        return (TRUE);
    }
    if (hdr->tail == NULL) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

boolean queueFull (QueueHeader *hdr)
{
    if (hdr == NULL) {
        errno = EINVAL;
        perror(NULL);
        return (FALSE);
    }
    if (hdr->counts >= hdr->maxEntries) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

void queueEnqueue(QueueHeader *hdr, void *data)
{
    QueueNode *node;

    if (hdr == NULL || data == NULL) {
        errno = EINVAL;
        perror(NULL);
        return;
    }

    if (queueFull(hdr)) {
        errno = ENOENT;
        perror(NULL);
        return;

    }
    node = (QueueNode *) malloc(sizeof(QueueNode) + hdr->dataLen);
    if (node == NULL) {
        errno = ENOMEM;
        perror(NULL);
        return;
    }
    node->next = NULL;
    node->prev = NULL;
    memcpy(node->data, data, hdr->dataLen);
    if(hdr->head != NULL) {
        hdr->head->prev = node;
    }
    node->next = hdr->head;
    hdr->head = node;
    hdr->counts += 1;
    if (hdr->tail == NULL) {
        /* first element */
        hdr->tail = node;
    }
}

void queueDequeue(QueueHeader *hdr, void *data)
{
    QueueNode *node;

    if (hdr == NULL || data == NULL) {
        errno = EINVAL;
        perror(NULL);
        return;
    }
    if (queueEmpty(hdr)) {
        errno = ENOENT;
        perror(NULL);
        return;
    }
    node = hdr->tail;
    memcpy(data, node->data, hdr->dataLen);
    hdr->tail = hdr->tail->prev;
    if (hdr->tail != NULL) {
        hdr->tail->next = NULL;
    }
    if (queueEmpty(hdr)) {
        hdr->head = hdr->tail;
    }
    hdr->counts -= 1;
    free(node);
}

/* commented main due to queue being used as library */
#if 0
#define MAX_ENTRIES 10

int main (void) 
{

    QueueHeader *queue;
    int data, item;

    queue = queueCreate(MAX_ENTRIES, sizeof(data));


    data = 5;
    printf("Enqueue data : %d\n", data);
    queueEnqueue(queue, &data);
    data = 7;
    printf("Enqueue data : %d\n", data);
    queueEnqueue(queue, &data);
    data = 9;
    printf("Enqueue data : %d\n", data);
    queueEnqueue(queue, &data);

    queueDequeue(queue, &item);
    printf("Dequeue data : %d\n", item);
    queueDequeue(queue, &item);
    printf("Dequeue data : %d\n", item);
    queueDequeue(queue, &item);
    printf("Dequeue data : %d\n", item);
    queueDequeue(queue, &item);
}
#endif
