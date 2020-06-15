//
// Created by stepan on 5/4/20.
//

#pragma once


#include <memory>
#include "PlayCard.h"
#include "RoleCard.h"

/**
 * Class that represents the player.
 * */
class Player {
    int health;                                         //number of health
    std::string name;                                   //name of the player (from role card)
    std::vector<std::shared_ptr<PlayCard>> cards;       //players play cards
    std::shared_ptr<RoleCard> role;                     //role that defines the player
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

    //getters
    int getHealth() const;

    const std::string &getName() const;

    const std::vector<std::shared_ptr<PlayCard>> &getCards() const;

    /**
     * Add card to players stack.
     * @param smart pointer of the card that will be added
     * */
    void giveCard(const std::shared_ptr<PlayCard> &);

    /**
     * Get and remove random card from the pack.
     * @returns smart pointer of the card
     * */
    std::shared_ptr<PlayCard> getRandomCard();

    /**
     * Removes card from the pack on index i.
     * @param index of card to be removed
     * */
    void removeCard(int index);

    /**
     * Decrease health.
     * @param h = number of health to be removed
     * */
    void decreaseHealth(int h);

    /**
     * Increase health.
     * @param h = number of health to be added
     * */
    void increaseHealth(int h);

    /**
     * Player has to defend himself.
     * @param attackStrength = power of attack that player is attacked with
     * @returns Players defense power.
     * */
    virtual int getDefenseChoice(int attackStrength);

    /**
     * Player has to defend himself (with attack card).
     * @param attackStrength = power of attack that player is attacked with
     * @returns Players defense power.
     * */
    virtual int getAttackChoice(int attackStrength);

    /**
     * Player has to give up onr card.
     * @returns index + 1of the card to give up
     * */
    virtual int getCardChoice();
};




