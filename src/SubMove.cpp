//
// Created by stepan on 6/10/20.
//

#include "SubMove.h"
#include "UIController.h"
#include "GameManager.h"

int SubMove::init() {
    UIController::print("Your opponent made move that requires your response. You are being attacked with power of ");
    UIController::println(std::to_string(attackStr).append("."));
    UIController::println("If you want to skip, enter 0.");
    return 0;
}


int SubMove::getDefenseValue(GameManager &m) {
    int defense = 0;
    while (true) {
        UIController::presentCards(this->target->getCards()); //todo remove from this class
        UIController::println("Play defensive cards to defend yourself! Enter 0 when done.");
        int cardNumber = target->getDefenseChoice(attackStr);
        cardNumber--; //make it an index
        if (cardNumber == -1) {
            return defense;
        } else {
            InstructionResponse res = target->getCards()[cardNumber]->getResponse();

            if (res.getDefensePower() < 0) {
                UIController::println("Not a defensive card.");
                continue;
            }

            //put card back to stack
            m.putCardInStack(target->getCards()[cardNumber]);
            target->removeCard(cardNumber);

            defense += res.getDefensePower();

        }
    }

}

int SubMove::getAttackValue(GameManager &m) {
    int attack = 0;
    while (true) {
        UIController::presentCards(this->target->getCards());
        UIController::println("Play attack cards to defend yourself! Enter 0 when done.");
        int cardNumber = target->getAttackChoice(attackStr);
        cardNumber--; //make it an index
        if (cardNumber == -1) {
            return attack;
        } else {
            InstructionResponse res = target->getCards()[cardNumber]->getResponse();

            if (res.getAttackPower() < 0) {
                UIController::println("Not an attack card.");
                continue;
            }

            //put card back to stack
            m.putCardInStack(target->getCards()[cardNumber]);
            target->removeCard(cardNumber);

            attack += res.getAttackPower();
        }
    }
}

std::shared_ptr<PlayCard> SubMove::getCardFromPlayer() {
    UIController::presentCards(this->target->getCards());
    UIController::println("You need to give up one of your cards..choose which one will it be.");
    int cardNumber = target->getCardChoice();
    cardNumber--; //make it an index

    std::shared_ptr<PlayCard> res = target->getCards()[cardNumber];
    target->removeCard(cardNumber);
    return res;

}

SubMove::SubMove(std::shared_ptr<Player> target, int attackStr) {
    this->target = target;
    this->attackStr = attackStr;
}

SubMove::SubMove(int attackStr) {
    this->attackStr = attackStr;
}




