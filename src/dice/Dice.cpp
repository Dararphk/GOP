#include <ctime>
#include <cstdlib>

#include "Dice.h"

using namespace std;

Dice::Dice() {
    srand(time(0));
}

Dice::throwDice() {
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    if (die1 == die2)
        double = true;
    else
        double = false;
    return die1 + die2;
}

Dice::isDouble() {
    return double;
}
