//
// Created by Skye on 29/05/2025.
//

#ifndef BATTLER_H
#define BATTLER_H

#include <string>

using namespace std;

class Battler {
public:
    explicit Battler(const string& name, int hp = MAX_HP, int mp = MAX_MP);
    [[nodiscard]] const string& getName() const;
    int getHp() const;
    int getMp() const;

    bool isAlive() const;
    bool isFullHp() const;
    bool isFullMp() const;

    void reduceHp(int amount);
    void reduceMp(int amount);
    void recoverHp(int amount);
    void recoverMp(int amount);
private:
    const string name;
    int hp;
    int mp;
    static constexpr int MAX_HP = 100;
    static constexpr  int MAX_MP = 100;
};
#endif //BATTLER_H
