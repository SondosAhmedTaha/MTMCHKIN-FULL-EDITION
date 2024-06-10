#include "Treasure.h"

Treasure::Treasure() : Card(Treasure_Name) {

}

Card *Treasure::clone() const {
    return new Treasure(*this);
}

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(Treasure_Loot);
    printTreasureMessage();
}


