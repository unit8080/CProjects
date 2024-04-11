#include <stdio.h>
#include <signal.h>

static void
sighandler (int sig)
{
    printf("Ouch! \n");
}


int 
main (int argc, char *argv[])
{
    int j;

    if (signal(SIGINT, sighandler) == SIG_ERR) {
        printf("SIG_ERR - signal\n");
        return -1;
    }
    
    for (j = 0; ; j++) {
        printf("%d\n", j);
        sleep(3);
    }
}
