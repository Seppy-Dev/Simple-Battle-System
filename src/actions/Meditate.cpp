//
// Created by Skye on 30/05/2025.
//

#include "Meditate.h"

#include <iostream>

Meditate::Meditate(Battler& battler, int min, int max)
{
    if (battler.isFullMp())
        cout << battler.getName() << "'s MP is already full!" << endl << endl;

    else
    {
        int amount = min + rand() % max;
        battler.recoverMp(amount);
        cout << battler.getName() << " recovered " << amount << " MP!" << endl << endl;
    }
}