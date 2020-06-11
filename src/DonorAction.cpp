//
// Created by stepan on 6/9/20.
//

#include "DonorAction.h"



DonorAction::DonorAction(const std::vector<std::string> &instructions) : Action(instructions) {}

void DonorAction::perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {
    Action::perform(leader, target);
}
