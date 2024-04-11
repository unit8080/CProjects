#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int sum = 0;
void *sum_num (void *arg)
{
    int *num_p = (int *)arg;
    int num = *num_p;
    for (int i = 0; i <= num; i++)
        sum += i;

    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    int val;
    if (argc < 2) {
        printf("Usage: %s <num>\n", argv[0] );
        return 0;
    }
    val = atoi(argv[1]); printf("Number = %d\n", val);
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, sum_num, &val);
    pthread_join(tid, NULL);
    printf(" Total sum = %d\n", sum);
}
