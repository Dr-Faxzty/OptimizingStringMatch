# OptimizingStringMatch

## Introduzione

**String Matching** (o ricerca di stringhe) è un problema centrale in informatica e ha innumerevoli applicazioni: dalla ricerca testuale nei motori di ricerca, alla bioinformatica, fino alla compressione dati. In termini semplici, lo String Matching consiste nel trovare tutte le occorrenze di una "stringa" o "pattern" (ad esempio una parola) all'interno di un testo più grande.

Il problema può essere risolto utilizzando vari algoritmi, alcuni dei quali offrono una maggiore efficienza in specifiche situazioni. Algoritmi come **Boyer-Moore**, **Horspool**, e loro varianti, rappresentano soluzioni classiche che ottimizzano i tempi di ricerca sfruttando salti e altre euristiche.

Questa repository documenta il nostro percorso di miglioramento degli algoritmi di String Matching, con particolare attenzione all'ottimizzazione delle loro prestazioni. Lo scopo di questo progetto è esplorare e implementare tecniche avanzate per migliorare l'efficienza degli algoritmi esistenti, nonché sperimentare nuove idee e varianti.

## Algoritmi Esplorati

1. **Boyer-Moore Algorithm**
    - Un algoritmo classico che combina il confronto all'indietro del pattern con due potenti euristiche per saltare porzioni del testo.
    
2. **Horspool Algorithm**
    - Una versione semplificata del Boyer-Moore che sfrutta solo la regola del cattivo carattere per determinare i salti.

3. **Horspool con Q-Grammi**
    - Un miglioramento che sfrutta gruppi di caratteri consecutivi (q-grammi) per aumentare l'efficienza del matching.

4. **Tuning e Ottimizzazione**
    - Tecniche per migliorare ulteriormente l'efficienza degli algoritmi, come la selezione di caratteri pivot basata su frequenze, ottimizzazione dei salti, parallelizzazione, e utilizzo di strutture dati avanzate.

## Obiettivi del Progetto

- **Documentare** le varianti principali degli algoritmi di String Matching.
- **Ottimizzare** e **sperimentare** tecniche avanzate per migliorare le prestazioni dell'**Algoritmo di Horspool**.
- **Confrontare** l'efficienza degli algoritmi in diverse situazioni, sia teoriche che pratiche.
- **Condividere** i risultati e creare una base di conoscenza per futuri sviluppatori e ricercatori interessati al campo.

## Struttura della Repository

- `src/`: Contiene il codice sorgente degli algoritmi implementati.
- `tests/`: Include test su vari dataset di esempio per misurare e confrontare le prestazioni degli algoritmi.
- `docs/`: Documentazione dettagliata del percorso seguito, inclusi articoli, spiegazioni tecniche, e riflessioni sui risultati ottenuti.

## Come Contribuire

Se sei interessato a contribuire a questo progetto, sentiti libero di creare un fork della repository e inviare una pull request con miglioramenti o nuove idee! Tutte le contribuzioni sono benvenute.

## Contatti

Se hai domande o suggerimenti, puoi aprire un'issue su GitHub.

---

*Grazie per aver visitato la repository!* 😊
