#include "Game.h"

#include <ctime>
#include <string>
#include <iostream>

using namespace std;

const int MIN_PLAYERS = 1;
const int MAX_PLAYERS = 4;
const int MIN_SQUARES = 40;
const int MAX_SQUARES = 100;

Game::Game() {
    srand(time(0));
    playerInput(MIN_PLAYERS, MAX_PLAYERS);
    initBoard(MIN_SQUARES, MAX_SQUARES);
    gameLoop();
}

void Game::gameLoop() {
    return;
}

void Game::playerInput(const int minp, const int maxp) {

    do {
        cout << "How many players? [" << minp << "-" << maxp << "]" << endl;
        cin >> n;
    } while (n < minp && n > maxp);

    string tmpName;
    for (int i = 0; i < n; i++) {
        cout << "Player " << i << " name: ";
        cin >> tmpName;
        players[i] = new Player(tmpName);
    }

}

void Game::initBoard(const int mins, const int maxs) {
    l = (rand() % (maxs - mins + 1)) + maxs;

    board[0] = new Square("Start");
    for (int i = 1; i < l - 1; i++) {
        board[i] = new Square(rand(), l);
    }
    board[l - 1] = new Square("Finish");
}
