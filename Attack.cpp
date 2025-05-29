//
// Created by Skye on 29/05/2025.
//

#include "Attack.h"
#include "Battler.h"
#include <iostream>

using namespace std;


bool MissChance(int accuracy)
{
    int rng = 1 + (rand() % 100);
    if (rng > accuracy)
        return true;
    return false;
}

Attack::Attack(const string &name, const Battler &user, const Battler &target, int minDamage, const int maxDamage,
    const int mpCost, const int accuracy) : user{user}, target{target}, name{name}, minDamage{minDamage}, maxDamage{maxDamage}, mpCost{mpCost}, accuracy{accuracy}{}

void Attack::useAttack() {
    if (user.getHp() < mpCost)
        cout << user.getName() << " doesn't have enough MP to use " << name << "!" << endl << endl;

    else if (MissChance(accuracy)) {
        user.reduceMp(mpCost);
        cout << user.getName() << " used " << name << "... but missed!" << endl << endl;
    }

    else {
        user.reduceMp(mpCost);
        int damage = minDamage + (rand() % maxDamage);
        target.reduceHp(damage);
        cout << user.getName() << " used " << name << " and dealt " << damage << " damage!" << endl << endl;
    }
}

string Attack::FlavourTextPicker(const string list[], size_t size) {
    string attackName = list[0]; //TODO: Add randomiser to pick a random index
    return attackName;
}
