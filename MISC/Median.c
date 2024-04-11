#include <stdio.h>

int main() {
        //code
        int count;
        int num;
        scanf("%d", &count);
        int sum = 0;
        for (int i=0; i < count; i++) {
            scanf("%d", &num);
            sum += num;
            printf("%d \n", sum/(i+1));
        }
        return 0;
}
