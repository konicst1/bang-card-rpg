//
// Created by stepan on 5/1/20.
//

#include <iostream>
#include "CardFactory.h"

std::vector<RoleCard> CardFactory::getAllRoleCards() {
    std::vector<RoleCard> cards;
    std::vector< std::vector<std::string>> data = dataLoader.loadAllRoleCards();

    for(auto a : data){

    }


    return cards;
}
