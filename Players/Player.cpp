#include "Player.h"
#include <iostream>
#include "../utilities.h"

using std::string;

int Player::getLevel() const {
    return m_level;
}
void Player::setName(std::string New_name){
    m_name=New_name;
}

Player :: Player(string name_arg,int maxHP_arg,int force_arg){
    m_name = name_arg;
    m_level = 1;
    m_coins =10;

    if (force_arg < 0) {
        m_force = 5;
    }
    else {
        m_force = force_arg;
    }
    if (maxHP_arg <= 0) {
        m_maxHP = 100;
        m_HP_HealthPoints = 100;
    }
    else {
        m_maxHP = maxHP_arg;
        m_HP_HealthPoints = maxHP_arg;
    }
}

void Player::heal(int extra_HP) {
    if(extra_HP<0){
        return;
    }
    m_HP_HealthPoints += extra_HP;
    if(m_HP_HealthPoints > m_maxHP){
        m_HP_HealthPoints = m_maxHP;
    }
}


bool Player::isKnockedOut() const {
    if(m_HP_HealthPoints<=0){
        return true;
    }
    return false;
}


bool Player::pay(int price) {
    if(m_coins < price){
        return false;
    }
    if(price>=0){
        m_coins=m_coins-price;
    }
    return true;
}


void Player::levelUp (){
    if (m_level<10){
        m_level=m_level+1;
    }
}


void Player:: buff (int add_force){
    if(add_force >= 0){
        m_force = m_force + add_force;
    }
}


void Player:: damage(int damagePoints){
    if(damagePoints<=0){
        return;
    }
    if(m_HP_HealthPoints<damagePoints){
        m_HP_HealthPoints=0;
        return;
    }
    m_HP_HealthPoints=m_HP_HealthPoints-damagePoints;
}


void Player:: addCoins(int extra_coins){
    if(extra_coins >= 0){
        m_coins=m_coins+extra_coins;
    }
}


int  Player:: getAttackStrength() const{
    return (m_level+m_force);
}
std::ostream& operator<<(std::ostream& ostream, const Player& player){
    player.printInfo(ostream);
    return ostream;
}

void Player::Debuff(int DebuffAmount) {
    if(DebuffAmount >= 0){
        m_force -= DebuffAmount;
    }
    if(m_force < 0){
        m_force = 0;
    }
}

void Player::fallen() {
    m_HP_HealthPoints = 0;
}

std::string Player::getName() const {
    return m_name;
}

int Player::getCoins() const {
    return m_coins;
}