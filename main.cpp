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
bool MissChance(int min, int max, int missNumber)
{
    int rng = RandomNumber(min, max);
    if (rng == missNumber)
    {
        return true;
    }
    else
        return false;
}


//----------------//
// Battle Actions //
//----------------//

// Basic attack which deals low damage & doesn't cost MP
void Attack(const string& user, int& HPTarget)
{
    if (MissChance(1,10,6))
    {
        cout << user << " missed!" << endl << endl;
    }
    else
    {
        int damage = RandomNumber(5, 10);
        HPTarget -= damage;
        cout << user << " attack dealt " << damage << " HP!" << endl << endl;
        if (HPTarget <= 0)
            EndBattle();
    }

}

// Stronger attack which deals higher damage at the cost of some MP
void Magic(const string& user, int& HPTarget, int& MPSource) // Perform a stronger attack at the cost of MP
{
    if (MPSource < 10)
    {
        cout << user << " doesn't have enough MP to cast a spell!" << endl << endl;
    }

    else if (MissChance(1, 5, 3))
    {
        cout << user << " missed!" << endl << endl;
    }
    else
    {
        int damage = RandomNumber(12, 22);
        HPTarget -= damage;
        MPSource -= 10;
        cout << user << " magic attack dealt " << damage << " HP!" << endl << endl;
        if (HPTarget <= 0)
            EndBattle();
    }
}

// Healing lets the user recover HP at the cost of some MP
void Heal(const string& user, int& HPTarget, int& MPSource) // Heal HP at the cost of MP
{
    if (MPSource < 20)
    {
        cout << user << " doesn't have enough MP to heal!" << endl << endl;
    }
    else if (HPTarget == 100)
    {
        cout << user << "'s HP is already full!" << endl << endl;
    }
    else
    {
        int amount = RandomNumber(10, 20);
        HPTarget += amount;
        if (HPTarget > 100)
        {
            HPTarget = 100;
        }
        MPSource -= 20;
        cout << user << " healed " << amount << " HP!" << endl << endl;
    }
}


//-----------------------//
// Enemy action selector //
//-----------------------//
void EnemyTurn()
{
    switch (int enemyAction = RandomNumber(1, 3))
    {
        case 1: Attack("Enemy", playerHP);
        break;

        case 2: Magic("Enemy", playerHP, enemyMP);
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
    cout << "2. Magic (Cost: 10MP)" << endl;
    cout << "3. Heal (Cost: 20MP)" << endl;
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
            case 1:
            Attack("Player", enemyHP);
            break;

            case 2:
            Magic("Player", enemyHP, playerMP);
            break;

            case 3:
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