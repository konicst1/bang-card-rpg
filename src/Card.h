//
// Created by stepan on 5/1/20.
//

#pragma once


#include <string>

class Card {
    std::string image;
    std::string logo;
    std::string name;
    int number;

public:

    Card(const std::string& image, const std::string& logo, const std::string& name, int number) {
        this->image = image;
        this->logo = logo;
        this->number = number;
        this->name = name;
    }


    const std::string &getName() const {
        return name;
    }

    const std::string &getImage() const {
        return image;
    }

    const std::string &getLogo() const {
        return logo;
    }

    int getNumber() const {
        return number;
    }
};




