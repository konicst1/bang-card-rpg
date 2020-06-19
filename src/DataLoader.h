//
// Created by stepan on 5/1/20.
//

#pragma once


#include <vector>
#include <string>
#include "PlayCard.h"


/**
 * Loader class that loads/saves raw data from/to files.
 * */
class DataLoader {
public:
    /**
     * Load raw data of role cards.
     * @returns Vector of vectors of strings.
     * */
    static std::vector<std::vector<std::string>> loadAllRoleCards();

    /**
     * Load raw data of role cards.
     * @returns Vector of vectors of strings.
     * */
    static std::vector<std::vector<std::string>> loadAllPlayCards();

    /**
     * Persist gameplay.
     * */
    static int saveGame(const std::string& player1Name, int player1Health, const std::string& player1Image,
                        const std::vector<std::shared_ptr<Instruction>>& player1Instructions,
                        std::vector<std::shared_ptr<PlayCard>> player1Cards,
                        const std::string& player2Name, int player2Health, const std::string& player2Image,
                        const std::vector<std::shared_ptr<Instruction>>& player2Instructions,
                        std::vector<std::shared_ptr<PlayCard>> player2Cards,
                        std::vector<std::shared_ptr<PlayCard>> gameStack, bool singlePlayer);

    /**
     * Load saved player data from previous gameplay.
     * @returns Vector of vectors of strings in this format: Player, PlayerStack
     * @param string: "player1" or "player2"
     * */
    static std::vector<std::vector<std::string>> loadSavedPlayer(const std::string& player);


    /**
   * Load saved game cards stack data from previous gameplay.
   * @returns Vector of vectors of strings in this format
   *
     */
    static std::vector<std::vector<std::string>> loadGameStack();

    /**Persists role card by given information. */
    static void persistRoleCard(const std::string& image, const std::string& name, int health, const std::vector<std::string>& instructions);

    /**
     * @returns 1 if saved game is single playe, else return 0
     * **/
    static int savedGameSingleplayer();

    /**
     * Persist Play Card
     * @returns name of the new file for tha play card
     * */
    static int persistPlayCard(const std::string& image, const std::string& name, const std::vector<std::string>& instructions);


private:
    /**
     * Helper function that loads single card.
     * @param Input file stream to read from.
     * @returns Vector of strings with data.
     * */
    static std::vector<std::string> loadCard(std::ifstream& file);



};




