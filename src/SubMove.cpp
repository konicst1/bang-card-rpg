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
    int cardNumber = leader->getDefenseChoice(attackStr);
    cardNumber--; //make it an index
    //  leader->getCards()[cardNumber-1]->getAction()->perform(this->leader, this->target);
    if (cardNumber == -1) {
        return 0;
    } else if (typeid(*leader->getCards()[cardNumber]->getAction()) == typeid(DefenseAction)) {
        int continueFlag = 1;
        int r = dynamic_cast<DefenseAction *>(leader->getCards()[cardNumber]->getAction().get())->getHealthDefensePower();

        for (auto ins : leader->getCards()[cardNumber]->getAction()->getInstructions()) {
            if (!ins.compare("nextCardIsHeart")) {
                std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                if (nCard->getSymbol().compare("heart")) {
                    continueFlag = 0;
                }
                m.putCardInStack(nCard);
            }else if(!ins.compare("nextCardIsSpades")){
                std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                if (nCard->getSymbol().compare("spades")) {
                    continueFlag = 0;
                }
                m.putCardInStack(nCard);
            }else if(!ins.compare("nextCardIsClub")){
                std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                if (nCard->getSymbol().compare("club")) {
                    continueFlag = 0;
                }
                m.putCardInStack(nCard);
            }else if(!ins.compare("nextCardIsDiamond")){
                std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                if (nCard->getSymbol().compare("diamond")) {
                    continueFlag = 0;
                }
                m.putCardInStack(nCard);
            }
        }

        //put card back to stack
        m.putCardInStack(leader->getCards()[cardNumber]);

        leader->removeCard(cardNumber);
        if (continueFlag) {
            UIController::println("Next card symbol was the correct type, you are being protected.");
            return r;
        } else {
            UIController::println("Next card symbol was the bad type, you are not protected.");
            return 0;
        }

    } else {
        return getDefenseValue(m);
    }
}

int SubMove::getAttackValue(GameManager &m) {
    UIController::presentCards(this->leader->getCards());
    UIController::println("Play an attack card to defend yourself!");
    int cardNumber = leader->getAttackChoice(attackStr);
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

std::shared_ptr<PlayCard> SubMove::getCardFromLeader() {
    UIController::presentCards(this->leader->getCards());
    UIController::println("You need to give up one of your cards..choose which one will it be.");
    int cardNumber = leader->getCardChoice();
    cardNumber--; //make it an index

    std::shared_ptr<PlayCard> res = leader->getCards()[cardNumber];
    leader->removeCard(cardNumber);
    return res;

}






