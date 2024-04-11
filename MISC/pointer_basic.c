#include <stdio.h>

main()
{
    int *x;
    int y = 12;

    x = &y;

    printf("&x = %p\n", &x);
    printf("&y = %p\n", &y);
    printf("x = %p\n", x);
    printf("*x = %d\n", *x);
    printf("y = %d\n", y);

    *x = 13;
    printf("y = %d\n", y);

    int i;

    void *p = &i;
    void *r;

    r = p;

    //void *q = p + 1;
    void *q;
         ++p;
    q = p;
    printf("address of p = %p and ++p = %p\n", r, q);

    void *ptr = NULL;
    printf("addpress of NULL Pointer = %p \n", ptr);
}
