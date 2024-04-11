#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int first, second;
    first = second = 0;
    scanf("%d",&n);
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          
          scanf("%d",&a[a_i][a_j]);
          if (a_i == a_j)
             first += (a[a_i][a_j]);
       }
    }
    printf("\nfirst = %d ", first);
    for (int a_i = 0; a_i < n; a_i++) {
        for (int a_j = n-1; a_j <=0 ; a_j--)
            second += (a[a_i][a_j]);
    }
    printf("\nsecond = %d ", second);
    if (first > second)
        printf("%d", (first - (second)));
    else 
        printf("%d", (second - (first)));
    return 0;
}
