#include "Player.h"

#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

using namespace std;

Player::Player(string name, char symbol, int l) {
    this->name = name;
    this->symbol = symbol;
    this->setPosition(0);
    this->bounds = l;
    this->clearStats();
}

void Player::clearStats() {
    for (int i = 0; i < 3; i++)
        this->bonuses[i] = false;
}

string Player::getName() {
    return this->name;
}

int Player::getPosition() {
    return this->position;
}

void Player::setPosition(int position) {
    cout << this->getName() << " si muove nella casella " << to_string(position) << endl << endl; //(!!!)
    this->position = position;
}
char Player::getSymbol() {
    return symbol;
}

int Player::move(int i) {
    int tmp = this->position + i;
    if (tmp >= this->bounds)
        tmp = this->bounds - (tmp - this->bounds) - 2;
    if (tmp < 0)
        tmp = 0;
    this->setPosition(tmp);
    return this->position;
}

int Player::throwDice() {
    //(!!!) put output messagge
    int tmp;
    cout << this->getName() << " tira ";
    int dice = (rand() % 6 + 1) + (rand() % 6 + 1);
    cout << to_string(dice);
    tmp = this->applyStats();
    if (tmp != 0) {
        dice += tmp;
        cout << " = " << dice;
    }
    cout << endl;
    return this->move(dice);
}

int Player::applyStats() {
    int tmp = 0;
    if (this->bonuses[0])
        tmp += 3;
    if (this->bonuses[1])
        tmp += -3;
    if (this->bonuses[2])
        tmp += 5;
    if (tmp != 0) {
        if (tmp > 0)
            cout << " + ";
        else
            cout << " - ";
        cout << abs(tmp);
    }
    return tmp;
}

void Player::activateBonus(int b) {
    this->bonuses[b] = true;
}

int Player::getBounds() {
    return bounds;
}
