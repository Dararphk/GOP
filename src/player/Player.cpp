#include "Player.h"

#include <string>
#include <cstdlib>

using namespace std;

Player::Player(string name) {
    this->name = name;
    this->position = 0;
}

string Player::getName() {
    return name;
}

int Player::getPosition() {
    return position;
}

void Player::move(int position) {
    this->position = position;
}

int Player::throwDice() {

}
