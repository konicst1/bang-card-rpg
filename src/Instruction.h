//
// Created by stepan on 6/16/20.
//

#pragma once

class Player;

class GameManager;

#include <memory>

class Instruction {
    std::string instructionRepresentation;

public:
    enum AffectedPlayer {
        LEADER, TARGET
    };
    enum DefenseType {
        DEFENSE, ATTACK, NONE
    };

    Instruction(const std::string &instructionRepresentation) : instructionRepresentation(
            instructionRepresentation) {}

    virtual void perform(GameManager &m, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {}


};




