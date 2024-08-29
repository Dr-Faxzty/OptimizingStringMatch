# Algoritmo di Boyer-Moore

## Introduzione

L'algoritmo di Boyer-Moore è uno degli algoritmi più efficienti per la ricerca di pattern in un testo. Sfrutta due euristiche: la **"bad character heuristic"** e la **"good suffix heuristic"**, che permettono di ridurre notevolmente il numero di confronti rispetto agli algoritmi di forza bruta. 

Nella sua forma base, l'algoritmo di Boyer-Moore utilizza la "bad character heuristic" per determinare gli spostamenti del pattern rispetto al testo, rendendolo particolarmente efficiente per pattern lunghi.

## Funzionamento dell'Algoritmo

### Fase 1: Preprocessing

L'algoritmo inizia costruendo una tabella di spostamenti per la "bad character heuristic". Questa tabella indica, per ogni carattere dell'alfabeto, la posizione dell'ultima occorrenza di quel carattere nel pattern. Se si verifica un mismatch durante la ricerca, l'algoritmo utilizza questa tabella per determinare quanto spostare il pattern in avanti.

### Fase 2: Ricerca

Durante la ricerca, l'algoritmo allinea il pattern con il testo e confronta i caratteri da destra verso sinistra. Se c'è un mismatch, il pattern viene spostato utilizzando le informazioni della tabella di spostamenti. Questo permette di saltare più posizioni nel testo, riducendo il numero di confronti.

### Vantaggi

- **Efficienza**: L'algoritmo di Boyer-Moore può, in alcuni casi, saltare intere sezioni del testo, riducendo drasticamente il numero di confronti.
- **Versatilità**: Boyer-Moore è particolarmente efficace per pattern lunghi, soprattutto in testi grandi e quando si verificano mismatch frequenti.

## Codice dell'Algoritmo di Boyer-Moore

```c
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define SIGMA 256 // Dimensione dell'alfabeto ASCII


int max(int a, int b) { return (a > b) ? a : b; }

/**
 * Funzione di preprocessing: badCharHeuristic
 * Costruisce la tabella delle distanze di salto per i caratteri del pattern.
 */
void badCharHeuristic(char* str, int size, int badchar[SIGMA])
{
    int i;

    // Inizializza tutte le occorrenze dei caratteri a -1
    for (i = 0; i < SIGMA; i++)
        badchar[i] = -1;

    // Assegna l'indice dell'ultima occorrenza di ogni carattere nel pattern
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

/**
 * Funzione di ricerca: search
 * Esegue la ricerca del pattern `pat` nel testo `txt` utilizzando l'algoritmo di Boyer-Moore.
 */
void search(char* txt, char* pat)
{
    int m = strlen(pat);  // Lunghezza del pattern
    int n = strlen(txt);  // Lunghezza del testo

    int badchar[SIGMA];  // Tabella delle distanze di salto per la bad character heuristic

    // Costruisce la tabella delle distanze per il pattern
    badCharHeuristic(pat, m, badchar);

    int s = 0;  // s è lo spostamento del pattern rispetto al testo

    // Loop principale di ricerca
    while (s <= (n - m)) {
        int j = m - 1;

        // Confronta i caratteri del pattern e del testo da destra verso sinistra
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        // Se il pattern è stato trovato, stampa l'indice
        if (j < 0) 
        {
            printf("\nPattern trovato con shift = %d", s);

            // Sposta il pattern in base alla tabella di distanze
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else
            // In caso di mismatch, utilizza la tabella per determinare lo spostamento
            s += max(1, j - badchar[txt[s + j]]);
    }
}

int main()
{
    char txt[] = "ABAAABCD";
    char pat[] = "ABC";

    search(txt, pat);

    return 0;
}
```