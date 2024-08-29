# Algoritmo di Horspool

## Introduzione

L'algoritmo di Horspool è un algoritmo efficiente per la ricerca di pattern in un testo. È una variante semplificata dell'algoritmo di Boyer-Moore, che sfrutta una tabella di spostamenti chiamata "bad character table" per determinare quanto l'algoritmo può saltare nel testo quando si verifica un mismatch tra il pattern e il testo.

## Funzionamento dell'Algoritmo

### Fase 1: Preprocessing

Durante la fase di preprocessing, viene costruita la tabella delle distanze di salto, `hbc` (heuristic bad character), per tutti i caratteri possibili nell'alfabeto ASCII (256 caratteri). Per ciascun carattere del pattern, viene calcolato lo spostamento da effettuare in caso di mismatch.

### Fase 2: Ricerca

Nella fase di ricerca, l'algoritmo confronta i caratteri del pattern con i caratteri del testo partendo dall'ultimo carattere del pattern. Se si verifica un mismatch, viene utilizzata la tabella `hbc` per determinare quante posizioni saltare nel testo, spostando il pattern di diverse posizioni in avanti.

### Vantaggi

- **Semplicità**: Horspool è più semplice rispetto all'algoritmo di Boyer-Moore, poiché utilizza solo la "bad character heuristic" e ignora altre euristiche più complesse.
- **Efficienza**: In caso di mismatch, l'algoritmo può saltare diverse posizioni, riducendo il numero di confronti necessari rispetto a un approccio più tradizionale come la ricerca con forza bruta.

## Codice dell'Algoritmo di Horspool

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIGMA 256 // Numero di caratteri dell'alfabeto ASCII (256 caratteri)

/**
 * Funzione di preprocessing: Pre_Horspool
 * Costruisce la tabella delle distanze di salto (bad character table) per i caratteri nel pattern.
 */
void Pre_Horspool(unsigned char *P, int m, int hbc[]) 
{
   int i;
   // Inizializza la tabella di salto con il valore m (lunghezza del pattern)
   for(i = 0; i < SIGMA; i++) 
       hbc[i] = m;

   // Aggiorna la tabella di salto con valori specifici per i caratteri presenti nel pattern
   for(i = 0; i < m - 1; i++) 
       hbc[P[i]] = m - i - 1;
}

/**
 * Funzione di ricerca: search
 * Cerca il pattern `P` nel testo `T` utilizzando l'algoritmo di Horspool.
 */
int search(unsigned char *P, unsigned char *T) 
{
    int i, shift = 0, count = 0, hbc[SIGMA];  // Variabili locali e tabella di spostamenti

    int n = strlen(T);  // Lunghezza del testo
    int m = strlen(P);  // Lunghezza del pattern

    // Preprocessing del pattern per costruire la tabella di spostamenti
    Pre_Horspool(P, m, hbc);
    
    // Loop principale di ricerca
    while (shift <= n - m) 
    {
        i = 0;
        
        // Confronto dei caratteri a partire dall'inizio del pattern
        while (i < m && P[i] == T[shift + i]) 
            i++;

        // Se tutti i caratteri corrispondono, il pattern è stato trovato
        if (i == m) 
            count++;  // Incrementa il conteggio delle occorrenze

        // Usa la tabella di spostamenti per determinare quanto saltare nel testo
        shift += hbc[T[shift + m - 1]];
    }
    
    return count;
}


int main()
{
    unsigned char txt[] = "ABAAABCD";
    unsigned char pat[] = "ABC";       

    int count = search(pat, txt);  
    
    printf("Il pattern appare %d volte", count);
    return 0;
}
