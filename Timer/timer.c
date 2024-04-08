/*
***************************************************************************
   sigev.sigev_notify = SIGEV_THREAD_ID | SIGEV_SIGNAL; 
   sigev.sigev_signo = YOUR_SIGNAL; 
   sigev.sigev_notify_thread_id = gettid(); 
   timer_create(CLOCK_MONOTONIC, &sigev, &timer); 

http://www.2net.co.uk/tutorial/periodic_threads

That signal for that timer will not be delivered to any other thread 
than the one specified in sigev.sigev_notify_thread_id as long as that 
thread has not exited w/o canceling the timer. 
***************************************************************************
*/
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include "timer.h"
#include <pthread.h>

struct itimerval timervalue;
struct sigaction new_handler, old_handler;

void (*timer_func_handler_pntr)(void);
void timer_handler(int);

void timer_sig_handler (int arg)
{
  timer_func_handler_pntr();
}

int start_timer (int mSec, void (*timer_func_handler)(void),
                        pthread_mutex_t *mutex1)
{
  timer_func_handler_pntr = timer_func_handler;
  pthread_mutex_lock(mutex1);

  timervalue.it_interval.tv_sec = mSec / 1000;
  timervalue.it_interval.tv_usec = (mSec % 1000) * 1000;
  timervalue.it_value.tv_sec = mSec / 1000;
  timervalue.it_value.tv_usec = (mSec % 1000) * 1000;

  if(setitimer(ITIMER_REAL, &timervalue, NULL))
  {
    printf("\nsetitimer() error\n");
    return(1);
  }

  new_handler.sa_handler = &timer_sig_handler;
  new_handler.sa_flags = SA_NODEFER;

  if(sigaction(SIGALRM, &new_handler, &old_handler))
  {
    printf("\nsigaction() error\n");
    return(1);
  }
  return(0);
}

void stop_timer(void)
{
  timervalue.it_interval.tv_sec = 0;
  timervalue.it_interval.tv_usec = 0;
  timervalue.it_value.tv_sec = 0;
  timervalue.it_value.tv_usec = 0;
  setitimer(ITIMER_REAL, &timervalue, NULL);

  sigaction(SIGALRM, &old_handler, NULL);
}
