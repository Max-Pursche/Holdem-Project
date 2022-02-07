//
// Created by mrgat on 1/31/2022.
//

#ifndef OPEN_ENDED_PROJECT1_CARD_H
#define OPEN_ENDED_PROJECT1_CARD_H
#include "vector"
#include "istream"
#include "ostream"

//Enumerated type for the suit
enum Suit{ HEART = 0, CLUB = 1, SPADE = 2, DIAMOND = 3};
//Enumerated type for the values of the card
enum Value{TWO = 0, THREE = 1, FOUR = 2, FIVE = 3, SIX = 4, SEVEN = 5, EIGHT = 6, NINE = 7, TEN = 8, JACK = 9, QUEEN = 10, KING = 11, ACE = 12};
class Card {
private:
    Value value;
    Suit suitVal;
public:

    /*
     * Default Constructor
     * Initializes a card object with a specified suit and value
     * both set to their values at 0
     */
    Card();

    /*
     * Fields: Int value and Int Value
     * Initializes a card object with a suit and value depending on the ints input
     */
    Card(int, int);

    /*
     * Returns the value
     */
    int getValue() const;

    /*
     * Returns the suit
     */
    Suit getSuit() const;

    /*
     * Fields: int value
     * sets the int value to the enum
     */
    void setValue(int);

    /*
     * Fields: int value
     * sets the int value to the enum
     */
    void setSuitVal(int);

    //Overloaded Boolean Operators
    friend bool operator > (const Card& card1L, const Card& card2R);

    friend bool operator >= (const Card& card1L, const Card& card2R);

    friend bool operator < (const Card& card1L, const Card& card2R);

    friend bool operator <= (const Card& card1L, const Card& card2R);

    friend bool operator == (const Card& card1L, const Card& card2R);

    //overloaded printing operator
    friend std::ostream& operator << (std::ostream& outs, const Card &card);
};
#endif //OPEN_ENDED_PROJECT1_CARD_H
