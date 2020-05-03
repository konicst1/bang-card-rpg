//
// Created by stepan on 5/3/20.
//

#pragma once


#include <queue>
#include "PlayCard.h"
#include "CardFactory.h"

class GameManager {
    std::queue<PlayCard *> cardStack;
    RoleCard playerA;
    RoleCard playerB;

    CardFactory cardFactory = CardFactory();

    //std::map<std::string, std::function> instructionTranslator


public:
    bool initNewGame();

    Card getCardFromStack();

    Card getCardFromPlayer(RoleCard & player);

    bool givePlayerCardFromStack(RoleCard & player);

    bool givePlayerCardFromPlayer(RoleCard & donor, RoleCard & acceptor);



    void nextMove();




};




