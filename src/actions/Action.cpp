//
// Created by Skye on 02/06/2025.
//

#include "Action.h"

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
    accuracy = data.value("accuracy", 100);
    critRate = data.value("critRate", 10);
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