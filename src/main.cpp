#include <iostream>
#include "battle/BattleManager.h"
#include "battle/BattleMenu.h"
#include "battle/EnemyAI.h"

int main() {
    srand(time(nullptr));
    BattleManager::assignPlayer();
    BattleManager::assignEnemy();

    BattleManager::startBattle();

    while (BattleManager::isActive()) {
        BattleMenu::printStats();
        BattleMenu::mainBattleMenu();
        //EnemyAI::chooseAction(BattleManager::getEnemy());
        BattleManager::executeTurn();
    }
}


