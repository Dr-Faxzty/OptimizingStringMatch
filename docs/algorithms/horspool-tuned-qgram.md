# Algoritmo Horspool Tuned con q-grammi

## Introduzione

L'algoritmo di `Horspool Tuned` con q-grammi è una versione avanzata dell'algoritmo di Horspool per il matching delle stringhe. Combina il metodo di Horspool con l'analisi delle frequenze dei q-grammi (blocchi di due caratteri) nel testo per ottimizzare ulteriormente il numero di confronti necessari. Questo approccio migliora l'efficienza della ricerca riducendo il numero di spostamenti e confronti attraverso l'uso di una tabella di spostamenti ottimizzata e un ordinamento basato sulla frequenza.

## Funzionamento dell'Algoritmo

### Fase 1: Preprocessing delle Frequenze

L'algoritmo calcola la frequenza di ogni q-grammo (blocchi di due caratteri) nel testo e crea una lista ordinata basata su queste frequenze. Questo ordinamento permette di confrontare prima i q-grammi meno frequenti, riducendo i confronti.

### Fase 2: Ordinamento Pivot

Usando la lista ordinata dei q-grammi in base alla loro frequenza, l'algoritmo genera un "ordine di pivot" per i q-grammi del pattern. I q-grammi meno frequenti vengono confrontati per primi, poiché è più probabile che un mismatch si verifichi con q-grammi rari.

### Fase 3: Ricerca Ottimizzata

Durante la fase di ricerca, il pattern viene allineato con il testo e confrontato in base all'ordine determinato dalle frequenze dei q-grammi. Questo approccio consente di saltare porzioni del testo con maggiore efficienza rispetto all'algoritmo di Horspool standard.

### Vantaggi

- **Riduzione dei Confronti**: Confrontando prima i q-grammi meno frequenti, l'algoritmo riduce il numero totale di confronti.
- **Efficienza Ottimizzata**: L'uso dei q-grammi e l'ordinamento basato sulla frequenza migliorano l'efficienza rispetto all'algoritmo originale di Horspool.

## Codice dell'Algoritmo Horspool Tuned con q-grammi

```c
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

/**
 * Funzione di preprocessing: Pre_Horspool
 * Costruisce la tabella di spostamenti per l'algoritmo di Horspool.
 */
void Pre_Horspool(unsigned char *P, int m, int hbc[])
{
    int i;
    
    for (i = 0; i < SIGMA * SIGMA; i++)
        hbc[i] = m - 1;
    
    for (i = 0; i < m - 2; i++)
        hbc[P[i] * SIGMA + P[i + 1]] = m - i - 2;
}

/**
 * Funzione di supporto: select_pivot_character
 * Seleziona e ordina i q-grammi (blocchi di 2 caratteri) in base alla loro frequenza nel testo.
 */
int *select_pivot_character(unsigned char *text, int n)
{
    int i, j;
    int occ[SIGMA * SIGMA] = {0};  // Array delle occorrenze dei q-grammi
    double freq[SIGMA * SIGMA] = {0};  // Array delle frequenze dei q-grammi
    int *sig = (int *)malloc(sizeof(int) * (SIGMA * SIGMA));  // Array di indici per l'ordinamento

    // Inizializza array sig
    for (i = 0; i < SIGMA * SIGMA; i++)
        sig[i] = i;

    // Conta le occorrenze dei q-grammi nel testo
    for (i = 0; i < n - 1; i++)
        occ[text[i] * SIGMA + text[i + 1]]++;

    // Calcola le frequenze relative dei q-grammi
    for (i = 0; i < SIGMA * SIGMA; i++)
        freq[i] = (double)occ[i] / (double)n * 100;

    // Sposta i q-grammi con frequenza 0 all'inizio dell'array sig
    for (i = 0, j = 0; i < SIGMA * SIGMA; i++)
        if (freq[i] == 0)
            swap(sig, i, j++);

    // Ordina i q-grammi in base alle loro frequenze
    quicksort(freq, j, SIGMA * SIGMA - 1, sig);

    return sig;
}

/**
 * Funzione di ricerca: tun
 * Esegue la ricerca del pattern nel testo utilizzando l'algoritmo di Horspool Tuned con q-grammi.
 */
int tun(unsigned char *P, unsigned char *T)
{
    int i, s, count, hbc[SIGMA * SIGMA];  // hbc è la tabella di spostamenti

    int m = strlen(P);  // Lunghezza del pattern
    int n = strlen(T);  // Lunghezza del testo

    // Preprocessing di Horspool
    Pre_Horspool(P, m, hbc);

    // Seleziona i q-grammi basati sulla frequenza nel testo
    int *frequency = select_pivot_character(T, n);
    int order[m / 2 + m % 2];  // Array per memorizzare l'ordine dei q-grammi
    int pos = 0, car = 0;

    // Determina l'ordine di confronto dei q-grammi del pattern in base alle frequenze
    while (pos < m / 2)
    {
        for (int i = 0; i < m - 1; i += 2)
        {
            if (P[i] * SIGMA + P[i + 1] == frequency[car])
                order[pos++] = i;
        }
        car++;
    }

    // Gestione per il carattere rimanente (se la lunghezza è dispari)
    int shift = 0, count = 0;
    while (shift <= n - m)
    {
        i = 0;
        // Confronta il pattern con una porzione del testo
        while (i < m / 2 && P[order[i]] == T[shift + order[i]] && P[order[i] + 1] == T[shift + order[i] + 1])
            i++;

        // Se tutti i q-grammi sono uguali e il pattern è di lunghezza dispari, controlla anche l'ultimo carattere rimanente
        if (i == m / 2 && (m % 2 == 0 || P[m - 1] == T[shift + m - 1]))
            count++;

        // Sposta il pattern verso destra in base alla tabella di spostamenti
        shift += hbc[T[shift + m - 2] * SIGMA + T[shift + m - 1]];
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
}```
