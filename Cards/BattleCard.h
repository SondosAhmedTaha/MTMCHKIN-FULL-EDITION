#ifndef WORKING_EX4_BATTLECARD_H
#define WORKING_EX4_BATTLECARD_H


#include "Card.h"

class BattleCard : public Card{
public:
    /**
     * A constructor for BattleCard.
     * @param name the name of the monster.
     * @param power the power of the monster.
     * @param loot the amount of loot the player receives when he beats the monster.
     * @param damage_on_loss the amount of HealthPoints that the player will lose when the monster beats him.
     */
    BattleCard(std::string name, int power, int loot, int damage_on_loss);

    /**
     * The Big 3 are all set to default, notice we override the destructor because we inherit Card class.
     */
    BattleCard(const BattleCard& other) = default;
    BattleCard& operator=(const BattleCard& other) = default;
    ~BattleCard() override = default;

    /**
     * Encountering the monster in a fight.
     * @param player - the player that will face the monster.
     */
    void applyEncounter(Player &player) const override;
    /**
     * printing the details of the monster(his name, power, loot, HpOnLoss).
     * @param os - output stream.
     */
    void printInfo(std::ostream &os) const override;


protected:
    int m_Power;
    int m_Loot;
    int m_DamageOnDefeat;
};


#endif //WORKING_EX4_BATTLECARD_H