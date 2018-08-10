#include "Player.h"

#include <string>

using namespace std;

Player::Player(string name) {
    this->name = name;
    this->position = 0;
}

int Player::getPosition() {
    return position;
}

void Player::move(int position) {
    this->position = position;
}
