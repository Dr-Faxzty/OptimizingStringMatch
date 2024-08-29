# Algoritmo di Horspool

L'algoritmo di Horspool è una variante dell'algoritmo di Boyer-Moore progettata per migliorare l'efficienza nella ricerca di pattern in stringhe. Questa versione si concentra sulla **euristica del cattivo carattere** per effettuare salti durante la ricerca, rendendolo più efficiente rispetto a un approccio di forza bruta.

## Codice dell'Agoritmo

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIGMA 256 // Dimensione dell'alfabeto (256 caratteri ASCII)

/**
 * Funzione di preprocessing: Pre_Horspool
 * Costruisce la tabella delle distanze di salto per l'euristica del cattivo carattere.
 */
void Pre_Horspool(unsigned char *P, int m, int hbc[]) 
{
   int i;
   // Inizializza la tabella di salto: assume un salto pari alla lunghezza del pattern per tutti i caratteri.
   for(i = 0; i < SIGMA; i++) 
       hbc[i] = m;
   
   // Aggiorna i valori della tabella per i caratteri nel pattern.
   // Il salto per un carattere è pari alla distanza tra la sua ultima apparizione e la fine del pattern.
   for(i = 0; i < m - 1; i++) 
       hbc[P[i]] = m - i - 1;
}

/**
 * Funzione di ricerca: search
 * Cerca il pattern `P` nel testo `T` usando l'algoritmo di Horspool.
 */
int search(unsigned char *P, unsigned char *T) 
{
    int i, shift = 0, count = 0, hbc[SIGMA]; // Variabili locali e array per bad character shift

    int n = strlen(T);  // Lunghezza del testo
    int m = strlen(P);  // Lunghezza del pattern

    // Preprocessa il pattern per creare la tabella di salto
    Pre_Horspool(P, m, hbc);
    
    // Avvia la ricerca. Continua finché ci sono possibili allineamenti del pattern con il testo.
    while(shift <= n - m) 
    {
        i = 0;

        // Confronta il pattern `P` con la sezione corrente del testo `T`.
        // Avanza finché i caratteri corrispondono.
        while(i < m && P[i] == T[shift + i]) 
            i++;
        
        // Se tutti i caratteri corrispondono (i == m), il pattern è stato trovato
        if(i == m) 
            count++;  // Incrementa il conteggio delle occorrenze
        
        // Usa l'euristica del cattivo carattere per determinare quanto saltare
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
```



