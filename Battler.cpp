//
// Created by Skye on 29/05/2025.
//

#include "Battler.h"

const string &Battler::getName() const {
   return name;
}
int Battler::getHp() const {
   return hp;
}
int Battler::getMp() const {
   return mp;
}

bool Battler::isAlive() const {
   return (hp > 0);
}
bool Battler::isFullHp() const {
   return (hp == MAX_HP);
}
bool Battler::isFullMp() const {
   return (mp == MAX_MP);
}

void Battler::reduceHp(const int amount) {
   hp -= amount;
}
void Battler::reduceMp(int amount) {
   mp -= amount;
}
void Battler::recoverHp(int amount) {
   hp += amount;
}
void Battler::recoverMp(int amount) {
   mp += amount;
}

