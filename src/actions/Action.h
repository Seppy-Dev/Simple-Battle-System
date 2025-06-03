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

    const Type& getType () const {return type;}
    const Category& getCategory() const {return category;}
    const std::string& getName() const {return name;}
    const TargetStat& getTargetStat() const {return targetStat;}
    const RecoveryType& getRecoveryType() const {return recoveryType;}
    const int& getMpCost() const {return mpCost;}
    const int& getHpCost() const {return hpCost;}
    const int& getPriority() const {return priority;}
    const int& getMinDamage() const {return minDamage;}
    const int& getMaxDamage() const {return maxDamage;}
    const int& getAccuracy() const {return accuracy;}
    const int& getCritRate() const {return critRate;}
    const int& getMultiHitMin() const {return multiHitMin;}
    const int& getMultiHitMax() const {return multiHitMax;}
    const int& getHpDrainPercent() const {return hpDrainPercent;}
    const int& getMpDrainPercent() const {return mpDrainPercent;}
    const int& getMinRecovery() const {return minRecovery;}
    const int& getMaxRecovery() const {return maxRecovery;}

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
    static Type loadType(const nlohmann::json& jsonProperty);
    static Category loadCategory(const nlohmann::json& jsonProperty);
    static TargetStat loadTargetStat(const nlohmann::json& jsonProperty, TargetStat defaultStat);
    static RecoveryType loadRecoveryType(const nlohmann::json& jsonProperty, RecoveryType defaultType);

    void doAttack(Battler& user, Battler& target) const;
    void doRecovery(Battler& user) const;
};


#endif //ACTION_H
