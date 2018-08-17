#include "Player.h"

#include <string>
#include <cstdlib>

using namespace std;

Player::Player(string name, int l) {
    this->name = name;
    this->setPosition(0);
    this->bounds = l;
    for (int i = 0; i < 3; i++) {
      bonuses[i] = 0;
    }
    this->malus = false;
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

    if(bonuses[0] == 1)
    {
      dice += 3
    }
    if(bonuses[1] == 1)
    {

    }
    if(bonuses[2] == 1)
    {
      dice += 5
    }
    if(malus == true)
    {
      dice -= 3
    }

    this->move(dice);
}

int Player::getBounds() {
    return bounds;
}

void activateBonus(int i){
    switch (i) {
      case 0: //+3 dadi
          bonuses[0] = 1;
          break;
      case 1: // ...
          bonuses[1] = 1;
          break;
      case 2: //+5 dadi
          bonuses[2] = 1;
          break;
    }

}

void activateMalus(){
    malus = true; //-3 dadi
}

void cleanChanges(){
    for (int i = 0; i < 3; i++) {
      bonuses[i] = 0;
    }
    malus = false;
}

void drawCard(Deck deck){
    int u = rand() % deck->getNumber();
    deck->drawnCard(u, this);
}
