#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "SkyesRandomStuff/RandomNumber.h"

using namespace std;

bool battleActive = true;

int RandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Flavour text for certain attacks
vector<string> darkMeleeAttackText = {"BITE", "SCRATCH"};
vector<string> darkMagicText = {"FIREBALL", "DARK MAGIC", "LIGHTNING"};
vector<string> meleeAttackText = {"PUNCH", "KICK"};
vector<string> magicText = {"FIREBALL", "LIGHT MAGIC", "LIGHTNING"};
struct Battler {
    string name;
    int hp = 100;
    int mp = 100;
};
Battler player = {"YOU"};
Battler enemy = {"ENEMY"};


struct Attack {
    string name;
    int minDamage = 1;
    int maxDamage = 1;
    int mpCost = 0;
    int accuracy = 100;
};

//------------------------//
// Basic Battle Functions //
//------------------------//
// Cause the battle to cease and provide a message depending on the victor
void EndBattle()
{
    if (player.hp > enemy.hp)
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
void Attack(Battler& user, Battler& target, const Attack& attack)
{
    if (user.mp < attack.mpCost)
        cout << user.name << " doesn't have enough MP to use " << attack.name << "!" << endl << endl;

    else if (MissChance(attack.accuracy)) {
        user.mp -= attack.mpCost;
        cout << user.name << " used " << attack.name << "... but missed!" << endl << endl;
    }

    else {
        user.mp -= attack.mpCost;
        int damage = RandomNumber(attack.minDamage, attack.maxDamage);
        target.hp -= damage;
        cout << user.name << " used " << attack.name << " and dealt " << damage << " damage!" << endl << endl;

        if (target.hp <= 0)
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
    if (enemy.mp < 10)
        enemyActions[2] = 0;
    if (enemy.mp < 20)
        enemyActions[1] = 0;

    // Avoids healing if high HP
    if (enemy.hp > 70)
        enemyActions[2] = 0;

    // Avoids meditating if high MP
    if (enemy.hp > 20)
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
        EnemyTurn();

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