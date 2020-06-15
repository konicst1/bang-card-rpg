//
// Created by stepan on 5/3/20.
//

#pragma once


#include <queue>
#include "PlayCard.h"
#include "CardFactory.h"
#include "Player.h"
#include <map>
#include "UIController.h"
#include "Move.h"

class GameManager {
    std::deque<std::shared_ptr<PlayCard> > cardStack;
    std::shared_ptr<Player> playerA;
    std::shared_ptr<Player> playerB;

    CardFactory cardFactory = CardFactory();
    UIController ui = UIController();


    int turn = 1;


public:

    GameManager() {

    }

    ~GameManager() = default;

    void initNewGame(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2);

    void selectPlayersAndInitNewGame();

    void loadSavedGameAndPlay();

    std::shared_ptr<PlayCard> getCardFromStack();

    void putCardInStack(std::shared_ptr<PlayCard> card);

    bool givePlayerCardFromStack(std::shared_ptr<Player> player);

    static bool givePlayerCardFromPlayer(std::shared_ptr<Player> donor, std::shared_ptr<Player> acceptor);

    void startGame();

    Move nextMove();

    int getDefenseFromPlayer(std::shared_ptr<Player> leader,std::shared_ptr<Player> target, int attack);

    int getAttackDefenseFromPlayer(std::shared_ptr<Player> leader,std::shared_ptr<Player> target, int attack);

    std::shared_ptr<PlayCard> getCardFromPlayer(std::shared_ptr<Player> leader, std::shared_ptr<Player> target);

    void saveGame();


};




