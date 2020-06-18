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
public:
    enum CardSymbol {
        HEART, SPADES, CLUB, DIAMOND
    };

private:
    CardSymbol symbol;     //symbol of the cards (heart/spades/club/diamond)
    int number;             //number of the card..not really used yet

public:


    PlayCard(const std::string &image, CardSymbol symbol, const std::string &name, int number,
             std::vector<std::shared_ptr<Instruction>> instructions) : Card(image, name, instructions) {
        this->number = number;
        this->symbol = symbol;
    }

    //getters
    CardSymbol getSymbol() const {
        return symbol;
    }

    int getNumber() const {
        return number;
    }

    static CardSymbol getCardSymbolByName(std::string name) {
        if (name == "heart") {
            return CardSymbol::HEART;
        } else if (name == "spades") {
            return CardSymbol::SPADES;
        } else if (name == "club") {
            return CardSymbol::CLUB;
        } else {
            return CardSymbol::DIAMOND;
        }
    }

    static std::string getCardSymbolAsString(CardSymbol symbol){
        if (symbol == CardSymbol::HEART) {
            return "heart";
        } else if (symbol == CardSymbol::SPADES) {
            return "spades";
        } else if (symbol ==  CardSymbol::CLUB) {
            return "club";
        } else {
            return "diamond";
        }
    }
};




