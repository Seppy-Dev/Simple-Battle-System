//
// Created by Skye on 29/05/2025.
//

#ifndef BATTLER_H
#define BATTLER_H

#include <string>
#include <unordered_map>
#include "../actions/Attack.h"
#include "../actions/Recovery.h"
#include <nlohmann/json.hpp>

class Battler {
public:
    explicit Battler();

    const std::string& setName(std::string name);
    int setHp(int hp);
    int setMp(int mp);
    int setMaxHp(int maxHp);
    int setMaxMp(int maxMp);
    int setSpeed(int speed);

    [[nodiscard]] const std::string& getName() const {return name;}
    [[nodiscard]] int getHp() const {return hp;}
    [[nodiscard]] int getMp() const {return mp;}
    [[nodiscard]] int getMaxHp() const {return maxHp;}
    [[nodiscard]] int getMaxMp() const {return maxMp;}
    [[nodiscard]] int getSpeed() const {return speed;}

    [[nodiscard]] bool isAlive() const {return (hp > 0);}
    [[nodiscard]] bool isFullHp() const {return (hp == maxHp);}
    [[nodiscard]] bool isFullMp() const {return (mp == maxMp);}

    void reduceHp(int amount);
    void reduceMp(int amount);
    void recoverHp(int amount);
    void recoverMp(int amount);
private:
    std::string name;
    int maxHp;
    int maxMp;
    int hp;
    int mp;
    int speed;
    std::unordered_map<std::string, Attack> attacks;
    std::unordered_map<std::string, Recovery> recoveries;
};
#endif //BATTLER_H
