//
// Created by Skye on 30/05/2025.
//

#include "Heal.h"

#include <iostream>

void Heal::use(Battler& battler)
{
    if (battler.getMp() < mpCost)
        cout << battler.getName() << " doesn't have enough MP to use" << name << endl << endl;

    else if (battler.isFullHp())
        cout << battler.getName() << "'s HP is already full!" << endl << endl;

    else
    {
        int amount = minHeal + rand() % (maxHeal - minHeal + 1);
        battler.recoverHp(amount);
        battler.reduceMp(mpCost);
        cout << battler.getName() << " healed " << amount << " HP!" << endl << endl;
    }
}

const int Heal::getMaxHeal() {
    return maxHeal;
}

const int Heal::getMinHeal() {
    return minHeal;
}

const int Heal::getMpCost() {
    return mpCost;
}

const string &Heal::getName() {
    return name;
}