# Linee Guida per le Contribuzioni
Grazie per il tuo interesse a contribuire a **OptimizingStringMatch**! Siamo entusiasti di avere il tuo aiuto. Per garantire che il processo di collaborazione sia chiaro e ordinato, ti chiediamo di seguire queste semplici linee guida.

## Come Contribuire

### 1. Fork della Repository
Se desideri contribuire, il primo passo è fare il fork della repository. Questo creerà una copia del progetto nella tua area personale di GitHub. Puoi clonare il tuo fork sul tuo ambiente locale con il seguente comando:

```bash
git clone https://github.com/Dr-Faxzty/OptimizingStringMatch.git
```

### 2. Crea una Branch
Lavora sempre su una branch separata. Puoi creare una nuova branch per la tua feature o correzione:

```bash
git checkout -b nome-della-branch
```

Scegli un nome descrittivo per la tua branch, ad esempio `fix-boyer-moore-bug` o `add-horspool-optimization`.

### 3. Fai Modifiche
Fai le tue modifiche nel tuo ambiente locale. Assicurati che il codice funzioni e che rispetti gli standard e lo stile del progetto.

### 4. Aggiungi Commenti e Documentazione
- `Documentazione`: Assicurati di aggiornare o creare file di documentazione per le nuove funzionalità o algoritmi.
- `Commenti`: Inserisci commenti chiari e descrittivi nel codice per facilitare la comprensione delle tue modifiche da parte degli altri collaboratori.

### 5. Testa il Codice
Testa sempre il codice prima di inviare la tua pull request. Se possibile, includi anche unit test per verificare che la funzionalità o la correzione funzioni come previsto.

### 6. Crea una Pull Request
Una volta che il tuo lavoro è completo e testato, effettua il commit e il push delle tue modifiche sul tuo fork:

```bash
git add .
git commit -m "Descrizione delle modifiche"
git push origin nome-della-branch
```

Ora puoi creare una **Pull Request** (PR) dalla tua branch verso il branch principale di questa repository.

**Suggerimenti per una Buona Pull Request**
- `Titolo Chiaro`: Scrivi un titolo descrittivo che riassuma il contenuto della PR.
- `Descrizione`: Spiega le modifiche apportate, la ragione per cui sono state fatte e qualsiasi dettaglio aggiuntivo necessario per capire il contesto.
- `Collega i Problemi`: Se la tua PR risolve un problema esistente, collega il numero del problema nella descrizione della PR.

## Stile di Codice
Per mantenere un codice coerente e leggibile, ti chiediamo di seguire questi standard di stile:

- Utilizza indentazioni coerenti (spazi o tab, secondo quanto già utilizzato nel progetto).
- Segui i convenzionali nomi delle variabili e delle funzioni.
- Mantieni funzioni e blocchi di codice modulari e ben organizzati.
- Commenta il codice dove necessario, specialmente in sezioni complesse.

## Comunicazione
Se hai dubbi o domande durante il processo di contributo, sentiti libero di aprire una **Issue** nella repository o di partecipare alle discussioni esistenti. La collaborazione è fondamentale per migliorare il progetto!

## Segnalazione di Problemi
Se noti bug, problemi di performance o qualsiasi comportamento strano nell'algoritmo, ti invitiamo a creare una **Issue**. Cerca di fornire quanti più dettagli possibili, tra cui:

- Descrizione del problema
- Passi per riprodurre il bug
- Comportamento atteso e comportamento riscontrato
- Ambiente (sistema operativo, versione di compilatore, etc.)

## Grazie!
Grazie ancora per il tuo contributo! Il tuo aiuto è essenziale per migliorare e ottimizzare gli algoritmi di string matching. Apprezziamo il tuo tempo e il tuo impegno.