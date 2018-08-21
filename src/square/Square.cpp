#include "Square.h"

#include <stdlib.h>
#include <string>

using namespace std;

const int squareTypes = 6;
const int MAX_STRING_LENGTH = 40;

Square::Square(string msg, int pos) {
    this->msg = msg;
    this->pos = pos;
}

Square::Square(int r_id, int pos, int l) {
    this->id = r_id % squareTypes;
    this->pos = pos;
    this->randomize(l);
}

void Square::randomize(int l) {
    this->msg = "";
    switch (this->id) {
        case 0:
            this->msg = "Casella vuota";
            break;
        case 1:
            this->msg = "Tira un'altra volta";
            break;
        case 2:
            this->msg = "Vai ";

            do {
                //(!!! correggere il range: cosa succede se i basso e rand alto?)
                int l_r = rand() % 12 - 12; //left range
                int r_r = rand() % 12 + 1; //right range
                //correzione del range del random
                if (this->pos + l_r <= 0) {
                    l_r = - this->pos;
                } else if (this->pos + r_r > l - 1) {
                    r_r = (l - 1) - this->pos;
                }
                this->val = (rand() % (r_r - l_r)) + l_r;
            } while (this->val == 0);

            if (val > 0)
                this->msg += "avanti ";
            else
                this->msg += "indietro ";

            this->msg += "di " + to_string(abs(this->val));
            break;
        case 3:
            this->val = (rand() % (l / 2)) + (l / 2);
            this->msg = "Vai alla casella " + to_string(val);
            break;
        case 4:
            this->msg = "Pesca una carta";
            break;
        case 5:
            this->msg = "Indovina...";
            break;
    }
}

bool Square::activate(Player *p, Deck *d) {
    bool tmp = false;
    switch (this->id) {
        case 0:
            break;
        case 1:
            p->throwDice();
            tmp = true;
            break;
        case 2:
            p->move(val);
            tmp = true;
            break;
        case 3:
            p->setPosition(val);
            tmp = true;
            break;
        case 4:
            tmp = d->drawCard().activate(p);
            break;
        case 5:
            //(!!!) attenzione, 1 messo come argomento solo per testing, ripristinare commento e cancellare riga sotto ad esso
            //Question *q = new Question(rand());
            Question *q = new Question(1);
            tmp = q->answer(p);
            break;
    }
    return tmp;
}

string Square::print() {
    string tmp = to_string(this->pos) + " - " + this->msg;
    int max = MAX_STRING_LENGTH - tmp.length();

    for (int i = 0; i < max; i++) {
        tmp += " ";
    }

    return tmp;
}
