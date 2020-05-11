//
// Created by stepan on 5/3/20.
//

#include "Move.h"
#include "UIController.h"

void Move::init() {

    UIController::startMove(*this);
}

const std::shared_ptr<Player> &Move::getLeader() const {
    return leader;
}

const std::shared_ptr<Player> &Move::getTarget() const {
    return target;
}

void Move::startMoveCycle() {
    while(true){
        UIController::presentCards(this->leader->getCards());
        int cardNumber = UIController::getChoice(this->leader->getCards().size());


        break;
    }

}
