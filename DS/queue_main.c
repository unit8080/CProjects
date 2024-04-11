#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "queue.h"

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
