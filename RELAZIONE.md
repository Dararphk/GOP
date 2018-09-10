# GOP (Gioco dell'Oca Pazza)

## Introduzione

Versione digitale del gioco dell'oca, con alcune rivisitazioni.

* GitHub: https://github.com/Dararphk/GOP

### Grafica

Per la gestione grafica abbiamo manipolato i colori del testo del terminale, facendo riferimento a: https://gist.github.com/vratiu/9780109.

### Tema

Carte e domande seguono il noto gioco di ruolo Dark Souls.

### Caratteristiche

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

## Scelte implementative

### Libreria String

Per lo sviluppo di questo progetto abbiamo usato la libreria **string**, che fornisce funzioni utili per la gestione delle stringhe (es `string.lenght();` e l'operatore `+`, ovvero la concatenazione).

### Domande a tema

Le domande, danno 4 possibili opzioni come risposta, se il giocatore indovina avanza di 2 caselle, in caso contrario rimane sulla casella della domanda.
Sono organizzate in un array di strutture (struct) "questions", tramite un intero randomico verrà estratta la domanda a cui il giocatore dovrà rispondere.
Per creare l'array abbiamo usato un template preimpostato da noi (presente nella cartella "question") in modo che aggiungere domande, o addirittura cambiarle, sia un'operazione veloce.

(!!! VIM)

### Programmazione ad oggetti

Di seguito una breve descrizione di tutti i vari oggetti sviluppati per il progetto:

##### Color - **Colori**
* Una classe statica che modifica i colori del testo, `getColor(int id)` per settare i colori e `resetColor()` per tornare al colore di default del terminale.

##### Player - **Giocatore**
* Contiene i parametri "nome" (stringa), "posizione" (int), "pedina" (char) e un array di booleani per tenere conto dei bonus e dei malus (bool[]).
* E' sempre possibile sapere la posizione del giocatore e modificarla tramite `setPosition()`.
* Ogni partecipante è contraddistinto da una pedina (char);

##### Question - **Domanda**
* Contiene i parametri "domanda" (stringa), "risposte" (string[]) e "risposta corretta" (int), ovvero l'indice nel vettore di risposte.
* Il costruttore randomizza la domanda dall'array di strutture sopracitato.
* Tramite il metodo `answer(Player *p)` si prenderà in input la risposta del giocatore e di conseguenza si gestirà l'esito.

##### Card - **Carta**
* Contiene i parametri "id" (int), "nome" (string) e "descrizione" (string).
* Ci sono due costruttori, uno che randomizza la carta da un intero in input e in base a questo vengono decisi nome e descrizione. L'altro prende in input la stringa "last" e crea l'ultima carta del `Deck` ovvero quella che metterà fine alla partita in caso si prolunghi troppo.
* Tramite il metodo `activate(Player *p)` l'effetto della carta avrà effetto sul giocatore che l'ha pescata.

##### Deck - **Mazzo**
* La struttura principale della classe mazzo è una pila, dato che inizializza una prima carta (nodo) e poi vi aggiunge altre carte con `addCard(int r_id)`, quindi l'ultima carta aggiunta sarà la prima pescata dal metodo `drawCard()`.
* Il costruttore inizializza solo il primo nodo, ovvero quello che contiene la carta che mette fine alla partita.

##### Square - **Casella**
* Contiene i parametri "id", "pos" (int) e "msg" (string).
* Il metodo costruttore decide il tipo di casella e invoca `randomize()` per generare i valori casuali.
* Il metodo `checkLoop()` evita la creazione di caselle con valori che permetterebbero cicli infiniti.


##### Game - **Gioco**
* Contiene i parametri "n_colonne", "n_giocatori", "lunghezza_board" (int), due array di puntatori (rispettivamente per i giocatori e per il tabellone) e un puntatore al mazzo di carte.
* E' possibile modificare a piacere il valore delle costanti dichiarate a inizio classe per alterare l'inizializzazione del gioco.
* Il costruttore richiama tutte le funzioni utili all'inizializzazione delle principali strutture dati del gioco.
* Il metodo gameLoop continua il turno del giocatore fino a quando si concatenano gli effetti su di esso.
* Il metodo `setPrint()` permette di visualizzare in anteprima quante colonne ci stanno nello schermo.

## Membri che hanno contribuito al progetto GOP

* **Raffaello Balica**
* **Lorenzo Niccolai**
