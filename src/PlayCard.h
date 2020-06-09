//
// Created by stepan on 5/1/20.
//

#pragma once


#include "Card.h"

#include <utility>

class PlayCard : public Card {
//    int cardEdit;
//    int healthEdit;
    std::string symbol;
    int number;

public:


    PlayCard(const std::string &image, const std::string &symbol, const std::string &name, int number, std::shared_ptr<Action> action)  : Card(image, name, std::move(action)) {
//        this->cardEdit = cardEdit;
//        this->healthEdit = healthEdit;
        this->number = number;
        this->symbol = symbol;
    }

    const std::string &getSymbol() const {
        return symbol;
    }

    int getNumber() const {
        return number;
    }
};




