#include "Game.h"

#include <ctime>
#include <iostream>

using namespace std;

const int MIN_PLAYERS = 1;
const int MAX_PLAYERS = 4;
const int MIN_SQUARES = 40;
const int MAX_SQUARES = 100;

Game::Game() {
    srand(time(0));

    playerInput(MIN_PLAYERS, MAX_PLAYERS, initBoard(MIN_SQUARES, MAX_SQUARES));

    bool gameFinished = false;
    int i = 0;
    int turni = 0;
    while (!gameFinished) {
        turni++;
        //(!!!) correggere con versione migliore
        cout << "Turno numero: " + to_string(turni) << endl;
        if (i >= n)
            i = 0;
        gameFinished = this->gameLoop(players[i]);
        i++;
    }
    i--;
    cout << "Il giocatore " << players[i]->getName() << " ha vinto. Congratulazioni!\n";
}

bool Game::gameLoop(Player *p) {
    //number of turn ++
    this->print(board, l);
    //players[i] throws dice and advances, while finding out effect of the card
    return board[p->throwDice()]->activate(p);
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
        players[i] = new Player(tmpName, l);
    }

}

int Game::initBoard(const int mins, const int maxs) {
    l = (rand() % (maxs - mins + 1)) + mins;

    board[0] = new Square("Start", 0);
    for (int i = 1; i < l - 1; i++) {
        board[i] = new Square(rand(), i, l);
    }
    board[l - 1] = new Square("Finish", l - 1);
    return l;
}

//(!!!) metodo farlocco, cancellare
void Game::print(Square *board[100], int l) {
    //(!!!) controllare che tutte le caselle vengano stampate, correggere calcolo
    for (int i = 0; i < l / 3; i++)
        cout << board[i]->print() << board[i+(l/3)]->print() << board[i+(l/3)*2]->print() << endl;
}
