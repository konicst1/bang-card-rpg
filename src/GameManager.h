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

/**
 * Class that manages the start, process and end of the game.
 * */
class GameManager {
    std::deque<std::shared_ptr<PlayCard> > cardStack;   //queue of cards for the current game
    std::shared_ptr<Player> playerA;                    //smart pointer for the first player
    std::shared_ptr<Player> playerB;                    //smart pointer for the second player

    CardFactory cardFactory = CardFactory();            //instance of cards factory to load cards definition
    UIController ui = UIController();                   //instance of ui controller to communicate with players


    int turn = 1;                                       //int that declares which player is on the move (0 or 1)


public:
    /** Default constructor */
    GameManager() {

    }

    /** Default destructor */
    ~GameManager() = default;

    /**
     * Initialize new game. New cards stack and assign manager attributes.
     * */
    void initNewGame(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2);

    /**
     * Function that can start a new game from outside this class.
     * Allows players to choose their roles and calls initNewGame.
     * */
    void selectPlayersAndInitNewGame();

    /**
     * Loads saved game and starts the game.
     * */
    void loadSavedGameAndPlay();

    /**
     * Gets play card from top of the pack.
     * @returns smart pointer of the play card
     * */
    std::shared_ptr<PlayCard> getCardFromStack();

    /**
     * Puts play card back to the pack.
     * @param smart pointer of the play card
     * */
    void putCardInStack(std::shared_ptr<PlayCard> card);

    /**
     * Gives player play card from the top of the pack.
     * @param Smart pointer of the player to give the card to.
     * */
    bool givePlayerCardFromStack(std::shared_ptr<Player> player);

    /**
     * Starts the game. Switches the moves for two players.
     * */
    void startGame();

    /**
     * Check which player is on the turn and creates new move.
     * @returns instance of Move class with correct leader and target
     * */
    Move nextMove();

    /**
     * Gets defense power from the player that is being attacked.
     * @param attack = attack power
     * @param leader = smart pointer of the player that is being attacked
     * @param target = smart pointer of the second player
     * @returns defense power as int
     * */
    int getDefenseFromPlayer(std::shared_ptr<Player> target, int attack);

    /**
    * Gets attack power from the player that is being attacked.
    * @param attack = attack power
    * @param leader = smart pointer of the player that is being attacked
    * @param target = smart pointer of the second player
    * @returns atack power as int
    * */
    int getAttackDefenseFromPlayer(std::shared_ptr<Player> target, int attack);

    /**
     * Some cards can take cards from players. This function realizes that.
     * @param leader = smart pointer of the player that is demanded a card
     * @param target = smart pointer of the second player
     * @returns Smart pointer of PlayCard that lead player gave up
     * */
    std::shared_ptr<PlayCard> getCardFromPlayer(std::shared_ptr<Player> target);

    /**
     * Persist the current gameplay. This overwrites any other saved gameplays.
     * */
    void saveGame();


};




