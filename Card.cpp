//
// Created by mrgat on 1/31/2022.
//

#include "Card.h"
Card::Card() {
    value = 0;
    suitVal = Suit(0);
    faceVal = Face(0);
}

Card::Card(int intVal, int suit, int face) {
    value = intVal;
    suitVal = Suit(suit);
    faceVal = Face(face);
}

Face Card::getFace() const {
    return faceVal;
}

Suit Card::getSuit() const {
    return suitVal;
}

int Card::getValue() const  {
    return value;
}

void Card::setFaceVal(int intVal) {
    faceVal = Face(intVal);
    setValue(Face(intVal));
}

void Card::setSuitVal(int intVal) {
    suitVal = Suit(intVal);
}

void Card::setValue(int intVal) {//wrking
    value = intVal;
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

std::ostream& operator << (std::ostream& outs, const Card &card) {
    if (card.getFace() ==  NOFACE){
        outs << card.getValue();
    }
    else if (card.getFace() == ACE) {
        outs << "ACE";
    }
    else if (card.getFace() == KING) {
        outs << "KING";
    }
    else if (card.getFace() == QUEEN) {
        outs << "QUEEN";
    }
    else{
        outs << "JACK";
    }
    if (card.getSuit() == HEART) {
        outs << "of HEART";
    }
    else if (card.getSuit() == SPADE) {
        outs << "of SPADE";
    }
    else if (card.getSuit() == DIAMOND) {
        outs << "of DIAMOND";
    }
    else {
        outs << "of CLUB";
    }
    return outs;
}