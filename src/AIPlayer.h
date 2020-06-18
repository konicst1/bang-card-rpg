//
// Created by stepan on 6/15/20.
//

#pragma once


#include "Player.h"

class AIPlayer : public Player {
public:
    AIPlayer(const std::vector<std::shared_ptr<PlayCard>> &cards, const std::shared_ptr<RoleCard> &role);

    AIPlayer(const std::shared_ptr<RoleCard> &role);

    int getDefenseChoice(int attackStrength) override;

    int getAttackChoice(int attackStrength) override;

    int getCardChoice() override;

    int getPlayChoice(Move &) override;
};


