# GOP (Gioco dell'Oca Pazza)

Versione per terminale del gioco dell'oca, leggermente rivisitato, implementato con C++.

* GitHub: https://github.com/Dararphk/GOP

## Tema

Carte e domande seguono il noto gioco di ruolo Dark Souls.

## Features
* **1-4 giocatori**
* **Carte**
    * Bonus/Malus ai tiri di dado
    * Torna allo start
    * Vai a metà tabellone
* **Tipologia Caselle**
	* Casella vuota
    * Tira un'altra volta
    * Vai avanti/indietro di X
    * Vai alla casella X
    * Pesca una carta
    * Indovina...

## Librerie

Per la realizzazione di questo gioco non sono state usate librerie grafiche.
I colori sono stati implementati tramite la codifica **[ANSI](https://en.wikipedia.org/wiki/ANSI_escape_code)** e poi richiamati tramite metodi statici per evitare di instanziare oggetti superflui.

## Esecuzione

* Il **makefile** è già presente nella repo.
* Si può creare l'**eseguibile**, eseguendo da terminale il comando `make` nella directory corrente.
* Infine il gioco potrà essere **eseguito** con il comando `GOP` su **Windows**, mentre in ambiente **Unix** si dovrà usare il comando `./GOP`

##### Unix
```bash
git clone https://github.com/Dararphk/GOP
cd GOP
make
./GOP
```

## Come Giocare

Avviato l'eseguibile viene richiesto il numero di giocatori, compreso tra 1 e 4 inclusi. Successivamente bisogna specificare il nome e il carattere che si intende usare come pedina per ogni giocatore.
Segue una schermata di regolazione manuale della larghezza dello schermo (si va a scegliere il numero di colonne con cui il tabellone verrà formattato)
Ad ogni turno viene stampato il tabellone con ogni casella formata da

* **Numero** (Crescente da start a finish).
* Eventuale **pedina** (Se un giocatore è nella sudddetta casella).
* **Descrizione** della casella (il **colore** varia in base al tipo).

Le uniche interazioni necessarie per avanzare nel gioco sono rispondere alle domande e premere invio alla fine di ogni turno.
Sotto al tabellone viene stampata la cronologia degli spostamenti del giocatore.

## Membri che hanno contribuito al progetto GOP

* **Raffaello Balica**
* **Lorenzo Niccolai**
