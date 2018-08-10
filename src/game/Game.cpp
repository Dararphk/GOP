#include "Game.h"

#include <string>
#include <iostream>

using namespace std;

const int MIN_PLAYERS = 1;
const int MAX_PLAYERS = 4;

Game::Game() {
    playerInput(MIN_PLAYERS, MAX_PLAYERS);
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
        cout << "Insert name: ";
        cin >> tmpName;
        players[i] = new Player(tmpName);
    }
}
