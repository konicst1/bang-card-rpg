//
// Created by stepan on 5/1/20.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "DataLoader.h"

std::vector<std::vector<std::string>> DataLoader::loadAllRoleCards() {
    std::vector<std::vector<std::string> > res;
    std::ifstream f = std::ifstream("../data/rolecards/rolesTotal");
    int n;
    f >> n;

    for (int i = 1; i <= n; i++) {
        std::vector<std::string> role;
        std::ifstream file = std::ifstream("../data/rolecards/" + std::to_string(i));
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                role.push_back(line);
            }
            res.push_back(role);
            file.close();
        }
    }

    return res;
}

std::vector<std::vector<std::string>> DataLoader::loadAllPlayCards() {
    std::vector<std::vector<std::string> > res;

    for (int i = 1; i <= 3/*tady to bude chtit zmenit pak*/; i++) {
        std::vector<std::string> role;
        std::ifstream file = std::ifstream("../data/playcards/" + std::to_string(i));
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                role.push_back(line);
            }
            res.push_back(role);
            file.close();
        }
    }

    return res;
}
