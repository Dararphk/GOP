#include "../card/Card.h"

#include <string>

using namespace std;

struct cardNode {
    Card *card;
    cardNode *next;
};

class Deck {
    cardNode *index;
    cardNode *last;
public:
    Deck();
    void addCard(int r_id);
    Card drawCard();
};
