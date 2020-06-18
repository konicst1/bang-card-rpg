//
// Created by stepan on 6/16/20.
//

#pragma once


class InstructionResponse {
    int attackPower;
    int defensePower;
    int continueFlag;

public:
    InstructionResponse(int attackPower, int defensePower, int continueFlag) : attackPower(attackPower),
                                                                               defensePower(defensePower),
                                                                               continueFlag(continueFlag) {}


    InstructionResponse &operator+(const InstructionResponse &response) {
        if (this->continueFlag) {
            if (response.getAttackPower() >= 0) {
                this->attackPower += response.getAttackPower();
            }
            if (response.getDefensePower() >= 0) {
                this->defensePower += response.getDefensePower();
            }
            this->continueFlag = response.getContinueFlag();
        } else {
            this->continueFlag = 1;
        }
        return *this;
    }

    int getAttackPower() const {
        return attackPower;
    }

    void setAttackPower(int attackPower) {
        InstructionResponse::attackPower = attackPower;
    }

    int getDefensePower() const {
        return defensePower;
    }

    void setDefensePower(int defensePower) {
        InstructionResponse::defensePower = defensePower;
    }

    int getContinueFlag() const {
        return continueFlag;
    }

    void setContinueFlag(int continueFlag) {
        InstructionResponse::continueFlag = continueFlag;
    }
};




