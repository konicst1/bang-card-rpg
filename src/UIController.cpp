//
// Created by stepan on 5/5/20.
//

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <limits>
#include "UIController.h"


int UIController::selectRole(const std::shared_ptr<RoleCard> &a, const std::shared_ptr<RoleCard> &b,
                             const std::shared_ptr<RoleCard> &c) {

    std::cout << "(1) " << a->getName() << "  -  " << a->getHealthCount() << "hp     " << "(" << a->getImage() << ")"
              << std::endl;
    std::cout << "(2) " << b->getName() << "  -  " << b->getHealthCount() << "hp     " << "(" << b->getImage() << ")"
              << std::endl;
    std::cout << "(3) " << c->getName() << "  -  " << c->getHealthCount() << "hp     " << "(" << c->getImage() << ")"
              << std::endl;
    int r;
    while (true) {
        if (std::cin.fail() || std::cin.eof()) {
            throw std::exception();
        }
        std::cin >> r;
        if (std::cin.fail() || std::cin.eof()) {
            throw std::exception();
        }
        if ((r >= 1) && (r <= 3)) {
            return r;
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Not valid, enter value in range <1;3>" << std::endl;
    }
}


void UIController::print(const std::string &a) {
    std::cout << a;
}

void UIController::println(const std::string &b) {
    std::cout << b << std::endl;
}

void UIController::startGame() {
    println("Game has started, good luck!");

}

void UIController::startMove(Move &move) {

    clearScreen();


    std::cout << "You:         " << std::setw(20) << move.getLeader()->getName() << "         "
              << move.getLeader()->getHealth() << "hp" << std::endl;
    std::cout << "Your oponent:" << std::setw(20) << move.getTarget()->getName() << "         "
              << move.getTarget()->getHealth() << "hp" << std::endl << std::endl;


}

void UIController::presentCards(std::vector<std::shared_ptr<PlayCard>> cards) {
    std::cout << "Your cards:" << std::endl;
    for (int i = 1; i <= (int) cards.size(); i++) {
        std::cout << "(" << i << ") " << cards[i - 1]->getName() << std::setw(30 - (int) cards[i - 1]->getName().size())
                  << "  (" << cards[i - 1]->getImage() << ")" << std::endl;
    }

}

int UIController::getChoice(int range, int lower) {

    while (true) {

        int r;
        if (std::cin.fail() || std::cin.eof()) {
            throw std::exception();
        }
        std::cin >> r;
        if (std::cin.fail() || std::cin.eof()) {
            throw std::exception();
        }
        if ((r >= lower) && (r <= range)) {
            return r;
        }

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Not valid, enter value in range <1;" << range << ">" << std::endl;
    }

}

void UIController::clearScreen() {
    std::cout << std::string(100, '\n');
}

void UIController::switchPlayers(const std::shared_ptr<Player> &player) {
    clearScreen();
    std::cout << "Switching to: " << player->getName() << std::endl;
    std::cout << "Enter any value to start switch." << std::endl;
    if (std::cin.fail() || std::cin.eof()) {
        throw std::exception();
    }
    std::string a;
    std::cin >> a;
    clearScreen();
    if (std::cin.fail() || std::cin.eof()) {
        throw std::exception();
    }

    std::cout << "You:         " << std::setw(20) << player->getName() << "         " << player->getHealth() << "hp"
              << std::endl;

}

void UIController::presentOptions(std::vector<std::string> options) {
    for (int i = 1; i <= (int) options.size(); i++) {
        std::cout << "(" << i << ") " << options[i - 1] << "  " << std::endl;;
    }
}

void UIController::endGame(const std::string &winner) {
    println("Game over.");
    println(winner + " won!\n\n");
}

std::string UIController::getStringInput() {
    if (std::cin.fail() || std::cin.eof()) {
        throw std::exception();
    }
    std::string res;
    std::cin >> res;
    if (std::cin.fail() || std::cin.eof()) {
        throw std::exception();
    }
    return res;
}

int UIController::getIntInput() {
    while (true) {
        int r;
        if (std::cin.fail() || std::cin.eof()) {
            throw std::exception();
        }
        std::cin >> r;
        if (std::cin.fail() || std::cin.eof()) {
            throw std::exception();
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return r;
        }
    }
}

void UIController::endMove(const std::shared_ptr<Player> &leader, const std::shared_ptr<Player> &target) {
    std::cout << std::endl << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl << "END OF THE MOVE" << std::endl;
    std::cout << "You:         " << std::setw(20) << leader->getName() << "         " << leader->getHealth() << "hp"
              << std::endl;
    std::cout << "Your oponent:" << std::setw(20) << target->getName() << "         "
              << target->getHealth() << "hp" << std::endl << std::endl;

    presentCards(leader->getCards());


    std::cout << std::endl << "Enter any value to proceed." << std::endl;
    if (std::cin.fail() || std::cin.eof()) {
        throw std::exception();
    }
    std::string a;
    std::cin >> a;
    if (std::cin.fail() || std::cin.eof()) {
        throw std::exception();
    }
    clearScreen();
}



