//
// Created by stepan on 6/15/20.
//

#pragma once


#include <vector>
#include <string>
#include "GameManager.h"

class Application {
    GameManager manager = GameManager();

    std::vector<std::string> menuOptions {"New Game", "Load Game", "Add Card", "Remove Card", "Exit"};

public:
    Application() = default;

    Application ( const Application & ) = default;

    Application & operator= ( const Application & ) = delete;

    ~Application () = default;

    int start();

};




