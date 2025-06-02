//
// Created by Skye on 31/05/2025.
//

#ifndef BATTLEMENU_H
#define BATTLEMENU_H

#include "../entities/Battler.h"

class BattleMenu {
public:
    BattleMenu(Battler& player, Battler& enemy) : player{player}, enemy{enemy} {}

    void printStats(const Battler& battler) ;
    void listActions();


private:
    Battler& player;
    Battler& enemy;
};



#endif //BATTLEMENU_H
