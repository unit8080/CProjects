#include <stdio.h>

int main (int argc, char *argv[])
{
    if (argc < 2) {
        printf("Error : Usage- %s  <numeric-string>\n", *argv);
        return -1;
    }
    int sign  = 0; // 0 - poistive, 1 - negative
    int total = 0;
    char *s = argv[1];

    if (*s == '-') {
        sign = 1;
        s++;
    }
    while (*s != '\0') {
        if (*s < '0' || *s > '9') {
            printf("Error : Invalid- %s  <numeric-string>\n", *argv);
            return -1;
        }
        total = total * 10 + (*s - '0');
        s++;
    }
    printf("%s = %d\n", argv[1], ((sign > 0) ?  ~total+1 : total));
    return 0;
}
