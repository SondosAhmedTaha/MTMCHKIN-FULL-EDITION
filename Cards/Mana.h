#ifndef WORKING_EX4_MANA_H
#define WORKING_EX4_MANA_H

#include "Card.h"

/**
 * the details of the Mana card.
 */
const std::string Mana_Name = "Mana";
const int Mana_buff = 10;

class Mana : public Card{
public:
    /**
     * Constructor + The Big 3 for Mana.
     */
    Mana();
    Mana (const Mana& other) = default;
    Mana& operator=(const Mana& other) = default;
    ~Mana() override = default;

    /**
     * Creates a new cloned Mana and returns a pointer to it.
     * @return a pointer to the new cloned Mana.
     */
    Card * clone() const override;

    /**
     * Encountering the Mana card. (the player will receive the mana if he is a healer!).
     * @param player the player that will encounter the mana card.
     */
    void applyEncounter(Player &player) const override;

};

#endif //WORKING_EX4_MANA_H