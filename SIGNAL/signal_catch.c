#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>
 
int i = 0;
volatile sig_atomic_t keep_going = 1;
 
volatile sig_atomic_t got_interrupt = 0;

void catch_alarm(int);
 
int main()
{
    signal(SIGALRM, catch_alarm);
    alarm(1);
   
    for(;;) {
        if (got_interrupt) {
            got_interrupt = 0;
            signal(SIGALRM, catch_alarm);
            printf("got alarm : %d\n", i);
            alarm(1);
        }
        i++;
    }
 
    return EXIT_SUCCESS;
}
 
void catch_alarm(int sig)
{
    //printf("--Alram Occurred");
    got_interrupt = 1;
}

