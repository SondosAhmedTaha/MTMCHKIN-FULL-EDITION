#ifndef EX4_FOR_TESTING_NINJA_H
#define EX4_FOR_TESTING_NINJA_H

#include "Player.h"

class Ninja: public Player{

    Ninja(const Ninja&)  =default; // Copy Constructor
    //Destructor
    Ninja& operator=(const Ninja& other) =default; // Assigment operator
    /**
    * a virtual copy constructor
    * @return pointer to the object that was created
    */
    Player* clone() const override;
    /**
    * Increases the coins of the Ninja by twice the specified amount.
    *
    * @param extra_coins- the amount of coins to be added to the player.
    * **/
    void addCoins(int extra_coins) override;

public:
    ~Ninja() override =default;

/**
 * constructor for the Player class
 *
 * @param name_arg- the name of the new Player.
 * @param force_arg- the force of the new Player. (the default value is 5)
 * @param maxHP_arg- the maximum HP the new Player can have. (the default value is 100)
 *
 * @return - a new level 1 Player with 0 coins, force equal to force_arg and HP equal to the maxHP_arg entered.
 * **/
    Ninja(std :: string name_arg,int maxHP_arg=100, int force_arg=5);

private:
    /**
     * prints the details of the current Ninja to ostream
     * @param ostream the output stream
     */
    void printInfo (std::ostream& ostream) const override;
};

#endif //EX4_FOR_TESTING_NINJA_H
