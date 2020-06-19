//
// Created by stepan on 6/15/20.
//

#include "AIPlayer.h"

int AIPlayer::getDefenseChoice(int attackStrength) {
    if(attackStrength <= 0){
        return 0;
    }

    //try to find the best defense
    for(unsigned int i = 0 ; i < getCards().size(); i++){
        if(getCards()[i]->getPotentialResponse().getDefensePower() >= attackStrength){
            return (int)(i + 1);
        }
    }
    //do at least some defense
    for(unsigned int i = 0 ; i < getCards().size(); i++){
        if(getCards()[i]->getPotentialResponse().getDefensePower() > 0){
            return (int)(i + 1);
        }
    }
    //give up
    return 0;
}

int AIPlayer::getAttackChoice(int attackStrength) {
    if(attackStrength <= 0){
        return 0;
    }

    //try to find the best defense
    for(unsigned int i = 0 ; i < getCards().size(); i++){
        if(getCards()[i]->getPotentialResponse().getAttackPower() >= attackStrength){
            return (int)(i + 1);
        }
    }
    //do at least some defense
    for(unsigned int i = 0 ; i < getCards().size(); i++){
        if(getCards()[i]->getPotentialResponse().getAttackPower() > 0){
            return (int)(i + 1);
        }
    }
    //give up
    return 0;
}

int AIPlayer::getCardChoice() {
    return 1;
}

int AIPlayer::getPlayChoice(Move &) {
    //first check for health
    if(health <= 2){
        for(unsigned int i = 0 ; i < getCards().size(); i++){
            if(getCards()[i]->getPotentialResponse().getHealthAddition() > 0){
                return (int)(i + 1);
            }
        }
    }
    //second check for card count
    if(cards.size() <= 4){
        for(unsigned int i = 0 ; i < getCards().size(); i++){
            if(getCards()[i]->getPotentialResponse().getCardAddition() > 0){
                return (int)(i + 1);
            }
        }
    }
    //third try to attack
    for(unsigned int i = 0 ; i < getCards().size(); i++){
        if(getCards()[i]->getPotentialResponse().getAttackPower() > 0){
            return (int)(i + 1);
        }
    }
    //or at least play the first card
    return 1;
}

AIPlayer::AIPlayer(const std::vector<std::shared_ptr<PlayCard>> &cards, const std::shared_ptr<RoleCard> &role) : Player(
        cards, role) {}

AIPlayer::AIPlayer(const std::shared_ptr<RoleCard> &role) : Player(role) {}

