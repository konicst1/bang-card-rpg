//
// Created by stepan on 5/5/20.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include "UIController.h"


int UIController::selectRole(std::string a, std::string b, std::string c) {

    std::cout << "(1) " << a << std::endl;
    std::cout << "(2) " << b << std::endl;
    std::cout << "(3) " << c << std::endl;
    int r;
    while (true) {
        std::cin >> r;
        if ((r >= 1) && (r <= 3)) {
            return r;
        }
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Not valid, enter value in range <1;3>" << std::endl;
    }
}


void UIController::print(std::string a) {
    std::cout << a;
}

void UIController::println(std::string b) {
    std::cout << b << std::endl;
}

void UIController::startGame() {
    println("Game has started, good luck!");

}

void UIController::startMove(Move &move) {
  /*  clearScreen();
    std::cout << "Now it is " << move.getLeader()->getName() << "'s turn." << std::endl;
    std::cout << "Enter any value to start move." << std::endl;

    std::string a;
    std::cin >> a;*/
    clearScreen();


    std::cout << "You:         " << std::setw(20) << move.getLeader()->getName() << "         "
              << move.getLeader()->getHealth() << "hp" << std::endl;
    std::cout << "Your oponent:" << std::setw(20) << move.getTarget()->getName() << "         "
              << move.getTarget()->getHealth() << "hp" << std::endl << std::endl;


}

void UIController::presentCards(std::vector<std::shared_ptr<PlayCard>> cards) {
    std::cout << "Your cards:" << std::endl;
    for (int i = 1; i <= (int) cards.size(); i++) {
        std::cout << "(" << i << ") " << cards[i - 1]->getName() << "  " << std::endl;;
    }

}

int UIController::getChoice(int range, int lower) {
    //std::cout << std::endl << "What card would ya like to play?" << std::endl;

    while (true) {
        int r;
        std::cin >> r;

        if ((r >= lower) && (r <= range)) {
            return r;
        }

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Not valid, enter value in range <1;" << range << ">" << std::endl;
    }

}

void UIController::clearScreen() {
    std::cout << std::string(100, '\n');
}

void UIController::switchPlayers(std::shared_ptr<Player> player) {
    clearScreen();
    std::cout << "Switching to: " << player->getName() << std::endl;
    std::cout << "Enter any value to start switch." << std::endl;

    std::string a;
    std::cin >> a;
    clearScreen();


    std::cout << "You:         " << std::setw(20) << player->getName() << "         " << player->getHealth() << "hp" << std::endl;

}

void UIController::presentOptions(std::vector<std::string> options) {
    for (int i = 1; i <= (int) options.size(); i++) {
        std::cout << "(" << i << ") " << options[i - 1] << "  " << std::endl;;
    }
}

void UIController::endGame(const std::string& winner) {
    println("Game over.");
    println(winner + " won!\n\n");
}

std::string UIController::getStringInput() {
    std::string res;
    std::cin >> res;
    return res;
}

int UIController::getIntInput() {
    while (true) {
        int r;
        std::cin >> r;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }else {
            return r;
        }
    }
}



