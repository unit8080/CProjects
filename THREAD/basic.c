#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char * buf = "abcdefghijklmnopqrstuvwxyz";
int num_pthreads = 3;
int count = 10;
int fd = 1;

void * new_thread(void * arg)
{
    for (int i = 0; i < count; i++) {
        write(fd, arg, 1);
        usleep(1000000);
    }
    return(NULL);
}

int main()
{
   pthread_t thread;
   int i;

   for (i = 0; i < num_pthreads; i++) {
        if (pthread_create(&thread, NULL, new_thread, (void *)(buf + i))) {
           fprintf(stderr, "error creating a new thread \n");
           exit(1);
        }
        pthread_detach(thread);
   }
   pthread_exit(NULL);
}
