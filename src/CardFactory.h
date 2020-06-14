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

class CardFactory {
    DataLoader dataLoader = DataLoader();

public:

    static std::vector< std::shared_ptr<RoleCard> > getAllRoleCards();

    static std::vector< std::shared_ptr<PlayCard> > getNewStackOfCards();

    std::vector< std::shared_ptr<PlayCard> > getSavedStack();

    std::vector< std::shared_ptr<Player> > getSavedPlayers();

private:
    static std::vector<std::shared_ptr<PlayCard>>  loadPlayCards(std::vector<std::vector<std::string>> &data);

    static std::vector<std::shared_ptr<RoleCard> > loadRoleCards(std::vector<std::vector<std::string>> &data) ;


    /**Need separate function due to different store format.*/
    static std::vector<std::shared_ptr<PlayCard>>  loadSavedPlayCards(std::vector<std::vector<std::string>> &data);

};