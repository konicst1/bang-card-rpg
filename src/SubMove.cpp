//
// Created by stepan on 6/10/20.
//

#include "SubMove.h"
#include "UIController.h"
#include "GameManager.h"

int SubMove::init() {
    UIController::println("Your opponent made move that requires your response. ");
    if (attackStr > 0) {
        UIController::println("You are being attacked with power of " + std::to_string(attackStr).append("."));
    }
    UIController::println("If you want to skip, enter 0.");
    return 0;
}


int SubMove::getDefenseValue(GameManager &m) {
    int defense = 0;
    while (true) {
        int cardNumber = target->getDefenseChoice(attackStr);
        cardNumber--; //make it an index
        if (cardNumber == -1) {
            return defense;
        } else {
            InstructionResponse res = target->getCards()[cardNumber]->getResponse(m);

            if (res.getDefensePower() < 0) {
                UIController::println("Not a defensive card.");
                continue;
            }

            //put card back to stack
            m.putCardInStack(target->getCards()[cardNumber]);
            target->removeCard(cardNumber);


            attackStr -= res.getDefensePower();
            if (attackStr < 0) {
                attackStr = 0;
            }

            defense += res.getDefensePower();

        }
    }

}

int SubMove::getAttackValue(GameManager &m) {
    int attack = 0;
    while (true) {

        int cardNumber = target->getAttackChoice(attackStr);
        cardNumber--; //make it an index
        if (cardNumber == -1) {
            return attack;
        } else {
            InstructionResponse res = target->getCards()[cardNumber]->getResponse(m);

            if (res.getAttackPower() < 0) {
                UIController::println("Not an attack card.");
                continue;
            }
            //put card back to stack
            m.putCardInStack(target->getCards()[cardNumber]);
            target->removeCard(cardNumber);

            attackStr -= res.getAttackPower();
            if (attackStr < 0) {
                attackStr = 0;
            }
            attack += res.getAttackPower();
        }
    }
}

std::shared_ptr<PlayCard> SubMove::getCardFromPlayer() {
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




