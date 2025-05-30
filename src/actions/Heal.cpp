//
// Created by Skye on 30/05/2025.
//

#include "Heal.h"

#include <iostream>

Heal::Heal(Battler& battler, int min, int max)
{
    if (battler.getMp() < 20)
        cout << battler.getName() << " doesn't have enough MP to heal!" << endl << endl;

    else if (battler.isFullHp())
        cout << battler.getName() << "'s HP is already full!" << endl << endl;

    else
    {
        int amount = min + rand() % max;
        battler.recoverHp(amount);
        battler.reduceMp(20);
        cout << battler.getName() << " healed " << amount << " HP!" << endl << endl;
    }
}