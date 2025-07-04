//
// Created by Skye on 30/05/2025.
//

#ifndef MEDITATE_H
#define MEDITATE_H

#include "../entities/Battler.h"


class Recover {
public:
    Recover(const string name, int minRecover, int maxRecover) : name{name}, minRecover{minRecover}, maxRecover{maxRecover} {};
    void use(Battler& user);

    const string& getName();
    const int getMinRecover();
    const int getMaxRecover();
private:
    const string& name;
    int minRecover;
    int maxRecover;
};



#endif //MEDITATE_H
