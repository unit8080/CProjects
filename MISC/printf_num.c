#include <stdio.h>

static int i = 0;
int get_int ()
{
    return ++i;
}

int main (int argc, char *argv[])
{
    printf (" i = %d, %d\n", get_int(), get_int());
    return 0;
}
