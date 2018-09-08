#include "../player/Player.h"

#include <string>

using namespace std;

class Question{
    int n;
    string q; //domanda
    string answers[4]; //possibilità
    int correctAnswer; //indice soluzione
public:
    Question(int r_id);
    bool answer(Player *p);
};
