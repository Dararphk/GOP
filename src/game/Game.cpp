#include "Game.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <limits>

#define clear() printf("\033[H\033[J")

using namespace std;

const int MIN_PLAYERS = 1;
const int MAX_PLAYERS = 4;
const int MIN_SQUARES = 40;
const int MAX_SQUARES = 100;
const int MIN_CARDS = 40;
const int MAX_CARDS = 100;

Game::Game() {
    srand(time(0));

    playerInput(MIN_PLAYERS, MAX_PLAYERS, initBoard(MIN_SQUARES, MAX_SQUARES));

    initDeck(MIN_CARDS, MAX_CARDS);

    //(!!!) eliminare controllo esterno ciclo
    bool gameFinished = false;
    int i = -1;
    int turni = 0;
    while (!gameFinished) {
        clear();
        turni++;
        //(!!!) correggere con versione migliore
        cout << "Turno numero: " + to_string(turni) << endl;
        i++;
        if (i >= n)
            i = 0;
        gameLoop(players[i]);
        gameFinished = players[i]->getPosition() == l - 1;
        if (!gameFinished) {
            cout << "Turno terminato. Premere Invio per continuare . . .";
            cin.get();
        }
    }
    cout << players[i]->getName() << " ha vinto. Congratulazioni!\n";
}

void Game::gameLoop(Player *p) {
    bool sameTurn;
    this->print(board, l);
    //players[i] throws dice and advances, while finding out effect of the card
    p->throwDice();
    //(!!!) BUG REPORT: infinite loop possibile if squares random values are not controlled.
    do {
        sameTurn = board[p->getPosition()]->activate(p, deck);
    } while (sameTurn);
}

void Game::playerInput(const int minp, const int maxp, int l) {

    do {
        cout << "How many players? [" << minp << "-" << maxp << "]" << endl;
        cin >> n;
    } while (n < minp && n > maxp);

    string tmpName;
    for (int i = 0; i < n; i++) {
        cout << "Player " << i << " name: ";
        cin >> tmpName;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        players[i] = new Player(tmpName, l);
    }

}

int Game::initBoard(const int mins, const int maxs) {
    l = ((rand() % (maxs - mins + 1)) / 3) * 3 + mins - 1;

    board[0] = new Square("Start", 0);
    for (int i = 1; i < l - 1; i++) {
        board[i] = new Square(rand(), i, l);
    }
    board[l - 1] = new Square("Finish", l - 1);
    return l;
}

void Game::initDeck(const int minc, const int maxc) {
    int tmp = (rand() % (maxc - minc + 1)) + minc;

    deck = new Deck();

    for (int i = 0; i < tmp; i++) {
        deck->addCard(rand());
    }
}

//(!!!) metodo farlocco, cancellare
void Game::print(Square *board[100], int l) {
    //(!!!) controllare che tutte le caselle vengano stampate, correggere calcolo
    for (int i = 0; i < l / 3; i++)
        cout << board[i]->print() << board[i+(l/3)]->print() << board[i+(l/3)*2]->print() << endl;
}
