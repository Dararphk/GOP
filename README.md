# GOP (Gioco dell'Oca Pazza)

Versione console del gioco dell'oca, leggermente rivisto, implementata con C++.

* Trello: https://trello.com/b/qjETa9oT/progetto-gop
* GitHub: https://github.com/Dararphk/GOP

## Tema

Il noto gioco di ruolo per PlayStation e PC: Dark Souls, saga che conta 3 capitoli e molto famosa in tutto il mondo.

## Features
* <b>1-4 giocatori</b>
* <b>Carte</b> 
    * Bonus o Malus ai tiri di dado
    * Spostamenti fissati per rendere la partita più avvincente
* <b>Tipologia Caselle</b>
    * Pesca una carta
    * Vai avanti di n caselle
    * Torna indietro di n caselle
    * Vai alla casella X
    * Tira di nuovo il dado
	* Casella vuota

## Librerie 

Per la realizzazione di questo gioco non è stata usata alcuna libreria particolare. <br>
I colori sono stati implementati tramite la codifica <b>[ANSI](https://en.wikipedia.org/wiki/ANSI_escape_code)</b> e poi richiamati tramite metodi
statici per evitare di instanziare oggetti superflui.

## Esecuzione

* Il <b>makefile</b> è già presente nella repo.
* Si può creare l'<b>eseguibile</b>, eseguendo da terminale il comando `make` nella directory corrente.
* Infine il gioco potrà essere <b>eseguito</b> con il comando `GOP` su <b>Windows</b>, mentre in ambiente <b>Unix</b> si dovrà usare il comando `./GOP`

##### Windows
```bash
make
GOP
```

##### Unix
```bash
make
./GOP
```

## Come Giocare

Avviato l'eseguibile si inserirà il numero di giocatori, compreso tra 1 e 4 inclusi. Successivamente bisogna
specificare il nome e il carattere che si intende usare come pedina per ogni giocatore.
Ad ogni turno viene stampato il tabellone con ogni casella formata da

	* <b>Numero</b> (Crescente da start a finish).
	* Eventuale <b>pedina</b> (Se un giocatore è nella sudddetta casella).
	* Descrizione dell'<b>effetto</b> della casella.
	* Il <b>colore</b> della descrizione varia in base al tipo di casella

Per avanzare nel gioco è sufficiente premere invio alla fine di ogni turno, ogni volta il gioco stampa a video il punteggio ottenuto con i dadi e l'effetto
della casella su cui il giocatore si è fermato.

## Membri che hanno contribuito al progetto GOP

* <b>Raffaello Balica</b>
* <b>Lorenzo Niccolai</b>
