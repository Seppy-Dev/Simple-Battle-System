#include <iostream>
#include "battle/BattleManager.h"

int main() {
    srand(time(nullptr));
    BattleManager::loadBattlerFromJson(BattleManager::getPlayer());
    BattleManager::loadBattlerFromJson(BattleManager::getEnemy());

    BattleManager::startBattle();

    while (BattleManager::isActive()) {
        BattleManager::playerAction();
        BattleManager::enemyAction();
        BattleManager::executeTurn();
    }
}


