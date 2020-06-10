//
// Created by stepan on 6/9/20.
//

#include "DefenseAction.h"

void DefenseAction::perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {

}

int DefenseAction::getHealthDefensePower() const {
    return healthDefensePower;
}

int DefenseAction::getManaDefensePower() const {
    return manaDefensePower;
}
