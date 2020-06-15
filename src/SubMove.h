//
// Created by stepan on 6/10/20.
//

#pragma once
class GameManager;

#include "Move.h"

/**
 * Submove class used for getting response from the second player in the main move.
 * */
class SubMove : public Move{

    int attackStr;      //attack strength to react to

public:
    SubMove(std::shared_ptr<Player> &leader, std::shared_ptr<Player> &target, int attackStr);

    /**
     * Switch players and introduce move to the player
     * */
    int init() override;

    /**
     * Get defense power from the player.
     * @param m = instance of game manager of the current game
     * */
    int getDefenseValue(GameManager & m);

    /**
     * Get attack power from the player.
     * @param m = instance of game manager of the current game
     * */
    int getAttackValue(GameManager & m);

    /**
     * Get card from player.
     * @returns smart pointer of the card that has been given up
     * */
    std::shared_ptr<PlayCard> getCardFromLeader();
};




