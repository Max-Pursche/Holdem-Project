//
// Created by mrgat on 1/31/2022.
//

#include "Card.h"
Card::Card() {
    value = Value(0);
    suitVal = Suit(0);
}

Card::Card(int intVal, int suit) {
    value = Value(intVal);
    suitVal = Suit(suit);
}

Suit Card::getSuit() const {
    return suitVal;
}

int Card::getValue() const  {
    return value;
}

void Card::setSuitVal(int intVal) {
    suitVal = Suit(intVal);
}

void Card::setValue(int intVal) {
    value = Value(intVal);
}

bool operator >= (const Card& lhs, const Card& rhs) {
    return lhs.getValue() >= rhs.getValue();
}
bool operator <= (const Card& lhs, const Card& rhs) {
    return lhs.getValue() <= rhs.getValue();
}

bool operator > (const Card& lhs, const Card& rhs) {
    return lhs.getValue() >= rhs.getValue();
}

bool operator < (const Card& lhs, const Card& rhs) {
    return lhs.getValue() < rhs.getValue();
}

bool operator == (const Card& lhs, const Card& rhs) {
    return lhs.getValue() == rhs.getValue();
}

std::ostream& operator << (std::ostream& outs, const Card &card) {
    if (card.getValue()== ACE) {
        outs << "ACE";
    }
    else if (card.getValue() == KING) {
        outs << "KING";
    }
    else if (card.getValue() == QUEEN) {
        outs << "QUEEN";
    }
    else if (card.getValue() == JACK) {
        outs << "JACK";
    }
    else if (card.getValue() == TEN) {
        outs << "TEN";
    }
    else if (card.getValue() == NINE) {
        outs << "NINE";
    }
    else if (card.getValue() == EIGHT) {
        outs << "EIGHT";
    }
    else if (card.getValue() == SEVEN) {
        outs << "SEVEN";
    }
    else if (card.getValue() == SIX) {
        outs << "SIX";
    }
    else if (card.getValue() == FIVE) {
        outs << "FIVE";
    }
    else if (card.getValue() == FOUR) {
        outs << "FOUR";
    }
    else if (card.getValue() == THREE) {
        outs << "THREE";
    }
    else{
        outs << "TWO";
    }
    if (card.getSuit() == HEART) {
        outs << " of HEARTS";
    }
    else if (card.getSuit() == SPADE) {
        outs << " of SPADES";
    }
    else if (card.getSuit() == DIAMOND) {
        outs << " of DIAMONDS";
    }
    else {
        outs << " of CLUBS";
    }
    return outs;
}