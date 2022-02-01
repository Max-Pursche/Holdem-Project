//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_CARD_H
#define OPEN_ENDED_PROJECT1_CARD_H
#include "vector"
class Card {
private:
    enum Suit{ HEART = 1, CLUB = 2, SPADE = 3, DIAMOND = 4 };
    enum Face{ NOFACE = 10, JACK = 11, QUEEN = 12, KING = 13, ACE = 14};
    int value;
    Suit suitVal;
    Face faceVal;
public:
    Card();

    Card(int, int, int);

    int getValue();

    Suit getSuit();

    Face getFace();

    void setValue(int);

    void setSuitval(int);

    void setFacetval(int);
};


#endif //OPEN_ENDED_PROJECT1_CARD_H
