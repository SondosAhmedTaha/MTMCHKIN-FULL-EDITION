
#include "Gremlin.h"

Gremlin::Gremlin() : BattleCard(Gremlin_Name, Gremlin_Power, Gremlin_Loot, Gremlin_DamageOnLoss) {

}

Card* Gremlin::clone() const {
    return new Gremlin(*this);
}

