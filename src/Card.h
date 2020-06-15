//
// Created by stepan on 5/1/20.
//

#pragma once


#include <string>
#include <memory>
#include <utility>
#include "Action.h"


/**
 * Parent class that represents both PlayCards and RoleCards
 * */
class Card {
    std::string image;                  //path to graphics for the card
    std::string name;                   //name of the card
    std::shared_ptr<Action> action;     //special power of the card

public:

    Card(const std::string& image, const std::string& name, std::shared_ptr<Action> action)  {
        this->image = image;
        this->name = name;
        this->action = std::move(action);
    }

    const std::shared_ptr<Action> &getAction() const {
        return action;
    }


    const std::string &getImage() const {
        return image;
    }


    std::string getName() const {
        return name;
    }
};




