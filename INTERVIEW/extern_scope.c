#include <stdio.h>
#if 0
/*
 * This code will give linker error becoz no storage defined.
 */
extern int var;
int main(void)
{
 //extern int var = 10;
 var = 10;
 return 0;
}
#endif

#if 1
/*
 * This code will give compilation error becoz no storage defined.
 * - error: ‘var’ has both ‘extern’ and initializer
 */
int main(void)
{
 extern int var = 10;
 return 0;
}
#endif
