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
    static int saveGame(std::string player1Name, int player1Health, std::string player1Image,
                        std::vector<std::shared_ptr<Instruction>> player1Instructions,
                        std::vector<std::shared_ptr<PlayCard>> player1Cards,
                        std::string player2Name, int player2Health, std::string player2Image,
                        std::vector<std::shared_ptr<Instruction>> player2Instructions,
                        std::vector<std::shared_ptr<PlayCard>> player2Cards,
                        std::vector<std::shared_ptr<PlayCard>> gameStack);

    /**
     * Load saved player data from previous gameplay.
     * @returns Vector of vectors of strings in this format: Player, PlayerStack
     * @param string: "player1" or "player2"
     * */
    static std::vector<std::vector<std::string>> loadSavedPlayer(std::string player);


    /**
   * Load saved game cards stack data from previous gameplay.
   * @returns Vector of vectors of strings in this format
   *
     */
    static std::vector<std::vector<std::string>> loadGameStack();

    /**Persists role card by given information. */
    static void persistRoleCard(std::string image, std::string name, int health, std::vector<std::string> instructions);

    /**Persists play attack card by given information. */
    static void
    persistAttackCard(std::string image, std::string name, int leaderHealth, int leaderMana, int targetHealth,
                      int targetMana, std::vector<std::string> instructions);

    /**Persists play defense card by given information. */
    static void persistDefenseCard(std::string image, std::string name, int healthDefense, int manaDefense,
                                   std::vector<std::string> instructions);

    /**Persists play card of other type by given information. */
    static void persistOtherPlayCard(std::string image, std::string name,
                                     std::vector<std::string> instructions);

private:
    /**
     * Helper function that loads single card.
     * @param Input file stream to read from.
     * @returns Vector of strings with data.
     * */
    static std::vector<std::string> loadCard(std::ifstream &file);

    /**
     * Helper function to find type of the card.
     * @returns attack/defense/donor/other
     * @obsolete
     * */
    static std::string getPlayCardType(std::shared_ptr<PlayCard> card);


    /**
     * @returns name of the new file for tha play card
     * */
    static int persistPlayCard();

};




