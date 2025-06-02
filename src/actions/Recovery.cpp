//
// Created by Skye on 30/05/2025.
//

#include "Recovery.h"

#include <iostream>

void Recovery::use(Battler& user) const {
    if (user.isFullMp()) {
        cout << user.getName() << "'s MP is already full!" << endl << endl;
    }

    else {
        const int amount = minRecover + rand() % (maxRecover - minRecover + 1);
        user.recoverMp(amount);
        cout << user.getName() << " used " << name << " and recovered " << amount << " MP!" << endl << endl;
    }
}