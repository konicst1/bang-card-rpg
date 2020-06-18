//
// Created by stepan on 6/16/20.
//

#pragma once


class InstructionResponse {
    int attackPower;
    int defensePower;
    int continueFlag;
    int healthAddition;
    int cardAddition;

public:
    InstructionResponse(int attackPower, int defensePower, int continueFlag, int healthAddition, int cardAddition)
            : attackPower(attackPower), defensePower(defensePower), continueFlag(continueFlag),
              healthAddition(healthAddition), cardAddition(cardAddition) {}


    InstructionResponse &operator+(const InstructionResponse &response) {
        if (this->continueFlag) {
            this->attackPower += response.getAttackPower();
            this->defensePower += response.getDefensePower();
            this->healthAddition += response.getHealthAddition();
            this->cardAddition += response.getCardAddition();
            this->continueFlag = response.getContinueFlag();
        } else {
            this->continueFlag = 1;
        }
        return *this;
    }

    int getAttackPower() const {
        return attackPower;
    }

    int getDefensePower() const {
        return defensePower;
    }

    int getContinueFlag() const {
        return continueFlag;
    }

    int getHealthAddition() const {
        return healthAddition;
    }

    int getCardAddition() const {
        return cardAddition;
    }
};




