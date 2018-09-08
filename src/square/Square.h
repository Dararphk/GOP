#include "../deck/Deck.h"

#include <string>

using namespace std;

class Square {
    string msg;
    int id;
    int pos;
    int val;
    void randomize(Square *board[], int l);
    bool checkLoop(Square *board[]);
public:
    Square(string msg, int pos);
    Square(int r_id, Square *board[], int pos, int l);
    bool activate(Player *p, Deck *d, Question *q);
    string getMsg();
};
