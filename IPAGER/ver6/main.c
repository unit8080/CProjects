/**************************************************

file: main.c
purpose: simple demo that demonstrates the timer-function

**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include <pthread.h>

//pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int var=0;

void timer_handler(void)
{
  printf("timer: var is %i\n", var++);
  //stop_timer();
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

