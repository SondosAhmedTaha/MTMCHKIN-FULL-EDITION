#ifndef WORKING_EX4_GREMLIN_H
#define WORKING_EX4_GREMLIN_H

#include "BattleCard.h"
/**
 * the stats of the gremlin.
 */
const std::string Gremlin_Name = "Gremlin";
const int Gremlin_Loot = 2;
const int Gremlin_Power = 5;
const int Gremlin_DamageOnLoss = 10;

class Gremlin : public BattleCard{
public:
    /**
     * Constructor + The Big 3 for Gremlin.
     */
    Gremlin();
    Gremlin (const Gremlin& other) = default;
    Gremlin& operator=(const Gremlin& other) = default;
    ~Gremlin() override = default;

    /**
     * Creates a new cloned gremlin and returns a pointer to it.
     * @return a pointer to the new cloned gremlin.
     */
    Card * clone() const override;

};

#endif //WORKING_EX4_GREMLIN_H