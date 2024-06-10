#ifndef WORKING_EX4_WITCH_H
#define WORKING_EX4_WITCH_H


#include "BattleCard.h"
/**
 * the stats of the Witch.
 */
const std::string Witch_Name = "Witch";
const int Witch_Loot = 2;
const int Witch_Power = 11;
const int Witch_DamageOnDefeat = 10;
const int Witch_Debuff = 1;

class Witch : public BattleCard{
public:
    /**
     * Constructor + The Big 3 for Witch.
     */
    Witch();
    Witch (const Witch& other) = default;
    Witch& operator=(const Witch& other) = default;
    ~Witch() override = default;

    /**
     * Creates a new cloned Witch and returns a pointer to it.
     * @return a pointer to the new cloned Witch.
     */
    Card * clone() const override;

    /**
     * Encountering the Witch in a fight. if you lose to the witch you will receive a debuff.
     * @param player the player that will fight the witch.
     */
    void applyEncounter(Player &player) const override;

};

#endif //WORKING_EX4_WITCH_H