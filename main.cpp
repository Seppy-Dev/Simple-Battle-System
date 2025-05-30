#include <iostream>
#include <chrono>
#include <thread>

#include "src/actions/Attack.h"
#include "src/entities/Battler.h"
#include "src/actions/Heal.h"
#include "src/actions/Recover.h"

using namespace std;

bool battleActive = true;

Battler player("PLAYER", 100, 100);
Battler enemy("ENEMY", 100, 100);

Attack melee("PUNCH", 5, 12, 0, 90);
Attack magic("MAGIC", 15, 20, 15, 70);
Attack darkMelee("BITE", 8, 14, 0, 80);
Attack darkMagic("DARK MAGIC", 17, 22, 15, 60);

Heal heal("HEAL", 15, 25, 20);
Heal bigHeal("BIG HEAL", 30, 50, 35);
Heal maxHeal("SUPER HEAL", 70, 100, 50);

Recover recover("MEDITATE", 10, 15);
Recover zenZone("ZEN ZONE", 20, 30);

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
// Enemy action selector // //TODO: Clear this fucking shit up oh my god
//-----------------------//
void EnemyTurn()
{
    int enemyActions[] = {1,2,3,4};

    // Enemy avoids magic if they don't have enough MP
    if (enemy.getMp() < darkMagic.getMpCost())
        enemyActions[1] = 0;
    if (enemy.getMp() < heal.getMpCost())
        enemyActions[2] = 0;

    // Avoids healing if high HP
    if (enemy.getHp() > 70)
        enemyActions[2] = 0;

    // Avoids meditating if high MP
    if (enemy.getMp() > 20)
        enemyActions[3] = 0;


    int enemyAction = 0;
    while (enemyAction == 0)
    {
        if (int rng = enemyActions[rand() % size(enemyActions)]; rng != 0)
        {
            enemyAction = rng;
            break;
        }
    }
    switch (enemyAction)
    {
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


//-----------//
// Menu area //
//-----------//
void BattleMenu()
{
    while (battleActive)
    {
    cout << "----------" << endl;
    cout << player.getName() << endl;
    cout << "HP: " << player.getHp() << endl;
    cout << "MP: " << player.getMp() << endl;
    cout << "----------" << endl << endl;

    cout << "----------" << endl;
    cout << enemy.getName() << endl;
    cout << "HP: " << enemy.getHp() << endl;
    cout << "MP: " << enemy.getMp() << endl;
    cout << "----------" << endl << endl;

    this_thread::sleep_for(chrono::seconds(1));

    cout << "1. Attack" << endl;
    cout << "2. Magic (Cost: 15MP)" << endl;
    cout << "3. Heal (Cost: 20MP)" << endl;
    cout << "4. Recover" << endl << endl;
    cout << "Your choice: ";

    int action;
    while (!(cin >> action))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number: ";
    }
        system("cls");

        switch (action)
        {
            case 1:
            melee.use(player, enemy);
                break;

            case 2:
            magic.use(player, enemy);
                break;

            case 3:
            heal.use(player);
                break;

            case 4:
            recover.use(player);
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