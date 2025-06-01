//
// Created by Skye on 31/05/2025.
//

#include "EnemyAI.h"

void EnemyTurn() {
    int enemyActions[] = {1,2,3,4};

    if (enemy.getMp() < darkMagic.getMpCost()) {
        enemyActions[1] = 0;
    }
    if (enemy.getMp() < heal.getMpCost()) {
        enemyActions[2] = 0;
    }
    if (enemy.getHp() > 70) {
        enemyActions[2] = 0;
    }
    if (enemy.getMp() > 20) {
        enemyActions[3] = 0;
    }

    int enemyAction = 0;
    while (enemyAction == 0) {
        if (int rng = enemyActions[rand() % size(enemyActions)]; rng != 0)
        {
            enemyAction = rng;
            break;
        }
    }

    switch (enemyAction) {
        case 1: darkMelee.use(enemy, player);
            break;

        case 2: darkMagic.use(enemy, player);
            break;

        case 3: heal.use(enemy);
            break;

        case 4: recover.use(enemy);
            break;

        default:
            cout << "Enemy action failed! (" << enemyAction << ")" << endl << endl;
    }
}