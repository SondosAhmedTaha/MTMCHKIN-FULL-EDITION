#ifndef WORKING_EX4_CARD_H
#define WORKING_EX4_CARD_H

#include "../utilities.h"
#include "../Players/Player.h"
#include "../Players/Ninja.h"
#include "../Players/Warrior.h"
#include "../Players/Healer.h"


class Card {
public:
    /**
     * A constructor for card class.
     * @param name - the name of the card.
     */
    Card(std::string name);

    /**
     * The Big 3 are all set to default with a virtual destructor to inherit to sub classes.
     *
     */
    Card(const Card& other) = default;
    Card& operator=(const Card& other) = default;
    virtual ~Card() = default;

    /**
     * pure virtual clone function that clones the card and returns pointer to it.
     * @return a pointer to the cloned card.
     */
    virtual Card* clone() const = 0;

    /**
     * a pure virtual function that applies the encounter with the card.
     * @param player - the player that will encounter the card.
     */
    virtual void applyEncounter(Player& player) const = 0;

    /**
     * A printing function that prints the details of the card.
     * @param os- output stream.
     */
    virtual void printInfo(std::ostream& os) const;


protected:
    std::string m_name;

private:
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};



#endif //WORKING_EX4_CARD_H