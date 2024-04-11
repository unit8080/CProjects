#include <stdio.h>

extern void quest81();
extern void static_scope_test();
extern void test_ptr();
extern void print_string();
extern void print_var();

int main()
{

    quest81();
    static_scope_test();
    test_ptr();
    print_string();
    print_var();
    return(0);
}
