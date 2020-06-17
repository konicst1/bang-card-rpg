//
// Created by stepan on 6/16/20.
//

#include "AttackInstruction.h"
#include "Player.h"
#include "GameManager.h"

void AttackInstruction::perform(GameManager &m, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) {
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

    leader->decreaseHealth(attackPower - defensePower);
}

AttackInstruction::AttackInstruction(const std::string &instructionRepresentation, int attackPower,
                                     Instruction::AffectedPlayer playerAffected, DefenseType defenseType) : Instruction(
        instructionRepresentation), attackPower(attackPower), playerAffected(playerAffected), defenseType(
        defenseType) {}

InstructionResponse AttackInstruction::getResponse() {
    return {attackPower, -1,1};
}


