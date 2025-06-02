//
// Created by Skye on 31/05/2025.
//

#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include "../entities/Battler.h"
#include "../actions/Action.h"

class BattleManager {
public:
    static Battler player;
    static Battler enemy;

    static void assignPlayer();
    static void assignEnemy();

    static void startBattle();

    static Action playerAction();

    static Action enemyAction();
    static void executeTurn();
    static void endBattle(const Battler& winner);

    [[nodiscard]] static bool isActive() {return battleActive;}

private:
    std::string battlerPath = "../../data/battlers/";
    static bool battleActive;
    static int turns;
};

#endif //BATTLEMANAGER_H
