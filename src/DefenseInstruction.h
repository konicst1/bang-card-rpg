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

    int perform(GameManager &, std::shared_ptr<Player> , std::shared_ptr<Player> ) override {return 1;}

    InstructionResponse getResponse(GameManager &m) override {
        return InstructionResponse(-1, defensePower, 1);
    }
};




