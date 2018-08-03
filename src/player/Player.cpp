#include "Player.h"

Player::Player(String name) {
    this.name = name;
    this.position = 0;
    this.score = 0;
}

Player::getScore() {
    return score;
}

Player::getPosition() {
    return position;
}

Player::move(int position) {
    this.position = position;
}
