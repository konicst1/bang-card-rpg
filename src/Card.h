//
// Created by stepan on 5/1/20.
//

#pragma once


#include <string>
#include "Action.h"

class Card {
    std::string image;
    std::string name;
    Action action;

public:

    Card(const std::string& image, const std::string& name, Action & action) : action(action) {
        this->image = image;
        this->name = name;
    }

    virtual int getHealthCount(){return -100;} ;


    const std::string &getImage() const {
        return image;
    }


    std::string getName() const {
        return name;
    }
};




