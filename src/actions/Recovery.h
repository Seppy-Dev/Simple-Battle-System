//
// Created by Skye on 30/05/2025.
//

#ifndef MEDITATE_H
#define MEDITATE_H

#include "../entities/Battler.h"


class Recovery {
public:
    Recovery(const string &name, const int minRecover, const int maxRecover) : name{name}, minRecover{minRecover}, maxRecover{maxRecover} {};
    void use(Battler& user) const;

    [[nodiscard]] const string& getName() const {return name;}
    [[nodiscard]] int getMinRecover() const {return minRecover;}
    [[nodiscard]] int getMaxRecover() const {return maxRecover;}

private:
    const string& name;
    int minRecover;
    int maxRecover;
};

#endif //MEDITATE_H
