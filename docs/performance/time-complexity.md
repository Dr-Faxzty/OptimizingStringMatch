# Complessità Temporale e Spaziale degli Algoritmi di String Matching

In questa sezione esaminiamo la complessità temporale e spaziale degli algoritmi di string matching inclusi nel progetto **OptimizingStringMatch**. La complessità temporale rappresenta il tempo richiesto da un algoritmo per risolvere un problema in funzione della dimensione dell'input, mentre la complessità spaziale riguarda la quantità di memoria necessaria per eseguire l'algoritmo.

## Algoritmo di Boyer-Moore

L'algoritmo di Boyer-Moore utilizza una strategia di matching che permette di ridurre significativamente il numero di confronti necessari.

- **Complessità Temporale:**
  - **Caso Peggiore:** `O(m * n)` dove `m` è la lunghezza del pattern e `n` è la lunghezza del testo.
  - **Caso Medio:** `O(n / m)`, grazie all'euristica di salto, l'algoritmo può evitare numerosi confronti.
  - **Caso Ottimale:** `O(n)` nel migliore dei casi, può saltare molte sezioni del testo.

- **Complessità Spaziale:** `O(m + SIGMA)` dove `SIGMA` rappresenta l'alfabeto (tipicamente 256 per i caratteri ASCII). Lo spazio aggiuntivo è utilizzato per memorizzare le tabelle di shift e bad character.

## Algoritmo di Horspool

L'algoritmo di Horspool è una semplificazione di Boyer-Moore, mantenendo buone performance con una struttura più semplice.

- **Complessità Temporale:**
  - **Caso Peggiore:** `O(m * n)` il caso peggiore è lo stesso di Boyer-Moore.
  - **Caso Medio:** `O(n)`, grazie all'euristica di salto che riduce i confronti.
  - **Caso Ottimale:** `O(n / m)`, saltando direttamente molti caratteri.

- **Complessità Spaziale:** `O(SIGMA)`, poiché è necessaria solo una tabella per il bad character rule, riducendo l'uso di memoria rispetto a Boyer-Moore.

## Algoritmo di Horspool con q-grammi

Questo algoritmo migliora Horspool utilizzando blocchi di caratteri (q-grammi) per aumentare la velocità di ricerca.

- **Complessità Temporale:**
  - **Caso Peggiore:** `O(m * n)`, simile agli altri algoritmi.
  - **Caso Medio:** `O(n)`, l'uso di q-grammi riduce ulteriormente il numero di confronti.
  - **Caso Ottimale:** `O(n / q)` dove `q` è la dimensione dei blocchi, permettendo salti ancora più grandi.

- **Complessità Spaziale:** `O(SIGMA^2)`, poiché vengono utilizzate tabelle più grandi per gestire i q-grammi, aumentando l'uso di memoria rispetto alla versione standard.

## Algoritmo di Horspool Ottimizzato (Tuned)

Questo algoritmo introduce un'ottimizzazione basata sulla frequenza dei caratteri nel testo, migliorando ulteriormente l'efficienza.

- **Complessità Temporale:**
  - **Caso Peggiore:** `O(m * n)`, lo scenario peggiore rimane lo stesso.
  - **Caso Medio:** `O(n)`, ottimizzato per gestire i caratteri più frequenti prima, migliorando le prestazioni.
  - **Caso Ottimale:** `O(n / m)`, sfruttando una selezione ottimale dei caratteri pivot per velocizzare il matching.

- **Complessità Spaziale:** `O(SIGMA + m)`, dato che oltre alla tabella per il bad character si tiene traccia delle frequenze dei caratteri e dell'ordine ottimizzato di confronto.

## Confronto dei Tempi di Esecuzione e Spazio Occupato

| Algoritmo                          | Complessità Temporale Peggiore | Complessità Temporale Media | Complessità Temporale Migliore | Complessità Spaziale |
|------------------------------------|-------------------------------|-----------------------------|-------------------------------|----------------------|
| Boyer-Moore                        | `O(m * n)`                    | `O(n / m)`                  | `O(n)`                        | `O(m + SIGMA)`       |
| Horspool                           | `O(m * n)`                    | `O(n)`                      | `O(n / m)`                    | `O(SIGMA)`           |
| Horspool con q-grammi              | `O(m * n)`                    | `O(n)`                      | `O(n / q)`                    | `O(SIGMA^2)`         |
| Horspool Ottimizzato (Tuned)       | `O(m * n)`                    | `O(n)`                      | `O(n / m)`                    | `O(SIGMA + m)`       |

## Conclusione

La complessità temporale e spaziale varia a seconda dell'algoritmo utilizzato. Sebbene tutti gli algoritmi abbiano lo stesso comportamento nel caso peggiore (`O(m * n)`), le ottimizzazioni come quelle introdotte da Horspool, q-grammi e dalla versione Tuned permettono di migliorare le prestazioni medie e ottimali. Tuttavia, queste ottimizzazioni hanno un costo in termini di memoria, poiché algoritmi più complessi richiedono strutture di dati più grandi per supportare le euristiche di salto e le ottimizzazioni dei caratteri pivot.
