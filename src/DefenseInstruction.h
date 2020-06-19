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
        return {0, defensePower, 1, 0, 0};
    }

    InstructionResponse getPotentialResponse()override {
        return {0, defensePower, 1, 0, 0};
    }
};




