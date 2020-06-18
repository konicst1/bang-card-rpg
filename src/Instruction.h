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

    virtual int perform(GameManager &, std::shared_ptr<Player>, std::shared_ptr<Player>) { return 1; }

    const std::string &getInstructionRepresentation() const {
        return instructionRepresentation;
    }

    virtual InstructionResponse getResponse(GameManager &) {return {-1, -1, 1, -1, -1};}

    virtual InstructionResponse getPotentialResponse() { return {-1, -1, 1, -1, -1}; }


    static AffectedPlayer getAffectedPlayerByName(const std::string& name) {
        if (name == "leader") {
            return AffectedPlayer::LEADER;
        } else {
            return AffectedPlayer::TARGET;
        }
    }

    static DefenseType getDefenseTypeByName(const std::string& name) {
        if (name == "defense") {
            return DefenseType::DEFENSE;
        } else if (name == "attack") {
            return DefenseType::ATTACK;
        } else {
            return DefenseType::NONE;
        }
    }

};




