//
// Created by stepan on 6/15/20.
//

#include <iostream>
#include "Application.h"
#include "UIController.h"

int Application::start() {
    try {

        while (true) {
            UIController::presentOptions(menuOptions);
            int index = UIController::getChoice(menuOptions.size()) - 1;
            std::string choice = menuOptions[index];


            if (choice == menuOptions[0]) {
                manager.selectPlayerAndInitSinglePlayerGame();      //new game single player
            } else if (choice == menuOptions[1]) {
                manager.selectPlayersAndInitNewGame();              //new game multi player
            } else if (choice == menuOptions[2]) {
                manager.loadSavedGameAndPlay();                     // load game
            } else if (choice == menuOptions[3]) {
                cBuilder.createCard();                              // add card
            } else if (choice == menuOptions[4]) {
                break;                                              // exit
            }
        }
    } catch (std::exception &e) {
        return 0;
    }

    return 0;
}
