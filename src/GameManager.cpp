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
    if (cardStack.empty()) {
        return false;
    }
    player->giveCard(this->getCardFromStack());
    return true;
}

void GameManager::startGame() {
    ui.startGame();
    while (true) {
        UIController::clearScreen();
        Move move = nextMove();
        if (!singlePlayer || !turn) {
            int con = move.init();
            if (con == 2) {
                saveGame();
                break;
            } else if (con == 3) {
                break;
            }
        }

        move.startMove(*this);
        if (!singlePlayer || !turn) {
            UIController::endMove(move.getLeader(), move.getTarget());
        }

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
    int roleA, roleB;

    //give each player 3 roles to choose from
    UIController::println("Player A, please, select your character:");
    try {
        roleA = ui.selectRole(roles[0],
                              roles[1],
                              roles[2]);
    } catch (std::invalid_argument &e) {
        return;
    }
    UIController::println("Player B, please, select your character:");
    roleB = ui.selectRole(roles[3],
                          roles[4],
                          roles[5]);


    Player a = Player(roles[roleA - 1]);
    Player b = Player(roles[roleB + 2]);
    this->singlePlayer = false;

    initNewGame(std::make_shared<Player>(a), std::make_shared<Player>(b));
}

void GameManager::selectPlayerAndInitSinglePlayerGame() {
    std::shared_ptr<Player> a;
    std::shared_ptr<Player> b;
    try {
        //select roles
        std::vector<std::shared_ptr<RoleCard> > roles = CardFactory::getAllRoleCards();

        //shuffle roles
        std::shuffle(roles.begin(), roles.end(), std::mt19937(std::random_device()()));

        UIController::clearScreen();
        //give each player 3 roles to choose from
        UIController::println("Player A, please, select your character:");
        int roleA = ui.selectRole(roles[0],
                                  roles[1],
                                  roles[2]);

        a = std::make_shared<Player>(Player(roles[roleA - 1]));
        b = std::make_shared<AIPlayer>(roles[3]);

        this->singlePlayer = true;
    } catch (std::invalid_argument &e) {
        UIController::println("Error loading data.");
    }
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
                             stack, singlePlayer);
    } else {

        DataLoader::saveGame(this->playerA->getName(), this->playerA->getHealth(), this->playerA->getRole()->getImage(),
                             this->playerA->getRole()->getInstructions(), this->playerA->getCards(),
                             this->playerB->getName(), this->playerB->getHealth(), this->playerB->getRole()->getImage(),
                             this->playerB->getRole()->getInstructions(), this->playerB->getCards(),
                             stack, singlePlayer);
    }


}

void GameManager::putCardInStack(const std::shared_ptr<PlayCard> &card) {
    this->cardStack.push_back(card);
}

int GameManager::getDefenseFromPlayer(const std::shared_ptr<Player> &target, int attack) {
    SubMove s = SubMove(target, attack);
    if (!singlePlayer) {
        UIController::switchPlayers(target);
        s.init();
    }
    return s.getDefenseValue(*this);
}


int
GameManager::getAttackDefenseFromPlayer(const std::shared_ptr<Player> &target, int attack) {
    SubMove s = SubMove(target, attack);
    if (!singlePlayer) {
        UIController::switchPlayers(target);
        s.init();
    }
    return s.getAttackValue(*this);
}


std::shared_ptr<PlayCard>
GameManager::getCardFromPlayer(const std::shared_ptr<Player> &target) {
    SubMove s = SubMove(target, 0);
    if (!singlePlayer) {
        UIController::switchPlayers(target);
        s.init();
    }
    return s.getCardFromPlayer();

}

void GameManager::loadSavedGameAndPlay() {
    try {
        auto x = CardFactory::getSavedPlayers();

        this->playerA = x[0];
        this->playerB = x[1];

        this->singlePlayer = DataLoader::savedGameSingleplayer();

        cardStack.clear();
        for (const auto &c : CardFactory::getSavedStack()) {
            cardStack.push_back(c);
        }
    } catch (std::invalid_argument &e) {
        UIController::println("Error loading data...");
        return;
    }


    startGame();
}



