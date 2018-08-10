#include <ctime>
#include <cstdlib>

#include "Dice.h"

using namespace std;

Dice::Dice() {
    srand(time(0));
}

int Dice::throwDice() {
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    return die1 + die2;
}

bool Dice::isDouble() {
    return die1 == die2;
}
