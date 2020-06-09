//
// Created by stepan on 6/8/20.
//

#include "AttackAction.h"
#include "Player.h"

//void AttackAction::perform() {
//   // naaaaaaaah tohle asi nepujde, actiony se budou performovat primo z Move za pomoci derivatu Action. Asi bude vhodne pridelat nejaky subMove na odpovedi na attack
//}

void AttackAction::perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {
    target->decreaseHealth(decreaseHealthTarget);
    leader->decreaseHealth(decreaseHealthLeader);
}
