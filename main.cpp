#include <iostream>
#include <chrono>
#include <thread>
#include "SkyesRandomStuff/RandomNumber.h"

using namespace std;
using namespace srs;

// Silly goofy global variables
// These shud probs be a class/struct or smth but idrk how to do that properly in C++ yet
int playerHP = 100;
int playerMP = 100;
int enemyHP = 100;
int enemyMP = 100;
bool battleActive = true;


//------------------------//
// Basic Battle Functions //
//------------------------//

// Cause the battle to cease and provide a message depending on the victor
void EndBattle()
{
    if (playerHP > enemyHP)
    {
        cout << "You win!" << endl << endl;
    }
    else
        cout << "You lose!" << endl << endl;
    battleActive = false;
}

// Used to return a bool which decides if attacks miss or not in attack functions
bool MissChance(int accuracy)
{
    int rng = RandomNumber(1,100);
    if (rng > accuracy)
    {
        return true;
    }
    else
        return false;
}

//----------------//
// Battle Actions //
//----------------//


void Attack(const string& attackName, const string& user, int& hpTarget, int hpDamageMin, int hpDamageMax, int mpCost, int& mpSource, int accuracy)
{
    if (mpSource < mpCost)
        cout << user << " doesn't have enough MP to use " << attackName << "!" << endl << endl;
    else if (MissChance(accuracy))
    {
        mpSource -= mpCost;
        cout << user << " used " << attackName << "... but missed!" << endl << endl;
    }
    else
    {
        mpSource -= mpCost;
        int damage = RandomNumber(hpDamageMin, hpDamageMax);
        hpTarget -= damage;
        cout << user << " used " << attackName << " and dealt " << damage << " damage!" << endl << endl;
        if (hpTarget <= 0)
            EndBattle();
    }
}


// Healing lets the user recover HP at the cost of some MP
void Heal(const string& user, int& HPTarget, int& MPSource) // Heal HP at the cost of MP
{
    if (MPSource < 10)
    {
        cout << user << " doesn't have enough MP to heal!" << endl << endl;
    }
    else if (HPTarget == 100)
    {
        cout << user << "'s HP is already full!" << endl << endl;
    }
    else
    {
        int amount = RandomNumber(25, 35);
        HPTarget += amount;
        if (HPTarget > 100)
        {
            HPTarget = 100;
        }
        MPSource -= 10;
        cout << user << " healed " << amount << " HP!" << endl << endl;
    }
}


//-----------------------//
// Enemy action selector //
//-----------------------//
void EnemyTurn()
{
    int enemyActions[] = {1,2,3};

    // Enemy avoids magic if they don't have enough MP
    if (enemyMP < 10)
        enemyActions[2] = 0;
    if (enemyMP < 15)
        enemyActions[1] = 0;

    // Enemy avoids healing if they have high HP
    if (enemyHP > 80)
        enemyActions[2] = 0;

    // Selects a random non-disabled action
    int enemyAction = 0;
    while (enemyAction == 0)
    {
        int rng = enemyActions[RandomNumber(0,2)];
        if (rng != 0)
        {
            enemyAction = rng;
            break;
        }
    }
    switch (enemyAction)
    {
        case 1: Attack("Bite", "Enemy", playerHP, 8, 18, 0, enemyMP, 80);
        break;

        case 2: Attack("Magic", "Enemy", playerHP, 20, 30, 15, enemyMP, 60);
        break;

        case 3: Heal("Enemy", enemyHP, enemyMP);
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
    cout << "YOU" << endl;
    cout << "HP: " << playerHP << endl;
    cout << "MP: " << playerMP << endl << endl;

    // Enemy Stats
    cout << "ENEMY" << endl;
    cout << "HP: " << enemyHP << endl;
    cout << "MP: " << enemyMP << endl << endl;

    // Battle Options
    cout << "1. Attack" << endl;
    cout << "2. Magic (Cost: 15MP)" << endl;
    cout << "3. Heal (Cost: 10MP)" << endl;
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
            Attack("Punch", "Player", enemyHP, 5, 12, 0, playerMP, 80);
            break;

            case 2: // Magic Attack
            Attack("Magic", "Player", enemyHP, 15, 24, 15, playerMP, 60);
            break;

            case 3: // Healing
            Heal("Player", playerHP, playerMP);
            break;

            default:
            cout << "Invalid Action!" << endl;
            continue;
        }
        if (playerHP <= 0 || enemyHP <= 0)
        {
            EndBattle();
            break;
        }

        this_thread::sleep_for(chrono::seconds(1));

        // Enemy's turn
        EnemyTurn();
        this_thread::sleep_for(chrono::seconds(1));
        if (playerHP <= 0 || enemyHP <= 0)
        {
            EndBattle();
            break;
        }
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