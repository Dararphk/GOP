#include "../square/Square.h"

#include <string>

using namespace std;

class Game {
    int n; //n° of players
    int l; //length of the board
    Player *players[10];
    Square *board[100];
    void gameLoop();
    void playerInput(const int minp, const int maxp, int l);
    int initBoard(const int mins, const int maxs);
public:
    Game();
    void print(Square *board[100], int l);
};
