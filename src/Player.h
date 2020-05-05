//
// Created by stepan on 5/4/20.
//

#pragma once


#include <memory>
#include "PlayCard.h"
#include "RoleCard.h"

class Player {
    int health;
    std::string name;
    std::vector< std::shared_ptr<Card>> cards;
    std::shared_ptr<Card> role;
public:

    Player(std::vector<std::shared_ptr<Card>> cards, std::shared_ptr<Card> role){
        this->cards = cards;
        this->health = role->getHealthCount();
        this->name = role->getName();
    }

    Player(std::shared_ptr<Card> role){
        this->cards = std::vector<std::shared_ptr<Card>>();
        this->health = role->getHealthCount();
        this->name = role->getName();
    }

    int getHealth() const;

    const std::string &getName() const;

    const std::vector<std::shared_ptr<Card>> &getCards() const;

    void giveCard( std::shared_ptr<Card> );

    std::shared_ptr<Card> getRandomCard();
};




