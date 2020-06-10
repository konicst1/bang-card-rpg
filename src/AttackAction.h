//
// Created by stepan on 6/8/20.
//

#pragma once


#include <memory>
#include "Action.h"

class AttackAction : public Action {
    int decreaseHealthLeader;
    int decreaseManaLeader;
    int decreaseHealthTarget;
    int decreaseManaTarget;

public:
    AttackAction(const std::vector<std::string> &instructions, int decreaseHealthLeader, int decreaseManaLeader,
                 int decreaseHealthTarget, int decreaseManaTarget) : Action(instructions),
                                                                     decreaseHealthLeader(decreaseHealthLeader),
                                                                     decreaseManaLeader(decreaseManaLeader),
                                                                     decreaseHealthTarget(decreaseHealthTarget),
                                                                     decreaseManaTarget(decreaseManaTarget) {}

    void perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override ;

    virtual ~AttackAction() {

    }

    int getDecreaseHealthLeader() const;

    int getDecreaseManaLeader() const;

    int getDecreaseHealthTarget() const;

    int getDecreaseManaTarget() const;

};



