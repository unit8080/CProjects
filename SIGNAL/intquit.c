#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void
sigHandler (int sig)
{


    static int count = 0;

    if (sig == SIGINT) {
        count++;
        printf("Caught SIGINT (%d) \n", count);
        return;
    }

    if (sig == SIGQUIT) {
        printf("Caught SIGQUIT - that's all folks!\n");
            exit(EXIT_SUCCESS);
    }
}

int
main (int argc, char *argv[])
{

    /*
     * Establish same handler for SIGINT and SIGQUIT.
     */
    if (signal(SIGINT, sigHandler) == SIG_ERR)
        return (-1);
    if (signal(SIGQUIT, sigHandler) == SIG_ERR)
        return (-1);

    for (;;)                  /* Loop forever, waiting for signals */
        pause();              /* Block until a signal is caught */
}


