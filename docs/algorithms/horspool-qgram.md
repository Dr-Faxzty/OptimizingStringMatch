# Algoritmo di Horspool con q-grammi

## Introduzione

L'algoritmo di Horspool con q-grammi è una variante avanzata dell'algoritmo di Horspool per la ricerca di pattern all'interno di un testo. Mentre l'algoritmo standard di Horspool utilizza singoli caratteri per determinare gli spostamenti in caso di mismatch, questa versione sfrutta i `q-grammi`, ossia coppie di caratteri consecutivi (q = 2), per saltare in modo più efficiente nel testo. Utilizzando queste coppie di caratteri, l'algoritmo riesce a ridurre il numero di confronti necessari durante la ricerca, migliorando le prestazioni in alcuni scenari.

## Funzionamento dell'Algoritmo

### Fase 1: Preprocessing

Nella fase di preprocessing, viene costruita una tabella di spostamenti chiamata `hbc` (heuristic bad character) per tutte le possibili coppie di caratteri consecutivi. Per ogni q-gramma trovato nel pattern, viene calcolato lo spostamento che indica di quante posizioni l'algoritmo può saltare nel caso di un mismatch.

### Fase 2: Ricerca

Durante la fase di ricerca, l'algoritmo confronta il pattern e il testo a coppie di caratteri, avanzando di due caratteri per volta. Se tutti i q-grammi corrispondono, il pattern viene considerato trovato. In caso di mismatch, viene utilizzata la tabella `hbc` per determinare il numero di caratteri da saltare, basandosi sulla coppia di caratteri che ha causato il mismatch.

### Vantaggi

- **Maggiore Efficienza**: Poiché l'algoritmo confronta coppie di caratteri anziché singoli caratteri, può potenzialmente saltare più posizioni nel testo in caso di mismatch, riducendo il numero complessivo di confronti.
- **Riduzione di Confronti Ridondanti**: Confrontando direttamente q-grammi, l'algoritmo riduce la probabilità di confronti ridondanti che possono verificarsi con un approccio carattere per carattere.

## Codice dell'Algoritmo di Horspool con q-grammi

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIGMA 256 // Numero di caratteri dell'alfabeto ASCII (256 caratteri)

/**
 * Funzione di preprocessing: Pre_Horspool
 * Costruisce la tabella delle distanze di salto per i q-grammi
 */
void Pre_Horspool(unsigned char *P, int m, int hbc[])
{
   int i;
   // Inizializza la tabella di salto per tutte le combinazioni possibili di coppie di caratteri
   for (i = 0; i < SIGMA * SIGMA; i++)
      hbc[i] = m - 1;  // Imposta un salto predefinito di m-1 per tutte le coppie

   // Calcola lo spostamento per le coppie effettive di caratteri nel pattern
   for (i = 0; i < m - 2; i++)
      hbc[P[i] * SIGMA + P[i + 1]] = m - i - 2;  // Aggiorna il salto per ogni coppia
}

/**
 * Funzione di ricerca: search
 * Cerca il pattern `P` nel testo `T` utilizzando q-grammi e la tabella di salto.
 */
int search(unsigned char *P, unsigned char *T)
{
    int i, shift = 0, count = 0, hbc[SIGMA * SIGMA];  // Variabili locali e tabella di spostamenti

    int m = strlen(P);  // Lunghezza del pattern
    int n = strlen(T);  // Lunghezza del testo
   
    // Preprocessing del pattern per costruire la tabella di spostamenti basata sui q-grammi
    Pre_Horspool(P, m, hbc);

    // Loop principale di ricerca
    while (shift <= n - m)
    {
        i = 0;
        
        // Confronto per q-grammi (coppie di caratteri consecutivi)
        while (i < m && P[i] == T[shift + i] && P[i + 1] == T[shift + i + 1])
            i += 2;  // Avanza di due posizioni (confronto q-gramma)

        // Se tutti i q-grammi corrispondono, il pattern è stato trovato
        if (i == m)
            count++;  // Incrementa il conteggio delle occorrenze

        // Usa la tabella di spostamenti basata sui q-grammi per determinare il salto
        shift += hbc[T[shift + m - 2] * SIGMA + T[shift + m - 1]];
    }

    return count;
}


int main()
{
    unsigned char txt[] = "ABAAABCD"; s
    unsigned char pat[] = "ABC";       

    int count = search(pat, txt);  
    
    printf("Il pattern appare %d volte", count); 
    return 0;
}
```