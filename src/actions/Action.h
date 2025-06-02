#ifndef ACTION_H
#define ACTION_H
#include <string>

#include "nlohmann/json.hpp"


class Action {
public:
    explicit Action(const nlohmann::json& data);

    enum class Type {
        ATTACK,
        RECOVERY
    };
    enum class Category {
        MAGIC,
        ABILITY
    };
    enum class TargetStat {
        HP,
        MP
    };
    enum class RecoveryType {
        HP,
        MP
    };

    static Type getType(const nlohmann::json& jsonProperty);
    static Category getCategory(const nlohmann::json& jsonProperty);
    static TargetStat getTargetStat(const nlohmann::json& jsonProperty, TargetStat defaultStat);
    static RecoveryType getRecoveryType(const nlohmann::json& jsonProperty, RecoveryType defaultType);

private:
    Type type;
    Category category;
    std::string name;

    int mpCost;
    int hpCost;
    int priority;

    TargetStat targetStat;
    int minDamage;
    int maxDamage;
    int accuracy;
    int critRate;
    int multiHitMin;
    int multiHitMax;
    int hpDrainPercent;
    int mpDrainPercent;

    int minRecovery;
    int maxRecovery;
    RecoveryType recoveryType;

    void loadAttackProperties(const nlohmann::json& data);
    void loadRecoveryProperties(const nlohmann::json& data);
};


#endif //ACTION_H
