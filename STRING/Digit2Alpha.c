#include <stdio.h>
#include <string.h>

const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printAlpha (int A[], int curr_digit, char output[], int len)
{
    if (curr_digit == len) {
        printf(" %s ", output);
        return;
    }
    for (int i = 0; i < strlen(hashTable[A[curr_digit]]); i++) {
        output[curr_digit] = hashTable[A[curr_digit]][i];
        printAlpha(A, curr_digit+1, output, len);
    }
}

int main(void)
{
    int A[] = {2, 3, 4};
    char output[5];
    output[4] = '\0';
    int len = sizeof(A)/sizeof(A[0]);
    printAlpha(A, 0, output, len);
}
