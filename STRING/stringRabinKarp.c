#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// basic rules of modular arithmetic expression:
// A + B = C => (A % M + B % M) % M = C % M
// A * B = C => ((A % M) * (B % M)) % M = C % M
#define BASE 256  /* Base */
#define MOD  331  /* Modulo prime number >= |S| */

// correctly calculates a mod b even if a < 0
int int_mod (int a, int b)
{
    return(a % b + b) % b;
}

int BasePowerModulo( int base, int m, int mod)
{
    int E = 1;
    for (int i= 1; i < m; i++)
         E = int_mod(E*base, mod);
    return E;
}

bool rabinKarpMatch(char P[], char T[])
{
    int i;
    if (P == NULL || T == NULL)
        return false;

    int m = strlen(P); /* pattern string length */
    int n = strlen(T); /* Text string length */
    if (n < m) 
        return false; // no match is possible

    // calculate the hash value of pattern - one time only
    int hp = 0;
    for (i = 0; i < m; i++)
        hp = int_mod(hp*BASE + P[i],  MOD);

    // calculate the hash value of the first segment
    // of the text of lenght m
    int ht = 0;
    for (i = 0; i < m; i++)
        ht = int_mod(ht*BASE + T[i], MOD);

    printf("1: ht = %d; hp = %d\n", ht, hp);
    if (ht == hp)
        return true; // Note need to compare the pattern with text

    // start the "rolling hash" for every next character in
    // the test calculate the hash value of the new segment of
    // length m; needs E = Base power of (m-1) % M
    int E = BasePowerModulo(BASE, m, MOD);  /* Base power (m-1) modulo M */
    for (i = m; i < n; i++) {
        ht = int_mod(ht - int_mod(T[i-m] * E, MOD), MOD); // step 1
        ht = int_mod(ht * BASE, MOD);                     // step 2
        ht = int_mod(ht + T[i], MOD);                     // step 3
        if (ht == hp) {
            printf("Matched: i = %d; n = %d; ht = %d; hp = %d\n", i-m+1, n, ht, hp);
            return true; // note need to compare the each char
        }
    }
    printf("End: i = %d; n = %d; ht = %d; hp = %d\n", i-m, n, ht, hp);
    return false;
}

int main ()
{
    char pattern[] = "asdasd";
    char text[] = "7asdasd1229asd1asddedd334djdfskljfsdlfjdajdhsfjsasdasdff";
    printf("Match found ? %s\n", 
           rabinKarpMatch(pattern, text) ? "Yes" : "No");
}
