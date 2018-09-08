#include "Deck.h"

#include <iostream>

using namespace std;


Deck::Deck() {
    cardNode *win = new cardNode;
    win->card = new Card("last");
    win->next = win;
    index = win;
    last = win;
}

void Deck::addCard(int r_id) {
    cardNode *tmp = new cardNode;
    tmp->card = new Card(r_id);
    tmp->next = last->next;
    last->next = tmp;
    last = tmp;
}

Card Deck::drawCard() {
    index = index->next;
    return *(index->card);
}
