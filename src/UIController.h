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
    int selectRole(std::string a, std::string b, std::string c);



    static void clearScreen();

    static void switchPlayers(std::shared_ptr<Player> player);

   // void startMove(Player & player);

    static void print(std::string a);

    static void println(std:: string b);

    static void presentOptions(std::vector<std::string> options);

    static void startMove(Move & move);

    static void presentCards(std::vector<std::shared_ptr<PlayCard>> cards);

    static int getChoice(int range, int lower = 1);

    static void endGame(std::string winner);

};




