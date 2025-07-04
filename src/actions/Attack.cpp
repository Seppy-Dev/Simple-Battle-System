//
// Created by Skye on 29/05/2025.
//

#include "Attack.h"
#include <iostream>

using namespace std;


bool MissChance(int accuracy)
{
    int rng = 1 + (rand() % 100);
    if (rng > accuracy)
        return true;
    return false;
}

Attack::Attack(const string& name, int minDamage, int maxDamage, int mpCost, int accuracy) : name{name}, minDamage{minDamage}, maxDamage{maxDamage}, mpCost{mpCost}, accuracy{accuracy}{}

void Attack::use(Battler& user, Battler& target) const {
    if (user.getHp() < mpCost)
        cout << user.getName() << " doesn't have enough MP to use " << name << "!" << endl << endl;

    else if (MissChance(accuracy)) {
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

string Attack::FlavourTextPicker(const string list[], size_t size) {
    string attackName = list[0]; //TODO: Add randomiser to pick a random index
    return attackName;
}

const int Attack::getMinDamage() const {
    return minDamage;
}

const int Attack::getMaxDamage() const {
    return maxDamage;
}

const int Attack::getMpCost() const {
    return mpCost;
}

const int Attack::getAccuracy() const {
    return accuracy;
}