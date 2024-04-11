#include <signal.h>
#include <stdio.h>

struct two_int { int a, b; } data;

void signal_handler(int signum){
   
    printf ("%d, %d\n", data.a, data.b);
    alarm (1);
}

int main (void){
 
    static struct two_int zeros = { 0, 0 }, ones = { 1, 1 };
    sigset_t newmask, oldmask, zeromask;

    /* Register the signal handler */
    signal(SIGALRM, signal_handler);


    /* Initialize the signal sets */
    sigemptyset(&newmask); sigemptyset(&zeromask);


    /* Add the signal to the set */
    sigaddset(&newmask, SIGALRM);

    data = zeros;
    alarm (1);


    while (1) {
        /* 
         * Block SIGALRM and save current signal mask in set variable 'oldmask'
         */
        sigprocmask(SIG_BLOCK, &newmask, &oldmask);

        data = zeros; 
        data = ones;

        /* Now allow all signals and pause */
        sigsuspend(&zeromask);

        /* Resume to the original signal mask */
        sigprocmask(SIG_SETMASK, &oldmask, NULL);
    }
}
