#include <stdio.h>

int main()
{

    int val[2];
    int *p1, *p2;
    int result;
    void *xyz;
#if 0
    char  *a[100];
    char  *(b)[100];
    char  (*c)[100];

    printf("sizeof(a) = %d, sizeof(b) = %d, sizeof(c) = %d\n",
            sizeof(a), sizeof(b), sizeof(c));
#endif

    p1 = &val[0];
    p2 = &val[1];
    result = (char *)p2 - (char *)p1;
    printf("&p1 = %p, &p2 = %p\n", p1, p2);
    printf("size of integer = %d bytes\n", result);
    printf("size of pointer = %d bytes\n", sizeof(xyz));
}


