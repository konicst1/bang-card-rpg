//
// Created by stepan on 6/16/20.
//

#pragma once


class CardBuilderPersister {
    std::vector<std::string> instructionSet{"decreaseTargetHealth", "giveLeaderCardFromStack", "decreaseLeaderHealth",
                                         "giveTargetCardFromStack", "targetAttackDefense", "leaderAttackDefense",
                                         "targetDefendDefense", "leaderDefendDefense", "addHealthTarget",
                                         "addHealthLeader", "takeCardFromTarget", "robCardFromTarget",
                                         "nextCardIsHeart", "nextCardIsSpades", "nextCardIsClub", "nextCardIsDiamond"};

public:
    /**Create custom card */
    void createCard();

private:
    /**Create custom role card */
    void createRoleCard();

    /**Create custom play card */
    void createPlayCard();

    /**Check if instruction is valid */
    bool instructionExists(std::string s);

    //todo comment
    std::vector<std::string> loadInstructions();
};




