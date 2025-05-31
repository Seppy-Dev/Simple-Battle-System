//
// Created by Skye on 30/05/2025.
//

#ifndef HEAL_H
#define HEAL_H

#include "../entities/Battler.h"


class Heal {
public:
    Heal(const string& name, const int minHeal, const int maxHeal, const int mpCost) : name{name}, minHeal{minHeal}, maxHeal{maxHeal}, mpCost{mpCost} {};
    void use(Battler& user) const;

    [[nodiscard]] const string& getName() const {return name;}
    [[nodiscard]] int getMinHeal() const {return minHeal;}
    [[nodiscard]] int getMaxHeal() const {return maxHeal;}
    [[nodiscard]] int getMpCost() const {return mpCost;}

private:
    const string& name;
    const int minHeal;
    const int maxHeal;
    const int mpCost;
};

#endif //HEAL_H
