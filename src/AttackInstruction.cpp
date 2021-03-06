//
// Created by stepan on 6/16/20.
//

#include "AttackInstruction.h"
#include "Player.h"
#include "GameManager.h"

int AttackInstruction::perform(GameManager &m, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {
    std::shared_ptr<Player> victim;
    if (playerAffected == AffectedPlayer::LEADER) {
        victim = leader;
    } else {
        victim = target;
    }
    int defensePower = 0;
    if (defenseType == DefenseType::DEFENSE) {
        defensePower = m.getDefenseFromPlayer(victim, attackPower);
    } else if (defenseType == DefenseType::ATTACK) {
        defensePower = m.getAttackDefenseFromPlayer(victim, attackPower);
    }
    if ((attackPower - defensePower) > 0) {
        victim->decreaseHealth(attackPower - defensePower);
    }
    return 1;
}

AttackInstruction::AttackInstruction(const std::string &instructionRepresentation, int attackPower,
                                     Instruction::AffectedPlayer playerAffected, DefenseType defenseType) : Instruction(
        instructionRepresentation), attackPower(attackPower), playerAffected(playerAffected), defenseType(
        defenseType) {}

InstructionResponse AttackInstruction::getResponse(GameManager &) {
    return {attackPower, 0, 1, 0, 0};
}

InstructionResponse AttackInstruction::getPotentialResponse() {
    return {attackPower, 0, 1, 0, 0};
}


