/**************************************************

file: main.c
purpose: simple demo that demonstrates the timer-function

**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int var=0;

void timer_handler(void)
{
  printf("timer: var is %i\n", var++);
  stop_timer();
  pthread_mutex_unlock(&mutex1);
}

//int main(void)
int pause_for (unsigned int tmo)
{
  if(start_timer(tmo, &timer_handler, &mutex1))
  {
    printf("\n timer error\n");
    return(1);
  }
  printf("\nAcquiring lock or  ctl-c to quit.\n");
  pthread_mutex_lock(&mutex1);
  pthread_mutex_unlock(&mutex1);
  printf("\nAcquired lock now, resume execution...\n");
  stop_timer();
  return(0);
}

