//
// Created by stepan on 5/1/20.
//

#include <iostream>
#include <algorithm>
#include <memory>
#include <random>
#include <sstream>
#include "CardFactory.h"
#include "Player.h"
#include "AttackInstruction.h"
#include "DefenseInstruction.h"
#include "GiveCardInstruction.h"
#include "AddHealthInstruction.h"
#include "Instruction.h"
#include "TakeCardInstruction.h"
#include "RobCardInstruction.h"
#include "IfNextCardIsInstruction.h"
#include "AIPlayer.h"


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
    std::shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()()));
    return cards;

}

std::vector<std::shared_ptr<PlayCard>> CardFactory::loadPlayCards(std::vector<std::vector<std::string>> &data) {
    std::vector<std::shared_ptr<PlayCard> > cards;

    /*Format of play card in the file
 * image path 0
 * name       1
 * instructions 2
 * */

    for (auto a : data) {
        if(a.size() < 2){
            throw std::invalid_argument("Error loading data");
        }
        std::vector<std::shared_ptr<Instruction>> ins;

        for (unsigned int i = 2; i < a.size(); i++) {
            ins.push_back(buildInstruction(a[i]));
        }


        PlayCard card = PlayCard(a[0], PlayCard::CardSymbol::HEART, a[1], 9, ins);
        PlayCard card1 = PlayCard(a[0], PlayCard::CardSymbol::SPADES, a[1], 9, ins);
        PlayCard card2 = PlayCard(a[0], PlayCard::CardSymbol::DIAMOND, a[1], 9, ins);
        PlayCard card3 = PlayCard(a[0], PlayCard::CardSymbol::CLUB, a[1], 9, ins);

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
    std::shared_ptr<Player> p2;

    if(DataLoader::savedGameSingleplayer()){
         p2 = std::make_shared<AIPlayer>(AIPlayer(loadSavedPlayCards(ins2), loadRoleCards(ins)[0]));
    }else{
         p2 = std::make_shared<Player>(Player(loadSavedPlayCards(ins2), loadRoleCards(ins)[0]));
    }


    result.push_back(std::make_shared<Player>(p1));
    result.push_back(p2);

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
        if(a.size() < 3){
            throw std::invalid_argument("Error loading data");
        }

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
 * number  3
 * instructions 4
 * */

    for (auto a : data) {
        if(a.size() < 3){
            throw std::invalid_argument("Error loading data");
        }
        std::vector<std::shared_ptr<Instruction>> ins;

        for (unsigned int i = 4; i < a.size(); i++) {
            ins.push_back(buildInstruction(a[i]));
        }
        PlayCard card = PlayCard(a[0], PlayCard::getCardSymbolByName(a[1]), a[2], std::stoi(a[3]), ins);

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

        affectedPlayer = AttackInstruction::getAffectedPlayerByName(segList[2]);
        defenseType = AttackInstruction::getDefenseTypeByName(segList[3]);

        i = std::make_shared<AttackInstruction>(
                AttackInstruction(ins, std::stoi(segList[1]), affectedPlayer, defenseType));
    } else if (segList[0] == "defense") {
        i = std::make_shared<DefenseInstruction>(DefenseInstruction(ins, std::stoi(segList[1])));
    } else if (segList[0] == "giveCard") {
        Instruction::AffectedPlayer affectedPlayer = Instruction::getAffectedPlayerByName(segList[1]);
        i = std::make_shared<GiveCardInstruction>(GiveCardInstruction(ins, affectedPlayer));
    } else if (segList[0] == "addHealth") {
        Instruction::AffectedPlayer affectedPlayer = Instruction::getAffectedPlayerByName(segList[2]);
        i = std::make_shared<AddHealthInstruction>(AddHealthInstruction(ins, std::stoi(segList[1]), affectedPlayer));
    }else if(segList[0] == "takeCard"){
        Instruction::AffectedPlayer affectedPlayer = Instruction::getAffectedPlayerByName(segList[1]);
        i = std::make_shared<TakeCardInstruction>(TakeCardInstruction(ins, affectedPlayer));
    }else if(segList[0] == "robCard"){
        Instruction::AffectedPlayer affectedPlayer = Instruction::getAffectedPlayerByName(segList[1]);
        i = std::make_shared<RobCardInstruction>(RobCardInstruction(ins, affectedPlayer));
    }else if(segList[0] == "ifNextCardIs"){
        PlayCard::CardSymbol symbol = PlayCard::getCardSymbolByName(segList[1]);
        i = std::make_shared<IfNextCardIsInstruction>(IfNextCardIsInstruction(ins, symbol));
    }

    return i;

}
