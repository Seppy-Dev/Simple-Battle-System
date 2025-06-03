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

enum class MENU_OPTIONS {
    ATTACK = 1,
    MAGIC = 2,
    ABILITIES = 3
};

void BattleMenu::mainBattleMenu() {
    std::cout << "1. Basic Attack\n"
              << "2. Magic\n"
              << "3. Abilities\n" << std::endl;
    while (true) {
        std::cout << "Your choice: ";
        int choice;
        std::cin >> choice;

        switch (auto option = static_cast<MENU_OPTIONS>(choice)) {
            case MENU_OPTIONS::ATTACK:
                std::cout << "Currently Unimplemented!" << std::endl;
                break;
            case MENU_OPTIONS::MAGIC:
                magicMenu();
                break;
            case MENU_OPTIONS::ABILITIES:
                abilityMenu();
                break;
            default:
                std::cout << "Invalid Option!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
        }
    }
}

