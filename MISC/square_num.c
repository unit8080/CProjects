#include <stdio.h>


int
main (int argc, char *argv[])
{

    int num;

    printf("Please enter number to check for Square: ");
    scanf("%d", &num);

    if ((num & (num - 1)) == 0) {
        printf("Number %d is perfect Square number\n", num);
    } else {
        printf("Number %d is not Square number\n", num);
    }
}

