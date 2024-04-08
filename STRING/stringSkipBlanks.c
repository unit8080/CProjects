#include <stdio.h>
#include <string.h>

#define DELIM    " "
#define MAXWORD  80
#define MAXLEN   20
#define BUFFSIZ  2000
//char buf[] = "asd  asd";
//char buf[] = "   sasa   dsds   ssdsdsds   dsdsd   ";// skip:10
//char buf[] = "sasa   dsds   ssdsdsds   dsdsd   "; // skip:8
//char buf[] = " Fungi ble is";
char buf[] = " Fungi     ble      is";
void skipBlank (char *str) 
{
    int i = 0;
    int j = 0;
    //int skip = 0;

    j = 1;
    while (str[j] != '\0' ) {
        if (str[j] == ' ' && str[j-1] == ' ') {
            i++; j++; //skip++; 
            while (str[j] != '\0'  && str[j] == ' ') {
                j++; //skip++;
            }
            while (str[j] != '\0' && str[j] != ' ') {
                str[i] = str[j];
                str[j] = ' ';
                i++; j++;
            }
        } else {
            i++; j++;
        }
    }
    //printf("\n Skip blanks: %d\n", skip);
}

int main (void)
{
#if 1
    printf("%s\n", buf);
    skipBlank(buf);
    printf("%s\n", buf);
#else
    char words[MAXWORD][MAXLEN];
    char buff[BUFFSIZ];
    int  ntokens = 0;
    int  i;
    printf("Enter a string: ");
    fflush(stdout);

    if (fgets(buff, sizeof(buff), stdin) != NULL) {
        char *sep;

        sep = strtok(buff, DELIM);
        while (sep != NULL) {
            strcpy(words[ntokens++], sep);
            sep = strtok(NULL, DELIM);
        }
        for (i = 0; i < ntokens; i++) {
            fputs(words[i], stdout);
            fputs(" ", stdout);
            //printf("\n");
        }
    }
#endif
}
