#include <string>

using namespace std;

class Player {
    string name;
    char symbol;
    int position;
    int bounds;
    bool bonuses[3];
    int applyStats();
public:
    Player(string name, char symbol, int l);
    string getName();
    int getPosition();
    void setPosition(int position);
    char getSymbol();
    int move(int i);
    int throwDice();
    void activateBonus(int b);
    void clearStats();
    int getBounds();
};
