//
// Created by stepan on 6/15/20.
//

#pragma once


#include "Player.h"

class AIPlayer : public Player{



    int getDefenseChoice(int attackStrength) override;

    int getAttackChoice(int attackStrength) override;

    int getCardChoice() override;
};




