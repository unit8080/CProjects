#include <stdio.h>

char A[] = {'c', 'a', 'p', 'b', 'a', 'c', 'd', 'e', 'g', 'h', 'z', 'h', 'e', 's', 'g', 't', 'y', 'd'};

int len = sizeof(A)/sizeof(A[0]);

        //printf( "\n A[%d] : %c ", i, A[i]);
            //printf(" \n count %d, max %d  last %d\n", count, max, last);
int main(void)
{
    int idx[26]; 
    for(int i = 0; i < 26; i++)
        idx[i] = -1;

    int max = 1;
    int count = 1;
    int last = 0;

    int i = 0;
    while (i < len) {
        if (idx[A[i] - 'a'] < 0) {
            idx[A[i] -'a'] = i;
        } else { 
            count = i - last;
            if (idx[A[i] - 'a'] < last )
                count +=1;
            if (max < count)
                max = count;
            if (last <= idx[A[i] - 'a'] )
                last =  idx[A[i] - 'a'] + 1;
            idx[A[i] - 'a'] = i;
        }
        i++;
    }
    printf(" %d \n", max);
}

