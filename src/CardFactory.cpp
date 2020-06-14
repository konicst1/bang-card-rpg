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
#include "DonorAction.h"
#include "Player.h"


std::vector<std::shared_ptr<RoleCard> > CardFactory::getAllRoleCards() {
    std::vector<std::shared_ptr<RoleCard>> cards;
    std::vector<std::vector<std::string>> data = DataLoader::loadAllRoleCards();

    cards = loadRoleCards(data);
    return cards;
}

std::vector<std::shared_ptr<PlayCard>> CardFactory::getNewStackOfCards() {
    std::vector<std::shared_ptr<PlayCard> > cards;
    std::vector<std::vector<std::string>> data = DataLoader::loadAllPlayCards();

    cards = loadPlayCards(data);
    //shuffle
    srand(unsigned(time(nullptr)));
    std::shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()()));
    return cards;

}

std::vector<std::shared_ptr<PlayCard>> CardFactory::loadPlayCards(std::vector<std::vector<std::string>> &data) {
    std::vector<std::shared_ptr<PlayCard> > cards;

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
        }else if(!a[2].compare("donor")){
            for (unsigned int i = 3; i < a.size(); i++) {
                ins.push_back(a[i]);
            }
            b = std::make_shared<Action>(Action(ins));
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


    return cards;

}

std::vector<std::shared_ptr<PlayCard> > CardFactory::getSavedStack() {
    std::vector<std::shared_ptr<PlayCard> > cards;
    std::vector<std::vector<std::string>> data = DataLoader::loadGameStack();

    cards = loadPlayCards(data);

    return cards;
}

std::vector<std::shared_ptr<Player> > CardFactory::getSavedPlayers() {
    std::vector<std::shared_ptr<Player> > result;
    std::vector<std::vector<std::string>> data = DataLoader::loadSavedPlayer("player1");
    std::vector<std::vector<std::string>> ins;
    std::vector<std::vector<std::string>> ins2;
    ins.push_back(data[0]);

    for(unsigned int i = 1; i < data.size(); i++){
        ins2.push_back(data[i]);
    }
    Player p1 = Player(loadPlayCards(ins2), loadRoleCards(ins)[0]);

    data = DataLoader::loadSavedPlayer("player2");
    ins.clear();
    ins2.clear();

    ins.push_back(data[0]);

    for(unsigned int i = 1; i < ins.size(); i++){
        ins2.push_back(data[i]);
    }
    Player p2 = Player(loadPlayCards(ins2), loadRoleCards(ins)[0]);

    result.push_back(std::make_shared<Player>(p1));
    result.push_back(std::make_shared<Player>(p2));

    return result;

}

std::vector<std::shared_ptr<RoleCard> > CardFactory::loadRoleCards(std::vector<std::vector<std::string>> &data) {
    std::vector<std::shared_ptr<RoleCard>> cards;
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
