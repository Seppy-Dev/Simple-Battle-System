//
// Created by Skye on 31/05/2025.
//

#ifndef BATTLEMENU_H
#define BATTLEMENU_H

#include "../entities/Battler.h"

class BattleManager;

class BattleMenu {
public:
    BattleMenu::BattleMenu(BattleManager& battleManager, Battler& player, Battler& enemy) : player{player}, enemy{enemy}, battleManager{battleManager} {}

    void printStats(Battler& battler);


private:
    BattleManager& battleManager;
    Battler& player;
    Battler& enemy;
};



#endif //BATTLEMENU_H
