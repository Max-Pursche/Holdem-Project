//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_CARD_H
#define OPEN_ENDED_PROJECT1_CARD_H
#include "vector"
#include "istream"
#include "ostream"

enum Suit{ HEART = 1, CLUB = 2, SPADE = 3, DIAMOND = 4 };
enum Face{NULLFACE = 0, JACK = 11, QUEEN = 12, KING = 13, ACE = 14};

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

    //Overloaded Printing Operators
    friend void operator
};


#endif //OPEN_ENDED_PROJECT1_CARD_H
