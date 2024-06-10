#include "Well.h"

Well::Well() : Card(Well_Name) {

}


void Well::applyEncounter(Player &player) const {
    if (dynamic_cast<Ninja*>(&player) != nullptr){
        printWellMessage(true);
    }else{
        player.damage(Well_dmg);
        printWellMessage(false);
    }
}

Card *Well::clone() const {
    return new Well(*this);
}



