//
// Created by stepan on 6/8/20.
//

#include "AttackAction.h"
#include "Player.h"



void AttackAction::perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {
    target->decreaseHealth(decreaseHealthTarget);
    leader->decreaseHealth(decreaseHealthLeader);
}
