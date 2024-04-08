#include <stdio.h>

int getVal (void) 
{
    char *s = NULL;
    static int num = 1;
    return (num++);
}

int main (void)
{
    char *s = NULL;

    printf("%d %d %d\n", getVal(), getVal(), getVal());             //with linefeed char
    //printf("%s", s);               //without linefeed char
#if 0
    printf("display %s, %s, %s \n", getVal(), getVal(), getVal()); 
    printf("Null String %s\n", s); //with linefeed char
    printf("Null String %s", s);   //without linefeed char
#endif
}

