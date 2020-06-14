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
    std::vector<std::shared_ptr<PlayCard>> cards;
    std::shared_ptr<RoleCard> role;
public:

    Player(std::vector<std::shared_ptr<PlayCard>> cards, std::shared_ptr<RoleCard> role) {
        this->cards = cards;
        this->health = role->getHealthCount();
        this->name = role->getName();
        this->role = role;
    }

    const std::shared_ptr<RoleCard> &getRole() const;

    Player(std::shared_ptr<RoleCard> role) {
        this->cards = std::vector<std::shared_ptr<PlayCard>>();
        this->health = role->getHealthCount();
        this->name = role->getName();
        this->role = role;
    }

    int getHealth() const;

    const std::string &getName() const;

    const std::vector<std::shared_ptr<PlayCard>> &getCards() const;

    void giveCard(const std::shared_ptr<PlayCard>&);

    std::shared_ptr<PlayCard> getRandomCard();

    void removeCard(int index);

    void decreaseHealth(int h);

    void increaseHealth(int h);

    virtual int getDefenseChoice(int attackStrength);

    virtual int getAttackChoice(int attackStrength);

    virtual int getCardChoice();
};




