//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_HOLDEM_H
#define OPEN_ENDED_PROJECT1_HOLDEM_H
#include "vector"
#include "card.h"
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

class HoldemGame {
private:
    std::vector<Card> const deck;
    Player P1;
public:
    HoldemGame();

    bool flop();

    bool turn();

    bool river();

    static char getPlayerChoice(std::ostream &outs, std::istream &ins);
};


#endif //OPEN_ENDED_PROJECT1_HOLDEM_H
