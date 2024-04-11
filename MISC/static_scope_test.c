#include <stdio.h>

int val = 30;
void check_value()
{
     static int val = 0;

     val += 10;
     printf("%d\n", val);
}

void static_scope_test()
{
    printf("\n[] Testing scope of static variable ---->\n");

    check_value();
    check_value();
    check_value();
}
