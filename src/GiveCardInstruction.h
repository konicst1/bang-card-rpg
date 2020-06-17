//
// Created by stepan on 6/17/20.
//

#pragma once


#include "Instruction.h"
#include "GameManager.h"

class GiveCardInstruction : public Instruction {
    AffectedPlayer playerAffected;

public:
    GiveCardInstruction(const std::string &instructionRepresentation, AffectedPlayer playerAffected) : Instruction(
            instructionRepresentation), playerAffected(playerAffected) {}

    void perform(GameManager &m, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override {
        if (playerAffected == AffectedPlayer::LEADER) {
            m.givePlayerCardFromStack(leader);
        } else {
            m.givePlayerCardFromStack(target);
        }
    }

    InstructionResponse getResponse() override {
        return {-1, -1, 1};
    }
};
