//
// Created by stepan on 5/1/20.
//

#pragma once


#include "Card.h"

class RoleCard : public Card{
    int healthCount;

public:
    RoleCard(const std::string &image, const std::string &name, int healthCount, std::shared_ptr<Action> action) : Card(image, name, action) {
        this->healthCount = healthCount;
    }

    int getHealthCount() {
        return healthCount;
    }
};




