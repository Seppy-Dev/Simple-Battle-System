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


void BattleMenu::magicMenu() {
    std::vector<std::pair<::std::string, Action>> action_list;

    int listNumber = 1;
    for (const auto& action : player.getMagicActions()) {
        action_list.push_back(action);
        std::cout << listNumber << ". " << action.first << std::endl;
        listNumber++;
    }
    while (true) {
        std::cout << "Your choice (0 to return to main menu): ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            return;
        }

        if (choice > 0 && choice <= action_list.size()) {
            auto& selected_action = action_list[choice - 1];
            BattleManager::setPlayerAction(selected_action.second);
            return;
        }


        std::cout << "Invalid Option!" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
}

void BattleMenu::abilityMenu() {
    int listNumber = 1;
    for (const std::pair action : player.getAbilityActions()) {
        std::cout << listNumber << ". " << action.first << std::endl;
        listNumber++;
    }
}