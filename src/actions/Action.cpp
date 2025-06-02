//
// Created by Skye on 02/06/2025.
//

#include "Action.h"
#include "../entities/Battler.h"
#include <iostream>

Action::Action(const nlohmann::json& data) {
    if (!data.contains("type")) {
        throw std::invalid_argument("Action file missing required field: type");
    }
    type = getType(data["type"]);

    if (!data.contains("category")) {
        throw std::invalid_argument("Action file missing required field: category");
    }
    category = getCategory(data["category"]);

    if (!data.contains("name")) {
        throw std::invalid_argument("Action file missing required field: name");
    }
    name = data["name"];

    mpCost = data.value("mpCost", 0);
    hpCost = data.value("hpCost", 0);
    priority = data.value("priority", 0);

    if (type == Type::ATTACK) {
        loadAttackProperties(data);
    }
    else {
        loadRecoveryProperties(data);
    }

}
Action::Type Action::getType(const nlohmann::json& jsonProperty) {
    if (jsonProperty == "ATTACK") {
        return Type::ATTACK;
    }
    if (jsonProperty == "RECOVERY") {
        return Type::RECOVERY;
    }
    throw std::invalid_argument("Invalid action type: " + jsonProperty.dump());
}
Action::Category Action::getCategory(const nlohmann::json& jsonProperty) {
    if (jsonProperty == "MAGIC") return Category::MAGIC;
    if (jsonProperty == "ABILITY") return Category::ABILITY;
    throw std::invalid_argument("Invalid category: " + jsonProperty.dump());
}

Action::TargetStat Action::getTargetStat(const nlohmann::json& jsonProperty, const TargetStat defaultStat) {
    if (jsonProperty == "HP") return TargetStat::HP;
    if (jsonProperty == "MP") return TargetStat::MP;
    else return defaultStat;
}

Action::RecoveryType Action::getRecoveryType(const nlohmann::json& jsonProperty, const RecoveryType defaultType) {
    if (jsonProperty == "HP") return RecoveryType::HP;
    if (jsonProperty == "MP") return RecoveryType::MP;
    else return defaultType;
}

void Action::loadAttackProperties(const nlohmann::json& data) {
    targetStat = getTargetStat(data.value("targetStat", "HP"), TargetStat::HP);
    minDamage = data.value("minDamage", 1);
    maxDamage = data.value("maxDamage", minDamage);
    accuracy = std::clamp(data.value("accuracy", 100), 0, 100);
    critRate = std::clamp(data.value("critRate", 10), 0 , 100);
    multiHitMin = data.value("multiHitMin", 1);
    multiHitMax = data.value("multiHitMax", 1);
    hpDrainPercent = data.value("hpDrainPercent", 0);
    mpDrainPercent = data.value("mpDrainPercent", 0);
}

void Action::loadRecoveryProperties(const nlohmann::json& data) {
    minRecovery = data.value("minRecovery", 1);
    maxRecovery = data.value("maxRecovery", minRecovery);
    recoveryType = getRecoveryType(data.value("recoveryType", "HP"), RecoveryType::HP);
}

bool MissChance(int accuracy)
{
    int rng = 1 + (rand() % 100);
    if (rng > accuracy)
        return true;
    return false;
}
bool critChance(int critRate)
{
    int rng = 1 + (rand() % 100);
    if (rng > critRate)
        return true;
    return false;
}

void Action::doAttack(Battler& user, Battler& target) const {
    if (user.getMp() < mpCost)
        std::cout << user.getName() << " doesn't have enough MP to use " << name << "!\n" << std::endl;
    if (user.getHp() < hpCost)
        std::cout << user.getName() << " doesn't have enough HP to use " << name << "!\n" << std::endl;
    
    else if (MissChance(accuracy)) {
        user.reduceMp(mpCost);
        std::cout << user.getName() << " used " << name << "... but missed!\n" << std::endl;
    }
    else if (MissChance(accuracy)) {
        user.reduceHp(hpCost);
        std::cout << user.getName() << " used " << name << "... but missed!\n" << std::endl;
    }

    else {
        user.reduceMp(mpCost);
        user.reduceHp(hpCost);
        int hitTimes;
        hitTimes = multiHitMin + (rand() % (multiHitMax - multiHitMin + 1));
        for (int hit = 0; hit < hitTimes; hit++) {
            int damage = minDamage + (rand() % (maxDamage - minDamage + 1));
            if (critChance(critRate)) {
                damage *= 1.5;
                std::cout << "A CRITITCAL HIT!" << std::endl;
            }
            
            if (targetStat == TargetStat::HP) {
                target.reduceHp(damage);
                std::cout << user.getName() << " used " << name << " and dealt " << damage << " MP damage!\n" << std::endl;
            }
            else if (targetStat == TargetStat::MP) {
                target.reduceMp(damage);
                std::cout << user.getName() << " used " << name << " and dealt " << damage << " HP damage!\n" << std::endl;
            }

            if (hpDrainPercent != 0) {
                int recoverAmount = ((damage * hpDrainPercent) / 100);
                user.recoverHp(recoverAmount);
                std::cout << user.getName() << " stole " << recoverAmount << " HP!" << std::endl;
            }
            if (mpDrainPercent != 0) {
                int recoverAmount = ((damage * mpDrainPercent) / 100);
                user.recoverMp(recoverAmount);
                std::cout << user.getName() << " stole " << recoverAmount << " MP!" << std::endl;
            }
        }
    }
}

void Action::doRecovery(Battler& user) const {
    int amount = minRecovery + (rand() % (maxRecovery - minRecovery + 1));
    if (recoveryType == RecoveryType::HP) {
        user.recoverHp(amount);
        std::cout << user.getName() << " used " << name << " and recovered " << amount << " HP!";
    }
    else if (recoveryType == RecoveryType::MP) {
        user.recoverMp(amount);
        std::cout << user.getName() << " used " << name << " and recovered " << amount << " MP!";
    }
}

void Action::use(Battler& user, Battler& target) const {
    switch (type) {
        case Type::ATTACK:
            doAttack(user, target);
            break;
        case Type::RECOVERY:
            doRecovery(user);
            break;
    }
}
