//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_PLAYER_H
#define OPEN_ENDED_PROJECT1_PLAYER_H
#include "Card.h"
#include "vector"

using namespace std;
//Enumerated type for the types of hands possible in poker
enum HandValue{HIGH = 0, PAIR = 1, TWOPAIR = 2, THREEOFKIND = 3, STRAIGHT = 4, FLUSH = 5, FULLHOUSE = 6, FOUROFKIND = 7, STRAIGHTFLUSH = 8};
//Struct for a players hand
struct Hand {
    Card card1;
    Card card2;
    HandValue handVal = HIGH;
};
class Player {
private:
    //Fields
    string name;
    Hand hand;
public:
    /*
     * Default Constructor
     * Initializes a player with name set to default
     */
    Player();

    /*
     * Fields: Card object and Card object
     */
    Player(Card, Card);

    /*
     * returns card1
     */
    Card getCard1() const;

    /*
     * Returns card2
     */
    Card getCard2() const;

    /*
     * returns name
     */
    string getName() const;

    /*
     * returns hand
     */
    Hand getHand() const;

    /*
     * returns the value of the hand
     */
    int getHandVal() const;

    /*
     * Fields: Card
     * sets card1 of the hand equal to the field
     */
    void setCard1(Card);

    /*
     * Fields: Card
     * sets card2 of the hand equal to the field
     */
    void setCard2(Card);

    /*
     * Fields: string
     * sets name of the player equal to the field
     */
    void setName(string);

    /*
     * Fields: HandValue
     * sets handVal of the hand equal to the field
     */
    void setHandVal(HandValue);

    /*
     * Fields: vector of cards
     * sorts the cards in ascending order for hand evaluation
     */
    vector<Card> BubbleSort(vector<Card>);

    /*
     * Fields: vector of cards
     * calls functions that check the vector of cards for specific types of poker hands
     */
    void evaluateHand(vector<Card>);

    /*
     * Fields: vector of cards
     * checks the vector of cards for a straight combination of card objects
     */
    static bool isStraight(vector<Card>&);

    /*
     * Fields: vector of cards
     * checks the vector of cards for a flush combination of card objects
     */
    static bool isFlush(vector<Card>&);

    /*
     * Fields: vector of cards
     * checks the vector of cards for a straight flush combination of card objects
     */
    static bool isStraightFlush(vector<Card>&);

    /*
     * Fields: vector of cards
     * checks the vector of cards for a pair of card objects
     */
    static bool isPair(vector<Card>&);

    /*
     * Fields: vector of cards
     * checks the vector of cards for two pairs of card objects
     */
    static bool isTwoPair(vector<Card>&);

    /*
     * Fields: vector of cards
     * checks the vector of cards for a three of a kind combination of card objects
     */
    static bool isTrips(vector<Card>&);

    /*
     * Fields: vector of cards
     * checks the vector of cards for a full house combination of card objects
     */
    static bool isFullHouse(vector<Card>&);

    /*
     * Fields: vector of cards
     * checks the vector of cards for a four of a kind combination of card objects
     */
    static bool isQuads(vector<Card>&);

    //overloaded printing operators
    friend std::ostream& operator << (std::ostream& outs, const Player &player);
};


#endif //OPEN_ENDED_PROJECT1_PLAYER_H
