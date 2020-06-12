//
// Created by stepan on 5/3/20.
//

#include "Move.h"
#include "UIController.h"
#include "GameManager.h"
#include "AttackAction.h"
#include "DefenseAction.h"

void Move::init() {

    UIController::startMove(*this);
}

const std::shared_ptr<Player> &Move::getLeader() const {
    return leader;
}

const std::shared_ptr<Player> &Move::getTarget() const {
    return target;
}

void Move::startMove(GameManager &m) {

    UIController::presentCards(this->leader->getCards());
    int cardNumber = UIController::getChoice(this->leader->getCards().size());
    cardNumber--; //make it an index
    //  leader->getCards()[cardNumber-1]->getAction()->perform(this->leader, this->target);

    int continueFlag = 1, power = 9;

    for (const std::string &ins : leader->getCards()[cardNumber]->getAction()->getInstructions()) {
        if (!ins.compare("decreaseTargetHealth")) {
            if (continueFlag) {
                target->decreaseHealth(power);
            }
            continueFlag = 1;
        } else if (!ins.compare("giveLeaderCardFromStack")) {
            if (continueFlag) {
                m.givePlayerCardFromStack(leader);
            }
            continueFlag = 1;
        } else if (!ins.compare("decreaseLeaderHealth")) {
            if (continueFlag) {
                target->decreaseHealth(power);
            }
            continueFlag = 1;
        } else if (!ins.compare("giveTargetCardFromStack")) {
            if (continueFlag) {
                m.givePlayerCardFromStack(target);
            }
            continueFlag = 1;
        } else if (!ins.compare("targetAttackDefense")) {
            int attackPower = dynamic_cast<AttackAction *>(leader->getCards()[cardNumber]->getAction().get())->getDecreaseHealthTarget();
            int def = m.getAttackDefenseFromPlayer(target, leader, attackPower);
            if (def >= attackPower) {
                continueFlag = 0;
            } else {
                continueFlag = 1;
            }
            power = attackPower - def;
        } else if (!ins.compare("leaderAttackDefense")) {
            int attackPower = dynamic_cast<AttackAction *>(leader->getCards()[cardNumber]->getAction().get())->getDecreaseHealthLeader();
            int def = m.getAttackDefenseFromPlayer(leader, target, attackPower);
            if (def >= attackPower) {
                continueFlag = 0;
            } else {
                continueFlag = 1;
            }
            power = attackPower - def;
        } else if (!ins.compare("targetDefendDefense")) {
            int attackPower = dynamic_cast<AttackAction *>(leader->getCards()[cardNumber]->getAction().get())->getDecreaseHealthTarget();
            int def = m.getDefenseFromPlayer(target, leader, attackPower);
            if (def >= attackPower) {
                continueFlag = 0;
            } else {
                continueFlag = 1;
            }
            power = attackPower - def;
        } else if (ins.compare("leaderDefendDefense")) {
            int attackPower = dynamic_cast<AttackAction *>(leader->getCards()[cardNumber]->getAction().get())->getDecreaseHealthTarget();
            int def = m.getDefenseFromPlayer(leader, target, attackPower);
            if (def >= attackPower) {
                continueFlag = 0;
            } else {
                continueFlag = 1;
            }
            power = attackPower - def;
        }
    }
    //put card back to stack
    m.putCardInStack(leader->getCards()[cardNumber]);
    leader->removeCard(cardNumber);


}





