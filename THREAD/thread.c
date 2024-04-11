#include <stdio.h>
#include <pthread.h>

int bool = 0;
char *str1 = "Hello ";
char *str2 = "Stranger\n";

void *threadFunc(void  *str)
{
    printf("%s\n", (char *) str);
    pthread_exit((void *) bool);
}
int
main (int argc, char *argv[])
{
    pthread_t  th1;
    pthread_t  th2;
    int val;

    pthread_create(&th1, NULL, threadFunc, (void *) str1);

    if (!(val = pthread_join(th1, NULL))) {
        pthread_create(&th2, NULL, threadFunc, (void *) str2);
    }

    pthread_exit((void *) bool);
}
