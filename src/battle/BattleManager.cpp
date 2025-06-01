//
// Created by Skye on 31/05/2025.
//

#include "BattleManager.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

using json = nlohmann::json;

void loadBattlerFromJson(Battler& battler) {
    const std::string path = "data/battlers/";

    std::cout << "Enter name of battler json file (do not include .json or file path!): " << std::endl;
    std::string input;
    std::cin >> input;

    std::ifstream file(path + input + ".json");
    const auto data = json::parse(file);
    file.close();

    battler.setName(data["name"]);
    battler.setMaxHp(data["stats"]["maxHp"]);
    battler.setMaxMp(data["stats"]["maxMp"]);
    battler.setSpeed(data["stats"]["speed"]);
}

void BattleManager::startBattle() {
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
}

