#include "Witch.h"

Witch::Witch() : BattleCard(Witch_Name, Witch_Power, Witch_Loot, Witch_DamageOnDefeat) {

}

Card *Witch::clone() const {
    return new Witch(*this);
}

void Witch::applyEncounter(Player &player) const {
    if(player.getAttackStrength() < m_Power){
        player.damage(m_DamageOnDefeat);
        player.Debuff(Witch_Debuff);
        printLossBattle(player.getName(), m_name);
    }else{
        player.addCoins(m_Loot);
        player.levelUp();
        printWinBattle(player.getName(), m_name);
    }
}

