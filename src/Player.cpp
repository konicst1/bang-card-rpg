//
// Created by stepan on 5/4/20.
//

#include "Player.h"

void Player::giveCard(std::shared_ptr<Card> card) {
    this->cards.push_back(card);
}

std::shared_ptr<Card> Player::getRandomCard() {
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

const std::vector<std::shared_ptr<Card>> &Player::getCards() const {
    return cards;
}
