#ifndef WORKING_EX4_MERCHANT_H
#define WORKING_EX4_MERCHANT_H

#include "Card.h"

/**
 * the details of the Merchant card and the prices of his merch.
 */
const std::string Merchant_Name = "Merchant";
const int HealthPotion = 1;
const int DamagePotion = 1;
const int HealthPotionPrice = 5;
const int DamagePotionPrice = 10;
const int Leave = 0;
const int BuyHealth = 1;
const int BuyDamage = 2;


class Merchant : public Card{
public:
    /**
     * Constructor + The Big 3 for Merchant.
     */
    Merchant();
    Merchant (const Merchant& other) = default;
    Merchant& operator=(const Merchant& other) = default;
    ~Merchant() override = default;

    /**
     * Creates a new cloned Merchant and returns a pointer to it.
     * @return a pointer to the new cloned Merchant.
     */
    Card * clone() const override;

    /**
     * Encountering the Merchant. (you can buy potions!).
     * @param player the player that encountered the Merchant.
     */
    void applyEncounter(Player &player) const override;

};

#endif //WORKING_EX4_MERCHANT_H