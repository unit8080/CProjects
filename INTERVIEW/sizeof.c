

#if 1
#include <stdio.h> 
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)
#define MYSIZEOF(X) (unsigned int)((X*)0 + 1)
int main()
{
    double x;
    printf("size of double = %ld\n", my_sizeof(x));
    int y;
    printf("size of int = %d\n", MYSIZEOF(int));
    printf("size of char = %d\n", MYSIZEOF(char));
    getchar();
    return 0;
}
#else

//#pragma pack(1)
#include <stdio.h> 
struct s
{
     char c;
     int i;
} __attribute__ ((packed));
 
int main()
{
     struct s s1;
     printf("%lu ", sizeof(s1));
     return 0;
}
#endif
