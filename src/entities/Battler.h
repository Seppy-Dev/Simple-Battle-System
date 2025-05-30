//
// Created by Skye on 29/05/2025.
//

#ifndef BATTLER_H
#define BATTLER_H

#include <string>

using namespace std;

class Battler {
public:
    explicit Battler(const string& name, int maxHp, int maxMp) : name{name}, maxHp{maxHp}, maxMp{maxMp}, hp{maxHp}, mp{maxMp} {};
    [[nodiscard]] const string& getName() const;

    int getHp() const;
    int getMp() const;
    int getMaxHp() const;
    int getMaxMp() const;

    bool isAlive() const;
    bool isFullHp() const;
    bool isFullMp() const;

    void reduceHp(int amount);
    void reduceMp(int amount);
    void recoverHp(int amount);
    void recoverMp(int amount);
private:
    const string name;
    int maxHp;
    int maxMp;
    int hp;
    int mp;
};
#endif //BATTLER_H
