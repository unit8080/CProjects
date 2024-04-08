#include <stdio.h>

int main()
{
   FILE *fp;
   char str[80];

   /* opening file for reading */
   fp = fopen("input.txt" , "r");
   if(fp == NULL) 
   {
      perror("Error opening file");
      return(-1);
   }

   do {
   if( fgets (str, 80, fp)!=NULL ) 
   {
      /* writing content to stdout */
      puts(str);
   }
   } while (str[0] != EOF); //????

   fclose(fp);
   return(0);
}
