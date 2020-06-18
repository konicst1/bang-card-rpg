//
// Created by stepan on 6/18/20.
//

#pragma once


#include "Instruction.h"
#include "PlayCard.h"
#include "GameManager.h"

class IfNextCardIsInstruction : public Instruction{
PlayCard::CardSymbol symbol;
public:
    IfNextCardIsInstruction(const std::string &instructionRepresentation, PlayCard::CardSymbol symbol) : Instruction(
            instructionRepresentation), symbol(symbol) {}



    int perform(GameManager &m, std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override {
        std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
        UIController::print("Next card symbol is: " + PlayCard::getCardSymbolAsString(nCard->getSymbol()));
        if(nCard->getSymbol() == symbol){
            m.putCardInStack(nCard);
            UIController::println(". Nice!");
            return 1;
        }
        UIController::println(". Bad luck.");
        m.putCardInStack(nCard);
        return 0;
    }

    InstructionResponse getResponse(GameManager &m) override {
        std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
        UIController::print("Next card symbol is: " + PlayCard::getCardSymbolAsString(nCard->getSymbol()));
        if(nCard->getSymbol() == symbol){
            m.putCardInStack(nCard);
            UIController::println(". Nice!");
            return {0,0,1};
        }

        m.putCardInStack(nCard);
        UIController::println(". Bad luck.");
        return {0,0,0};
    }
};




