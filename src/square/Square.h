#include "../player/Player.h"

#include <string>

using namespace std;

class Square {
    string msg;
    int id;
    int pos;
    int val;
    void randomize(int l);
public:
    Square(string msg, int pos);
    Square(int r_id, int pos, int l);
    bool activate(Player *p);
    string print();
};
