#include "Card.h"

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

const int cardTypes = 8;

Card::Card(string s) {
    if (s == "last")
        this->id = 7;
    else
        this->id = 6;
}

Card::Card(int r_id) {
    this->id = r_id % (cardTypes - 1);
    this->randomize();
}

void Card::randomize() {
    this->desc = "";
    this->name = "";
    switch (this->id) {
        case 0:
            this->name = "git gut";
            this->desc = "Torna alla casella 0";
            break;
        case 1:
            this->name = "Malus - Fat roll";
            this->desc = "D'ora in poi -3 ai tiri di dado (si va in negativo)";
            break;
        case 2:
            this->name = "Bonus - Fast roll";
            this->desc = "D'ora in poi +3 ai tiri di dado";
            break;
        case 3:
            this->name = "Speedrun";
            this->desc = "Vai a metà tabellone";
            break;
        case 4:
            this->name = "Discriminato";
            this->desc = "Reset di tutti i bonus/malus";
            break;
        case 5:
            this->name = "Bonus - New Game Plus";
            this->desc = "Torna alla casella 0 ma +5 ai tiri";
            break;
        case 6:
            this->name = "Giovane Ramo Bianco";
            this->desc = "Nulla cosmico";
            break;
        case 7:
            this->name = "Dark Soul";
            this->desc = "Hai trovato l'anima oscura, hai vinto la partita";
            break;
    }
}

bool Card::activate(Player *p) {
    cout << p->getName() << " pesca una carta dal mazzo.\n";
    cout << this->name << " \"" << this->desc << "\"\n";
    bool tmp = false;
    switch (this->id) {
        case 0:
            p->setPosition(0);
            tmp = true;
            break;
        case 1:
            p->activateBonus(1);
            break;
        case 2:
            p->activateBonus(0);
            break;
        case 3:
            p->setPosition(p->getBounds()/2); //eventualità dispari da aggiungere
            tmp = true;
            break;
        case 4:
            p->clearStats();
            break;
        case 5:
            p->setPosition(0);
            p->activateBonus(2);
            break;
        case 6:
            break;
        case 7:
            p->setPosition(p->getBounds() - 1);
            break;
    }
    return tmp;
}
