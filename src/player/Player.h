#include <string>

using namespace std;

class Player {
    string name;
    int position;
    int score;
public:
    Player(string name);
    int getPosition();
    void move(int position);
};
