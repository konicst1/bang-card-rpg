//

#include <memory>
#include <algorithm>
#include <queue>
#include <random>
#include <utility>
#include "GameManager.h"
#include "Move.h"
#include "SubMove.h"
#include "AIPlayer.h"


void GameManager::initNewGame(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2) {
    UIController::clearScreen();

    this->playerA = std::move(p1);
    this->playerB = std::move(p2);


    //get new shuffled stack of cards
    for (const auto &card : CardFactory::getNewStackOfCards()) {
        cardStack.push_back(card);
    }


    //give each player 6 cards for start
    for (int i = 0; i < 6; ++i) {
        this->givePlayerCardFromStack(playerA);
        this->givePlayerCardFromStack(playerB);
    }


    startGame();


}



std::shared_ptr<PlayCard> GameManager::getCardFromStack() {
    auto r = this->cardStack.front();
    this->cardStack.pop_front();
    return r;
}

bool GameManager::givePlayerCardFromStack(const std::shared_ptr<Player> &player) {
    player->giveCard(this->getCardFromStack());
    return true;
}

void GameManager::startGame() {
    ui.startGame();
    while (true) {
        UIController::clearScreen();
        Move move = nextMove();
        int con = move.init();
        if (con == 2) {
            saveGame();
            break;
        } else if (con == 3) {
            break;
        }
        move.startMove(*this);

        if ((playerA->getHealth() <= 0) || (playerB->getHealth() <= 0)) {
            break;
        }
    }

    if (playerA->getHealth() <= 0) {
        UIController::endGame(playerB->getName());
    } else if (playerB->getHealth() <= 0) {
        UIController::endGame(playerA->getName());
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
    std::vector<std::shared_ptr<RoleCard> > roles = CardFactory::getAllRoleCards();

    //shuffle roles
    std::shuffle(roles.begin(), roles.end(), std::mt19937(std::random_device()()));

    UIController::clearScreen();

    //give each player 3 roles to choose from
    UIController::println("Player A, please, select your character:");
    int roleA = ui.selectRole(roles[0]->getName(), roles[1]->getName(), roles[2]->getName());
    UIController::println("Player B, please, select your character:");
    int roleB = ui.selectRole(roles[3]->getName(), roles[4]->getName(), roles[5]->getName());


    Player a = Player(roles[roleA - 1]);
    Player b = Player(roles[roleB + 2]);

    initNewGame(std::make_shared<Player>(a), std::make_shared<Player>(b));
}

void GameManager::selectPlayerAndInitSinglePlayerGame() {
    //select roles
    std::vector<std::shared_ptr<RoleCard> > roles = CardFactory::getAllRoleCards();

    //shuffle roles
    std::shuffle(roles.begin(), roles.end(), std::mt19937(std::random_device()()));

    UIController::clearScreen();
    //give each player 3 roles to choose from
    UIController::println("Player A, please, select your character:");
    int roleA = ui.selectRole(roles[0]->getName(), roles[1]->getName(), roles[2]->getName());

    std::shared_ptr<Player> a = std::make_shared<Player>(Player(roles[roleA - 1]));
    std::shared_ptr<Player> b = std::make_shared<AIPlayer>(roles[3]);

    initNewGame(a, b);

}

void GameManager::saveGame() {
    std::vector<std::shared_ptr<PlayCard>> stack = std::vector<std::shared_ptr<PlayCard>>(cardStack.begin(),
                                                                                          cardStack.end());
    if (turn) {
        DataLoader::saveGame(this->playerB->getName(), this->playerB->getHealth(), this->playerB->getRole()->getImage(),
                             this->playerB->getRole()->getInstructions(), this->playerB->getCards(),
                             this->playerA->getName(), this->playerA->getHealth(), this->playerA->getRole()->getImage(),
                             this->playerA->getRole()->getInstructions(), this->playerA->getCards(),
                             stack);
    } else {

        DataLoader::saveGame(this->playerA->getName(), this->playerA->getHealth(), this->playerA->getRole()->getImage(),
                             this->playerA->getRole()->getInstructions(), this->playerA->getCards(),
                             this->playerB->getName(), this->playerB->getHealth(), this->playerB->getRole()->getImage(),
                             this->playerB->getRole()->getInstructions(), this->playerB->getCards(),
                             stack);
    }


}

void GameManager::putCardInStack(const std::shared_ptr<PlayCard> &card) {
    this->cardStack.push_back(card);
}

int GameManager::getDefenseFromPlayer(const std::shared_ptr<Player> &target, int attack) {
    UIController::switchPlayers(target);
    SubMove s = SubMove(target, attack);
    s.init();
    return s.getDefenseValue(*this);
}


int
GameManager::getAttackDefenseFromPlayer(const std::shared_ptr<Player> &target, int attack) {
    UIController::switchPlayers(target);
    SubMove s = SubMove(target, attack);
    s.init();
    return s.getAttackValue(*this);
}


std::shared_ptr<PlayCard>
GameManager::getCardFromPlayer(const std::shared_ptr<Player> &target) {
    UIController::switchPlayers(target);
    SubMove s = SubMove(target, 0);
    s.init();
    return s.getCardFromPlayer();

}

void GameManager::loadSavedGameAndPlay() {
    auto x = cardFactory.getSavedPlayers();

    this->playerA = x[0];
    this->playerB = x[1];

    cardStack.clear();
    for (const auto &c : cardFactory.getSavedStack()) {
        cardStack.push_back(c);
    }

    startGame();
}



