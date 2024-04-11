#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* time = (char *)malloc(10240 * sizeof(char));
    scanf("%s",time);
    char hh[2], mm[2], ss[2];
    
    hh = (char *)time;
    mm = (char *)time + 3;
    ss = (char *)time + 6;

    printf("Hours = %d ", atoi(hh));
    printf("Min = %d ", atoi(mm));
    printf("Sec = %d ", atoi(ss));

    if (time[8] == 'A') {
        printf(" AM format \n");
        if (atoi(hh) == 12 && atoi(mm) == 00 && atoi(ss) == 00)
            printf("00:00:00");
        else
            printf("%d:%s:%s", atoi(hh), mm, ss);
    }
    else 
        printf(" PM format \n");
     
    getchar();
    return 0;
}
