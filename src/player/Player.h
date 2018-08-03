#include <String>

class Player {
    String name;
    int position;
    int score;
public:
    Player(String name);
    int getScore();
    int getPosition();
    void move(int position);
}
