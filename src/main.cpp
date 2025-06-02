#include <iostream>
#include "battle/BattleManager.h"
#include "battle/BattleMenu.h"

int main() {
    srand(time(nullptr));
    BattleManager::assignPlayer();
    BattleManager::assignEnemy();

    BattleManager::startBattle();

    while (BattleManager::isActive()) {
        BattleMenu::printStats();
        BattleManager::playerAction();
        BattleManager::enemyAction();
        BattleManager::executeTurn();
    }
}


