//
// Created by stepan on 5/1/20.
//

#pragma once


#include "Card.h"

#include <utility>

class RoleCard : public Card{
    int healthCount;

public:
    RoleCard(const std::string &image, const std::string &name, int healthCount, std::vector<std::shared_ptr<Instruction>> instructions) : Card(image, name, std::move(instructions)) {
        this->healthCount = healthCount;
    }

    int getHealthCount() {
        return healthCount;
    }
};




