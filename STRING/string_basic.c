#include <stdio.h>
#include <string.h>
/*
 * Tips: 
 * 1. main() return integer. don't try void return
 * 2. strlen() always return the string length *without*
 *    '\0' character.
 * 3. sizeof operator always return the allocated memory size
 *    including '\0' character.
 *
 */
int main(void)
{
    char new_string[256];
    char _string[256];
    char *string;
    int i;

    char strings[32] = "Hello, World";
    printf("sizeof(strings[32]) : %d, strlen = %d\n",
            (int)sizeof(strings),  (int)strlen(strings));
    printf("sizeof(sanjeev) : %d, strlen = %d\n", 
            (int)sizeof("sanjeev"), (int)strlen("sanjeev"));

    printf("Enter the string: ");
    /*
     * Tips: 
     * 1. scanf reads only the word. To read the sentence
     *    it should read until the end-of-line (or CR)
     * 2. don't forget to add the \n in printf.
     */
    scanf("%s", new_string);
    printf("string format   :%s\n", new_string);
   
    printf("char format     : %c\n", new_string[0]);

    new_string[0] = '\0';
    printf("NULL char, idx=0: %d\n", new_string[0]);

    new_string[0] = 0;
    printf("zero at 1st elem: %d\n", new_string[0]);

    char str[] = "123456789123456789123456789123455667722345566222232456632222";
    printf("Given string   : %s\n", str);
    for (i=0;i<20;i++) {
        str[i]='x';
    }
    printf("string with x  : %s\n", str);
    str[25] = '\0';
    printf("null@index 25: : %s\n", str);

   // printf("%s\n", str[2]); // this would cause segmentation fault */

    /*
    printf("Enter the sentence: \n");
     * Tips: 
     * 1. scanf reads only the word. To read the sentence
     *    it should read until the end-of-line (or CR)
     * 2. don't forget to add the \n in printf.
    new_string[0] = '\0';
    scanf("%s", new_string);
    while (new_string != NULL) {
        scanf("%s", new_string);
    }
    printf("%s\n", new_string);
     */
    return(0);
}
