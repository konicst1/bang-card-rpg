//
// Created by stepan on 5/5/20.
//

#include <iostream>
#include <iomanip>
#include "UIController.h"

int UIController::selectRoleA(std::string a, std::string b, std::string c) {
    println("Player A, please, select your character:");
    std::cout << "(1) " << a << std::endl;
    std::cout << "(2) " << b << std::endl;
    std::cout << "(3) " << c << std::endl;
    int r;
    while (true) {
        std::cin >> r;
        if ((r >= 1) && (r <= 3)) {
            return r;
        }
        std::cout << "Not valid, enter value in range <1;3>" << std::endl;
    }
}

int UIController::selectRoleB(std::string a, std::string b, std::string c) {
    println("Player B, please, select your character:");
    std::cout << "(1) " << a << std::endl;
    std::cout << "(2) " << b << std::endl;
    std::cout << "(3) " << c << std::endl;
    int r;
    while (true) {
        std::cin >> r;
        if ((r >= 1) && (r <= 3)) {
            return r;
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
    clearScreen();
    std::cout << "Now it is " << move.getLeader()->getName() << "'s turn." << std::endl;
    std::cout << "Enter any value to start move." << std::endl;

    std::string a;
    std::cin >> a;
    clearScreen();


    std::cout << "You:         " << std::setw(20) << move.getLeader()->getName() << "         " << move.getLeader()->getHealth() << "hp" << std::endl;
    std::cout << "Your oponent:" << std::setw(20) << move.getTarget()->getName() << "         " << move.getTarget()->getHealth() << "hp" << std::endl << std::endl;



}

void UIController::presentCards(std::vector<std::shared_ptr<PlayCard>> cards) {
    std::cout << "Your cards:" << std::endl;
    for (int i = 1; i <= (int) cards.size(); i++) {
        std::cout << "(" << i << ") " << cards[i - 1]->getName() << "  " << std::endl;;
    }

}

int UIController::getChoice(int range) {
    std::cout << std::endl << "What card would ya like to play?" << std::endl;
    int r;
    while (true) {
        std::cin.ignore(10000, '\n');
        std::cin.clear();
        std::cin >> r;

        if ((r >= 1) && (r <= range)) {
            return r;
        }

        std::cin.ignore(10000, '\n');
        std::cin.clear();
        std::cout << "Not valid, enter value in range <1;" << range << ">" << std::endl;
    }

}

void UIController::clearScreen() {
    std::cout << std::string( 100, '\n' );
}



