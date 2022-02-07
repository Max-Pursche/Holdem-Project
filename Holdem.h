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
    HoldemGame();

    void runGame();

    void turn(std::vector<Card>,std::vector<Card>);

    int evaluatePlayers(std::vector<Player>,std::vector<Card>);

    void createDeck(std::vector<Card> &deck);

    void removeCard(int, std::vector<Card>);

    int getPlayerChoice(std::ostream &outs, std::istream &ins);

    void printPlayerOptions(std::ostream &outs);

    char getUIChoice(std::ostream &outs, std::istream &ins);

    void printUiOptions(std::ostream &outs);

    void clearCards(std::vector<Card>);

    void printCardsInPlay(std::ostream &outs, std::vector<Card>);

    void printPlayersHands(std::ostream &outs, std::vector<Player>);

    ostream& printPlayerHand(std::ostream &outs, Player);

    static void printRules(std::ostream &outs);

    void printHands(std::ostream &outs);

};
#endif //OPEN_ENDED_PROJECT1_HOLDEM_H
