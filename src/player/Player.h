#include <string>

using namespace std;

class Player {
    string name;
    int position;
public:
    Player(string name);
    string getName();
    int getPosition();
    void move(int position);
    int throwDice();
};
