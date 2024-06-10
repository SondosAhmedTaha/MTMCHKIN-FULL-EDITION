#include "Barfight.h"

Barfight::Barfight() : Card(Barfight_Name){

}

Card *Barfight::clone() const {
    return new Barfight(*this);
}

void Barfight::applyEncounter(Player &player) const {
    if(dynamic_cast<Warrior*>(&player) != nullptr){
        printBarfightMessage(true);
    }else{
        player.damage(Barfight_dmg);
        printBarfightMessage(false);
    }

}



