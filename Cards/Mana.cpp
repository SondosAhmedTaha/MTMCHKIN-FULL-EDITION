#include "Mana.h"


Mana::Mana() : Card(Mana_Name){

}

Card* Mana::clone() const {
    return new Mana(*this);
}

void Mana::applyEncounter(Player &player) const {
    if (dynamic_cast<Healer*>(&player) != nullptr){
        player.heal(Mana_buff);
        printManaMessage(true);
    }else{
        printManaMessage(false);
    }
}



