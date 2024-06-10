#ifndef WORKING_EX4_BARFIGHT_H
#define WORKING_EX4_BARFIGHT_H

#include "Card.h"
/**
 * the details of the Barfight card.
 */
const std::string Barfight_Name = "Barfight";
const int Barfight_dmg = 10 ;

class Barfight : public Card{
public:
    /**
     * Constructor + The Big 3 for Barfight.
     */
    Barfight();
    Barfight (const Barfight& other) = default;
    Barfight& operator=(const Barfight& other) = default;
    ~Barfight() override = default;

    /**
     * Creates a new cloned Barfight and returns a pointer to it.
     * @return a pointer to the new cloned Barfight.
     */
    Card * clone() const override;

    /**
     * Encountering the Barfight (getting into a bar fight you don't take damage if you are a warrior!).
     * @param player the player that be getting into a bar fight.
     */
    void applyEncounter(Player &player) const override;
};

#endif //WORKING_EX4_BARFIGHT_H