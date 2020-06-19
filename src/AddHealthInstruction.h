//
// Created by stepan on 6/18/20.
//

#pragma once


#include "Instruction.h"
#include "Player.h"

class AddHealthInstruction : public Instruction{
    int addHealth;
    AffectedPlayer playerAffected;

public:
    AddHealthInstruction(const std::string &instructionRepresentation, int addHealth, AffectedPlayer playerAffected)
            : Instruction(instructionRepresentation), addHealth(addHealth), playerAffected(playerAffected) {}

    int perform(GameManager &, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override {
        if (playerAffected == AffectedPlayer::LEADER) {
            leader->increaseHealth(addHealth);
        } else {
            target->increaseHealth(addHealth);
        }
        return 1;
    }

    InstructionResponse getResponse(GameManager &) override {
        return {0, 0, 1, 1, 0};
    }

    InstructionResponse getPotentialResponse()override {
        return {0, 0, 1, 1, 0};
    }
};

