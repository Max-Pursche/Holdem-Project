//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_PLAYER_H
#define OPEN_ENDED_PROJECT1_PLAYER_H
#include "Card.h"
#include "vector"

using namespace std;

class Player {
private:
    Card card1;
    Card card2;
    int handVal;
public:
    Player();

    Player(Card, Card);

    Card getCard1();

    Card getCard2();

    int getHandVal();

    void setCard1(Card);

    void setCard2(Card);

    void setHandVal(int);

    void evaluateHand(vector<Card>);

    bool isStraight(vector<Card>);

    bool isFlush(vector<Card>);

    bool isPairTripQuad(vector<Card>);
};


#endif //OPEN_ENDED_PROJECT1_PLAYER_H
