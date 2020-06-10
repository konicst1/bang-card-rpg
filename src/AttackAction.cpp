//
// Created by stepan on 6/8/20.
//

#include "AttackAction.h"
#include "Player.h"



void AttackAction::perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {
    target->decreaseHealth(decreaseHealthTarget);
    leader->decreaseHealth(decreaseHealthLeader);
}

int AttackAction::getDecreaseHealthLeader() const {
    return decreaseHealthLeader;
}

int AttackAction::getDecreaseManaLeader() const {
    return decreaseManaLeader;
}

int AttackAction::getDecreaseHealthTarget() const {
    return decreaseHealthTarget;
}

int AttackAction::getDecreaseManaTarget() const {
    return decreaseManaTarget;
}
