#include "Card.h"

#include <stdlib.h>
#include <string>

using namespace std;

const int cardTypes = 7;

Card::Card(int r_id) {
    this->id = r_id % cardTypes;
    this->randomize();
}

Card::Card(int i,int id) {
    this->id = id;
    this->randomize();
}

void Card::randomize() {
    this->desc = "";
    this->name = "";

    switch (this->id) {
        case 0:
            this->name = "git gut";
            this->desc = "Torna alla casella 0"
            break;
        case 1:
            this->name = "Malus - Fat roll";
            this->desc = "Da ora in poi -3 ai tiri di dado (si va in negativo)"
            break;
        case 2:
            this->name = "Bonus - Fast roll";
            this->desc = "Da ora in poi +3 ai tiri di dado"
            break;
        case 3:
            this->name = "Speedrun";
            this->desc = "Vai a metà tabellone";
            break;
        case 4:
            this->name = "Bonus - Level Up";
            this->desc = "" //any ideas? un bonus/malus
            break;
        case 5:
            this->name = "Discriminato";
            this->desc = "Reset di tutti i bonus/malus"
            break;
        case 6:
            this->name = "Bonus - New Game Plus";
            this->desc = "Torna alla casella 0 ma +5 ai tiri"
            break;
        case 7:
            this->name = "Dark Soul";
            this->desc = "Hai trovato l'anima oscura, hai vinto la partita"
            break;
    }
}


void Card::activate(Player *p) {
    switch (this->id) {
            case 0:
                p->setPosition(0);
                break;
            case 1:
                p->activateMalus();
                break;
            case 2:
                p->activateBonus(0);
                break;
            case 3:
                p->setPosition(p->getBounds()/2); //eventualità dispari da aggiungere
                break;
            case 4:
                p->activateBonus(1);
                break;
            case 5:
                p->cleanChanges();
                break;
            case 6:
                p->setPosition(0);
                p->activateBonus(2);
                break;
            case 7:
                p->setPosition(p->getBounds());
                break;
    }
}
