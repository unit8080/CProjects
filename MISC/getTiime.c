#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    time_t t;
    time(&t);

    printf("Today's date and time : %s",ctime(&t));
    FILE *output = NULL;
    output = fopen("output.txt", "w");
    fprintf(output, " %s ", ctime(&t));
    fclose(output);

    getchar();
    return 0;
}
