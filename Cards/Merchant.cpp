#include "Merchant.h"




Merchant::Merchant() : Card(Merchant_Name) {

}

Card *Merchant::clone() const {
    return new Merchant(*this);
}

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::string input;
    int UserInput;
    bool sequence = false;


    while (true) {
        std::getline(std::cin, input);
        if (input.empty()) {
            if(!sequence){
                printInvalidInput();
            }
            sequence = true;
            continue;
        }

        try {
            UserInput = std::stoi(input);
            if (UserInput == Leave || UserInput == BuyHealth || UserInput == BuyDamage) {
                break;
            } else {
                printInvalidInput();
            }
        } catch (const std::exception &e) {
            printInvalidInput();
        }
        sequence = false;
    }

    switch (UserInput) {

        case Leave:
            printMerchantSummary(std::cout, player.getName(), Leave, Leave);
            break;

        case BuyHealth:
            if (player.pay(HealthPotionPrice)) {
                player.heal(HealthPotion);
                printMerchantSummary(std::cout, player.getName(), BuyHealth, HealthPotionPrice);
            } else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), BuyHealth, Leave);
            }
            break;

        case BuyDamage:
            if (player.pay(DamagePotionPrice)) {
                player.buff(DamagePotion);
                printMerchantSummary(std::cout, player.getName(), BuyDamage, DamagePotionPrice);
            } else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), BuyDamage, Leave);
            }
            break;
    }
}