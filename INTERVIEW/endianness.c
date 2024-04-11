#include <stdio.h>

/* 
 * function to show bytes in memory, from location start to start+n
 */
void show_mem_rep(char *start, int n) 
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %p : %.2x\n", &start[i], start[i]);
    printf("\n");
}
 
/*
 * Main function to call above function for 0x01234567
 */
int main()
{
   int i = 0x12345678;
   char *c = (char *)&i;
   if (*c == 0x78) printf("Little endian\n"); else printf("Big Endian\n");
   printf("Memory content = 0x%x \n", i);
   printf("Data stored as in Memory : \n");
   show_mem_rep((char *)&i, sizeof(i));
   getchar();

   return 0;
}
