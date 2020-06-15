//
// Created by stepan on 5/1/20.
//

#pragma once


#include <string>
#include <vector>
#include <memory>
#include "RoleCard.h"
#include "DataLoader.h"
#include "PlayCard.h"

/**
 * Factory class
 * Creates card objects using raw data
 * */
class CardFactory {
    DataLoader dataLoader = DataLoader();

public:

    /**
     * @returns list of smart pointers of all RoleCards
     * */
    static std::vector< std::shared_ptr<RoleCard> > getAllRoleCards();


    /**
     * @returns New stack (as list) of PlayCards (as smart pointers) ready to be used when creating new game. Already shuffled.
     * */
    static std::vector< std::shared_ptr<PlayCard> > getNewStackOfCards();

    /**
     * @returns List of PlayCards (as smart pointers) saved from previous game
     * */
    std::vector< std::shared_ptr<PlayCard> > getSavedStack();

    /**
     * @returns Two players in vector loaded from previous saved game (with loaded card stack)
     * */
    std::vector< std::shared_ptr<Player> > getSavedPlayers();

private:

    /**
     * Helper function for loading play cards
     * */
    static std::vector<std::shared_ptr<PlayCard>>  loadPlayCards(std::vector<std::vector<std::string>> &data);

    /**
     * Helper function for loading role cards
     * */
    static std::vector<std::shared_ptr<RoleCard> > loadRoleCards(std::vector<std::vector<std::string>> &data) ;


    /**
     * Helper function for loading playcards from saved game.
     * Need separate function due to different store format.
     * */
    static std::vector<std::shared_ptr<PlayCard>>  loadSavedPlayCards(std::vector<std::vector<std::string>> &data);

};