//
// Created by stepan on 6/16/20.
//

#pragma once


#include "Instruction.h"

class AttackInstruction : public Instruction{
    int attackPower;
    AffectedPlayer playerAffected;
    DefenseType defenseType;

public:

    AttackInstruction(const std::string &instructionRepresentation, int attackPower, AffectedPlayer playerAffected,
                      DefenseType defenseType);

    void perform(GameManager &m, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override;

    InstructionResponse getResponse() override;

};




