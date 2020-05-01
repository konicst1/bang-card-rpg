//
// Created by stepan on 5/1/20.
//

#include <iostream>
#include "CardFactory.h"

std::vector<RoleCard> CardFactory::getAllRoleCards() {
    std::vector<RoleCard> cards;
    std::vector< std::vector<std::string>> data = dataLoader.loadAllRoleCards();

    /*Format of role card in the file
     * image path
     * name
     * health count
     *
     * */

    for(auto a : data){
        RoleCard role = RoleCard(/*image*/ a[0], /*logo*/ "nullptr", /*name*/ a[1], /*number*/ 0, /*health count*/ std::stoi(a[2]));
        cards.push_back(role);
    }


    return cards;
}
