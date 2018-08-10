#include "../player/Player.h"

#include <string>

using namespace std;

class Game {
    int n; //n° of players
    Player *players[10];
    void gameLoop();
    void playerInput(const int minp, const int maxp);
public:
    Game();
};
