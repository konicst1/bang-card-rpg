//
// Created by stepan on 5/1/20.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "DataLoader.h"
#include "PlayCard.h"

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

    for (int i = 1; i <= 4/*todo tady to bude chtit zmenit pak*/; i++) {
        std::ifstream file = std::ifstream("../data/playcards/" + std::to_string(i));
        res.push_back(loadCard(file));
    }

    return res;
}

//    PlayCard role = RoleCard(/*image*/ a[0], /*name*/ a[1],/*health count*/ std::stoi(a[2]), b);
int DataLoader::saveGame(std::string player1Name, int player1Health, std::string player1Image,
                         std::vector<std::string> player1Instructions,
                         std::vector<std::shared_ptr<PlayCard>> player1Cards,
                         std::string player2Name, int player2Health, std::string player2Image,
                         std::vector<std::string> player2Instructions,
                         std::vector<std::shared_ptr<PlayCard>> player2Cards) {
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
    for (auto s : player1Instructions) {
        f << s << std::endl;
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
    for (auto s : player2Instructions) {
        f << s << std::endl;
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
    for (int i = 0; i < player1Cards.size(); i++) {
        f = std::ofstream("../data/save/player1Cards/" + std::to_string(i));
        auto s = player1Cards[i];
        f << s->getImage() << std::endl << s->getSymbol() << std::endl << s->getName() << std::endl << s->getNumber()
          << std::endl;
        for (auto i : s->getAction()->getInstructions()) {
            f << i << std::endl;
        }
    }
    f.close();
    if (!f.good()) {
        return 0;
    }

    f = std::ofstream("../data/save/player2Cards/cardsTotal");
    f << player2Cards.size();
    f.close();
    for (int i = 0; i < player2Cards.size(); i++) {
        auto s = player2Cards[i];
        f = std::ofstream("../data/save/player2Cards/" + std::to_string(i));
        f << s->getImage() << std::endl << s->getSymbol() << std::endl << s->getName() << std::endl << s->getNumber()
          << std::endl;
        for (auto i : s->getAction()->getInstructions()) {
            f << i << std::endl;
        }
    }
    f.close();
    if (!f.good()) {
        return 0;
    }


    return 1;
}

std::vector<std::vector<std::string>> DataLoader::loadSavedPlayer(std::string player) {
    std::vector<std::vector<std::string> > res;
    std::ifstream file = std::ifstream("../data/save/" + player);
    res.push_back(loadCard(file));

    std::ifstream f = std::ifstream("../data/save/" + player + "Cards");
    int n;
    f >> n;

    for (int i = 1; i <= n; i++) {
        std::ifstream file = std::ifstream("../data/save/" + player + "Cards" + "/" + std::to_string(i));
        res.push_back(loadCard(file));
    }


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
        std::ifstream file = std::ifstream("../data/save/gameStack" + std::to_string(i));
        res.push_back(loadCard(file));
    }

    return res;
}

