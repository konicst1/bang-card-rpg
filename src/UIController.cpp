//
// Created by stepan on 5/5/20.
//

#include <iostream>
#include "UIController.h"

int UIController::selectRoleA(std::string a, std::string b, std::string c) {
    println("Player A, please, select your character:");
    std::cout << "(1) " << a << std::endl;
    std::cout << "(2) " << b << std::endl;
    std::cout << "(3) " << c << std::endl;
    int r;
    while(true){
        std::cin >> r;
        if((r >= 1) && (r <= 3)){
            return r;
        }
    }
}

int UIController::selectRoleB(std::string a, std::string b, std::string c) {
    println("Player B, please, select your character:");
    std::cout << "(1) " << a << std::endl;
    std::cout << "(2) " << b << std::endl;
    std::cout << "(3) " << c << std::endl;
    int r;
    while(true){
        std::cin >> r;
        if((r >= 1) && (r <= 3)){
            return r;
        }
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

