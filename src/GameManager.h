//
// Created by stepan on 5/3/20.
//

#pragma once


#include <queue>
#include "PlayCard.h"
#include "CardFactory.h"
#include "Player.h"
#include "UIController.h"
#include "Move.h"

class GameManager {
    std::queue<std::shared_ptr<Card> > cardStack;
    std::shared_ptr<Player> playerA;
    std::shared_ptr<Player> playerB;

    CardFactory cardFactory = CardFactory();
    UIController ui = UIController();

    int turn = 1;

    //std::map<std::string, std::function> instructionTranslator


public:

    void initNewGame(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2);

    void selectPlayersAndInitNewGame();

    void loadSavedGameAndPlay();

    std::shared_ptr<Card> getCardFromStack();

    Card getCardFromPlayer(std::shared_ptr<Player> player);

    bool givePlayerCardFromStack(std::shared_ptr<Player> player);

    static bool givePlayerCardFromPlayer(std::shared_ptr<Player> donor, std::shared_ptr<Player> acceptor);

    void startGame();

    Move nextMove();


};




