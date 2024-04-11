#include <signal.h>
#include <stdio.h>
#include <pthread.h>

struct two_int { int a, b; } data;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void signal_handler(int signum){
   
    printf ("%d, %d\n", data.a, data.b);
    alarm (1);
}

int main (void){
 
    static struct two_int zeros = { 0, 0 }, ones = { 1, 1 };

    /* Register the signal handler */
    signal(SIGALRM, signal_handler);


    data = zeros;
    alarm (1);


    while (1) {

        pthread_mutex_lock(&mtx);
        data = zeros; 
        data = ones;
        pthread_mutex_unlock(&mtx);
    }
}
