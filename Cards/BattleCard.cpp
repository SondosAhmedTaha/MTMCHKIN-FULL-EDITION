#include "BattleCard.h"

BattleCard::BattleCard(std::string name, int power, int loot, int damage_on_loss) : Card(name), m_Power(power), m_Loot(loot), m_DamageOnDefeat(damage_on_loss) {}

void BattleCard::applyEncounter(Player &player) const {
    if(player.getAttackStrength() < m_Power){
        player.damage(m_DamageOnDefeat);
        printLossBattle(player.getName(), m_name);
    }else{
        player.addCoins(m_Loot);
        player.levelUp();
        printWinBattle(player.getName(), m_name);
    }
}

void BattleCard::printInfo(std::ostream &os) const {
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_Power, m_DamageOnDefeat, m_Loot, false);
    printEndOfCardDetails(os);
}





