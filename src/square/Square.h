#include "../player/Player.h"

#include <string>

using namespace std;

class Square {
    string msg;
    int id;
    int val[5];
    void randomize(int r, int l);
public:
    Square(string s);
    Square(int r, int l);
    void activate(Player *p);
};
