//
// Created by stepan on 5/1/20.
//

#include <iostream>
#include <algorithm>
#include <memory>
#include <random>
#include <sstream>
#include "CardFactory.h"
#include "AttackAction.h"
#include "DefenseAction.h"
#include "DonorAction.h"
#include "Player.h"
#include "AttackInstruction.h"


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

    /*Format of play card in the file
 * image path 0
 * name       1                 obsolete
                             * type (attack/defense/donor)
                             * attack - decreaseHealthLeader, decreaseManaLeader, decreaseHealthTarget, decreaseManaTarget
                             * defense - healthDefensePower, manaDefensePower
 * instructions 2
 * */

    for (auto a : data) {
        std::vector<std::shared_ptr<Instruction>> ins;

        for (unsigned int i = 2; i < a.size(); i++) {
            ins.push_back(buildInstruction(a[i]));
        }


        PlayCard card = PlayCard(a[0], "spades", a[1], 9, ins);
        PlayCard card1 = PlayCard(a[0], "heart", a[1], 9, ins);
        PlayCard card2 = PlayCard(a[0], "diamond", a[1], 9, ins);
        PlayCard card3 = PlayCard(a[0], "club", a[1], 9, ins);

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

    cards = loadSavedPlayCards(data);

    return cards;
}

std::vector<std::shared_ptr<Player> > CardFactory::getSavedPlayers() {
    std::vector<std::shared_ptr<Player> > result;
    std::vector<std::vector<std::string>> data = DataLoader::loadSavedPlayer("player1");
    std::vector<std::vector<std::string>> ins;
    std::vector<std::vector<std::string>> ins2;
    ins.push_back(data[0]);

    for (unsigned int i = 1; i < data.size(); i++) {
        ins2.push_back(data[i]);
    }
    Player p1 = Player(loadSavedPlayCards(ins2), loadRoleCards(ins)[0]);

    data = DataLoader::loadSavedPlayer("player2");
    ins.clear();
    ins2.clear();

    ins.push_back(data[0]);

    for (unsigned int i = 1; i < data.size(); i++) {
        ins2.push_back(data[i]);
    }
    Player p2 = Player(loadSavedPlayCards(ins2), loadRoleCards(ins)[0]);

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
        std::vector<std::shared_ptr<Instruction>> ins;
        for (unsigned int i = 3; i < a.size(); i++) {
            ins.push_back(buildInstruction(a[i]));
        }

        int health = std::stoi(a[2]);
        RoleCard role = RoleCard(/*image*/ a[0], /*name*/ a[1],/*health count*/ health, ins);

        cards.push_back(std::make_shared<RoleCard>(role));
    }

    return cards;
}

std::vector<std::shared_ptr<PlayCard>> CardFactory::loadSavedPlayCards(std::vector<std::vector<std::string>> &data) {
    std::vector<std::shared_ptr<PlayCard> > cards;
/*Format of play card in the file
 * image path  0
 * symbol  1
 * name  2
 * number  3                            OBSOLETE
                                    //     * type (attack/defense/donor)  4
                                    //     * attack - decreaseHealthLeader, decreaseManaLeader, decreaseHealthTarget, decreaseManaTarget
                                    //     * defense - healthDefensePower, manaDefensePower
 * instructions 4
 * */

    for (auto a : data) {
        std::vector<std::shared_ptr<Instruction>> ins;

        for (unsigned int i = 4; i < a.size(); i++) {
            ins.push_back(buildInstruction(a[i]));
        }
        PlayCard card = PlayCard(a[0], a[1], a[2], std::stoi(a[3]), ins);

        cards.push_back(std::make_shared<PlayCard>(card));

    }

    return cards;
}

std::shared_ptr<Instruction> CardFactory::buildInstruction(const std::string &ins) {
    std::stringstream toSplit(ins);
    std::string segment;
    std::vector<std::string> segList;

    std::shared_ptr<Instruction> i;

    while (std::getline(toSplit, segment, '-')) {
        segList.push_back(segment);
    }

    if (segList[0] == "attack") {
        AttackInstruction::AffectedPlayer affectedPlayer;
        AttackInstruction::DefenseType defenseType;

        if (segList[2] == "leader") {
            affectedPlayer = AttackInstruction::AffectedPlayer::LEADER;
        } else if (segList[2] == "target") {
            affectedPlayer = AttackInstruction::AffectedPlayer::TARGET;
        }

        if (segList[3] == "defense") {
            defenseType = AttackInstruction::DefenseType::DEFENSE;
        } else if (segList[3] == "attack") {
            defenseType = AttackInstruction::DefenseType::ATTACK;
        } else if (segList[3] == "none") {
            defenseType = AttackInstruction::DefenseType::NONE;
        }

        i = std::make_shared<AttackInstruction>(AttackInstruction(ins, std::stoi(segList[1]), affectedPlayer, defenseType));
        return i;
    }

}
