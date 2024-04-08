#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char a[] = "11";
char b[] = "1";
char* addBinary(char* a, char* b) {
    if (a == NULL && b == NULL)
        return a;
    if (a == NULL) return b;
    if (b == NULL) return a;
    size_t len1 = strlen(a);
    size_t len2 = strlen(b);
    if (len1 == 0 && len2 == 0)
        return a;
    if (len1 == 0)
        return b;
    else if (len2 == 0)
        return a;
    
    int size = len1 > len2 ? len1 : len2;
    char *result = (char *)malloc(sizeof(char) * (size + 2));
    assert(result != NULL);
    int i = len1 -1;
    int j = len2 -1;
    int k = size + 2;
    int carry = 0;
    result[--k] = '\0';
    printf("size = %d\n", size);
    while (i >=0 && j >= 0) {
        int d = (a[i--] -'0') + (b[j--] -'0') + carry;
        result[--k] = d % 2 + '0';
        carry = d / 2;
    }
    while (i >=0) {
        int d = (a[i--] -'0') + carry;
        result[--k] = d % 2 + '0';
        carry = d / 2;
    }
    while (j >= 0) {
        int d =  (b[j--] -'0') + carry;
        result[--k] = d % 2 + '0';
        carry = d / 2;
    }
    printf("carry = %d\n", carry);
    printf("k = %d\n", k);
    if (carry)
        result[--k] = '1';
    else {
        while (k < (size + 1)) {
            result[k-1] = result[k];
            k++;
        }
        result[k] = '\0';
    }
    return result;
}

int main (void)
{
    printf("%s\n", addBinary(a, b));
}

