//
// Created by stepan on 5/1/20.
//

#include <iostream>
#include <algorithm>
#include <memory>
#include <random>
#include "CardFactory.h"
#include "AttackAction.h"
#include "DefenseAction.h"


std::vector<std::shared_ptr<RoleCard> > CardFactory::getAllRoleCards() {
    std::vector<std::shared_ptr<RoleCard>> cards;
    std::vector<std::vector<std::string>> data = dataLoader.loadAllRoleCards();

    /*Format of role card in the file
     * image path
     * name
     * health count
     * instructions
     * */

    for (auto a : data) {
        std::vector<std::string> ins;
        for (unsigned int i = 3; i < a.size(); i++) {
            ins.push_back(a[i]);
        }
        Action b = Action(ins);
        int health = std::stoi(a[2]);
        RoleCard role = RoleCard(/*image*/ a[0], /*name*/ a[1],/*health count*/ health, std::make_shared<Action>(b));

        cards.push_back(std::make_shared<RoleCard>(role));
    }

    return cards;
}

std::vector<std::shared_ptr<PlayCard>> CardFactory::getNewStackOfCards() {
    std::vector<std::shared_ptr<PlayCard> > cards;
    std::vector<std::vector<std::string>> data = DataLoader::loadAllPlayCards();

    /*Format of role card in the file
 * image path
 * name
     * type (attack/defense/donor)
     * attack - decreaseHealthLeader, decreaseManaLeader, decreaseHealthTarget, decreaseManaTarget
     * defense - healthDefensePower, manaDefensePower
 * instructions
 * */

    for (auto a : data) {
        std::vector<std::string> ins;

        std::shared_ptr<Action> b;

        if (!a[2].compare("attack")) {
            for (unsigned int i = 7; i < a.size(); i++) {
                ins.push_back(a[i]);
            }
            b = std::make_shared<AttackAction>(AttackAction(ins, std::stoi(a[3]), std::stoi(a[4]), std::stoi(a[5]), std::stoi(a[6])));
        }else if(!a[2].compare("defense")){
            for (unsigned int i = 5; i < a.size(); i++) {
                ins.push_back(a[i]);
            }
            b = std::make_shared<DefenseAction>(DefenseAction(ins, std::stoi(a[3]), std::stoi(a[4])));
        }

        PlayCard card = PlayCard(a[0], "spades", a[1], 9, b);
        PlayCard card1 = PlayCard(a[0], "heart", a[1], 9, b);
        PlayCard card2 = PlayCard(a[0], "diamond", a[1], 9, b);
        PlayCard card3 = PlayCard(a[0], "club", a[1], 9, b);

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
