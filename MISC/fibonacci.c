#include <stdio.h>

int
main (int argc, char **argv[])
{
    int last_but_one;
    int last_one;
    int current;
    int n;

    scanf("%d", &n);
    while (n != -1) {
        if (n == 0) {
            printf("Fibonacci (%d) = %d\n", n, n);
        } else if (n == 1) {
            printf("Fibonacci (%d) = %d\n", n, n);
        } else {
            int i;
            last_but_one = 0;
            last_one = 1;
            for (i = 2; i < n; i++) {
                current = last_but_one + last_one;
                last_but_one = last_one;
                last_one = current;
            }
            printf("Fibonacci (%d) = %d\n", n, current);
        }
        scanf("%d", &n);
    }
    return 0;
}


