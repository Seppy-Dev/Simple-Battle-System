//
// Created by Skye on 29/05/2025.
//

#include "Attack.h"
#include <iostream>

using namespace std;


bool MissCheck(const int accuracy) {
    if (const int rng = 1 + (rand() % 100); rng > accuracy) {
        return true;
    }
    return false;
}

void Attack::use(Battler& user, Battler& target) const {
    if (user.getHp() < mpCost) {
        cout << user.getName() << " doesn't have enough MP to use " << name << "!" << endl << endl;
    }

    else if (MissCheck(accuracy)) {
        user.reduceMp(mpCost);
        cout << user.getName() << " used " << name << "... but missed!" << endl << endl;
    }

    else {
        user.reduceMp(mpCost);
        const int damage = minDamage + (rand() % (maxDamage - minDamage + 1));
        target.reduceHp(damage);
        cout << user.getName() << " used " << name << " and dealt " << damage << " damage!" << endl << endl;
    }
}