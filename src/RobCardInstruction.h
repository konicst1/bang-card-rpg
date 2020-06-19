//
// Created by stepan on 6/18/20.
//

#pragma once


#include "Instruction.h"
#include "GameManager.h"

class RobCardInstruction : public Instruction {
    AffectedPlayer playerAffected;

public:
    RobCardInstruction(const std::string &instructionRepresentation, AffectedPlayer playerAffected) : Instruction(
            instructionRepresentation), playerAffected(playerAffected) {}

    int perform(GameManager &m, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override {
        if (playerAffected == AffectedPlayer::LEADER) {
            target->giveCard(m.getCardFromPlayer(leader));
        } else {
            leader->giveCard(m.getCardFromPlayer(target));
        }
        return 1;
    }

    InstructionResponse getResponse(GameManager &) override {
        return {0, 0, 1, 0, 1};
    }

    InstructionResponse getPotentialResponse() override {
        return {0, 0, 1, 0 ,1};
    }
};


