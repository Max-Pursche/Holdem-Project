//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_CARD_H
#define OPEN_ENDED_PROJECT1_CARD_H
#include "vector"
#include "istream"
#include "ostream"

enum Suit{ HEART = 0, CLUB = 1, SPADE = 2, DIAMOND = 3};
enum Value{TWO = 0, THREE = 1, FOUR = 2, FIVE = 3, SIX = 4, SEVEN = 5, EIGHT = 6, NINE = 7, TEN = 8, JACK = 9, QUEEN = 10, KING = 11, ACE = 12};
class Card {
private:
    Value value;
    Suit suitVal;
public:
    Card();

    Card(int, int);

    int getValue() const;

    Suit getSuit() const;

    void setValue(int);

    void setSuitVal(int);

    //Overloaded Boolean Operators
    friend bool operator > (const Card& card1L, const Card& card2R);

    friend bool operator >= (const Card& card1L, const Card& card2R);

    friend bool operator < (const Card& card1L, const Card& card2R);

    friend bool operator <= (const Card& card1L, const Card& card2R);

    friend std::ostream& operator << (std::ostream& outs, const Card &card);
};
#endif //OPEN_ENDED_PROJECT1_CARD_H
