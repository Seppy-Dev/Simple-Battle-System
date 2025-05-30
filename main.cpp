#include <iostream>
#include <chrono>
#include <thread>

#include "Attack.h"
#include "Battler.h"
#include "Heal.h"
#include "Meditate.h"

using namespace std;

bool battleActive = true;

Battler player("PLAYER");
Battler enemy("ENEMY");

Attack melee("PUNCH", 5, 12, 0, 90);
Attack magic("MAGIC", 15, 20, 15, 70);
Attack darkMelee("BITE", 8, 14, 0, 80);
Attack darkMagic("DARK MAGIC", 17, 22, 15, 60);

//------------------------//
// Basic Battle Functions //
//------------------------//
// Cause the battle to cease and provide a message depending on the victor
void EndBattle(Battler& winner)
{
    cout << winner.getName() << " wins!";
    battleActive = false;
}



//-----------------------//
// Enemy action selector //
//-----------------------//
void EnemyTurn()
{
    int enemyActions[] = {1,2,3,4};

    // Enemy avoids magic if they don't have enough MP
    if (enemy.getMp() < darkMagic.getMpCost())
        enemyActions[1] = 0;
    if (enemy.getMp() < 20)
        enemyActions[2] = 0;

    // Avoids healing if high HP
    if (enemy.getHp() > 70)
        enemyActions[2] = 0;

    // Avoids meditating if high MP
    if (enemy.getMp() > 20)
        enemyActions[3] = 0;

    // Selects a random non-disabled action by looping the value of enemyAction to the value of the chosen action until it reaches a non-zero value
    int enemyAction = 0;
    while (enemyAction == 0)
    {
        if (int rng = enemyActions[rand() % size(enemyActions)]; rng != 0)
        {
            enemyAction = rng;
            break;
        }
    }
    switch (enemyAction) // List of enemy actions
    {
        case 1: darkMelee.useAttack(enemy, player);
            break;

        case 2: darkMagic.useAttack(enemy, player);
            break;

        case 3: Heal(enemy, 15, 25);
            break;

        case 4: Meditate(enemy, 5, 15);
            break;

        default:
        cout << "Enemy action failed! (" << enemyAction << ")" << endl << endl;
    }
}


//-----------//
// Menu area //
//-----------//
void BattleMenu()
{
    while (battleActive) // Main game loop
    {
    // Player stats
    cout << "----------" << endl;
    cout << player.getName() << endl;
    cout << "HP: " << player.getHp() << endl;
    cout << "MP: " << player.getMp() << endl;
    cout << "----------" << endl << endl;

    // Enemy Stats
    cout << "----------" << endl;
    cout << enemy.getName() << endl;
    cout << "HP: " << enemy.getHp() << endl;
    cout << "MP: " << enemy.getMp() << endl;
    cout << "----------" << endl << endl;

    this_thread::sleep_for(chrono::seconds(1));

    // Battle Options
    cout << "1. Attack" << endl;
    cout << "2. Magic (Cost: 15MP)" << endl;
    cout << "3. Heal (Cost: 20MP)" << endl;
    cout << "4. Meditate" << endl << endl;
    cout << "Your choice: ";

    int action;
    while (!(cin >> action))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number: ";
    }
        system("cls");

        // Player's turn
        switch (action)
        {
            case 1: // Basic Attack
            melee.useAttack(player, enemy);
                break;

            case 2: // Magic Attack
            magic.useAttack(player, enemy);
                break;

            case 3: // Healing
            Heal(player, 15, 25);
                break;

            case 4: // Meditating
            Meditate(player, 10, 20);
                break;

            case 69420: // Secret amazing attack
                cout << "YOU used LIGHT THAT BURNS MY EYES!" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                cout << ".";
                this_thread::sleep_for(chrono::seconds(1));
                cout << ".";
                this_thread::sleep_for(chrono::seconds(1));
                cout << ".";
                this_thread::sleep_for(chrono::seconds(1));
                cout << "!";
                this_thread::sleep_for(chrono::seconds(1));
                for (int i = 0; i < 100; i++) {
                    cout << endl;
                    for (int j = 0; j < 100; j++)
                        cout << "#####";
                }
                    exit(-1);

            default:
            cout << "Invalid Action!" << endl;
            continue;
        }
        if (!enemy.isAlive())
            EndBattle(player);

        this_thread::sleep_for(chrono::seconds(1));
        if (battleActive)
            EnemyTurn();
            this_thread::sleep_for(chrono::seconds(1));
        if (!player.isAlive())
            EndBattle(enemy);
    }
}


//------------------//
// Game start & end //
//------------------//
int main()
{
    srand(time(nullptr));
    BattleMenu();
    system("pause");
    return 0;
}