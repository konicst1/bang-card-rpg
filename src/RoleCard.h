//
// Created by stepan on 5/1/20.
//

#pragma once


#include "Card.h"

class RoleCard : Card{
    int healthCount;
public:
    RoleCard(const std::string &image, const std::string &logo, const std::string &name, int number, int healthCount) : Card(image, logo, name, number) {
        this->healthCount = healthCount;
    }
};




