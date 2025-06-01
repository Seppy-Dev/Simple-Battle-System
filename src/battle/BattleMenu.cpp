//
// Created by Skye on 31/05/2025.
//

#include "BattleMenu.h"
#include <iostream>
#include <limits>
#include <thread>

void BattleMenu::printStats(const Battler& battler) {
}

void BattleMenu::listActions() {

}

void selectAction() {
    while (true) {
    int action;
    while (!(std::cin >> action)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a number: ";
    }

        // case 69420: // Secret amazing attack
        //      std::cout << "YOU used LIGHT THAT BURNS MY EYES!" << std::endl;
        //      std::this_thread::sleep_for(std::chrono::seconds(2));
        //      std::cout << ".";
        //      std::this_thread::sleep_for(std::chrono::seconds(1));
        //      std::cout << ".";
        //      std::this_thread::sleep_for(std::chrono::seconds(1));
        //      std::cout << ".";
        //      std::this_thread::sleep_for(std::chrono::seconds(1));
        //      std::cout << "!";
        //      std::this_thread::sleep_for(std::chrono::seconds(1));
        //      for (int i = 0; i < 100; i++) {
        //         std::cout << std::endl;
        //         for (int j = 0; j < 100; j++)
        //             std::cout << "#####";
        //      exit(-1);
    }
}