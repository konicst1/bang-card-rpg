//
// Created by stepan on 6/18/20.
//

#pragma once


#include "Instruction.h"
#include "GameManager.h"

class TakeCardInstruction : public Instruction{
    AffectedPlayer playerAffected;

public:
    TakeCardInstruction(const std::string &instructionRepresentation, AffectedPlayer playerAffected) : Instruction(
            instructionRepresentation), playerAffected(playerAffected) {}

    void perform(GameManager &m, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override {
        if (playerAffected == AffectedPlayer::LEADER) {
            m.putCardInStack(m.getCardFromPlayer(leader));
        } else {
            m.putCardInStack(m.getCardFromPlayer(target));
        }
    }

    InstructionResponse getResponse() override {
        return {-1, -1, 1};
    }
};




