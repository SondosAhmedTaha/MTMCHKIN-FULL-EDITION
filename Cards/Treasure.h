#ifndef WORKING_EX4_TREASURE_H
#define WORKING_EX4_TREASURE_H

#include "Card.h"
/**
 * the details of the Treasure card.
 */
const std::string Treasure_Name = "Treasure";
const int Treasure_Loot = 10;

class Treasure : public Card{
public:
    /**
     * Constructor + The Big 3 for Treasure.
     */
    Treasure();
    Treasure (const Treasure& other) = default;
    Treasure& operator=(const Treasure& other) = default;
    ~Treasure() override = default;

    /**
     * Creates a new cloned Treasure and returns a pointer to it.
     * @return a pointer to the new cloned Treasure.
     */
    Card * clone() const override;

    /**
     * Encountering the Treasure card. (You found a treasure!).
     * @param player the player that will find the treasure.
     */
    void applyEncounter(Player &player) const override;

};

#endif //WORKING_EX4_TREASURE_H