#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGMA 256

void swap(int *sig, int i, int j)
{
    int a = sig[i];
    sig[i] = sig[j];
    sig[j] = a;
}

void quicksort(double v[], int left, int right, int sig[])
{
    int i, j;
    i = left;
    j = right;
    double pivot = v[sig[(i + j) / 2]];

    while(i <= j)
    {
        while(v[sig[i]] < pivot) i++;
        while(v[sig[j]] > pivot) j--;
        
        if(i <= j)
        {
            swap(sig, i, j);
            i++;
            j--;
        }
    }

    if(left < j) quicksort(v, left, j, sig);
    if(i < right) quicksort(v, i, right, sig);
}

void Pre_Horspool(unsigned char *P, int m, int hbc[])
{
    int i;
    
    for (i = 0; i < SIGMA * SIGMA; i++)
        hbc[i] = m - 1;
    
    for (i = 0; i < m - 2; i++)
        hbc[P[i] * SIGMA + P[i + 1]] = m - i - 2;
}

int *select_pivot_character(unsigned char *text, int n)
{
	int i, j;
	int occ[SIGMA * SIGMA] = {0};
	double freq[SIGMA * SIGMA] = {0};
	int *sig = (int *)malloc(sizeof(int) * (SIGMA * SIGMA));

	for (i = 0; i < SIGMA * SIGMA; i++)
		sig[i] = i;

	for (i = 0; i < n - 1; i++)
		occ[text[i] * SIGMA + text[i + 1]]++;

	for (i = 0; i < SIGMA * SIGMA; i++)
		freq[i] = (double)occ[i] / (double)n * 100;

	for (i = 0, j = 0; i < SIGMA * SIGMA; i++)
		if (freq[i] == 0)
			swap(sig, i, j++);

	quicksort(freq, j, SIGMA * SIGMA - 1, sig);

	return sig;
}

int search(unsigned char *P, unsigned char *T)
{
    int i, hbc[SIGMA * SIGMA];

    int m = strlen(P);
    int n = strlen(T);

    Pre_Horspool(P, m, hbc);

    int *frequency = select_pivot_character(T, n);
    int order[m / 2 + m % 2];
	int pos = 0, car = 0;

	while (pos < m / 2)
	{
		for (int i = 0; i < m - 1; i += 2)
		{
			if (P[i] * SIGMA + P[i + 1] == frequency[car])
				order[pos++] = i;
		}
		car++;
	}

    int shift = 0, count = 0;

    while (shift <= n - m)
    {
        i = 0;
        while (i < m / 2 && P[order[i]] == T[shift + order[i]] && P[order[i] + 1] == T[shift + order[i] + 1])
            i++;

        if (i == m / 2 && (m % 2 == 0 || P[m - 1] == T[shift + m - 1]))
            count++;

        shift += hbc[T[shift + m - 2] * SIGMA + T[shift + m - 1]];
    }

    return count;
}

int main()
{
    unsigned char pattern[] = "bra";
    unsigned char text[] = "abracadabra";

    printf("%d\n", search(pattern, text));

    return 0;
}
