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
    //need to init a Deck
    std::vector<Card> const deck;
    //
    std::vector<Card> cardsInPlay;
    //consdering making these guys in main and having them as parameters
    Player P1;
    Player P2;
    Player P3;
    Player P4;

public:

    HoldemGame();

    bool flop();

    bool turn();

    void newHands();

    void clearCardsInPlay(vector<Card>);

    void createDeck();

    static int getPlayerChoice(std::ostream &outs, std::istream &ins);

    static char getUIChoice(std::ostream &outs, std::istream &ins);

    void printCardsInPlay(std::ostream &outs);

    void printPlayerHands(std::ostream &outs);

    static void print_options(std::ostream &outs);

    static void print_rules(std::ostream &outs);
};

#endif //OPEN_ENDED_PROJECT1_HOLDEM_H
