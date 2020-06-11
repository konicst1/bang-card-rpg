//
// Created by stepan on 6/10/20.
//

#include "SubMove.h"
#include "UIController.h"
#include "DefenseAction.h"
#include "GameManager.h"
#include "AttackAction.h"

void SubMove::init() {
    UIController::print("Your opponent made move that requires your response. You are being attacked with power of ");
    UIController::println(std::to_string(attackStr).append("."));
    UIController::println("If you want to skip, enter 0.");
}

SubMove::SubMove(std::shared_ptr<Player> &leader, std::shared_ptr<Player> &target, int attackStr) : Move(leader,
                                                                                                         target),
                                                                                                    attackStr(
                                                                                                            attackStr) {}

int SubMove::getDefenseValue(GameManager &m) {
    UIController::presentCards(this->leader->getCards());
    UIController::println("Play a defensive card to defend yourself!");
    int cardNumber = UIController::getChoice(this->leader->getCards().size(), 0);
    cardNumber--; //make it an index
    //  leader->getCards()[cardNumber-1]->getAction()->perform(this->leader, this->target);
    if (cardNumber == -1) {
        return 0;
    } else if (typeid(*leader->getCards()[cardNumber]->getAction()) == typeid(DefenseAction)) {
        int r = dynamic_cast<DefenseAction *>(leader->getCards()[cardNumber]->getAction().get())->getHealthDefensePower();
        //put card back to stack
        m.putCardInStack(leader->getCards()[cardNumber]);
        leader->removeCard(cardNumber);
        return r;
    } else {
        return getDefenseValue(m);
    }
}

int SubMove::getAttackValue(GameManager &m) {
    UIController::presentCards(this->leader->getCards());
    UIController::println("Play an attack card to defend yourself!");
    int cardNumber = UIController::getChoice(this->leader->getCards().size(), 0);
    cardNumber--; //make it an index
    if (cardNumber == -1) {
        return 0;
    } else if (typeid(*leader->getCards()[cardNumber]->getAction()) == typeid(AttackAction)) {
        int r = dynamic_cast<AttackAction *>(leader->getCards()[cardNumber]->getAction().get())->getDecreaseHealthTarget();
        //put card back to stack
        m.putCardInStack(leader->getCards()[cardNumber]);
        leader->removeCard(cardNumber);
        return r;
    } else {
        return getAttackValue(m);
    }
}






