//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_CARD_H
#define OPEN_ENDED_PROJECT1_CARD_H
#include "vector"
#include "istream"
#include "ostream"

enum Suit{ HEART = 0, CLUB = 1, SPADE = 2, DIAMOND = 3};
enum Face{NOFACE = 0, JACK = 11, QUEEN = 12, KING = 13, ACE = 14};

class Card {
private:
    int value;
    Suit suitVal;
    Face faceVal;
public:
    Card();

    Card(int, int, int);

    int getValue() const;

    Suit getSuit() const;

    Face getFace()const;

    void setValue(int);

    void setSuitVal(int);

    void setFaceVal(int);

    //Overloaded Boolean Operators
    friend bool operator > (const Card& card1L, const Card& card2R);

    friend bool operator >= (const Card& card1L, const Card& card2R);

    friend bool operator < (const Card& card1L, const Card& card2R);

    friend bool operator <= (const Card& card1L, const Card& card2R);

    friend std::ostream& operator << (std::ostream& outs, const Card &card);
};
#endif //OPEN_ENDED_PROJECT1_CARD_H
