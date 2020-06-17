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

    virtual void perform(GameManager &, std::shared_ptr<Player> , std::shared_ptr<Player> ) {}

    virtual InstructionResponse getResponse() {}

    static AffectedPlayer getAffectedPlayerByName(std::string name) {
        if (name == "leader") {
            return AffectedPlayer::LEADER;
        } else {
            return AffectedPlayer::TARGET;
        }
    }

    static DefenseType getDefenseTypeByName(std::string name) {
        if (name == "defense") {
            return DefenseType::DEFENSE;
        } else if (name == "attack") {
            return DefenseType::ATTACK;
        } else {
            return DefenseType::NONE;
        }
    }

};




