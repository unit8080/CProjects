#include <stdio.h>
#include <time.h>

void func (void)
{
    printf("Press any key to exit \n");
    while (1) {
        printf("\n print something");
        if (getchar())
            break;
    }
}

int main (void)
{
    clock_t start, end;
    double seconds_used;

    start = clock();
    func();
    end = clock();
    seconds_used = (double)(end -start)/CLOCKS_PER_SEC;
    printf(" Total execution time ticks %lu, %f\n", 
            end - start, seconds_used);
}
