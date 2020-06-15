//
// Created by stepan on 5/3/20.
//

#pragma once

class GameManager;

#include "Player.h"

/**
 * Class that represent one move. Player can play one card during the move. Move can consist of several submoves.
 * */
class Move {
    std::vector<std::string> menuOptions{"Start move", "Save and Exit", "Exit",         //string options for move menu (to start move, save/exit etc.)
                                         "Any other input will start the move..."};

protected:
    std::shared_ptr<Player> leader;                                                     //player that is on the move
    std::shared_ptr<Player> target;                                                     //second player

public:
    Move(std::shared_ptr<Player> &leader, std::shared_ptr<Player> &target) : leader(leader),
                                                                             target(target) {}
    /**
     * Introduces the move and presents the menu.
     * */
    virtual int init();

    //getters
    const std::shared_ptr<Player> &getLeader() const;

    const std::shared_ptr<Player> &getTarget() const;

    /**
     * Cards are presented. Player will pick the cards and card instructions will be translated and performed.
     * */
    virtual void startMove(GameManager &m);


};




