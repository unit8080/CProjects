#include <stdio.h>

void
pushZeroToEnd( int arr[], int count)
{
   int index = 0;
   for (int i=0; i < count; i++) 
   {
      if (arr[i] > 0) {
         arr[index++] = arr[i]; 
      }
   }
   while(index < count) 
      arr[index++] = 0;
}

int 
main(void)
{
   int arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9, 0};
   int n = sizeof(arr)/sizeof(arr[0]);

   printf("Array[%d] = ", n);
   for (int i = 0; i < n; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
   pushZeroToEnd(arr, n);
   printf("Array[%d] = ", n);

   for (int i = 0; i < n; i++)
   {
      printf("%d ", arr[i]);
   }
   getchar();
}
