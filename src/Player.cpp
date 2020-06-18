//
// Created by stepan on 5/4/20.
//

#include "Player.h"
#include "UIController.h"

void Player::giveCard(const std::shared_ptr<PlayCard>& card) {
    this->cards.push_back(card);
}

std::shared_ptr<PlayCard> Player::getRandomCard() {
    int num = (0 + (rand() % (int)(this->cards.size() + 1)));

    auto r = this->cards[num];
    auto it = this->cards.begin();
    std::advance(it, num);
    this->cards.erase(it);

    return r;
}

int Player::getHealth() const {
    return health;
}

const std::string &Player::getName() const {
    return name;
}

const std::vector<std::shared_ptr<PlayCard>> &Player::getCards() const {
    return cards;
}

const std::shared_ptr<RoleCard> &Player::getRole() const {
    return role;
}

void Player::decreaseHealth(int h) {
    if(h >= 0){
        this->health -= h;
    }
}



void Player::removeCard(int index) {
    cards.erase(cards.begin() + index);
}

void Player::increaseHealth(int h) {
    if(h >= 0){
        this->health += 1;
    }
}

int Player::getDefenseChoice(int attackStrength) {
    UIController::presentCards(this->getCards());
    UIController::println("You are being attacked with power of " + std::to_string(attackStrength));
    UIController::println("Play defend cards to defend yourself! Enter 0 when done.");
    return UIController::getChoice(this->cards.size(), 0);

}

int Player::getAttackChoice(int attackStrength) {
    UIController::presentCards(this->getCards());
    UIController::println("You are being attacked with power of " + std::to_string(attackStrength));
    UIController::println("Play attack cards to defend yourself! Enter 0 when done.");
    return UIController::getChoice(this->cards.size(), 0);
}

int Player::getCardChoice() {
    UIController::presentCards(this->getCards());
    UIController::println("You need to give up one of your cards..choose which one will it be.");
    return UIController::getChoice(this->cards.size(), 1);
}
