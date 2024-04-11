#include <stdio.h>

unsigned long long XOR(unsigned long long n)
{
        if (n <= 1)
                return n;
        return n ^ XOR(n - 1);
}

int main()
{
    int n;
    long long value;
    printf("Enter number : ");
    scanf("%d", &n);
    printf("Value = %lld\n", XOR(n));
    value = n--;
    while (n > 0) {
        value = value ^ n--;
    }
    printf("Value = %lld\n", value);
}
