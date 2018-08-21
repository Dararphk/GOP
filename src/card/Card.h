#include "../question/Question.h"

#include <string>

using namespace std;

class Card {
    int id;
    string name;
    string desc;
    void randomize();
public:
    Card(string s);
    Card(int r_id);
    bool activate(Player *p);
};
