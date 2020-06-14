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

    static int saveGame(std::string player1Name, int player1Health, std::string player1Image,
                        std::vector<std::string> player1Instructions,
                        std::vector<std::shared_ptr<PlayCard>> player1Cards,
                        std::string player2Name, int player2Health, std::string player2Image,
                        std::vector<std::string> player2Instructions,
                        std::vector<std::shared_ptr<PlayCard>> player2Cards,
                        std::vector<std::shared_ptr<PlayCard>> gameStack);

    /**
     * Player, PlayerStack, accept player1 or player2
     * */
    static std::vector<std::vector<std::string>> loadSavedPlayer(std::string player);

    static std::vector<std::vector<std::string>> loadGameStack();

private:
    static std::vector<std::string> loadCard(std::ifstream &file);

    static std::string getPlayCardType(std::shared_ptr<PlayCard> card);

};




