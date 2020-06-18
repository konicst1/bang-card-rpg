//
// Created by stepan on 6/17/20.
//

#pragma once


#include <string>
#include <utility>
#include "Player.h"

class DefenseInstruction : public Instruction {
    int defensePower;

public:

    DefenseInstruction(std::string instructionRepresentation1,
                       int defensePower) : Instruction(std::move(instructionRepresentation1)) {
        this->defensePower = defensePower;
    }

    int perform(GameManager &, std::shared_ptr<Player> , std::shared_ptr<Player> ) override {return 1;}

    InstructionResponse getResponse(GameManager &) override {
        return {-1, defensePower, 1, -1, -1};
    }

    InstructionResponse getPotentialResponse()override {
        return {-1, defensePower, 1, -1, -1};
    }
};




