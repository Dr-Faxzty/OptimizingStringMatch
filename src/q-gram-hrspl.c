#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIGMA 256

void Pre_Horspool(unsigned char *P, int m, int hbc[])
{
    int i;
    
    for (i = 0; i < SIGMA * SIGMA; i++)
        hbc[i] = m - 1;
    
    for (i = 0; i < m - 2; i++)
        hbc[P[i] * SIGMA + P[i + 1]] = m - i - 2;
}

int search(unsigned char *P, unsigned char *T)
{
    int i, shift = 0, count = 0, hbc[SIGMA * SIGMA];

    int m = strlen(P);
    int n = strlen(T);
   
    Pre_Horspool(P, m, hbc);

    while (shift <= n - m)
    {
        i = 0;
        while (i < m && P[i] == T[shift + i] && P[i + 1] == T[shift + i + 1])
            i += 2;

        if (i == m)
            count++;

        shift += hbc[T[shift + m - 2] * SIGMA + T[shift + m - 1]];
    }

    return count;
}

int main()
{
    unsigned char txt[] = "ABAAABCD";
    unsigned char pat[] = "ABC";

    int count = search(pat, txt);
    printf("pattern occurs %d times", count);

    return 0;
}