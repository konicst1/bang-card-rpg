//
// Created by stepan on 6/16/20.
//

#include <vector>
#include <string>
#include "CardBuilderPersister.h"
#include "UIController.h"
#include "DataLoader.h"

void CardBuilderPersister::createCard() {
    std::vector<std::string> ops{"Add Play Card", "Add Role Card"};

    UIController::presentOptions(ops);
    int index = UIController::getChoice(ops.size()) - 1;
    std::string choice = ops[index];

    if (choice == ops[0]) {
        this->createPlayCard();
    } else if (choice == ops[1]) {
        this->createRoleCard();
    }
}

void CardBuilderPersister::createRoleCard() {
    std::string image, name;
    int health;


    UIController::println("Enter image path for the card.");
    image = UIController::getStringInput();
    UIController::println("Enter name of the card.");
    name = UIController::getStringInput();
    UIController::println("Enter health number for the role.");
    health = UIController::getIntInput();


    UIController::println("Enter instructions to define ability. Enter \"done\" when done.");


    DataLoader::persistRoleCard(image, name, health, loadInstructions());

}

void CardBuilderPersister::createPlayCard() {
    std::string image, name, type;
    std::vector<std::string> instructions;

    UIController::println("Enter image path for the card.");
    image = UIController::getStringInput();
    UIController::println("Enter name of the card.");
    name = UIController::getStringInput();

    UIController::println("Enter instructions to define ability. Enter \"done\" when done.");

    DataLoader::persistPlayCard(image, name, loadInstructions());
}

bool CardBuilderPersister::instructionExists(const std::string& s) {
    for (const auto& i : instructionRegexSet) {
        if (std::regex_match(s, i)) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> CardBuilderPersister::loadInstructions() {

    UIController::println("Valid instructions are: ");
    UIController::presentOptions(instructionStringSet);
    std::vector<std::string> instructions;
    UIController::println("Enter instructions to define ability. Enter \"done\" when done.");
    while (true) {
        std::string ins;
        ins = UIController::getStringInput();
        if (ins == "done") {
            break;
        }
        if (!instructionExists(ins)) {
            UIController::println("Invalid instruction...");
            continue;
        }
        instructions.push_back(ins);
    }
    return instructions;
}
