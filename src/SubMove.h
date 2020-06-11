//
// Created by stepan on 6/10/20.
//

#pragma once
class GameManager;

#include "Move.h"

class SubMove : public Move{

    int attackStr;

public:
    SubMove(std::shared_ptr<Player> &leader, std::shared_ptr<Player> &target, int attackStr);

    void init() override;

    int getDefenseValue(GameManager & m);

    int getAttackValue(GameManager & m);
};




