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

Action BattleManager::playerAction() {
    //get action reference from player
    //return that action reference
}

Action BattleManager::enemyAction() {
    //get action reference from enemy
    //return that action reference
}

void BattleManager::executeTurn() {
    //compare priority level of both attacks
    //if priority is same, compare speed of users
    //if speed is the same, choose randomly (THIS CAN ALL BE ONE TURN ORDER CALCULATION FUNCTION)

    //execute fastest attack first
    //check if target was killed, if so run endBattle

    //execute other attack
    //check if target was killed, if so run endBattle

    turns++;
}

void BattleManager::endBattle(const Battler& winner) {
    std::cout << "The winner is: " << winner.getName();
    battleActive = false;
}

