#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <thread>
#include "Attack.h"
#include "Battler.h"

using namespace std;

bool battleActive = true;

Battler player("YOU");
Battler enemy("ENEMY");

Attack melee("PUNCH", 5, 12, 0, 90);
Attack magic("MAGIC", 15, 20, 15, 70);
Attack darkMelee("BITE", 8, 14, 0, 80);
Attack darkMagic("DARK MAGIC", 17, 22, 15, 60);

//------------------------//
// Basic Battle Functions //
//------------------------//
// Cause the battle to cease and provide a message depending on the victor
void EndBattle()
{
    if (player.hp > enemy.hp)
        cout << "You win!" << endl << endl;
    else
        cout << "You lose!" << endl << endl;
    battleActive = false;
}


// Healing lets the user recover HP at the cost of some MP
void Heal(const string& user, int& HPTarget, int& MPSource, int min, int max)
{
    if (MPSource < 20)
        cout << user << " doesn't have enough MP to heal!" << endl << endl;

    else if (HPTarget == 100)
        cout << user << "'s HP is already full!" << endl << endl;

    else
    {
        int amount = RandomNumber(min, max);
        HPTarget += amount;
        if (HPTarget > 100)
            HPTarget = 100;
        MPSource -= 20;
        cout << user << " healed " << amount << " HP!" << endl << endl;
    }
}

// Meditating lets the user recover some MP
void Meditate(const string& user, int& MPTarget, int min, int max)
{
    if (MPTarget == 100)
        cout << user << "'s MP is already full!" << endl << endl;

    else
    {
        int amount = RandomNumber(min, max);
        MPTarget += amount;
        if (MPTarget > 100)
            MPTarget = 100;
        cout << user << " recovered " << amount << " MP!" << endl << endl;
    }
}



//-----------------------//
// Enemy action selector //
//-----------------------//
void EnemyTurn()
{
    int enemyActions[] = {1,2,3,4};

    // Enemy avoids magic if they don't have enough MP
    if (enemy.mp < darkMagic.mpCost)
        enemyActions[1] = 0;
    if (enemy.mp < 20)
        enemyActions[2] = 0;

    // Avoids healing if high HP
    if (enemy.hp > 70)
        enemyActions[2] = 0;

    // Avoids meditating if high MP
    if (enemy.mp > 20)
        enemyActions[3] = 0;

    // Selects a random non-disabled action by looping the value of enemyAction to the value of the chosen action until it reaches a non-zero value
    int enemyAction = 0;
    while (enemyAction == 0)
    {
        if (int rng = enemyActions[RandomNumber(0,(size(enemyActions) - 1))]; rng != 0)
        {
            enemyAction = rng;
            break;
        }
    }
    switch (enemyAction) // List of enemy actions
    {
        case 1: Attack(enemy, player, darkMelee);
            break;

        case 2: Attack(enemy, player, darkMagic);
            break;

        case 3: Heal("ENEMY", enemy.hp, enemy.mp, 15, 25);
            break;

        case 4: Meditate("ENEMY", enemy.mp, 5, 15);
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
    LoadAttacks();
    // Player stats
    cout << "----------" << endl;
    cout << "YOU" << endl;
    cout << "HP: " << player.hp << endl;
    cout << "MP: " << player.mp << endl;
    cout << "----------" << endl << endl;

    // Enemy Stats
    cout << "----------" << endl;
    cout << "ENEMY" << endl;
    cout << "HP: " << enemy.hp << endl;
    cout << "MP: " << enemy.mp << endl;
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

        // Player's turn
        switch (action)
        {
            case 1: // Basic Attack
            Attack(player, enemy, melee);
                break;

            case 2: // Magic Attack
            Attack(player, enemy, magic);
                break;

            case 3: // Healing
            Heal("YOU", player.hp, player.mp, 15, 25);
                break;

            case 4: // Meditating
            Meditate("YOU", player.mp, 10, 20);
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


        this_thread::sleep_for(chrono::seconds(1));
        if (battleActive)
            EnemyTurn();
            this_thread::sleep_for(chrono::seconds(1));
    }
}


//------------------//
// Game start & end //
//------------------//
int main()
{
    srand(time(nullptr));
    LoadAttacks();
    BattleMenu();
    system("pause");
    return 0;
}