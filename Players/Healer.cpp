#include "../utilities.h"
#include "Healer.h"

Healer::Healer(std :: string name_arg,int maxHP_arg, int force_arg): Player(name_arg,maxHP_arg,force_arg){}
void Healer::printInfo (std::ostream& ostream) const {
    printPlayerDetails(ostream, m_name,"Healer",m_level,m_force,m_HP_HealthPoints,m_coins);
}

Player* Healer::clone() const {
    Healer *newObject = new Healer(m_name,m_maxHP,m_force);
    newObject ->m_coins=m_coins;
    newObject ->m_level=m_level;
    newObject ->m_coins=m_coins;
    return newObject;
}
void Healer::heal(int extra_HP) {
    if(extra_HP>0){
        m_HP_HealthPoints += (2*extra_HP);
        if(m_HP_HealthPoints > m_maxHP){
            m_HP_HealthPoints = m_maxHP;
        }
    }
}