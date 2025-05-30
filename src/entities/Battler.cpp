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
int Battler::getMaxHp() const {
   return maxHp;
}
int Battler::getMaxMp() const {
   return maxMp;
}


bool Battler::isAlive() const {
   return (hp > 0);
}
bool Battler::isFullHp() const {
   return (hp == maxHp);
}
bool Battler::isFullMp() const {
   return (mp == maxMp);
}

void Battler::reduceHp(const int amount) {
   hp = max(0, hp -= amount);
}
void Battler::reduceMp(const int amount) {
   mp = max(0, mp - amount);
}
void Battler::recoverHp(const int amount) {
   hp = min(maxHp, hp + amount);
}
void Battler::recoverMp(const int amount) {
   mp = min(maxMp, mp + amount);
}

