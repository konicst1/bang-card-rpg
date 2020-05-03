//
// Created by stepan on 5/3/20.
//

#pragma once


#include <queue>
#include "PlayCard.h"
#include "Player.h"
#include "CardFactory.h"

class GameManager {
    std::queue<PlayCard *> cardStack;
    Player playerA;
    Player playerB;

    CardFactory cardFactory = CardFactory();



public:
    bool initNewGame();

    Card getCardFromStack();

    Card getCardFromPLayer(Player & player);




};




