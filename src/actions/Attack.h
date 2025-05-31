//
// Created by Skye on 29/05/2025.
//

#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include "../entities/Battler.h"

using namespace std;

class Attack {
public:
    explicit Attack(string name, const int minDamage, const int maxDamage, const int mpCost, const int accuracy) : name{std::move(name)}, minDamage{minDamage}, maxDamage{maxDamage}, mpCost{mpCost}, accuracy{accuracy}{}

    void use(Battler& user, Battler& target) const;

    [[nodiscard]] int getMinDamage() const {return minDamage;}
    [[nodiscard]] int getMaxDamage() const {return maxDamage;}
    [[nodiscard]] int getMpCost() const {return mpCost;}
    [[nodiscard]] int getAccuracy() const {return accuracy;}

private:
    string name;
    const int minDamage;
    const int maxDamage ;
    const int mpCost;
    const int accuracy;
};

#endif //ATTACK_H
