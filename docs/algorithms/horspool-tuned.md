# Algoritmo Horspool Tuned

## Introduzione

L'algoritmo di `Horspool Tuned` è una versione ottimizzata dell'algoritmo di Horspool per lo string matching. Si basa su un'analisi più dettagliata delle frequenze dei caratteri nel testo di input, al fine di ridurre ulteriormente il numero di confronti e spostamenti durante la ricerca. Questa versione fa uso di una tecnica di "ordinamento pivot", basata sulla frequenza dei caratteri, per migliorare la velocità del confronto del pattern nel testo.

## Funzionamento dell'Algoritmo

### Fase 1: Preprocessing delle Frequenze

L'algoritmo calcola la frequenza di ogni carattere presente nel testo e genera una lista ordinata di questi caratteri, con quelli più rari ordinati prima. Questo permette di confrontare prima i caratteri meno frequenti, riducendo potenzialmente i confronti.

### Fase 2: Ordinamento Pivot

Usando la lista ordinata delle frequenze dei caratteri, l'algoritmo genera un "ordine di pivot" per i caratteri del pattern. Con questo approccio, i caratteri meno frequenti nel testo vengono confrontati per primi, poiché è più probabile che un mismatch si verifichi con caratteri rari.

### Fase 3: Ricerca Ottimizzata

Durante la fase di ricerca, il pattern viene allineato con il testo e confrontato in base all'ordine determinato dalle frequenze dei caratteri. Questo permette all'algoritmo di saltare sezioni del testo con maggiore efficienza rispetto alla versione standard dell'algoritmo di Horspool.

### Vantaggi

- **Miglioramento del Confronto**: Confrontando prima i caratteri meno frequenti, si riducono i confronti complessivi.
- **Ottimizzazione**: La fase di preprocessing dell'ordine dei caratteri introduce una leggera complessità aggiuntiva, ma riduce significativamente i confronti nella fase di ricerca.

## Codice dell'Algoritmo Horspool Tuned

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGMA 256 // Dimensione dell'alfabeto ASCII


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

/**
 * Funzione di preprocessing: Pre_Horspool
 * Costruisce la tabella di spostamenti per l'algoritmo di Horspool.
 */
void Pre_Horspool(unsigned char *P, int m, int hbc[])
{
	int i;
	for (i = 0; i < SIGMA; i++)
		hbc[i] = m;  // Imposta il valore massimo di spostamento per ogni carattere

	for (i = 0; i < m - 1; i++)
		hbc[P[i]] = m - i - 1;  // Calcola gli spostamenti per i caratteri del pattern
}

/**
 * Funzione di supporto: select_pivot_character
 * Seleziona e ordina i caratteri in base alla loro frequenza nel testo.
 */
int *select_pivot_character(unsigned char *text, int n)
{
	int i, j;
	int occ[SIGMA] = {0};   // Array delle occorrenze dei caratteri
	double freq[SIGMA] = {0};  // Array delle frequenze dei caratteri
	int *sig = (int *)malloc(sizeof(int) * SIGMA);  // Array di indici per l'ordinamento

	// Inizializza array sig
	for (i = 0; i < SIGMA; i++)
		sig[i] = i;

	// Conta le occorrenze dei caratteri nel testo
	for (i = 0; i < n; i++)
		occ[text[i]]++;

	// Calcola le frequenze relative dei caratteri
	for (i = 0; i < SIGMA; i++)
		freq[i] = (double)occ[i] / (double)n * 100;

	// Sposta i caratteri con frequenza 0 all'inizio dell'array sig
	for (i = 0, j = 0; i < SIGMA; i++)
		if (freq[i] == 0)
			swap(sig, i, j++);

	// Ordina i caratteri in base alle loro frequenze
	quicksort(freq, j, SIGMA - 1, sig);

	return sig;
}

/**
 * Funzione di ricerca: tun
 * Esegue la ricerca del pattern nel testo utilizzando l'algoritmo di Horspool Tuned.
 */
int tun(unsigned char *P, unsigned char *T)
{
	int i, s, count, hbc[SIGMA];  // hbc è la tabella di spostamenti

    int m = strlen(P);  // Lunghezza del pattern
    int n = strlen(T);  // Lunghezza del testo

	// Seleziona i caratteri pivot basati sulla frequenza nel testo
	int *frequency = select_pivot_character(T, n);

	int order[m];  // Ordine dei caratteri nel pattern
	int pos = 0;
	int car = 0;

	// Preprocessamento di Horspool
	Pre_Horspool(P, m, hbc);

	// Determina l'ordine di confronto dei caratteri del pattern in base alle frequenze
	while (pos < m)
	{
		for (int i = 0; i < m; i++)
		{
			if (P[i] == frequency[car])
			{
				order[pos++] = i;  // Inserisce l'indice del carattere nel pattern secondo l'ordine delle frequenze
			}
		}
		car++;
	}

	// Fase di ricerca nel testo
	s = 0;
	count = 0;
	while (s <= n - m)
	{
		i = 0;
		while (i < m && P[order[i]] == T[s + order[i]])
			i++;  // Confronta i caratteri in base all'ordine delle frequenze

		if (i == m)
			count++;  // Incrementa il contatore se il pattern è stato trovato

		// Sposta il pattern secondo la tabella di spostamenti
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
```