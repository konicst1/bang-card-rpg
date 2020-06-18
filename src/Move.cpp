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

    int cardNumber = leader->getPlayChoice(*this);
    cardNumber--; //make it an index
    //  leader->getCards()[cardNumber-1]->getAction()->perform(this->leader, this->target);

    int continueFlag = 1;

    for(const auto& instruction : leader->getCards()[cardNumber]->getInstructions()){
        if(continueFlag){
            continueFlag = instruction->perform(m, leader, target);
        }
    }


    //put card back to stack
    m.putCardInStack(leader->getCards()[cardNumber]);
    leader->removeCard(cardNumber);


    m.givePlayerCardFromStack(leader);


}





