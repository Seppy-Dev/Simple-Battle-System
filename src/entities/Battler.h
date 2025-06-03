//
// Created by Skye on 29/05/2025.
//

#ifndef BATTLER_H
#define BATTLER_H

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include "../actions/Action.h"
#include "../battle/EnemyAI.h"

class Battler {
public:
    void addAction(const std::string& actionName);
    void loadBattler(const nlohmann::json& data);

    [[nodiscard]] const std::string& getName() const {return name;}
    [[nodiscard]] int getHp() const {return hp;}
    [[nodiscard]] int getMp() const {return mp;}
    [[nodiscard]] int getMaxHp() const {return maxHp;}
    [[nodiscard]] int getMaxMp() const {return maxMp;}
    [[nodiscard]] int getSpeed() const {return speed;}
    [[nodiscard]] const EnemyAI& getAi() const {return battlerAi;}
    [[nodiscard]] const std::unordered_map<std::string, Action>& getMagicActions() const {return magic;}
    [[nodiscard]] const std::unordered_map<std::string, Action>& getAbilityActions() const {return abilities;}

    [[nodiscard]] bool isAlive() const {return (hp > 0);}
    [[nodiscard]] bool isFullHp() const {return (hp == maxHp);}
    [[nodiscard]] bool isFullMp() const {return (mp == maxMp);}

    void reduceHp(int amount);
    void reduceMp(int amount);
    void recoverHp(int amount);
    void recoverMp(int amount);
private:
    std::string name;
    int maxHp = 100;
    int maxMp = 100;
    int hp = maxHp;
    int mp = maxMp;
    int speed = 10;
    std::unordered_map<std::string, Action> magic;
    std::unordered_map<std::string, Action> abilities;
    EnemyAI battlerAi;
};
#endif //BATTLER_H
