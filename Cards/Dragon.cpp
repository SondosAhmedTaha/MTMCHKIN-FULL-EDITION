#include "Dragon.h"


Dragon :: Dragon() : BattleCard(Dragon_Name, Dragon_Power, Dragon_Loot, Dragon_DamageOnDefeat){}

Card *Dragon::clone() const {
    return new Dragon(*this);
}

void Dragon::applyEncounter(Player &player) const {
    if(player.getAttackStrength() < m_Power) {
        player.fallen();
        printLossBattle(player.getName(), m_name);
    }else{
        player.addCoins(m_Loot);
        player.levelUp();
        printWinBattle(player.getName(), m_name);
    }
}

void Dragon::printInfo(std::ostream &os) const {
    printCardDetails(os, m_name);
    printMonsterDetails(os, Dragon_Power, Dragon_DamageOnDefeat, Dragon_Loot, true);
    printEndOfCardDetails(os);
}