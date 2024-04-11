#include <stdio.h>

int *f2()
{

    int a = 10;
    return &a;
}

void print_var()
{

    int *b = (int *)f2();
    /*
     * Check the return by value (reference here)
     * - Compiler will give Warning and depending on the -W option
     *   it may or may not compile the code.
     *   Reason: Returning the address of the local variable from
     *   called function is risky business as stack memory may get over
     *   written.
     *
     */
    printf("[] Check the variable: %d\n", *b);
}
