#include <stdio.h>

int main(void) 
{


   int addr = 0xffffffff;
   printf("Ip Address = 0x%x : \n", addr);
   printf("address = %d.%d.%d.%d\n",
          (addr & 0xff000000 ) >> 24,
          (addr & 0x00ff0000 ) >> 16,
          (addr & 0x0000ff00 ) >> 8,
          (addr & 0x000000ff ));
   getchar();

   addr = 0x01010101;
   printf("Ip Address = 0x%x : \n", addr);
   printf("address = %d.%d.%d.%d\n",
          (addr & 0xff000000 ) >> 24,
          (addr & 0x00ff0000 ) >> 16,
          (addr & 0x0000ff00 ) >> 8,
          (addr & 0x000000ff ));
   getchar();

   char *str;
   str = (char *)&addr;
   printf("Ip Address = 0x%x : \n", addr);
   printf("%d.%d.%d.%d\n", str[0] & 0xff, str[1] & 0xff, str[2] & 0xff, str[3]);

   getchar();
   addr = 0x01020304;
   printf("Ip Address = 0x%x : \n", addr);
   printf("%d.%d.%d.%d\n", str[3] & 0xff, str[2] & 0xff, str[1] & 0xff, str[0]);

   return 0;
}
