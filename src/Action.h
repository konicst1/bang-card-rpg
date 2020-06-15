//
// Created by stepan on 5/3/20.
//

#pragma once


class Player;

#include <string>
#include <vector>
#include <memory>


/**
 * Class that represents special abilities of each card.
 * */
class Action {
    std::vector<std::string> instructions;

public:
    Action(std::vector<std::string> instructions) {
        this->instructions = instructions;
    }

    Action() {

    }

    //obsolete
    virtual void perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {
        leader.get();
        target.get();
    }

    std::vector<std::string> getInstructions() const { return instructions; }


};