//
// Created by Skye on 31/05/2025.
//

#include <iostream>
#include "BattleMenu.h"
#include "BattleManager.h"

Battler& player = BattleManager::getPlayer();
Battler& enemy = BattleManager::getEnemy();

void BattleMenu::printStats() {
    std::cout << "----------" << "\n"
              << player.getName() << "\n"
              << "HP: " << player.getHp() << "\n"
              << "MP: " << player.getMp() << "\n"
              << "----------\n" <<  std::endl;

    std::cout << "----------" << "\n"
              << enemy.getName() << "\n"
              << "HP: " << enemy.getHp() << "\n"
              << "MP: " << enemy.getMp() << "\n"
              << "----------\n" <<  std::endl;
}
