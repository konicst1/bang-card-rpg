//
// Created by stepan on 6/15/20.
//

#include <iostream>
#include "Application.h"
#include "UIController.h"

int Application::start() {


    while(true){
        UIController::presentOptions(menuOptions);
        int index = UIController::getChoice(menuOptions.size()) - 1;
        std::string choice = menuOptions[index];


        if(choice == menuOptions[0]){
            manager.selectPlayersAndInitNewGame();
        }else if(choice == menuOptions[1]){
            manager.loadSavedGameAndPlay();
        } else if (choice == menuOptions[2]){

        } else if (choice == menuOptions[3]){

        }else if(choice == menuOptions[4]){
            break;
        }
    }

    return 0;
}
