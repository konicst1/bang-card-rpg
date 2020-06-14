//
// Created by stepan on 6/9/20.
//

#pragma once


#include "Action.h"

class DonorAction : Action{
public:
    DonorAction(const std::vector<std::string> &instructions){}

private:

    void perform(std::shared_ptr<Player> leader, std::shared_ptr<Player> target) override ;
};




