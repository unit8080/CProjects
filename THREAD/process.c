#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

//#include "curr_time.h" /* Declaration of currTime() */

char *str1 = "Hello ";
char *str2 = "Wonderer\n";

int bool;

int 
main (int argc, char * argv[])
{

    pid_t cpid;
    pid_t ppid;

    /*
     * do some inintial processing in parent process.
     */

    setbuf(stdout, NULL);  /* disable buffering of stdout */

    switch (cpid = fork()) {
        case -1:
            _exit(-1);

        case 0: /* child */
            //printf("[%s %ld] Child started - doing some work\n",
            //        currTime("%T"), (long) getpid());

            printf("[%ld] Child started - doing some work or going to sleep\n",
                    (long) getpid());
            sleep(2);    /* Simulate the child doing something */
            //printf("[%s %ld] Child slept for 2 seconds\n",
            //        currTime("%T"), (long) getpid());
            printf("[%ld] Child slept for 2 seconds\n",
                    (long) getpid());

            //printf("[%s %ld] Child Terminateing now\n",
            //        currTime("%T"), (long) getpid());
            printf("[%ld] Child Terminating now\n",
                    (long) getpid());
            printf("%s", str1);
            _exit(0);

        default: /* parent */
            break;
            //exit(0);
    }

    for (;;) {     /* Parent waits for each child to exit */
        cpid = wait(NULL);

        if (cpid == -1) {
            if (errno == ECHILD) {
                printf("No more child - bye\n");
                _exit(0);
            } else {
                _exit(-1);   /* some other (unexpected) error */
            }
        }

        printf("%s", str2);

        //  printf("[%s] wait() returned child pid [%ld]\n",
        //           currTime("%T"), (long) cpid);
        printf("wait() returned child pid [%ld]\n",
                (long) cpid);
    }

    /*
     * do the final processing in parent process and exit
    printf("[%s %ld] Parent Terminateing now\n",
            currTime("%T"), (long) getpid());
     */
    printf("[%ld] Parent Terminateing now\n",
           (long) getpid());
}

