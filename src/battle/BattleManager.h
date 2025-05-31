//
// Created by Skye on 31/05/2025.
//

#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include "../entities/Battler.h"

class BattleManager {
public:
    explicit BattleManager(Battler& player, Battler& enemy);

    void executeTurn();
    void endBattle(const Battler& winner);

    [[nodiscard]] bool isActive() const {return battleActive;}
    [[nodiscard]] Battler getPlayer() const {return player;}
    [[nodiscard]] Battler getEnemy() const {return enemy;}

private:
    const Battler& player;
    const Battler& enemy;
    bool battleActive;
    int turns;
};

#endif //BATTLEMANAGER_H
