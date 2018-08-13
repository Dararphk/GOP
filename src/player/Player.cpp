#include "Player.h"

#include <string>
#include <cstdlib>

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

void Player::move(int i) {
    int tmp = this->position + i;
    if (tmp >= this->bounds)
        this->position = this->bounds - (tmp - this->bounds) - 2;
    else
        this->position = tmp;
}

void Player::throwDice() {
    //put output messagge
    int dice = (rand() % 6 + 1) + (rand() % 6 + 1);
    this->move(dice);
}
