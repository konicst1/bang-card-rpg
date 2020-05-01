//
// Created by stepan on 5/1/20.
//

#pragma once


#include "Card.h"

class PlayCard : Card {
    int cardEdit;
    int healthEdit;

    PlayCard(const std::string &image, const std::string &logo, const std::string &name, int number, int cardEdit, int healthEdit) : Card(image, logo, name, number) {
        this->cardEdit = cardEdit;
        this->healthEdit = healthEdit;
    }

public:
    int getCardEdit() const {
        return cardEdit;
    }

    int getHealthEdit() const {
        return healthEdit;
    }

};




