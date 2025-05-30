//
// Created by Skye on 30/05/2025.
//

#ifndef HEAL_H
#define HEAL_H

#include "../entities/Battler.h"


class Heal {
public:
    Heal(string name, int minHeal, int maxHeal, int mpCost) : name{name}, minHeal{minHeal}, maxHeal{maxHeal} {};
    void use(Battler& battler);

    const string& getName();
    const int getMinHeal();
    const int getMaxHeal();
    const int getMpCost();
private:
    const string& name;
    int minHeal;
    int maxHeal;
    int mpCost;
};



#endif //HEAL_H
