#include <stdio.h>
#include <string.h>


void recursiveReverseString(char str[], int first, int last)
{
    if (first >= last)
        return;
    char temp;
    temp = str[first];
    str[first] =  str[last];
    str[last] = temp;
    recursiveReverseString(str, first+1, last -1);
}

int main ()
{
    char str[] = "level";
    char str1[] = "palindrome";
    char str2[] = "humtum";
    char str3[] = "hu";
    char str4[] = "h";
    char str5[] = "";

    recursiveReverseString(str, 0 , strlen(str) - 1);
    recursiveReverseString(str1, 0 , strlen(str1) -1);
    recursiveReverseString(str2, 0 , strlen(str2) -1);
    recursiveReverseString(str3, 0 , strlen(str3) -1);
    recursiveReverseString(str4, 0 , strlen(str4) -1);
    recursiveReverseString(str5, 0 , strlen(str5) -1);
    printf( "str = %s\n", str);
    printf( "str1 = %s\n", str1);
    printf( "str2 = %s\n", str2);
    printf( "str3 = %s\n", str3);
    printf( "str4 = %s\n", str4);
    printf( "str5 = %s\n", str5);
}
