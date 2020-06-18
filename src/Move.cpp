//
// Created by stepan on 5/3/20.
//

#include "Move.h"
#include "UIController.h"
#include "GameManager.h"

int Move::init() {
    UIController::println("Now it is " + leader->getName() + "'s turn.");
    UIController::presentOptions(menuOptions);
    return UIController::getChoice(INT32_MAX, 0);
}

const std::shared_ptr<Player> &Move::getLeader() const {
    return leader;
}

const std::shared_ptr<Player> &Move::getTarget() const {
    return target;
}

void Move::startMove(GameManager &m) {
    UIController::startMove(*this);
    UIController::presentCards(this->leader->getCards());
    int cardNumber = UIController::getChoice(this->leader->getCards().size());
    cardNumber--; //make it an index
    //  leader->getCards()[cardNumber-1]->getAction()->perform(this->leader, this->target);

    int continueFlag = 1;

    for(const auto& instruction : leader->getCards()[cardNumber]->getInstructions()){
        if(continueFlag){
            instruction->perform(m, leader, target);
        }
        continueFlag = 1;
    }

    /*for (const std::string &ins : leader->getCards()[cardNumber]->getAction()->getInstructions()) {

        } else if (!ins.compare("takeCardFromTarget")) {
            if (continueFlag) {
                m.putCardInStack(m.getCardFromPlayer(target, leader));
            }
            continueFlag = 1;
        } else if (!ins.compare("robCardFromTarget")) {
            if (continueFlag) {
                leader->giveCard(m.getCardFromPlayer(target, leader));
            }
            continueFlag = 1;
        }
        if (!ins.compare("nextCardIsHeart")) {
            std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
            if (!nCard->getSymbol().compare("heart")) {
                continueFlag = 1;
            }else{
                continueFlag = 0;

        }
    }*/
    //put card back to stack
    m.putCardInStack(leader->getCards()[cardNumber]);
    leader->removeCard(cardNumber);


    m.givePlayerCardFromStack(leader);


}





