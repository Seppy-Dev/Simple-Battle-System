//
// Created by Skye on 31/05/2025.
//

#ifndef ENEMYAI_H
#define ENEMYAI_H

class Battler;
class Action;

class EnemyAI {
public:
    Action& EnemyTurn(Battler& battler);
};



#endif //ENEMYAI_H
