//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_PLAYER_H
#define OPEN_ENDED_PROJECT1_PLAYER_H
#include "Card.h"
#include "vector"

using namespace std;
struct Hand {
    Card card1;
    Card card2;
    int handVal = 0;
};

class Player {
private:
    Hand hand;
public:
    Player();

    Player(Card, Card);

    Card getCard1() const;

    Card getCard2() const;

    Hand getHand() const;

    int getHandVal() const;

    void setCard1(Card);

    void setCard2(Card);

    void setHandVal(int);

    static void BubbleSort(vector<Card>);

    void evaluateHand(vector<Card>);

    bool isStraight(vector<Card>);

    bool isFlush(vector<Card>);

    bool isStraightFlush(vector<Card>);

    bool isPairTripQuad(vector<Card>);

    bool isPair(vector<Card>);

    bool isTwoPair(vector<Card>);

    bool isTrips(vector<Card>);

    bool isFullHouse(vector<Card>);

    bool isQuads(vector<Card>);

};


#endif //OPEN_ENDED_PROJECT1_PLAYER_H
