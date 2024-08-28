# Algoritmo di Boyer-Moore

L'algoritmo di **Boyer-Moore** è uno degli algoritmi più efficienti per il problema dello string matching. Fu sviluppato da Robert S. Boyer e J Strother Moore nel 1977. Questo algoritmo sfrutta il contenuto del pattern per "saltare" porzioni del testo, migliorando notevolmente la velocità rispetto a soluzioni più ingenue come l'algoritmo di ricerca a forza bruta.

## Descrizione dell'Algoritmo

Il Boyer-Moore utilizza due principali euristiche per ridurre il numero di confronti durante la ricerca di un pattern nel testo:

- **Euristica del Cattivo Carattere (Bad Character Heuristic)**: Se c'è un mismatch tra il pattern e il testo, si cerca la posizione del carattere "cattivo" (quello che ha causato il mismatch) all'interno del pattern stesso. In base a questa posizione, il pattern viene spostato in avanti.
  
- **Euristica del Buon Suffisso (Good Suffix Heuristic)**: Se c'è un suffisso del pattern che è stato trovato corrispondente al testo, l'algoritmo tenta di riallineare un altro suffisso del pattern al testo, piuttosto che ricominciare da capo.

Nel codice fornito, viene implementata l'euristica del cattivo carattere. L'euristica del buon suffisso non è presente in questa versione base, ma è una delle estensioni tipiche che rende l'algoritmo ancora più efficiente.

## Codice dell'Algoritmo

```c
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define SIGMA 256

int max(int a, int b) { return (a > b) ? a : b; }

void badCharHeuristic(char* str, int size, int badchar[SIGMA])
{
    int i;

    // Inizializza il bad character array
    for (i = 0; i < SIGMA; i++)
        badchar[i] = -1;

    // Riempie il bad character array con l'ultimo indice di ogni carattere nel pattern
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void search(char* txt, char* pat)
{
    int m = strlen(pat);  // Lunghezza del pattern
    int n = strlen(txt);  // Lunghezza del testo

    int badchar[SIGMA];

    // Preprocessing del pattern per l'euristica del cattivo carattere
    badCharHeuristic(pat, m, badchar);

    int s = 0;  // s rappresenta lo shift del pattern rispetto al testo

    // Ciclo per cercare tutte le occorrenze del pattern
    while (s <= (n - m)) {
        int j = m - 1;

        // Confronta il pattern con il testo da destra a sinistra
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        // Se il pattern è completamente trovato
        if (j < 0) 
        {
            printf("\n pattern occurs at shift = %d", s);

            // Shift del pattern in base alla prossima possibile occorrenza
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else
            // Shift del pattern in base alla euristica del cattivo carattere
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


## Descrizione Dettagliata del Codice

Il codice fornito implementa una versione semplificata dell'algoritmo di **Boyer-Moore**, sfruttando principalmente l'**euristica del cattivo carattere**. Questa implementazione si concentra sull'efficienza e sulla capacità di saltare porzioni del testo durante la ricerca di un pattern.



dubidubidubadubidubidubadu