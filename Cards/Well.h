#ifndef WORKING_EX4_WELL_H
#define WORKING_EX4_WELL_H

#include "Card.h"

/**
 * the details of the Well card.
 */
const std::string Well_Name = "Well";
const int Well_dmg = 10;

class Well : public Card{
public:

    /**
     * Constructor + The Big 3 for Well
     */
    Well();
    Well (const Well& other) = default;
    Well& operator=(const Well& other) = default;
    ~Well() override = default;

    /**
     * Creates a new cloned Well and returns a pointer to it.
     * @return a pointer to the new cloned Well.
     */
    Card * clone() const override;

    /**
     * Encountering the Well (falling into it, unless you are a Ninja!).
     * @param player - the player that will fall into the Well.
     */
    void applyEncounter(Player &player) const override;


};

#endif //WORKING_EX4_WELL_H