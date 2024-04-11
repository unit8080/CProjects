#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//int num = 5555;
//int num = 19;
//int num = 58;
int num = 1;
int square_sum (int num)
{
    int new_num = 0;
    while (num != 0)
    {
        int digit = num % 10;
        new_num += digit * digit;
        num = num / 10;
    }
    return new_num;
}
void findMagic(int num) 
{
    int slow, fast;
    slow = fast = abs(num);
    while (true) {
        slow = square_sum(slow);
        fast = square_sum(square_sum(fast));
        printf("Magic : %d %d\n", slow, fast);
        if ((slow  % 10 == 0) || 
            (fast % 10 == 0)) {
           printf("Magic : %d %d\n", slow, fast);
           return;
        }
        if (slow == fast) {
           printf("No Magic : %d %d\n", slow, fast);
            return;
        }
    }
}
int main (void)
{
    findMagic(num);
}
