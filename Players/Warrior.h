#ifndef EX4_FOR_TESTING_WARRIOR_H
#define EX4_FOR_TESTING_WARRIOR_H

#include "Player.h"
class Warrior: public Player{
public:
    /**
    * constructor for the Player class
    *
    * @param name_arg- the name of the new Player.
    * @param force_arg- the force of the new Player. (the default value is 5)
    * @param maxHP_arg- the maximum HP the new Player can have. (the default value is 100)
    *
    * @return - a new level 1 Player with 0 coins, force equal to force_arg and HP equal to the maxHP_arg entered.
    * **/
    Warrior(std :: string name_arg,int maxHP_arg=100, int force_arg=5);

    Warrior(const Warrior&)  =default; // Copy Constructor
    ~Warrior() override =default; //Destructor
    Warrior& operator=(const Warrior& other) =default; // Assigment operator
    /**
    * a virtual copy constructor
    * @return pointer to the object that was created
    */
    Player* clone() const override;
    /**
    * Gets the AttackStrength of the warrior.
    *
    * **/
    int getAttackStrength() const override;
private:
    /**
     * prints the details of the current Ninja to ostream
     * @param ostream the output stream
     */
    void printInfo (std::ostream& ostream) const override;
};

#endif //EX4_FOR_TESTING_WARRIOR_H
