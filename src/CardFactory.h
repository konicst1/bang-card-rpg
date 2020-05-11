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

    std::vector< std::shared_ptr<Card> > getAllRoleCards();

    static std::vector< std::shared_ptr<PlayCard> > getNewStackOfCards();



};




