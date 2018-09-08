#include "../square/Square.h"

#include <string>

using namespace std;

class Game {
    int c; //n° of columns
    int n; //n° of players
    int l; //length of the board
    Player *players[10];
    Square *board[100];
    Deck *deck;
    void gameLoop(Player *p);
    void playerInput(const int minp, const int maxp, int l);
    int initBoard(const int mins, const int maxs);
    void initDeck(const int minc, const int maxc);
    void print(Square *board[], int l);
    void printPlayers(int index);
    void setPrint();
public:
    Game();
};
