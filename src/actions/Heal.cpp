//
// Created by Skye on 30/05/2025.
//

#include "Heal.h"

#include <iostream>

void Heal::use(Battler& user) const {
    if (user.getMp() < mpCost) {
        cout << user.getName() << " doesn't have enough MP to use" << name << endl << endl;
    }

    else if (user.isFullHp()) {
        cout << user.getName() << "'s HP is already full!" << endl << endl;
    }

    else {
        const int amount = minHeal + rand() % (maxHeal - minHeal + 1);
        user.recoverHp(amount);
        user.reduceMp(mpCost);
        cout << user.getName() << " healed " << amount << " HP!" << endl << endl;
    }
}