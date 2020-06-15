//
// Created by stepan on 5/1/20.
//

#pragma once


#include "Card.h"

#include <utility>

/**
 * Class that represents the card that can be played by player.
 * */
class PlayCard : public Card {
    std::string symbol;     //symbol of the cards (heart/spades/club/diamond)
    int number;             //number of the card..not really used yet

public:


    PlayCard(const std::string &image, const std::string &symbol, const std::string &name, int number, std::shared_ptr<Action> action)  : Card(image, name, std::move(action)) {
        this->number = number;
        this->symbol = symbol;
    }

    //getters
    const std::string &getSymbol() const {
        return symbol;
    }

    int getNumber() const {
        return number;
    }
};




