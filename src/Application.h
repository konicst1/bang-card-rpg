//
// Created by stepan on 6/15/20.
//

#pragma once


#include <vector>
#include <string>
#include "GameManager.h"
#include "CardBuilderPersister.h"

/**
 * Class that manages the outer application. (Not the game). Provides basic start menu functions.
 * */
class Application {
    GameManager manager = GameManager();
    CardBuilderPersister cBuilder = CardBuilderPersister();
    std::vector<std::string> menuOptions {"New Game - One Player", "New Game - Two Players", "Load Game", "Add Card", "Exit"};


public:
    Application() = default;

    Application ( const Application & ) = default;

    Application & operator= ( const Application & ) = delete;

    ~Application () = default;

    /**
     * Runs the whole application. Shows the menu and manages the basic functions.
     * */
    int start();

};




