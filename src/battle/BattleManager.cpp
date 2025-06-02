//
// Created by Skye on 31/05/2025.
//

#include "BattleManager.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

using json = nlohmann::json;

void BattleManager::assignPlayer() {
    std::cout << "Please type the name of the battler you wish to use\n"
              << "Battler files should be .json files stored in data/battlers/\n"
              << "(Do NOT include the file path or .json)\n\n" << std::endl;
    while (true) {
        std::string input;
                  std::cout << "Enter Battler Name: " << std::endl;
        std::cin >> input;
        const std::string filePath = "../../data/battlers/" + input + ".json";
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cout << "Error: No file found!" << std::endl;
            continue;
        }
        player.loadBattler(filePath);
        system("cls");
        break;
    }
}

void BattleManager::assignEnemy() {
    std::cout << "Please type the name of the battler you wish to fight against\n"
              << "Battler files should be .json files stored in data/battlers/\n"
              << "(Do NOT include the file path or .json)\n\n" << std::endl;
    while (true) {
        std::string input;
        std::cout << "Enter Battler Name: " << std::endl;
        std::cin >> input;
        const std::string filePath = "../../data/battlers/" + input + ".json";
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cout << "Error: No file found!" << std::endl;
            continue;
        }
        enemy.loadBattler(filePath);
        system("cls");
        break;
    }
}

void BattleManager::startBattle() {
    battleActive = true;
}

void BattleManager::playerAction() {
}

void BattleManager::enemyAction() {
}

void BattleManager::executeTurn() {

    turns++;
}

void BattleManager::endBattle(const Battler& winner) {
    std::cout << "The winner is: " << winner.getName();
    battleActive = false;
}

