//
// Created by Skye on 31/05/2025.
//

#include <iostream>
#include "BattleMenu.h"
#include "BattleManager.h"


void BattleMenu::printStats() {
    std::cout << "----------" << "\n"
              << BattleManager::player.getName() << "\n"
              << "HP: " << BattleManager::player.getHp() << "\n"
              << "MP: " << BattleManager::player.getMp() << "\n"
              << "----------\n" <<  std::endl;

    std::cout << "----------" << "\n"
              << BattleManager::enemy.getName() << "\n"
              << "HP: " << BattleManager::enemy.getHp() << "\n"
              << "MP: " << BattleManager::enemy.getMp() << "\n"
              << "----------\n" <<  std::endl;
}
