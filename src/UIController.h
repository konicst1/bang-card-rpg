//
// Created by stepan on 5/5/20.
//

#pragma once


#include "Player.h"

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

    void switchPlayers();

    void startMove(Player & player);

    void print(std::string a);

    void println(std:: string b);

};




