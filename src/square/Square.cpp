#include "Square.h"
#include "../game/Game.cpp"

const int squareTypes = 6;

Square::Square(string s) {
    this->msg = s;
}

Square::Square(int r, int l) {
    r = r % squareTypes;
    this->id = r;
    this->randomize(r, l);
}

void Square::randomize(int r, int l) {
    switch (r) {
        case 0:
            this->msg = "Pesca una carta";
            break;
        case 1:
            this->msg = "Casella vuota";
            break;
        case 2:
            this->msg = "Tira un'altra volta";
            break;
        case 3:
            this->msg = "Vai ";

            do {
                this->val[0] = (rand() % 25) - 12;
            } while (this->val[0] == 0);

            if (val > 0)
                this->msg += "avanti ";
            else
                this->msg += "indietro ";

            this->msg += " di " + this->val[0];
            break;
        case 4:
            this->val[0] = (rand() % (l / 2)) + (l / 2);
            this->msg = "Vai alla casella " + val[0];
            break;
        case 5:
            //dovrebbe essere la casella indovina una domanda
            this->msg = "Casella vuota";
            break;
    }
}

void Square::activate(Player *p) {
    switch (this->id) {
        case 0:
            //pesca una carta
            break;
        case 1:
            break;
        case 2:
            //how to link it?
            throwDice();
            break;
        case 3:
            p->move(p->getPosition() + val[0]);
            break;
        case 4:
            p->move(val[0]);
            break;
        case 5:
            //dovrebbe essere la casella indovina una domanda
            break;
    }
}
