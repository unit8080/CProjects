#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str1[] = "aaaaabbccc";
char str2[] = "aaaaabccc";
char str3[] = "abc";
char str4[] = "aaa";
char str5[] = "aa";
char str6[] = "a";
void strCompression (char A[], int len)
{
    if (A == NULL || len < 2) return;
    int idx = 0;
    int i = 1;
    while (A[i] != '\0') {
        if ( A[i] == A[i-1] ) {
            int skip = 2;
            int j = i;
            i++;
            while ( A[i] != '\0' ) {
                if ( A[j] == A[i] ) {
                    skip++;
                } else {
                    break;
                }
                i++;
            }
            A[idx++] = A[j];
            A[idx++] = (char) skip + '0';
        } else {
            if ( A[i] != A[i+1] ) {
                if (idx > 0 ) {
                    A[idx++] = A[i];
                } else {
                    idx = idx + 2;
                }
            } // else nothing
            i++;
        }
    }
    A[idx] = '\0';
}
int main(void)
{
    printf("%s \n", str1);
    strCompression(str1, strlen(str1));
    printf("%s \n\n", str1);
    printf("%s \n", str2);
    strCompression(str2, strlen(str2));
    printf("%s \n\n", str2);
    printf("%s \n", str3);
    strCompression(str3, strlen(str3));
    printf("%s \n\n", str3);
    printf("%s \n", str4);
    strCompression(str4, strlen(str4));
    printf("%s \n\n", str4);
    printf("%s \n", str5);
    strCompression(str5, strlen(str5));
    printf("%s \n\n", str5);
    printf("%s \n", str6);
    strCompression(str6, strlen(str6));
    printf("%s \n\n", str6);
}
