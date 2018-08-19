#include <string>

using namespace std;

class Player {
    string name;
    int position;
    int bounds;
public:
    Player(string name, int l);
    string getName();
    int getPosition();
    void setPosition(int position);
    int move(int i);
    int throwDice();
};
