#include "Square.h"

#include <stdlib.h>
#include <string>

using namespace std;

const int squareTypes = 6;

Square::Square(string msg, int pos) {
    this->msg = Color::getColor(6) + msg + Color::resetColor();
    this->pos = pos;
}

Square::Square(int r_id, Square *board[], int pos, int l) {
    this->id = r_id % squareTypes;
    this->pos = pos;
    this->randomize(board, l);
}

void Square::randomize(Square *board[], int l) {
    this->msg = Color::getColor(this->id);
    switch (this->id) {
        case 0:
            this->msg = Color::getColor(6);
            this->msg += "Casella vuota";
            break;
        case 1:
            this->msg += "Tira un'altra volta";
            break;
        case 2:
            this->msg += "Vai ";
            int l_r;
            int r_r;
            do {
                l_r = rand() % 12 - 12; //left range
                r_r = rand() % 12 + 1; //right range
                if (this->pos + l_r <= 0) {
                    l_r = - this->pos;
                } else if (this->pos + r_r > l - 1) {
                    r_r = (l - 1) - this->pos;
                }
                this->val = (rand() % (r_r - l_r)) + l_r;
            } while (this->val == 0 || checkLoop(board));

            if (val > 0)
                this->msg += "avanti ";
            else
                this->msg += "indietro ";

            this->msg += "di " + to_string(abs(this->val));
            break;
        case 3:
            this->msg = Color::getColor(0);
            do {
                this->val = (rand() % (l / 2)) + (l / 4);
            } while (this->val == this->pos || checkLoop(board));
            this->msg += "Vai alla casella " + to_string(val);
            break;
        case 4:
            this->msg += "Pesca una carta";
            break;
        case 5:
            this->msg += "Indovina...";
            break;
    }
    this->msg += Color::resetColor();
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
            Question *q = new Question(rand());
            tmp = q->answer(p);
            break;
    }
    return tmp;
}

bool Square::checkLoop(Square *board[]) {
    bool tmp = false;
    int index;

    switch (this->id) {
        case 2:
            index = this->pos + this->val;
            break;
        case 3:
            index = this->val;
            break;
    }

    if (index < this->pos)
        switch (board[index]->id) {
            case 2:
                if (board[index]->val + index == this->pos)
                    tmp = true;
                break;
            case 3:
                if (board[index]->val == this->pos)
                    tmp = true;
                break;
            case 5:
                if (index + 2 == this->pos)
                    tmp = true;
                break;
        }
    return tmp;
}

string Square::getMsg() {
    return this->msg;
}
