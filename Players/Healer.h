#ifndef EX4_FOR_TESTING_HEALER_H
#define EX4_FOR_TESTING_HEALER_H

#include "Player.h"

class Healer : public Player{

    Healer(const Healer&)  =default; // Copy Constructor
    //Destructor
    Healer& operator=(const Healer& other) =default; // Assigment operator
    /**
    * a virtual copy constructor
    * @return pointer to the object that was created
    */
    Player* clone() const override;
    /**
    * Restores the HP of the Healer by a specified amount.
    *
    * @param extra_HP- the amount to be added to the HP of the player.
    * **/
    void heal(int extra_HP) override;

public:
    ~Healer() override =default;

/**
 * constructor for the Healer class
 *
 * @param name_arg- the name of the new Player.
 * @param force_arg- the force of the new Player. (the default value is 5)
 * @param maxHP_arg- the maximum HP the new Player can have. (the default value is 100)
 *
 * @return - a new level 1 Player with 0 coins, force equal to force_arg and HP equal to the maxHP_arg entered.
 * **/
    Healer(std :: string name_arg,int maxHP_arg=100, int force_arg=5);

private:
    /**
     * prints the details of the current Ninja to ostream
     * @param ostream the output stream
     */
    void printInfo (std::ostream& ostream) const override;

};

#endif //EX4_FOR_TESTING_HEALER_H
