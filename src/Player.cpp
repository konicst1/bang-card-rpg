//
// Created by stepan on 5/4/20.
//

#include "Player.h"

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
    this->health -= h;
}



void Player::removeCard(int index) {
    cards.erase(cards.begin() + index);
}

void Player::increaseHealth(int h) {
    this->health += 1;
}
