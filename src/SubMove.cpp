//
// Created by stepan on 6/10/20.
//

#include "SubMove.h"
#include "UIController.h"
#include "DefenseAction.h"
#include "GameManager.h"
#include "AttackAction.h"

int SubMove::init() {
    UIController::print("Your opponent made move that requires your response. You are being attacked with power of ");
    UIController::println(std::to_string(attackStr).append("."));
    UIController::println("If you want to skip, enter 0.");
    return 0;
}


int SubMove::getDefenseValue(GameManager &m) {
    int defense = 0;
   /* while (true) {
        UIController::presentCards(this->leader->getCards());
        UIController::println("Play defensive cards to defend yourself! Enter 0 when done.");
        int cardNumber = leader->getDefenseChoice(attackStr);
        cardNumber--; //make it an index
        //  leader->getCards()[cardNumber-1]->getAction()->perform(this->leader, this->target);
        if (cardNumber == -1) {
            return defense;
        } else if (typeid(*leader->getCards()[cardNumber]->getAction()) == typeid(DefenseAction)) {
            int continueFlag = 1;
            int r = dynamic_cast<DefenseAction *>(leader->getCards()[cardNumber]->getAction().get())->getHealthDefensePower();

            for (const auto &ins : leader->getCards()[cardNumber]->getAction()->getInstructions()) {
                if (!ins.compare("nextCardIsHeart")) {
                    std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                    if (nCard->getSymbol().compare("heart")) {
                        continueFlag = 0;
                    }
                    m.putCardInStack(nCard);
                } else if (!ins.compare("nextCardIsSpades")) {
                    std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                    if (nCard->getSymbol().compare("spades")) {
                        continueFlag = 0;
                    }
                    m.putCardInStack(nCard);
                } else if (!ins.compare("nextCardIsClub")) {
                    std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                    if (nCard->getSymbol().compare("club")) {
                        continueFlag = 0;
                    }
                    m.putCardInStack(nCard);
                } else if (!ins.compare("nextCardIsDiamond")) {
                    std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                    if (nCard->getSymbol().compare("diamond")) {
                        continueFlag = 0;
                    }
                    m.putCardInStack(nCard);
                }
            }

            //put card back to stack
            m.putCardInStack(leader->getCards()[cardNumber]);

            leader->removeCard(cardNumber);
            if (continueFlag) {
                defense += r;
                UIController::println("Next card symbol was the correct type, you are being protected by power of " +
                                      std::to_string(defense) + ".");

            } else {
                UIController::println("Next card symbol was the bad type, you are being protected by power of " +
                                      std::to_string(defense) + ".");
            }

        }
    }*/

return 0; //todo
}

int SubMove::getAttackValue(GameManager &m) {
    int attack = 0;
   /* while (true) {
        UIController::presentCards(this->leader->getCards());
        UIController::println("Play attack cards to defend yourself! Enter 0 when done.");
        int cardNumber = leader->getAttackChoice(attackStr);
        cardNumber--; //make it an index
        if (cardNumber == -1) {
            return attack;
        } else if (typeid(*leader->getCards()[cardNumber]->getAction()) == typeid(AttackAction)) {
            int continueFlag = 1;
            int r = dynamic_cast<AttackAction *>(leader->getCards()[cardNumber]->getAction().get())->getDecreaseHealthTarget();

            for (auto ins : leader->getCards()[cardNumber]->getAction()->getInstructions()) {
                if (!ins.compare("nextCardIsHeart")) {
                    std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                    if (nCard->getSymbol().compare("heart")) {
                        continueFlag = 0;
                    }
                    m.putCardInStack(nCard);
                } else if (!ins.compare("nextCardIsSpades")) {
                    std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                    if (nCard->getSymbol().compare("spades")) {
                        continueFlag = 0;
                    }
                    m.putCardInStack(nCard);
                } else if (!ins.compare("nextCardIsClub")) {
                    std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                    if (nCard->getSymbol().compare("club")) {
                        continueFlag = 0;
                    }
                    m.putCardInStack(nCard);
                } else if (!ins.compare("nextCardIsDiamond")) {
                    std::shared_ptr<PlayCard> nCard = m.getCardFromStack();
                    if (nCard->getSymbol().compare("diamond")) {
                        continueFlag = 0;
                    }
                    m.putCardInStack(nCard);
                }
            }

            //put card back to stack
            m.putCardInStack(leader->getCards()[cardNumber]);
            leader->removeCard(cardNumber);
            if (continueFlag) {
                attack += r;
                UIController::println("Next card symbol was the correct type, you are being protected by power of " +
                                      std::to_string(attack) + ".");

            } else {
                UIController::println("Next card symbol was the bad type, you are being protected by power of " +
                                      std::to_string(attack) + ".");
            }

        }
    }*/

}

std::shared_ptr<PlayCard> SubMove::getCardFromLeader() {
  //  UIController::presentCards(this->leader->getCards());
  //  UIController::println("You need to give up one of your cards..choose which one will it be.");
  //  int cardNumber = leader->getCardChoice();
 //   cardNumber--; //make it an index

  //  std::shared_ptr<PlayCard> res = leader->getCards()[cardNumber];
  //  leader->removeCard(cardNumber);
    return nullptr;

}

SubMove::SubMove(std::shared_ptr<Player> target, int attackStr) {
    this->target = target;
    this->attackStr = attackStr;
}

SubMove::SubMove(int attackStr) {
    this->attackStr = attackStr;
}




