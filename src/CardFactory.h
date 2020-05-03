//
// Created by stepan on 5/1/20.
//

#pragma once


#include <string>
#include <vector>
#include "RoleCard.h"
#include "DataLoader.h"
#include "PlayCard.h"

class CardFactory {
    DataLoader dataLoader = DataLoader();

public:

    std::vector<RoleCard> getAllRoleCards();

    std::vector<PlayCard> getNewStackOfCards();



};




