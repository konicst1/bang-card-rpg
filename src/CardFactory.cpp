//
// Created by stepan on 5/1/20.
//

#include <iostream>
#include <algorithm>
#include <memory>
#include <random>
#include "CardFactory.h"

std::vector< std::shared_ptr<Card> > CardFactory::getAllRoleCards() {
    std::vector<std::shared_ptr<Card>> cards;
    std::vector<std::vector<std::string>> data = dataLoader.loadAllRoleCards();

    /*Format of role card in the file
     * image path
     * name
     * health count
     * instructions
     * */

    for (auto a : data) {
        std::vector<std::string> ins;
        for(unsigned int i = 3; i < a.size(); i++) {
            ins.push_back(a[i]);
        }
        Action b = Action(ins);
        Card role = RoleCard(/*image*/ a[0], /*name*/ a[1],/*health count*/ std::stoi(a[2]), b);
        cards.push_back(std::make_shared<Card>(role));
    }

    return cards;
}

std::vector< std::shared_ptr<PlayCard>> CardFactory::getNewStackOfCards() {
    std::vector< std::shared_ptr<PlayCard> > cards;
    std::vector<std::vector<std::string>> data = DataLoader::loadAllPlayCards();

    /*Format of role card in the file
 * image path
 * name
 * instructions
 * */

    for (auto a : data) {
        std::vector<std::string> ins;
        for(unsigned int i = 2; i < a.size(); i++) {
            ins.push_back(a[i]);
        }
        Action b = Action(ins);

        PlayCard card =  PlayCard(a[0], "spades" , a[1], 9, b);
        PlayCard card1 = PlayCard(a[0], "heart" , a[1], 9, b);
        PlayCard card2 = PlayCard(a[0], "diamond" , a[1], 9, b);
        PlayCard card3 = PlayCard(a[0], "club" , a[1], 9, b);

        cards.push_back(std::make_shared<PlayCard>(card));
        cards.push_back(std::make_shared<PlayCard>(card1));
        cards.push_back(std::make_shared<PlayCard>(card2));
        cards.push_back(std::make_shared<PlayCard>(card3));

    }
    //shuffle
    srand(unsigned(time(nullptr)));
    std::shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()()));
    return cards;

}
