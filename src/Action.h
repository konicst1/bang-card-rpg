//
// Created by stepan on 5/3/20.
//

#pragma once


#include <string>
#include <vector>

class Action {
    std::vector<std::string> instructions;

public:
    Action(std::vector<std::string> instructions){
        this->instructions = instructions;
    }

    void perform();
};




