//
// Created by stepan on 5/1/20.
//

#pragma once


#include <string>
#include <memory>
#include <utility>
#include <vector>
#include "Instruction.h"


/**
 * Parent class that represents both PlayCards and RoleCards
 * */
class Card {
    std::string image;                  //path to graphics for the card
    std::string name;                   //name of the card
    std::vector<std::shared_ptr<Instruction>> instructions;     //special power of the card


public:

    Card(const std::string &image, const std::string &name, std::vector<std::shared_ptr<Instruction>> instructions) {
        this->image = image;
        this->name = name;
        this->instructions = std::move(instructions);
    }

    std::vector<std::shared_ptr<Instruction>> getInstructions() const {
        return instructions;
    }


    const std::string &getImage() const {
        return image;
    }


    std::string getName() const {
        return name;
    }

    InstructionResponse getResponse() {
        InstructionResponse res = InstructionResponse(0, 0, 1);
        for(auto i : instructions){
            res = res + i->getResponse();
        }
        return res;
    }


};




