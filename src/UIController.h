//
// Created by stepan on 5/5/20.
//

#pragma once


#include "Player.h"
#include "Move.h"

/**
 * Class that provides communication with players.
 * */
class UIController {
public:
    /**
     * Starts the game.
     * */
    static void startGame();

    /**
     * @returns int in range {1 - 3} that stands for index+1 of name of selected role offered to player
     * */
    static int selectRole(const std::shared_ptr<RoleCard>&  a, const std::shared_ptr<RoleCard>&  b, const std::shared_ptr<RoleCard>&  c);

    /** Clear the screen.*/
    static void clearScreen();

    /** Change control for another player
     * @param player = smart pointer of the player to control the game
     * */
    static void switchPlayers(const std::shared_ptr<Player>& player);

    /** Show message to player*/
    static void print(const std::string& a);

    /** Show message to player with new line.*/
    static void println(const std::string& b);

    /**
     * Present string options.
     * @param options vector of strings
     * */
    static void presentOptions(std::vector<std::string> options);

    /**
     * Present players and game status and start the move.
     * @param move with information
     * */
    static void startMove(Move &move);

    /**
     * Present cards in format to choose from.
     * @param vector of smart pointers to cards to be presented
     * */
    static void presentCards(std::vector<std::shared_ptr<PlayCard>> cards);

    /**
     * Choose number from range.
     * @param lower lower bound of interval to choose from, default is 1
     * @param upper bound of interval to choose from
     * @returns int - choice from the player
     * */
    static int getChoice(int range, int lower = 1);

    /** Show end game message and announce the winner.*/
    static void endGame(const std::string& winner);

    /**
     * End move. Present cards and wait for response.
     * */
    static void endMove(const std::shared_ptr<Player> &leader, const std::shared_ptr<Player> &target) ;

    /**Get string from input */
    static std::string getStringInput();

    /**Get int from input*/
    static int getIntInput();

};




