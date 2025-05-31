//
// Created by Skye on 29/05/2025.
//

#ifndef BATTLER_H
#define BATTLER_H

#include <string>
#include <utility>

using namespace std;

class Battler {
public:
    explicit Battler(string name, const int maxHp, const int maxMp) : name{std::move(name)}, maxHp{maxHp}, maxMp{maxMp}, hp{maxHp}, mp{maxMp} {};

    [[nodiscard]] const string& getName() const {return name;}
    [[nodiscard]] int getHp() const {return hp;}
    [[nodiscard]] int getMp() const {return mp;}
    [[nodiscard]] int getMaxHp() const {return maxHp;}
    [[nodiscard]] int getMaxMp() const {return maxMp;}

    [[nodiscard]] bool isAlive() const {return (hp > 0);}
    [[nodiscard]] bool isFullHp() const {return (hp == maxHp);}
    [[nodiscard]] bool isFullMp() const {return (mp == maxMp);}

    void reduceHp(int amount);
    void reduceMp(int amount);
    void recoverHp(int amount);
    void recoverMp(int amount);
private:
    const string name;
    const int maxHp;
    const int maxMp;
    int hp;
    int mp;
};
#endif //BATTLER_H
