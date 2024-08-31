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

	for (i = 0; i < SIGMA; i++)
		hbc[i] = m;

	for (i = 0; i < m - 1; i++)
		hbc[P[i]] = m - i - 1;
}

int *select_pivot_character(unsigned char *text, int n)
{
	int i, j;
	int occ[SIGMA] = {0};
	double freq[SIGMA] = {0};
	int *sig = (int *)malloc(sizeof(int) * (SIGMA));

	for (i = 0; i < SIGMA; i++)
		sig[i] = i;

	for (i = 0; i < n; i++)
		occ[text[i]]++;

	for (i = 0; i < SIGMA; i++)
		freq[i] = (double)occ[i] / (double)n * 100;

	for (i = 0, j = 0; i < SIGMA; i++)
		if (freq[i] == 0)
			swap(sig, i, j++);

	quicksort(freq, j, SIGMA - 1, sig);

	return sig;
}

int tun(unsigned char *P, unsigned char *T)
{
	int i, hbc[SIGMA];

    int m = strlen(P);
    int n = strlen(T);

	Pre_Horspool(P, m, hbc);
	
	int *frequency = select_pivot_character(T, n);
	int order[m];
	int pos = 0, car = 0;

	while (pos < m)
	{
		for (int i = 0; i < m; i++)
		{
			if (P[i] == frequency[car])
				order[pos++] = i;
		}
		car++;
	}

	int s = 0, count = 0;

	while (s <= n - m)
	{
		i = 0;
		while (i < m && P[order[i]] == T[s + order[i]])
			i++;

		if (i == m)
			count++;

		s += hbc[T[s + m - 1]];
	}

	return count;
}

int search(unsigned char *x, unsigned char *y) { return tun(x, y); }

int main()
{
    unsigned char pattern[] = "bra";
    unsigned char text[] = "abracadabra";

    printf("%d\n", search(pattern, text));

    return 0;
}