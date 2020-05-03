//
// Created by stepan on 5/1/20.
//

#pragma once


#include "Card.h"

class RoleCard : Card{
    int healthCount;

public:
    RoleCard(const std::string &image, const std::string &name, int healthCount, Action & action) : Card(image, name, action) {
        this->healthCount = healthCount;
    }
};




