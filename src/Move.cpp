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

void Move::startMove(GameManager & m) {

        UIController::presentCards(this->leader->getCards());
        int cardNumber = UIController::getChoice(this->leader->getCards().size());
        cardNumber--; //make it an index
    //  leader->getCards()[cardNumber-1]->getAction()->perform(this->leader, this->target);
        for(std::string ins : leader->getCards()[cardNumber]->getAction()->getInstructions()){
            if(!ins.compare("decreaseTargetHealth")){
                int def = m.getDefenseFromPlayer(target, leader, 1);
                //todo attackpower
                if(/*attack power*/ (1 - def) > 0){
                    target->decreaseHealth(1 - def);
                }
            }
        }
        //put card back to stack
        m.putCardInStack(leader->getCards()[cardNumber]);
        leader->removeCard(cardNumber);


}





