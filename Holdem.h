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
#include <memory>

using namespace std;

class HoldemGame {
public:
    HoldemGame(vector<Card>, vector<Player>);

    void turn(vector<Card>, vector<Card>);

    void newHands(vector<Player>, vector<Card>);

    int evaluatePlayers(vector<Player>, vector<Card>);

    void createDeck(vector<Card> deck);

    void removeCard(int, vector<Card>);

    int getPlayerChoice(std::ostream &outs, std::istream &ins);

    void printPlayerOptions(std::ostream &outs);

    char getUIChoice(std::ostream &outs, std::istream &ins);

    void printUiOptions(std::ostream &outs);

    void clearCards(vector<Card>);

    void printCardsInPlay(std::ostream &outs, vector<Card>);

    void printPlayerHands(std::ostream &outs, vector<Player>);

    static void printRules(std::ostream &outs);

    void printHands(std::ostream &outs);

};
#endif //OPEN_ENDED_PROJECT1_HOLDEM_H
