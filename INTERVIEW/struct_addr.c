/*
 * This prorgram finds the size of structure and
 * pointer address and also offset of the member field.
 */
#include <stdio.h>

#define offsetof2(foo, memb) \
    ((size_t)&(((foo *)0)->memb))
#define offsetof1(name, memb) \
    ((size_t)((unsigned long)&(((name *)0)->memb)))
#define offset(foo, memb) \
    ((size_t)((char *)&((foo *)0)->memb - (char *)0))

struct foo {
    int i;
    char j;
    int k;
    char f;
};

struct poo {
    int i;
    char j;
    int k;
    char f;
} __attribute__((packed));

int
main (int argc, char *argv[])
{
    struct foo f;
    struct foo *f_p = &f;

    printf("size of foo %d\n", sizeof(f));
    printf("%p  \n", f_p);
    printf("%p  %p \n", f_p, f_p++);
    printf("offset of K = %u \n", offsetof2(struct foo, k));

    struct poo p;
    struct poo *p_p = &p;

    printf("size of poo %d\n", sizeof(p));
    printf("%p  \n", p_p);
    printf("%p  %p \n", p_p, p_p++);
    printf("offset of K = %u \n", offsetof2(struct poo, k));
}
