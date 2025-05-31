//
// Created by Skye on 29/05/2025.
//

#include "Battler.h"

void Battler::reduceHp(const int amount) {
   hp = max(0, hp - amount);
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

