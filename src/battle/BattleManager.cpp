//
// Created by Skye on 31/05/2025.
//

#include "BattleManager.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

Battler BattleManager::player;
Battler BattleManager::enemy;
bool BattleManager::battleActive = false;
int BattleManager::turns = 0;

void BattleManager::assignPlayer() {
    std::cout << "Please type the name of the battler you wish to use\n"
              << "Battler files should be .json files stored in data/battlers/\n"
              << "(Do NOT include the file path or .json)\n\n" << std::endl;
    while (true) {
        std::string input;
        std::cout << "Enter Battler Name: ";
        std::cin >> input;
        const std::string filePath = "../data/battlers/" + input + ".json";
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cout << "Error: No file found!" << std::endl;
            continue;
        }
        nlohmann::json battlerData = nlohmann::json::parse(file);
        file.close();
        player.loadBattler(battlerData);
        //system("cls");
        break;
    }
}

void BattleManager::assignEnemy() {
    std::cout << "Please type the name of the battler you wish to fight against\n"
              << "Battler files should be .json files stored in data/battlers/\n"
              << "(Do NOT include the file path or .json)\n\n" << std::endl;
    while (true) {
        std::string input;
        std::cout << "Enter Battler Name: ";
        std::cin >> input;
        const std::string filePath = "../data/battlers/" + input + ".json";
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cout << "Error: No file found!" << std::endl;
            continue;
        }
        nlohmann::json battlerData = nlohmann::json::parse(file);
        file.close();
        enemy.loadBattler(battlerData);
        //system("cls");
        break;
    }
}

void BattleManager::startBattle() {
    battleActive = true;
}

void BattleManager::setPlayerAction(const Action &action) {
    playerAction = action;
}
void BattleManager::setEnemyAction(const Action &action) {
    enemyAction = action;
}


void playerFirst() {
    BattleManager::getPlayerAction().use(BattleManager::getPlayer(), BattleManager::getEnemy());
    BattleManager::getEnemyAction().use(BattleManager::getEnemy(), BattleManager::getPlayer());
}

void enemyFirst() {
    BattleManager::getEnemyAction().use(BattleManager::getEnemy(), BattleManager::getPlayer());
    BattleManager::getPlayerAction().use(BattleManager::getPlayer(), BattleManager::getEnemy());
}

void randomFirst() {
    if (const int num = rand() % 1; num == 0) {
        enemyFirst();
    }
    else {
        playerFirst();
    }
}

void BattleManager::executeTurn() {
    if (playerAction.getPriority() > enemyAction.getPriority()) {
        playerFirst();
    }
    else if (playerAction.getPriority() < enemyAction.getPriority()) {
        enemyFirst();
    }

    else if (player.getSpeed() > enemy.getSpeed()) {
        playerFirst();
    }
    else if (player.getSpeed() < enemy.getSpeed()) {
        enemyFirst();
    }

    else {
        randomFirst();
    }

    turns++;
}

void BattleManager::endBattle(const Battler& winner) {
    std::cout << "The winner is: " << winner.getName();
    battleActive = false;
}

