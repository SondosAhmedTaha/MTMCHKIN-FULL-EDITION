#include "../utilities.h"
#include "Warrior.h"

Warrior::Warrior(std :: string name_arg,int maxHP_arg,int force_arg): Player(name_arg,maxHP_arg,force_arg)
{

}
Player* Warrior::clone() const {
    Warrior *newObject = new Warrior(m_name,m_maxHP,m_force);
    newObject ->m_coins=m_coins;
    newObject ->m_level=m_level;
    newObject ->m_coins=m_coins;
    return newObject;
}
void Warrior::printInfo (std::ostream& ostream) const {
    printPlayerDetails(ostream, m_name,"Warrior",m_level,m_force,m_HP_HealthPoints,m_coins);
}
int Warrior::getAttackStrength() const {
    return m_level + (2*m_force);
}