//
// Created by Skye on 29/05/2025.
//

#include "Battler.h"
#include <fstream>
#include <iostream>

void Battler::addAction(const std::string& actionName) {
   const std::string filePath = "../../data/actions/" + actionName + ".json";
   std::ifstream file(filePath);
   if (!file.is_open()) {
      throw std::runtime_error("Could not open action file: " + filePath);
   }
   const nlohmann::json actionData = nlohmann::json::parse(file);
   actions.emplace(actionName, Action(actionData));
}

void Battler::loadBattler(const nlohmann::json& data) {
   name = data.value("name", "battler");
   maxHp = data.value("maxHp", 100);
   maxMp = data.value("maxMp", 100);
   hp = maxHp;
   mp = maxMp;
   speed = data.value("speed", 10);

   if (data.contains("actions")) {
      for (const auto& actionName : data["actions"]) {
         addAction(actionName.get<std::string>());
      }
   }
}

void Battler::reduceHp(const int amount) {
   hp = std::max(0, hp - amount);
}
void Battler::reduceMp(const int amount) {
   mp = std::max(0, mp - amount);
}
void Battler::recoverHp(const int amount) {
   hp = std::min(maxHp, hp + amount);
}
void Battler::recoverMp(const int amount) {
   mp = std::min(maxMp, mp + amount);
}

