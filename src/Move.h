//
// Created by stepan on 5/3/20.
//

#pragma once

class GameManager;

#include "Player.h"


class Move {
    std::vector<std::string> menuOptions {"Start move", "Save and Exit" ,"Exit", "Any other input will start the move..."};

protected:
    std::shared_ptr<Player> leader;
    std::shared_ptr<Player> target;

public:
    Move(std::shared_ptr<Player> &leader, std::shared_ptr<Player> &target) : leader(leader),
                                                                             target(target) {}

    virtual int init();

    const std::shared_ptr<Player> &getLeader() const;

    const std::shared_ptr<Player> &getTarget() const;

    virtual void startMove(GameManager &m);


};




