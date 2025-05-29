//
// Created by Skye on 29/05/2025.
//

#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include "Battler.h"

using namespace std;

class Attack {
public:
    explicit Attack(const string& name, int minDamage, int maxDamage, int mpCost, int accuracy);
    void useAttack(Battler& user, Battler& target) const;
    string FlavourTextPicker(const string list[], size_t size);

    const int getMinDamage() const;
    const int getMaxDamage() const;
    const int getMpCost() const;
    const int getAccuracy() const;

private:
    string name;
    int minDamage = 1;
    int maxDamage = 1;
    int mpCost = 0;
    int accuracy = 100;

    string meleeAttackText[2] = {"PUNCH", "KICK"};
    string magicText[2] = {"FIREBALL", "LIGHT MAGIC"};
    string darkMeleeAttackText[2] = {"BITE", "SCRATCH"};
    string darkMagicText[2] = {"DARK MAGIC", "LIGHTNING"};
};

#endif //ATTACK_H
