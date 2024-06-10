#ifndef WORKING_EX4_DRAGON_H
#define WORKING_EX4_DRAGON_H

#include "BattleCard.h"

/**
 * the stats of the Dragon.
 */
const std::string Dragon_Name = "Dragon";
const int Dragon_Loot = 1000;
const int Dragon_Power = 25;
const int Dragon_DamageOnDefeat = 999;


class Dragon : public BattleCard{
public:
    /**
     * Constructor + The Big 3 for Dragon.
     */
    Dragon();
    Dragon (const Dragon& other) = default;
    Dragon& operator=(const Dragon& other) = default;
    ~Dragon() override = default;

    /**
     * Creates a new cloned Dragon and returns a pointer to it.
     * @return a pointer to the new cloned Dragon.
     */
    Card * clone() const override;

    /**
     * Encountering the Dragon. if you lose you die.
     * @param player - the player that will fight the dragon.
     */
    void applyEncounter(Player &player) const override;

    /**
     * prints the stats of the Dragon.
     * @param os output stream.
     */
    void printInfo(std::ostream &os) const override;

};
#endif //WORKING_EX4_DRAGON_H