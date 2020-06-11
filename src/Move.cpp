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

        int continueFlag  = 1;
        auto inss = leader->getCards()[cardNumber]->getAction()->getInstructions();
        for(std::string ins : inss){
            if(!ins.compare("decreaseTargetHealth")){
                int def = m.getDefenseFromPlayer(target, leader, 1);
                //todo attackpower
                if(/*attack power*/ (1 - def) > 0){
                    target->decreaseHealth(1 - def);
                }
            }else if (!ins.compare("giveLeaderCardFromStack")){
                if(continueFlag){
                    m.givePlayerCardFromStack(leader); //todo nefunguje
                }
            }
        }
        //put card back to stack
        m.putCardInStack(leader->getCards()[cardNumber]);
        leader->removeCard(cardNumber);


}





