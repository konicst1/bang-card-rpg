//
// Created by stepan on 5/3/20.
//

#pragma once

class GameManager;

#include "Player.h"


class Move {

    std::shared_ptr<Player> leader;
    std::shared_ptr<Player> target;


public:
    Move(std::shared_ptr<Player> &leader, std::shared_ptr<Player> &target) : leader(leader),
                                                                                         target(target) {}

    void init();

    const std::shared_ptr<Player> &getLeader() const;

    const std::shared_ptr<Player> &getTarget() const;

    void startMoveCycle(GameManager & m);


};




