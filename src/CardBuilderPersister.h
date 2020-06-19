//
// Created by stepan on 6/16/20.
//

#pragma once

#include <regex>

class CardBuilderPersister {
    std::vector<std::regex> instructionRegexSet{std::regex("^attack-.*[0-9]-leader-defense$"),
                                                std::regex("^attack-.*[0-9]-leader-attack$"),
                                                std::regex("^attack-.*[0-9]-leader-none$"),
                                                std::regex("^attack-.*[0-9]-target-defense$"),
                                                std::regex("^attack-.*[0-9]-target-attack$"),
                                                std::regex("^attack-.*[0-9]-target-none$"),
                                                std::regex("^defense-.*[0-9]$"), std::regex("^giveCard-leader$"),
                                                std::regex("^giveCard-target$"),
                                                std::regex("^addHealth-.*[0-9]-leader$"),
                                                std::regex("^addHealth-.*[0-9]-target$"),
                                                std::regex("^takeCard-target$"),
                                                std::regex("^takeCard-leader$"), std::regex("^robCard-target$"),
                                                std::regex("^robCard-leader$"), std::regex("^ifNextCardIs-heart$"),
                                                std::regex("^ifNextCardIs-spades$"), std::regex("^ifNextCardIs-club$"),
                                                std::regex("^ifNextCardIs-diamond$")};

    std::vector<std::string> instructionStringSet{
            "attack-[attack_power {0-9}]-[target_player{leader/target}]-[defense_type{defense/attack/none}]",
            "defense-[defense_power {0-9}]", "giveCard-[target_player {leader/target}]",
            "addHealth-[health_number {0-9}]-[target_player {leader/target}]",
            "takeCard-[target_player {leader/target}]", "robCard-[target_player {leader/target}]",
            "ifNextCardIs-[card_symbol {heart/spades/club/diamond}]"};


public:
    /**Create custom card */
    void createCard();

private:
    /**Create custom role card */
    void createRoleCard();

    /**Create custom play card */
    void createPlayCard();

    /**Check if instruction is valid */
    bool instructionExists(const std::string& s);

    //todo comment
    std::vector<std::string> loadInstructions();
};




