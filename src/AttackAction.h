//
// Created by stepan on 6/8/20.
//

#pragma once


#include <memory>
#include "Action.h"

class AttackAction : public Action {
    int decreaseHealthLeader;       //lethal power of card against leader of the move
    int decreaseManaLeader;         //mana power of card against leader of the move
    int decreaseHealthTarget;       //lethal power of card against target of the move
    int decreaseManaTarget;         //mana power of card against target of the move

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
    //getters

    int getDecreaseHealthLeader() const;

    int getDecreaseManaLeader() const;

    int getDecreaseHealthTarget() const;

    int getDecreaseManaTarget() const;

};



