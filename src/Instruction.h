//
// Created by stepan on 6/16/20.
//

#pragma once

class Player;

class GameManager;

#include <memory>
#include <utility>
#include "InstructionResponse.h"

class Instruction {
    std::string instructionRepresentation;

public:
    enum AffectedPlayer {
        LEADER, TARGET
    };
    enum DefenseType {
        DEFENSE, ATTACK, NONE
    };

    explicit Instruction(std::string instructionRepresentation) : instructionRepresentation(std::move(
            instructionRepresentation)) {}

    virtual void perform(GameManager &m, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {}

    virtual InstructionResponse getResponse(){}

};




