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
    int continueFlag = 1;
    //perform players role special ability
    for(const auto& instruction : leader->getRole()->getInstructions()){
        if(continueFlag){
            continueFlag = instruction->perform(m, leader, target);
        }
    }
    //check if ability killed anyone
    if ((leader->getHealth() <= 0) || (target->getHealth() <= 0)) {
        return;
    }

    int cardNumber = leader->getPlayChoice(*this);
    cardNumber--; //make it an index

    auto c = leader->getCards()[cardNumber];

    //put card back to stack
    m.putCardInStack(leader->getCards()[cardNumber]);
    leader->removeCard(cardNumber);

    continueFlag = 1;

    for(const auto& instruction : c->getInstructions()){
        if(continueFlag){
            continueFlag = instruction->perform(m, leader, target);
        }
    }





    m.givePlayerCardFromStack(leader);


}





