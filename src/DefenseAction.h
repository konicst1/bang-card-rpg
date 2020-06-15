//
// Created by stepan on 6/9/20.
//

#pragma once


#include "Action.h"

class DefenseAction : public Action{
    int healthDefensePower;     //defense power for health
    int manaDefensePower;       //defense power for mana

public:
    DefenseAction(const std::vector<std::string> &instructions, int healthDefensePower, int manaDefensePower) : Action(
            instructions), healthDefensePower(healthDefensePower), manaDefensePower(manaDefensePower) {}

    //getters
    int getHealthDefensePower() const;

    int getManaDefensePower() const;

    void perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override ;
};




