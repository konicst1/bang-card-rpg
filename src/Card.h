//
// Created by stepan on 5/1/20.
//

#pragma once


#include <string>
#include <memory>
#include <utility>
#include "Action.h"

class Card {
    std::string image;
    std::string name;
    std::shared_ptr<Action> action;

public:

    Card(const std::string& image, const std::string& name, std::shared_ptr<Action> action)  {
        this->image = image;
        this->name = name;
        this->action = std::move(action);
    }

    const std::shared_ptr<Action> &getAction() const {
        return action;
    }

    virtual int getHealthCount(){return -100;} ;


    const std::string &getImage() const {
        return image;
    }


    std::string getName() const {
        return name;
    }
};




