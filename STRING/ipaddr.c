#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool convertIpAddr (const char *str, unsigned int *ip)
{   // abc.def.ghi.jkl'\0' = 16
    unsigned char *s = (unsigned char *)str;
    int dots = 0;
    int byte;
    int len = strlen(str);
    if (len > 16)  // abc.def.ghi.jkl'\0' = 16 max
        return false;
    *ip = 0;
    for (int i = 0; i < 4; i++)  {
        byte = 0;       // computes ip address bytes
        int j = 0;      // should be upto 3 numbers
        while (*s != '\0' && *s != '.' && j < 3) {
            unsigned char c = *s;
            if (!isdigit(c))  // check for valid digit
                return false;
            byte = byte*10 + (c - '0');
            j++;
            s++;
        }
        if (*s != '\0' && *s != '.') // invalid more than 3 digits
            return false;
        if (byte > 255)              // invalid byte gt 255
            return false;
        if (*s == '.')               // count dots 
            dots++;  

        if (byte == 0 && *(s-1) == '.')   // invalid if last char is dot
            return false;
        *ip = (*ip << 8) + byte;
        if (*s == '\0' && dots == 3)
            return true;
        else if (*s == '\0' && dots != 3) // three dots are must. 
            return false;
        s++; // to skip . and /0 
    }
    if (dots != 3 ) return false;
    return true;
}

int main()
{
    //char str[] = "0.0.0.0";           // valid
    //char str[] = "255.255.255.255";   // valid
    char str[] = "01.02.03.04";       // valid
    //char str[] = "001.020.255.000";   // valid
    //char str[] = "001.020.000.000";   // valid
    //char str[] = "001.0002.03.0000";  // invalid
    //char str[] = "001.002.03.000.111";// invalid
    // char str[] = "001.020.255.000.";  // invalid
    //char str[] = "256.256.256.256";   // invalid
    //char str[] = "001.020.000.000";   // valid
    uint32_t ip;
    bool valid = convertIpAddr(str, &ip);
    if (!valid)
        printf("Invalid IP address %s ", str);
    else 
        printf("Valid IP address %s ", str);
    printf(" Ip Addr 0x%x\n", ip);
}
