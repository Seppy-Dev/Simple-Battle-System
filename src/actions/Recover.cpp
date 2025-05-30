//
// Created by Skye on 30/05/2025.
//

#include "Recover.h"

#include <iostream>

void Recover::use(Battler& user)
{
    if (user.isFullMp())
        cout << user.getName() << "'s MP is already full!" << endl << endl;

    else
    {
        int amount = minRecover + rand() % (maxRecover - minRecover + 1);
        user.recoverMp(amount);
        cout << user.getName() << " used " << name << " and recovered " << amount << " MP!" << endl << endl;
    }
}

const string& Recover::getName() {
    return name;
}

const int Recover::getMinRecover() {
    return minRecover;
}

const int Recover::getMaxRecover() {
    return maxRecover;
}