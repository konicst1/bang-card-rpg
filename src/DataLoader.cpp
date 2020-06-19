//
// Created by stepan on 5/1/20.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "DataLoader.h"

std::vector<std::vector<std::string>> DataLoader::loadAllRoleCards() {
    std::vector<std::vector<std::string> > res;
    std::ifstream f = std::ifstream("../data/rolecards/rolesTotal");
    int n;
    f >> n;

    for (int i = 1; i <= n; i++) {
        std::ifstream file = std::ifstream("../data/rolecards/" + std::to_string(i));
        res.push_back(loadCard(file));
    }

    return res;
}

std::vector<std::vector<std::string>> DataLoader::loadAllPlayCards() {
    std::vector<std::vector<std::string> > res;

    std::ifstream f = std::ifstream("../data/playcards/cardsTotal");
    int n;
    f >> n;
    f.close();

    for (int i = 1; i <= n; i++) {
        std::ifstream file = std::ifstream("../data/playcards/" + std::to_string(i));
        res.push_back(loadCard(file));
    }

    return res;
}

std::vector<std::vector<std::string>> DataLoader::loadSavedPlayer(const std::string &player) {
    std::vector<std::vector<std::string> > res;
    std::ifstream file = std::ifstream("../data/save/" + player);
    res.push_back(loadCard(file));

    std::ifstream f = std::ifstream("../data/save/" + player + "Cards/cardsTotal");
    int n;
    f >> n;

    for (int i = 1; i <= n; i++) {
        std::string path = "../data/save/" + player + "Cards/" + std::to_string(i);
        std::ifstream file1 = std::ifstream(path);
        res.push_back(loadCard(file1));
    }

    return res;

}

std::vector<std::string> DataLoader::loadCard(std::ifstream &file) {
    std::vector<std::string> card;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            card.push_back(line);
        }
        file.close();
    }

    return card;
}

std::vector<std::vector<std::string>> DataLoader::loadGameStack() {
    std::vector<std::vector<std::string> > res;
    std::ifstream f = std::ifstream("../data/save/gameStack/cardsTotal");
    int n;
    f >> n;

    for (int i = 1; i <= n; i++) {
        std::ifstream file = std::ifstream("../data/save/gameStack/" + std::to_string(i));
        res.push_back(loadCard(file));
    }

    return res;
}

////    PlayCard role = RoleCard(/*image*/ a[0], /*name*/ a[1],/*health count*/ std::stoi(a[2]), b);
int DataLoader::saveGame(const std::string &player1Name, int player1Health, const std::string &player1Image,
                         const std::vector<std::shared_ptr<Instruction>> &player1Instructions,
                         std::vector<std::shared_ptr<PlayCard>> player1Cards,
                         const std::string &player2Name, int player2Health, const std::string &player2Image,
                         const std::vector<std::shared_ptr<Instruction>> &player2Instructions,
                         std::vector<std::shared_ptr<PlayCard>> player2Cards,
                         std::vector<std::shared_ptr<PlayCard>> gameStack) {
    std::ofstream f = std::ofstream("../data/save/player1");

    /*
     * storing players like this
     *
     *  imageName
     *  name
     *  healthCount
     *  vector of instructions
     *
     * */

    if (!f.good()) {
        return 0;
    }
    f << player1Image << std::endl << player1Name << std::endl << player1Health << std::endl;
    for (const auto &s : player1Instructions) {
        f << s->getInstructionRepresentation() << std::endl;
    }
    if (!f.good()) {
        return 0;
    }
    f.close();
    if (!f.good()) {
        return 0;
    }


    f = std::ofstream("../data/save/player2");
    f << player2Image << std::endl << player2Name << std::endl << player2Health << std::endl;
    for (const auto &s : player2Instructions) {
        f << s->getInstructionRepresentation() << std::endl;
    }
    f.close();
    if (!f.good()) {
        return 0;
    }

//PlayCard card =  PlayCard(a[0], "spades" , a[1], 9, b);
    /*
     * PlayCards are stored like this
     *
     * image
     * symbol
     * name
     * number
     * instructions
     * */

    f = std::ofstream("../data/save/player1Cards/cardsTotal");
    f << player1Cards.size();
    f.close();
    for (unsigned int i = 0; i < player1Cards.size(); i++) {
        f = std::ofstream("../data/save/player1Cards/" + std::to_string(i + 1));
        auto s = player1Cards[i];
        f << s->getImage() << std::endl << PlayCard::getCardSymbolAsString(s->getSymbol()) << std::endl << s->getName()
          << std::endl << s->getNumber()
          << std::endl;

        for (const auto &j : s->getInstructions()) {
            f << j->getInstructionRepresentation() << std::endl;
        }
    }
    f.close();
    if (!f.good()) {
        return 0;
    }

    f = std::ofstream("../data/save/player2Cards/cardsTotal");
    f << player2Cards.size();
    f.close();
    for (unsigned int i = 0; i < player2Cards.size(); i++) {
        auto s = player2Cards[i];
        f = std::ofstream("../data/save/player2Cards/" + std::to_string(i + 1));
        f << s->getImage() << std::endl << PlayCard::getCardSymbolAsString(s->getSymbol()) << std::endl << s->getName()
          << std::endl << s->getNumber()
          << std::endl;


        for (const auto &j : s->getInstructions()) {
            f << j->getInstructionRepresentation() << std::endl;
        }
    }
    f.close();
    if (!f.good()) {
        return 0;
    }


    f = std::ofstream("../data/save/gameStack/cardsTotal");
    f << gameStack.size();
    f.close();
    for (unsigned int i = 0; i < gameStack.size(); i++) {
        auto s = gameStack[i];
        f = std::ofstream("../data/save/gameStack/" + std::to_string(i + 1));
        f << s->getImage() << std::endl << PlayCard::getCardSymbolAsString(s->getSymbol()) << std::endl << s->getName()
          << std::endl << s->getNumber()
          << std::endl;


        for (const auto &j : s->getInstructions()) {
            f << j->getInstructionRepresentation() << std::endl;
        }
    }
    f.close();
    if (!f.good()) {
        return 0;
    }


    return 1;
}


void
DataLoader::persistRoleCard(const std::string &image, const std::string &name, int health,
                            const std::vector<std::string> &instructions) {
    std::ifstream f = std::ifstream("../data/rolecards/rolesTotal");
    int n;
    f >> n;
    n += 1;
    f.close();

    std::ofstream o = std::ofstream("../data/rolecards/rolesTotal");
    o << n;
    o = std::ofstream("../data/rolecards/" + std::to_string(n));

    o << image << std::endl << name << std::endl << health << std::endl;
    for (const auto &i : instructions) {
        o << i << std::endl;
    }
    o.close();

}

int DataLoader::persistPlayCard(const std::string &image, const std::string &name,
                                const std::vector<std::string> &instructions) {
    std::ifstream f = std::ifstream("../data/playcards/cardsTotal");
    int n;
    f >> n;
    n += 1;
    f.close();

    std::ofstream o = std::ofstream("../data/playcards/cardsTotal");
    o << n;
    o.close();
    o = std::ofstream("../data/playcards/" + std::to_string(n));

    o << image << std::endl << name << std::endl;
    for (const auto &i : instructions) {
        o << i << std::endl;
    }
    o.close();
    return 1;
}




