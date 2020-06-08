//
// Created by stepan on 6/8/20.
//

#pragma once


#include <memory>
#include "Action.h"

class AttackAction : public Action {
    int decreaseHealth;
    int decreaseMana;

public:
    AttackAction(const std::vector<std::string> &instructions, int decreaseHealth, int decreaseMana) : Action(instructions), decreaseHealth(decreaseHealth), decreaseMana(decreaseMana) {

    }

    void perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override {

    }

    virtual ~AttackAction() {

    }

};



