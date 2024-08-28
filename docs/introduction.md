# Introduzione alla Documentazione

Benvenuti nella documentazione del progetto **OptimizingStringMatch**. Questa repository esplora diversi algoritmi per il **string matching**, un problema centrale nell'informatica e nel processamento di testi.

## Cos'è lo String Matching?

Lo **string matching** (o ricerca di stringhe) consiste nell'individuare la posizione di un pattern (una sequenza di caratteri) all'interno di un testo più lungo. Questo problema è alla base di molte applicazioni, dalla ricerca su testi alla compressione dei dati e al bioinformatica.

Nel corso degli anni, sono stati sviluppati vari algoritmi per risolvere questo problema, ciascuno con vantaggi e svantaggi in termini di efficienza, semplicità di implementazione e adattabilità a diversi tipi di dati. In questa repository, abbiamo analizzato e ottimizzato diversi algoritmi, tra cui **Boyer-Moore**, **Horspool** e varianti con **q-grammi** e altre tecniche di ottimizzazione.

## Obiettivo del Progetto

Il nostro obiettivo principale è studiare e implementare una versione ottimizzata degli algoritmi di string matching esistenti per migliorare le prestazioni in contesti pratici.

La documentazione è suddivisa in varie sezioni per aiutare a comprendere meglio i vari algoritmi, le ottimizzazioni applicate e i risultati dei benchmark. 

## Contenuto della Documentazione

La documentazione è organizzata in più sezioni, ognuna delle quali affronta aspetti diversi degli algoritmi e delle ottimizzazioni sviluppate. Ecco una panoramica delle cartelle e dei file principali:

### `algorithms/`
Questa sottocartella contiene spiegazioni dettagliate sugli algoritmi di string matching inclusi nel progetto. Ogni file si focalizza su un particolare algoritmo, descrivendone il funzionamento e la logica dietro di esso:

- **`boyer-moore.md`**: Descrizione approfondita dell'algoritmo di Boyer-Moore, uno degli algoritmi classici e più efficienti per la ricerca di stringhe.
- **`horspool.md`**: Spiegazione dell'algoritmo di Horspool, una versione semplificata e ottimizzata di Boyer-Moore.
- **`horspool-qgram.md`**: Approfondimento sull'uso dei q-grammi nell'algoritmo di Horspool per incrementare l'efficienza nei salti.
- **`tun-optimized.md`**: Descrizione della versione ottimizzata sviluppata nel progetto, che applica diverse tecniche per migliorare la velocità e l'efficienza complessiva.

### `performance/`
In questa sezione analizziamo le prestazioni degli algoritmi attraverso benchmark e un'analisi dettagliata della loro complessità computazionale:

- **`benchmarks.md`**: Risultati dei benchmark effettuati su vari dataset, con confronti tra i diversi algoritmi implementati.
- **`time-complexity.md`**: Analisi della complessità temporale e spaziale degli algoritmi, con spiegazioni teoriche e esempi pratici.
- **`optimizations.md`**: Descrizione delle tecniche di ottimizzazione applicate agli algoritmi, con particolare attenzione alla selezione dei caratteri pivot e ai salti avanzati.

### `research/`
Questa cartella raccoglie il materiale teorico e gli articoli di ricerca che supportano il progetto:

- **`theoretical-background.md`**: Riassunto teorico del problema dello string matching e delle tecniche di risoluzione adottate.
- **`research-papers.md`**: Un elenco di articoli di ricerca e libri che hanno ispirato e guidato il nostro lavoro.

### `future-work.md`
In questo file esploriamo le possibili direzioni future per il progetto, incluse nuove ottimizzazioni e possibili estensioni.

### `references.md`
Un elenco di risorse utili e riferimenti bibliografici consultati durante lo sviluppo del progetto.

### `contribution-guidelines.md`
In questa sezione trovi le linee guida per chiunque voglia contribuire al progetto, con istruzioni su come proporre nuove ottimizzazioni o segnalare problemi.

---

Questa documentazione è pensata per essere una guida completa al nostro progetto. Ti invitiamo a esplorare le varie sezioni e ad approfondire gli algoritmi e le ottimizzazioni che abbiamo sviluppato. Siamo sempre aperti a contributi, suggerimenti e miglioramenti.

Buona lettura e buon lavoro!
