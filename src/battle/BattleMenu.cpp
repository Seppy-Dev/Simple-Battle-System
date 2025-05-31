//
// Created by Skye on 31/05/2025.
//

#include "BattleMenu.h"
#include <iostream>
#include <limits>
#include <thread>

void printStats(const Battler& battler) {
    std::cout << "----------\n" <<
              battler.getName() << "\n" <<
              "HP: " << battler.getHp() << "\n" <<
              "MP: " << battler.getMp() << "\n" <<
              "----------\n" << std::endl;
}

void listActions() {
    cout << "1. Attack\n"
         << "2. Magic (Cost: " << magic.getMpCost() << ")\n"
         << "3. Heal (Cost: " << heal.getMpCost() <<")\n"
         << "4. Recover\n" << endl << endl

         << "Your choice: ";
}

void selectAction() {
    while (true) {
    int action;
    while (!(cin >> action)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number: ";
    }

    system("cls");

    switch (action) {
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
    }
}