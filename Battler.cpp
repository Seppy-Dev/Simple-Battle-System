//
// Created by Skye on 29/05/2025.
//

#include "Battler.h"

Battler::Battler(const string &name, int hp, int mp) : name{name}, hp{hp}, mp{mp} {}

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
   hp = max(0, hp -= amount);
}
void Battler::reduceMp(const int amount) {
   mp = max(0, mp - amount);
}
void Battler::recoverHp(const int amount) {
   hp = min(MAX_HP, hp + amount);
}
void Battler::recoverMp(const int amount) {
   mp = min(MAX_MP, mp + amount);
}

