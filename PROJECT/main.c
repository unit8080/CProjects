/**************************************************

file: main.c
purpose: simple demo that demonstrates the timer-function

**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include "hash.h"
#include <sys/time.h>
#include "timer.h"
#include <pthread.h>
#include <semaphore.h>

//pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
//int var=0;
sem_t asem; // ager/timer semaaphore
extern bool inPauseLine;

void timer_handler(void)
{
  //printf("timer: var is %i\n", var++);
  stop_timer();
  sem_post(&asem);
}

int schedTimer (uint64_t tmo)
{
  if(start_timer(tmo, &timer_handler))
  {
    printf("\n timer error\n");
    return(1);
  }
  return(0);
}

void showAgerEntry(ListNode *node, FILE *fp, char *str)
{
    time_t t;
    unsigned int ipaddr = node->ipaddr;
    str = ctime(&node->start);
    str[20] = '\0';
    printf("%s : ", str);
    time(&t);
    str = ctime(&t);
    str[20] = '\0';
    printf("%s : ", str);
    printf("%02x.%02x.%02x.%02x\t%d\n", (ipaddr & 0xff000000) >> 24,
            (ipaddr & 0x00ff0000) >> 16,
            (ipaddr & 0x0000ff00) >> 8,
            (ipaddr & 0x000000ff), node->tmo);

    str = ctime(&node->start);
    str[20] = '\0';
    fprintf(fp, "%s : ", str);
    time(&t);
    str = ctime(&t);
    str[20] = '\0';
    fprintf(fp, "%s : ", str);
    fprintf(fp, "%d.%d.%d.%d\t%d - expired\n", (ipaddr & 0xff000000) >> 24,
            (ipaddr & 0x00ff0000) >> 16,
            (ipaddr & 0x0000ff00) >> 8,
            (ipaddr & 0x000000ff), node->tmo);

}
//void age_ipaddr(bool *PauseLine)
void *age_ipaddr(void *tmp)
{
    FILE* fpout;
    char* str = (char *)malloc(sizeof(char)*26);
    ListNode *node = base_list.head;
    printf("List :\n");
    fpout = fopen("output.txt", "a+");

    while (true) {
        sem_wait(&asem);

    uint64_t curr_time = current_timestamp();
    while (node != NULL &&  curr_time >= node->expirytime) {
        if (node->ipaddr == 0)
            //*inPauseLine = false;
            inPauseLine = false;   // global shared resource
        else
            showAgerEntry(node, fpout, str);

        ListNode *next = node->next;
        ListRemove(&base_list, node);
        HashDelete(table, node->ipaddr);
        node = next;
    }
        if (base_list.head != NULL) {
            int64_t  nextTimer = base_list.head->expirytime -
                                        curr_time;

            printf("Ager - sched time %lld, ip addr= %x, tmo=%d\n", nextTimer,
                   base_list.head->ipaddr, base_list.head->tmo);
            if (nextTimer > 0)
                schedTimer(nextTimer);
        } 
    } // while (true)

    if (node == NULL)
        base_list.head = NULL;

    free(str);
    fclose(fpout);

    pthread_exit((void *)tmp);
}

int main()
{
    pthread_t ager_thread;

    sem_init(&asem, 0, 1);
    ipager_init();
    pthread_create(&ager_thread, NULL, age_ipaddr, NULL);
    ipager_activity_loop();


    pthread_join(ager_thread, NULL);
    sem_destroy(&asem);
    return 0;
}
