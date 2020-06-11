//
// Created by stepan on 5/3/20.
//

#include "Move.h"
#include "UIController.h"
#include "GameManager.h"
#include "AttackAction.h"

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

        for(const std::string& ins : leader->getCards()[cardNumber]->getAction()->getInstructions()){
            if(!ins.compare("decreaseTargetHealth")){
                //todo tady to upraviot na instrukci obrany a dechealth bude podmineno flagem
                int attackPower = dynamic_cast<AttackAction *>(leader->getCards()[cardNumber]->getAction().get())->getDecreaseHealthTarget();
                int def = m.getDefenseFromPlayer(target, leader, 1);
                if((attackPower- def) > 0){
                    target->decreaseHealth(attackPower - def);
                }
            }else if (!ins.compare("giveLeaderCardFromStack")){
                if(continueFlag){
                    m.givePlayerCardFromStack(leader);
                }
            }else if(!ins.compare("decreaseLeaderHealth")){
                int def = m.getDefenseFromPlayer(leader, target, 1);
                //todo attackpower
                if(/*attack power*/ (1 - def) > 0){
                    target->decreaseHealth(1 - def);
                }
            }else if(!ins.compare("giveTargetCardFromStack")){
                if(continueFlag){
                    m.givePlayerCardFromStack(target);
                }
            }else if(!ins.compare("targetAttackDefense")){
                int attackPower = dynamic_cast<AttackAction *>(leader->getCards()[cardNumber]->getAction().get())->getDecreaseHealthTarget();
                int def = m.getAttackDefenseFromPlayer(target, leader, attackPower);
                if(def >= attackPower){
                    continueFlag = 0;
                }else{
                    continueFlag = 1;
                }
            }else if(!ins.compare("leaderAttackDefense")){
                int attackPower = dynamic_cast<AttackAction *>(leader->getCards()[cardNumber]->getAction().get())->getDecreaseHealthLeader();
                int def = m.getAttackDefenseFromPlayer(leader, target, attackPower);
                if(def >= attackPower){
                    continueFlag = 0;
                }else{
                    continueFlag = 1;
                }
            }
        }
        //put card back to stack
        m.putCardInStack(leader->getCards()[cardNumber]);
        leader->removeCard(cardNumber);


}





