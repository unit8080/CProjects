#include <stdio.h>

char *f1()
{
    char *b = "Hello, I am here";

    return b;
}

void print_string()
{
    /*
     * Check the return by value (reference here) for string
     */
    printf("[] Check the string: %s\n", f1());
}

// see main.c : included there.
