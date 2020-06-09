//
// Created by stepan on 5/3/20.
//

#include "Move.h"
#include "UIController.h"
#include "GameManager.h"

void Move::init() {

    UIController::startMove(*this);
}

const std::shared_ptr<Player> &Move::getLeader() const {
    return leader;
}

const std::shared_ptr<Player> &Move::getTarget() const {
    return target;
}

void Move::startMoveCycle(GameManager & manager) {
    std::vector<PlayCard> trash;
    while(true){
        UIController::presentCards(this->leader->getCards());
        int cardNumber = UIController::getChoice(this->leader->getCards().size());
        leader->getCards()[cardNumber-1]->getAction()->perform(this->leader, this->target);
        manager.putCardInStack(leader->getCards()[cardNumber - 1]);
        leader->removeCard(cardNumber - 1);


        break;
    }

}





