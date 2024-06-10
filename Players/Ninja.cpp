#include "../utilities.h"
#include"Ninja.h"

Ninja::Ninja(std :: string name_arg,int maxHP_arg, int force_arg):Player(name_arg,maxHP_arg,force_arg)
{
}

void Ninja::addCoins(int extra_coins){
    if(extra_coins >= 0){
        m_coins=m_coins+(2*extra_coins);
    }
}

void Ninja::printInfo (std::ostream& ostream) const {
    printPlayerDetails(ostream, m_name,"Ninja",m_level,m_force,m_HP_HealthPoints,m_coins);
}

Player* Ninja::clone() const {
    Ninja *newObject = new Ninja(m_name,m_maxHP,m_force);
    newObject ->m_coins=m_coins;
    newObject ->m_level=m_level;
    newObject ->m_coins=m_coins;
    return newObject;
}
