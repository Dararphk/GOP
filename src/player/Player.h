#include <string>

using namespace std;

class Player {
    string name;
    int position;
    int bounds;
    int *bonuses[3];
    bool malus;
public:
    Player(string name, int l);
    string getName();
    int getPosition();
    void setPosition(int position);
    void move(int i);
    void throwDice();
    int getBounds();
    void activateBonus(int w);
    void activateMalus();
    void cleanChanges();
};
