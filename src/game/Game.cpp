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
const int MAX_CARDS = 50;
const int MAX_SQUARE_LENGTH = 40;

Game::Game() {
    srand(time(0));
    playerInput(MIN_PLAYERS, MAX_PLAYERS, initBoard(MIN_SQUARES, MAX_SQUARES));
    setPrint();
    initDeck(MIN_CARDS, MAX_CARDS);

    bool gameFinished = false;
    int i = -1;
    int turni = 0;

    while (!gameFinished) {
        clear();
        turni++;
        cout << "Turno numero: " + to_string(turni) << endl << endl;
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
    clear();
    print(board, l);
    cout << players[i]->getName() << " ha vinto in "<< turni <<" turni. Congratulazioni!\n";
}

void Game::gameLoop(Player *p) {
    bool sameTurn;
    this->print(board, l);
    p->throwDice();
    do {
        sameTurn = board[p->getPosition()]->activate(p, deck);
    } while (sameTurn);
}

void Game::playerInput(const int minp, const int maxp, int l) {

    do {
        cout << "Quanti giocatori? [" << minp << "-" << maxp << "]" << endl;
        cin >> n;
    } while (n < minp && n > maxp);

    string tmpName;
    char tmpSym;
    for (int i = 0; i < n; i++) {
        cout << "Nome del giocatore " << i + 1 << ": ";
        cin >> tmpName;
        cout << "Scegli un segnalino (un char a scelta): ";
        cin >> tmpSym;
        players[i] = new Player(tmpName, tmpSym, l);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

}

int Game::initBoard(const int mins, const int maxs) {
    this->l = (rand() % (maxs - mins + 1)) + mins - 1;

    board[0] = new Square("Start", 0);
    for (int i = 1; i < l - 1; i++) {
        board[i] = new Square(rand(), board, i, l);
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

void Game::print(Square *board[], int l) {
    string tmp;
    int index, max;
    int rows = l / c;
    if (l % c > 0)
        rows++;
    for (int i = 0; i < rows; i++) {
        for (int j  = 0; j < c; j++) {
            index = i + rows * j;
            if (index < l) {
                if (index < 10)
                    cout << " ";
                cout << index << Color::getColor(2) << "|" << Color::resetColor();
                printPlayers(index);
                cout << Color::getColor(2) << "|" << Color::resetColor();
                tmp = board[i + rows * j]->getMsg();
                max = MAX_SQUARE_LENGTH - tmp.length();
                for (int k = 0; k < max; k++)
                    tmp += " ";
                cout << tmp;
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Game::setPrint() {
    clear();
    cout << "REGOLAZIONE LARGHEZZA SCHERMO\n\n";
    for (int i = 1; i < 9; i++) {
        cout << "0" << i << " ";
        for (int j = 0; j < n; j++)
            cout << "x";
        cout << " ";
        for (int j = 0; j < MAX_SQUARE_LENGTH - 2 - (Color::getColor(0).length() + Color::resetColor().length()); j++)
            cout << "-";
        cout << ">|";
    }
    cout << "\n\nInserisci il numero di colonne intere presenti nella prima riga: ";
    cin >> c;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clear();
}

void Game::printPlayers(int index) {
    for (int i = 0; i < n; i++) {
        if (players[i]->getPosition() == index) {
            cout << players[i]->getSymbol();
        } else {
            cout << " ";
        }
    }
}
