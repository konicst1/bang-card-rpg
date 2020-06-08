//
// Created by stepan on 5/3/20.
//

#pragma once

class Player;

#include <string>
#include <vector>
#include <memory>


class Action {
    std::vector<std::string> instructions;

public:
    Action(std::vector<std::string> instructions) {
        this->instructions = instructions;
    }

    virtual void perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {

    }

    const std::vector<std::string> &getInstructions() const { return instructions; }
};