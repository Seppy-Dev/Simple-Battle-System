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

    static void setPlayerAction(Action& action);
    static void setEnemyAction(Action& action);

    static Battler& getPlayer() {return player;}
    static Battler& getEnemy() {return enemy;}
    static Action& getPlayerAction() {return playerAction;}
    static Action& getEnemyAction() {return enemyAction;}

private:
    std::string battlerPath = "../data/battlers/";
    static bool battleActive;
    static int turns;
    static Battler player;
    static Battler enemy;
    static Action& playerAction;
    static Action& enemyAction;
    static EnemyAI& enemyAi;
};

#endif //BATTLEMANAGER_H
