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
        if(nCard->getSymbol() == symbol){
            m.putCardInStack(nCard);
            return 1;
        }

        m.putCardInStack(nCard);
        return 0;
    }

    InstructionResponse getResponse(GameManager &m) override {
        std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
        if(nCard->getSymbol() == symbol){
            m.putCardInStack(nCard);
            return InstructionResponse(-1,-1,1);
        }

        m.putCardInStack(nCard);
        return InstructionResponse(-1,-1,0);
    }
};




