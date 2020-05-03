//
// Created by stepan on 5/1/20.
//

#include <iostream>
#include "CardFactory.h"

std::vector<RoleCard> CardFactory::getAllRoleCards() {
    std::vector<RoleCard> cards;
    std::vector<std::vector<std::string>> data = dataLoader.loadAllRoleCards();

    /*Format of role card in the file
     * image path
     * name
     * health count
     * instructions
     * */

    for (auto a : data) {
        std::vector<std::string> ins;
        for(int i = 3; i < a.size(); i++) {
            ins.push_back(a[i]);
        }
        Action b = Action(ins);
        RoleCard role = RoleCard(/*image*/ a[0], /*name*/ a[1],/*health count*/ std::stoi(a[2]), b);
        cards.push_back(role);
    }

    return cards;
}

std::vector<PlayCard> CardFactory::getNewStackOfCards() {
    std::vector<PlayCard> cards;
    std::vector<std::vector<std::string>> data = dataLoader.loadAllPlayCards();

    /*Format of role card in the file
 * image path
 * name
 * instructions
 * */

    for (auto a : data) {
        std::vector<std::string> ins;
        for(int i = 2; i < a.size(); i++) {
            ins.push_back(a[i]);
        }
        Action b = Action(ins);
        PlayCard card = PlayCard(a[0], "spades" ,a[1],9, b);
        PlayCard card1 = PlayCard(a[0], "heart" ,a[1],9, b);
        PlayCard card2 = PlayCard(a[0], "diamond" ,a[1],9, b);
        PlayCard card3 = PlayCard(a[0], "club" ,a[1],9, b);
        cards.push_back(card);
        cards.push_back(card1);
        cards.push_back(card2);
        cards.push_back(card3);

    }
    return cards;

}
