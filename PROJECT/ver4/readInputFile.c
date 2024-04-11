#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "timer.h"

#define INVALID 0
unsigned int convert_ip_to_int(const char *line, int *index)
{
    unsigned int ip = 0;
    int i = 0;
    char c;
    unsigned int n = 0; // Value of this byte
    int j = 0;
    for (int i=0; i < 4; i++) {
    while (true) {
        c = line[j];
        if (c >= '0' && c <= '9') {
            n = n*10;
                n += (c -'0');
            j++;
        } else if ((i < 3 && c == '.') || (i == 3 && c == ' ')) {
            if (n >= 256)
                return INVALID;
            ip = (ip << 8);
            ip = (ip | n);
            n = 0;
            j++;
            break;
        } else {
            return INVALID;
        }
    }
    }
    *index = j;
    return ip;
}
unsigned int convert_tmo_to_int(const char *line)
{
    unsigned int tmo = 0; 
    int i = 0;
    while ((line[i] != '\0') && (line[i] != ' ')  &&
            (line[i] != '\t') && (line[i] >= '0' && line[i] <= '9')) {
        tmo = tmo*10;
        tmo += (line[i] - '0');
        i++;
    }
    return tmo;
}
void parse_line(const char *line)
{
    bool pause = false;
    int i = 0;
    unsigned int tmo = 0;
    unsigned int ip = 0;

    while (line[i] == ' ') { // skip space char
        i++;
        continue;
    }
    if (line[i] == 'P') {
        pause = true;
        printf("%c ", line[i]);
        i++;
    } else {
        int index = 0;
        ip = convert_ip_to_int(line, &index);
        printf("%d.%d.%d.%d ", (ip & 0xff000000) >> 24,
                               (ip & 0x00ff0000) >> 16,
                               (ip & 0x0000ff00) >> 8,
                               ip & 0x000000ff );
        i += index;
    }
    while (line[i] == ' ')  { //skip space char
        i++;
        continue;
    }
    tmo = convert_tmo_to_int(&line[i]);
    printf("%d\n", tmo);
    if (!pause)
        AddIpAddr(ip, tmo);
    else {
        AddIpAddr(ip, tmo);
        pause_for(tmo);
    }
}
void ParseInputFile (void)
{
    int size = 100, pos;
    int c;
    char *buffer = (char *)malloc(size);

    FILE *f = fopen("input.txt", "r");
    if (f) {
      do { // read all lines in file
        pos = 0;
        do { // read one line
          c = fgetc(f);
          if (c != EOF) buffer[pos++] = (char)c;
          if (pos >= size - 1) { // increase buffer length - leave room for 0
            size *=2;
            buffer = (char*)realloc(buffer, size);
          }
        } while (c != EOF && c != '\n');
        buffer[pos] = '\0';
        // line is now in buffer
        parse_line(buffer);
      } while (c != EOF); 
      fclose(f);           
    }
    free(buffer);
}
