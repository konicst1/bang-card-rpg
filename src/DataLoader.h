//
// Created by stepan on 5/1/20.
//

#pragma once


#include <vector>
#include <string>
#include "PlayCard.h"

class DataLoader {
public:
    static std::vector<std::vector<std::string>> loadAllRoleCards();

    static std::vector<std::vector<std::string>> loadAllPlayCards();

    static int saveGame(std::string player1Name, int player1Health, std::string player1Image, std::vector<std::string> player1Instructions, std::vector<std::shared_ptr<PlayCard>> player1Cards,
                        std::string player2Name, int player2Health, std::string player2Image, std::vector<std::string> player2Instructions,  std::vector<std::shared_ptr<PlayCard>> player2Cards);

    /**
     * Player1, Player2, Player1stack, Player2Stack, GameStack?
     * */
    static std::vector<std::vector<std::string>> loadSavedGameData();

};




