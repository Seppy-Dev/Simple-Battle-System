#ifndef ACTION_H
#define ACTION_H
#include <string>
#include "nlohmann/json.hpp"

class Battler;

class Action {
public:
    explicit Action(const nlohmann::json& data);

    enum class Type {
        ATTACK,
        RECOVERY
    };
    enum class Category {
        MAGIC,
        ABILITY,
        NULL_CATEGORY
    };
    enum class TargetStat {
        HP,
        MP
    };
    enum class RecoveryType {
        HP,
        MP
    };

    Type getType(const nlohmann::json& jsonProperty);
    Category getCategory(const nlohmann::json& jsonProperty);
    TargetStat getTargetStat(const nlohmann::json& jsonProperty, TargetStat defaultStat);
    RecoveryType getRecoveryType(const nlohmann::json& jsonProperty, RecoveryType defaultType);

    void use(Battler& user, Battler& target) const;

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

    void doAttack(Battler& user, Battler& target) const;
    void doRecovery(Battler& user) const;
};


#endif //ACTION_H
