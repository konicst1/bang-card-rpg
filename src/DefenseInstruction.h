//
// Created by stepan on 6/17/20.
//

#pragma once


#include <string>
#include "Player.h"

class DefenseInstruction : public Instruction {
    int defensePower;

public:

    DefenseInstruction(std::string instructionRepresentation1,
                       int defensePower) : Instruction(instructionRepresentation1) {
        this->defensePower = defensePower;
    }

    void perform(GameManager &m, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override {}

    InstructionResponse getResponse() override {
        return InstructionResponse(0, defensePower, 1);
    }
};




