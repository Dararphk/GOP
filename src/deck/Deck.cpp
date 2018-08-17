#include "Deck.h"

#include <ctime>
#include <iostream>

using namespace std;

const int MIN_CARDS = 40;
const int MAX_CARDS = 100;

Deck::Deck() {
    this->n = (rand() % (MAX_CARDS - MIN_CARDS + 1)) + MIN_CARDS;
    initDeck(this->n);
}

void Deck::initDeck(int n){
    for (int i = 0; i < n-1; i++) {
        cards[i] = new Card(rand());
    }
    cards[n-1] = new Card(0, 7)
}

int getNumber(){
    return n;
}

void drawnCard(Player *p, int f){
    cards[f]->activate(p);
    for (; f < n-1; f++) {
        cards[f] = cards[f+1];
    }
    n--;
}
