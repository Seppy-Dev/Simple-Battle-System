//
// Created by Skye on 31/05/2025.
//

#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include "../entities/Battler.h"
#include "../actions/Action.h"
#include "EnemyAI.h"

class BattleManager {
public:

    static void assignPlayer();
    static void assignEnemy();

    static void startBattle();

    static void executeTurn();
    static void endBattle(const Battler& winner);

    [[nodiscard]] static bool isActive() {return battleActive;}

    static void setPlayerAction(const Action& action);
    static void setEnemyAction(const Action& action);

    static Battler& getPlayer() {return player;}
    static Battler& getEnemy() {return enemy;}
    const Action& getPlayerAction() const {return playerAction;}
    const Action& getEnemyAction() const {return enemyAction;}

private:
    std::string battlerPath = "../data/battlers/";
    static bool battleActive;
    static int turns;
    static Battler player;
    static Battler enemy;
    Action& playerAction;
    Action& enemyAction;
    static EnemyAI& enemyAi;
};

#endif //BATTLEMANAGER_H
