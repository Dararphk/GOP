#include "../card/Card.h"

#include <string>

using namespace std;

class Deck {
    int n; //number of cards
    Card *cards[100];
    void initDeck();
public:
    Deck();
    int getNumber();
};
