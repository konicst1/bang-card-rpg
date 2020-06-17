//
// Created by stepan on 6/16/20.
//

#pragma once


class CardResponse {
int attackPower;
int defensePower;

public:
    CardResponse(int attackPower, int defensePower) : attackPower(attackPower), defensePower(defensePower) {}

    int getAttackPower() const {
        return attackPower;
    }

    void setAttackPower(int attackPower) {
        CardResponse::attackPower = attackPower;
    }

    int getDefensePower() const {
        return defensePower;
    }

    void setDefensePower(int defensePower) {
        CardResponse::defensePower = defensePower;
    }
};




