//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_PLAYER_H
#define OPEN_ENDED_PROJECT1_PLAYER_H
#include "Card.h"
#include "vector"

using namespace std;
enum HandValue{HIGH = 0, PAIR = 1, TWOPAIR = 2, THREEOFKIND = 3, STRAIGHT = 4, FLUSH = 5, FULLHOUSE = 6, FOUROFKIND = 7, STRAIGHTFLUSH = 8};
struct Hand {
    Card card1;//
    Card card2;//
    HandValue handVal = HIGH;
};

class Player {
private:
    string name;
    Hand hand;
public:
    Player();

    Player(Card, Card);

    Card getCard1() const;

    Card getCard2() const;

    string getName() const;

    Hand getHand() const;

    int getHandVal() const;

    void setCard1(Card);

    void setCard2(Card);

    void setName(string);

    void setHandVal(HandValue);

    vector<Card> BubbleSort(vector<Card>);

    void evaluateHand(vector<Card>);

    static bool isStraight(vector<Card>&);

    static bool isFlush(vector<Card>&);

    static bool isStraightFlush(vector<Card>&);

    static bool isPair(vector<Card>&);

    static bool isTwoPair(vector<Card>&);

    static bool isTrips(vector<Card>&);

    static bool isFullHouse(vector<Card>&);

    static bool isQuads(vector<Card>&);

    friend std::ostream& operator << (std::ostream& outs, const Player &player);
};


#endif //OPEN_ENDED_PROJECT1_PLAYER_H
