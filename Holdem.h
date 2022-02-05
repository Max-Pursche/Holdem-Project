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
private:
    //need to init a Deck
    std::vector<Card>* deck;
    //
    std::vector<Card>* cardsInPlay;
    //
    std::vector<Player>* players;
public:

    HoldemGame();

    void turn(Card);

    void newHands(vector<Player>);

    Player evaluatePlayers(vector<Player>, vector<Card>);

    vector<Player> getPlayers();

    void createDeck();

    static int getPlayerChoice(std::ostream &outs, std::istream &ins);

    static char getUIChoice(std::ostream &outs, std::istream &ins);

    void clearCards(vector<Card>);

    void printCardsInPlay(std::ostream &outs);

    void printPlayerHands(std::ostream &outs);

    static void printRules(std::ostream &outs);

    void HoldemGame::printHands(std::ostream &outs);

    };
#endif //OPEN_ENDED_PROJECT1_HOLDEM_H
