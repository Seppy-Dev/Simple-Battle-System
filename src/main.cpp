#include <iostream>
#include "battle/BattleManager.h"

int main() {
    srand(time(nullptr));
    BattleManager::assignPlayer();
    BattleManager::assignEnemy();

    BattleManager::startBattle();

    while (BattleManager::isActive()) {
        BattleManager::playerAction();
        BattleManager::enemyAction();
        BattleManager::executeTurn();
    }
}


