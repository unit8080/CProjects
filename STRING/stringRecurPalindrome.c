#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool checkPalindrome(char str[], int l, int r)
{
    if (l >= r)
        return true;
    while (!isalpha(str[l]))
        l++;
    while (!isalpha(str[r]))
        r--;
    return (tolower(str[l]) == tolower(str[r])) && 
            checkPalindrome(str, l + 1, r -1);
}
bool isPalindrome(char str[])
{
    return checkPalindrome(str, 0, strlen(str) -1);
}
int main()
{
    char str[] = "level";
    char str1[] = "string";
    char str2[] = "";
    char str3[] = "p";
    char str4[] = "pl";
    char str5[] = "pp";
    char str6[] = "A man, a plan, a canal, Panama!";
    char str7[] = "race car";
    printf("str length = %lu\n", strlen(str6));
    printf("%s is %s\n", str6, isPalindrome(str6) ? "Palindrome" : "Not Palindrome"); 
#if 1
    printf("%s is %s\n", str, isPalindrome(str) ? "Palindrome" : "Not Palindrome"); 
    printf("%s is %s\n", str1, isPalindrome(str1) ? "Palindrome" : "Not Palindrome"); 
    printf("%s is %s\n", str2, isPalindrome(str2) ? "Palindrome" : "Not Palindrome"); 
    printf("%s is %s\n", str3, isPalindrome(str3) ? "Palindrome" : "Not Palindrome"); 
    printf("%s is %s\n", str4, isPalindrome(str4) ? "Palindrome" : "Not Palindrome"); 
    printf("%s is %s\n", str5, isPalindrome(str5) ? "Palindrome" : "Not Palindrome"); 
    printf("%s is %s\n", str7, isPalindrome(str7) ? "Palindrome" : "Not Palindrome"); 
#endif
}
