#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "SkyesRandomStuff/RandomNumber.h"

using namespace std;
using namespace srs;

// Silly goofy global variables
// These shud probs be a class/struct or smth but idrk how to do that properly in C++ yet (sob)
int playerHP = 100;
int playerMP = 100;
int enemyHP = 100;
int enemyMP = 100;
bool battleActive = true;

// Flavour text for certain attacks
string enemyAttackText[] = {"BITE", "SCRATCH"};
string enemyMagicText[] = {"FIREBALL", "DARK MAGIC", "LIGHTNING"};
string playerAttackText[] = {"PUNCH", "KICK"};
string playerMagicText[] = {"FIREBALL", "LIGHT MAGIC", "LIGHTNING"};

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
// Basic attack calculator, inputs can be customised to create any simple attack
void Attack(const string attackText[], int attackTextRange, const string& user, int& hpTarget, int hpDamageMin, int hpDamageMax, int mpCost, int& mpSource, int accuracy)
{
    string attackName = attackText[RandomNumber(0, attackTextRange - 1)];

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
void Heal(const string& user, int& HPTarget, int& MPSource, int min, int max)
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
    if (enemyMP < 10)
        enemyActions[2] = 0;
    if (enemyMP < 20)
        enemyActions[1] = 0;

    // Avoids healing if high HP
    if (enemyHP > 70)
        enemyActions[2] = 0;

    // Avoids meditating if high MP
    if (enemyMP > 20)
        enemyActions[3] = 0;

    // Selects a random non-disabled action by looping the value of enemyAction to the value of the chosen action until it reaches a non-zero value
    int enemyAction = 0;
    while (enemyAction == 0)
    {
        int rng = enemyActions[RandomNumber(0,(size(enemyActions) - 1))];
        if (rng != 0)
        {
            enemyAction = rng;
            break;
        }
    }
    switch (enemyAction) // List of enemy actions
    {
        case 1: Attack(enemyAttackText, size(enemyAttackText), "ENEMY", playerHP, 5, 12, 0, enemyMP, 85);
            break;

        case 2: Attack(enemyMagicText, size(enemyMagicText),"ENEMY", playerHP, 15, 20, 15, enemyMP, 75);
            break;

        case 3: Heal("ENEMY", enemyHP, enemyMP, 15, 25);
            break;

        case 4: Meditate("ENEMY", enemyMP, 5, 15);
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
    cout << "----------" << endl;
    cout << "ENEMY" << endl;
    cout << "HP: " << enemyHP << endl;
    cout << "MP: " << enemyMP << endl;
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
            Attack(playerAttackText, size(playerAttackText), "YOU", enemyHP, 5, 12, 0, playerMP, 90);
                break;

            case 2: // Magic Attack
            Attack(enemyMagicText, size(playerMagicText),"YOU", enemyHP, 15, 20, 15, playerMP, 70);
                break;

            case 3: // Healing
            Heal("YOU", playerHP, playerMP, 15, 25);
                break;

            case 4: // Meditating
            Meditate("YOU", playerMP, 10, 20);
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