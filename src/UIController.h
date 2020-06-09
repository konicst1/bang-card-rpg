//
// Created by stepan on 5/5/20.
//

#pragma once


#include "Player.h"
#include "Move.h"

class UIController {
public:


    void startGame();

    /**
     * @returns int in range {1 - 3} that stands for index+1 of name of selected role offered to player
     * */
    int selectRoleA(std::string a, std::string b, std::string c);

    /**
    * @returns int in range {1 - 3} that stands for index+1 of name of selected role offered to player
    * */
    int selectRoleB(std::string a, std::string b, std::string c);

    static void clearScreen();

    void switchPlayers();

   // void startMove(Player & player);

    void print(std::string a);

    void println(std:: string b);

    static void prepareMove();

    static void startMove(Move & move);

    static void presentCards(std::vector<std::shared_ptr<PlayCard>> cards);

    static int getChoice(int range);

};




