//
// Created by stepan on 5/3/20.
//

#include <memory>
#include <algorithm>
#include <random>
#include <utility>
#include "GameManager.h"
#include "Move.h"


void GameManager::initNewGame(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2) {

    this->playerA = std::move(p1);
    this->playerB = std::move(p2);


    //get new shuffled stack of cards
    for (const auto& card : CardFactory::getNewStackOfCards()) {
        cardStack.push(card);
    }


    //give each player 6 cards for start
    for(int i = 0; i < 6; ++i) {
        this->givePlayerCardFromStack(playerA);
        this->givePlayerCardFromStack(playerB);
    }


    startGame();


}

std::shared_ptr<PlayCard> GameManager::getCardFromStack() {
    auto r = this->cardStack.front();
    this->cardStack.pop();
    return r;
}

bool GameManager::givePlayerCardFromStack(std::shared_ptr<Player> player) {
    player->giveCard(this->getCardFromStack());
    return true;
}

bool GameManager::givePlayerCardFromPlayer(std::shared_ptr<Player> donor, std::shared_ptr<Player> acceptor) {
    acceptor->giveCard(donor->getRandomCard());
    return true;
}

void GameManager::startGame() {
    ui.startGame();
    while (true) {
        Move move = nextMove();
        move.init();
        move.startMoveCycle();

        if ((playerA->getHealth() == 0) || (playerB->getHealth() == 0)) {
            break;
        }
    }
}

Move GameManager::nextMove() {
    if (turn) {
        turn = 0;
        return Move(playerA, playerB);
    } else {
        turn = 1;
        return Move(playerB, playerA);
    }
}

void GameManager::selectPlayersAndInitNewGame() {
    //select roles
    std::vector< std::shared_ptr<RoleCard> > roles = cardFactory.getAllRoleCards();
    srand(unsigned(time(nullptr)));
    //shuffle roles
    std::shuffle(roles.begin(), roles.end(), std::mt19937(std::random_device()()));

    //give each player 3 roles to choose from


    int roleA = ui.selectRoleA(roles[0]->getName(), roles[1]->getName(), roles[2]->getName());
    int roleB = ui.selectRoleB(roles[3]->getName(), roles[4]->getName(), roles[5]->getName());

    Player a = Player(roles[roleA-1]);
    Player b = Player(roles[roleB+2 ]);

    initNewGame(std::make_shared<Player>(a), std::make_shared<Player>(b));



}

//std::string player1Name, int player1Health, std::string player1Image, std::vector<std::string> player1Instructions, std::vector<std::shared_ptr<PlayCard>> player1Cards,
//std::string player2Name, int player2Health, std::string player2Image, std::vector<std::string> player2Instructions,  std::vector<std::shared_ptr<PlayCard>> player2Cards

void GameManager::saveGame() {
    DataLoader::saveGame(this->playerA->getName(), this->playerA->getHealth(), this->playerA->getRole()->getImage(), this->playerA->getRole()->getAction()->getInstructions(), this->playerA->getCards(),
                         this->playerB->getName(), this->playerB->getHealth(), this->playerB->getRole()->getImage(), this->playerB->getRole()->getAction()->getInstructions(), this->playerB->getCards());

}
