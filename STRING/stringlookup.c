// Read input from stdin, write output to stdout

#include <stdio.h>
#include <string.h>
#define Base 256
#define Mod  331
int int_mod (int a, int b)
{
    return (a % b + b) % b;
}
    char T[100000] = " dasdajkdjasdskjlasdkd";;
    char P[10000]  = "asd";
    // scanf("%s", T);
    // scanf("%s", P);
int main(void)
{
    
    int m = strlen(P);
    int n = strlen(T);
    if (m == 0 || n == 0 || m > n)
        return 0;
    int count = 0;
    int hp = 0;
    for (int i = 0; i < m; i++)
        hp = int_mod(hp * Base + P[i], Mod);
    int ht = 0;
    for (int i = 0; i < m; i++)
        ht = int_mod(ht * Base + T[i], Mod);
    if ((hp == ht) && (strncmp((const char *)P, (const char *)T, m) == 0))
        count++;
    int E = 1;
    for (int i = 1; i < m; i++)
        E = int_mod(E * Base, Mod);
    for (int i = m; i < n; i++) {
        ht = int_mod(ht - int_mod(T[i-m] * E, Mod), Mod);
        ht = int_mod(ht * Base, Mod);
        ht = int_mod(ht + T[i], Mod);
        if ((hp == ht) && (strncmp((const char *)P, (const char *)&T[i-m+1], m) == 0))
            count++;
    }
    printf(" count %d \n", count);
    return count;
}
