#include "Player.h"

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

Player::Player(string name, int l) {
    this->name = name;
    this->setPosition(0);
    this->bounds = l;
}

string Player::getName() {
    return name;
}

int Player::getPosition() {
    return position;
}

void Player::setPosition(int position) {
    this->position = position;
}

int Player::move(int i) {
    int tmp = this->position + i;
    if (tmp >= this->bounds)
        tmp = this->bounds - (tmp - this->bounds) - 2;
    cout << getName() << " si muove nella casella " << to_string(tmp) << endl;
    this->position = tmp;
    return this->position;
}

int Player::throwDice() {
    //put output messagge
    cout << this->getName() << " tira ";
    int dice = (rand() % 6 + 1) + (rand() % 6 + 1);
    cout << to_string(dice) << endl;
    return this->move(dice);
}
